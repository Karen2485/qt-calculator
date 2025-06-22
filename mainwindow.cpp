#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <QDebug>
#include <QJSEngine>
#include <QJSValue>
#include <QMessageBox>
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(300, 400);
    this->setWindowIcon(QIcon(":/icon.png"));
    this->setWindowTitle("Calculator");
    connect(ui->pushButton_theme, &QPushButton::clicked, this, &MainWindow::on_pushButton_theme_clicked);
    applyDarkTheme(); // стартовая тема
    isDarkTheme = true;

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

    // =
    connect(ui->btnEqual, &QPushButton::clicked, this, &MainWindow::calculateResult);

    // Очистка
    connect(ui->btnClear, &QPushButton::clicked, this, [this]() { ui->Display->clear(); });

    // Тема
    connect(ui->pushButton_theme, &QPushButton::clicked, this, &MainWindow::on_pushButton_theme_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::appendToDisplay(const QString &text)
{
    QString current = ui->Display->text();

    // Если нажата арифметическая операция
    if (text == "+" || text == "-" || text == "*" || text == "/") {
        if (current.isEmpty()) return;

        QChar lastChar = current.at(current.length() - 1);

        // Если предыдущий символ — тот же оператор, игнорируем
        if (QString(lastChar) == text) return;

        // Если предыдущий — другой оператор, заменим его
        if (QString("+-*/").contains(lastChar)) {
            current.chop(1);
        }

        current += text;
        ui->Display->setText(current);
        return;
    }

    // Если всё нормально — добавляем
    ui->Display->setText(current + text);
}

void MainWindow::on_pushButton_theme_clicked()
{
    if (isDarkTheme) {
        applyLightTheme();
    } else {
        applyDarkTheme();
    }
    isDarkTheme = !isDarkTheme;
}

void MainWindow::applyDarkTheme()
{
    qApp->setStyleSheet(R"(
        QWidget {
            background-color: #2b2b2b;
            color: #ffffff;
            font-size: 16px;
        }

        QPushButton {
            background-color: #444;
            color: #fff;
            border: 1px solid #666;
            border-radius: 5px;
            padding: 5px;
        }

        QPushButton:hover {
            background-color: #666;
        }

        QPushButton:pressed {
            background-color: #888;
        }

        QLineEdit {
            background-color: #1e1e1e;
            color: white;
            border: none;
            padding: 5px;
        }
    )");
    this->update(); // обновить интерфейс
}

void MainWindow::applyLightTheme()
{
    qApp->setStyleSheet(R"(
        QWidget {
            background-color: #5F9EA0;
            color: #ffffff;
            font-size: 16px;
        }

        QPushButton {
            background-color: #e0e0e0;
            color: #000;
            border: 1px solid #aaa;
            border-radius: 5px;
            padding: 5px;
        }

        QPushButton:hover {
            background-color: #ccc;
        }

        QPushButton:pressed {
            background-color: #bbb;
        }

        QLineEdit {
            background-color: #8FBC8F;
            color: black;
            border: none;
            padding: 5px;
        }
    )");
    this->update(); // обновить интерфейс
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();

    if (key >= Qt::Key_0 && key <= Qt::Key_9) {
        ui->Display->insert(QString::number(key - Qt::Key_0));
    }
    else if (key == Qt::Key_Plus) {
        ui->Display->insert("+");
    }
    else if (key == Qt::Key_Minus) {
        ui->Display->insert("-");
    }
    else if (key == Qt::Key_Asterisk) {
        ui->Display->insert("*");
    }
    else if (key == Qt::Key_Slash) {
        ui->Display->insert("/");
    }
    else if (key == Qt::Key_ParenLeft) {
        ui->Display->insert("(");
    }
    else if (key == Qt::Key_ParenRight) {
        ui->Display->insert(")");
    }
    else if (key == Qt::Key_Backspace) {
        QString text = ui->Display->text();
        text.chop(1);
        ui->Display->setText(text);
    }
    else if (key == Qt::Key_Return || key == Qt::Key_Enter) {
        calculateResult();
    }
    else if (key == Qt::Key_Escape) {
        ui->Display->clear();
    }
}

void MainWindow::calculateResult()
{
    QString expression = ui->Display->text();

    // Если выражение заканчивается на оператор — не считаем
    if (expression.isEmpty() || expression.endsWith("+") || expression.endsWith("-") ||
        expression.endsWith("*") || expression.endsWith("/")) {
        return; // ничего не делаем
    }

    // Если повторное нажатие "=" — повторяем последнюю операцию
    if (expression == lastResult && !lastOperator.isEmpty() && !lastOperand.isEmpty()) {
        expression += lastOperator + lastOperand;
    }

    // Проверка деления на ноль
    if (expression.contains(QRegularExpression(R"(/0+(\D|$)?)"))) {
        QMessageBox::warning(this, "Math Error", "Cannot divide by zero!");
        ui->Display->clear();
        return;
    }

    QJSEngine engine;
    QJSValue result = engine.evaluate(expression);

    if (result.isError() || result.toString() == "Infinity") {
        ui->Display->setText("Error");
    } else {
        ui->Display->setText(result.toString());
        lastResult = result.toString();

        // Запоминаем последнюю операцию, если она есть
        QRegularExpression re(R"((\d+(?:\.\d+)?)([+\-*/])(\d+(?:\.\d+)?))");
        QRegularExpressionMatch match = re.match(expression);
        if (match.hasMatch()) {
            lastOperator = match.captured(2);
            lastOperand = match.captured(3);
        }
    }
}
