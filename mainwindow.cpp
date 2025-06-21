#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Цифры
    connect(ui->btn0, &QPushButton::clicked, this, [this]() { appendToDisplay("0"); });
    connect(ui->btn1, &QPushButton::clicked, this, [this]() { appendToDisplay("1"); });
    connect(ui->btn2, &QPushButton::clicked, this, [this]() { appendToDisplay("2"); });
    connect(ui->btn3, &QPushButton::clicked, this, [this]() { appendToDisplay("3"); });
    connect(ui->btn4, &QPushButton::clicked, this, [this]() { appendToDisplay("4"); });
    connect(ui->btn5, &QPushButton::clicked, this, [this]() { appendToDisplay("5"); });
    connect(ui->btn6, &QPushButton::clicked, this, [this]() { appendToDisplay("6"); });
    connect(ui->btn7, &QPushButton::clicked, this, [this]() { appendToDisplay("7"); });
    connect(ui->btn8, &QPushButton::clicked, this, [this]() { appendToDisplay("8"); });
    connect(ui->btn9, &QPushButton::clicked, this, [this]() { appendToDisplay("9"); });

    // Операции
    connect(ui->btnPlus,  &QPushButton::clicked, this, [this]() { appendToDisplay("+"); });
    connect(ui->btnMinus, &QPushButton::clicked, this, [this]() { appendToDisplay("-"); });
    connect(ui->btnMul,   &QPushButton::clicked, this, [this]() { appendToDisplay("*"); });
    connect(ui->btnDiv,   &QPushButton::clicked, this, [this]() { appendToDisplay("/"); });

    // Кнопки = и C
    connect(ui->btnEqual, &QPushButton::clicked, this, &MainWindow::calculateResult);
    connect(ui->btnClear, &QPushButton::clicked, this, [this]() { ui->Display->clear(); });

}

#include <QDebug>
#include <QJSEngine>
#include <QJSValue>


void MainWindow::appendToDisplay(const QString &text)
{
    ui->Display->setText(ui->Display->text() + text);
}

void MainWindow::calculateResult()
{
    QString expression = ui->Display->text();

    // Для простоты используем QJSEngine (с Qt 5.12+) или QScriptEngine
    QJSEngine engine;
    QJSValue result = engine.evaluate(expression);
    if (result.isError()) {
        ui->Display->setText("Error");
    } else {
        ui->Display->setText(result.toString());
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
