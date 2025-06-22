/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *Display;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QPushButton *btn6;
    QPushButton *btn8;
    QPushButton *btn1;
    QPushButton *btnClear;
    QPushButton *btn7;
    QPushButton *btn5;
    QPushButton *btn2;
    QPushButton *btnMinus;
    QPushButton *btn4;
    QPushButton *btn0;
    QPushButton *btn9;
    QPushButton *btn3;
    QPushButton *btnEqual;
    QPushButton *btnPlus;
    QPushButton *btnMul;
    QPushButton *btnDiv;
    QPushButton *pushButton_theme;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        Display = new QLineEdit(centralwidget);
        Display->setObjectName("Display");
        Display->setMinimumSize(QSize(0, 55));
        QFont font;
        font.setFamilies({QString::fromUtf8("Roman")});
        font.setPointSize(28);
        font.setBold(true);
        Display->setFont(font);
        Display->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        Display->setReadOnly(true);

        verticalLayout->addWidget(Display);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName("gridLayout_2");
        btn6 = new QPushButton(widget);
        btn6->setObjectName("btn6");

        gridLayout_2->addWidget(btn6, 1, 2, 1, 1);

        btn8 = new QPushButton(widget);
        btn8->setObjectName("btn8");

        gridLayout_2->addWidget(btn8, 0, 1, 1, 1);

        btn1 = new QPushButton(widget);
        btn1->setObjectName("btn1");

        gridLayout_2->addWidget(btn1, 2, 0, 1, 1);

        btnClear = new QPushButton(widget);
        btnClear->setObjectName("btnClear");

        gridLayout_2->addWidget(btnClear, 3, 1, 1, 1);

        btn7 = new QPushButton(widget);
        btn7->setObjectName("btn7");

        gridLayout_2->addWidget(btn7, 0, 0, 1, 1);

        btn5 = new QPushButton(widget);
        btn5->setObjectName("btn5");

        gridLayout_2->addWidget(btn5, 1, 1, 1, 1);

        btn2 = new QPushButton(widget);
        btn2->setObjectName("btn2");

        gridLayout_2->addWidget(btn2, 2, 1, 1, 1);

        btnMinus = new QPushButton(widget);
        btnMinus->setObjectName("btnMinus");

        gridLayout_2->addWidget(btnMinus, 2, 4, 1, 1);

        btn4 = new QPushButton(widget);
        btn4->setObjectName("btn4");

        gridLayout_2->addWidget(btn4, 1, 0, 1, 1);

        btn0 = new QPushButton(widget);
        btn0->setObjectName("btn0");

        gridLayout_2->addWidget(btn0, 3, 0, 1, 1);

        btn9 = new QPushButton(widget);
        btn9->setObjectName("btn9");

        gridLayout_2->addWidget(btn9, 0, 2, 1, 1);

        btn3 = new QPushButton(widget);
        btn3->setObjectName("btn3");

        gridLayout_2->addWidget(btn3, 2, 2, 1, 1);

        btnEqual = new QPushButton(widget);
        btnEqual->setObjectName("btnEqual");

        gridLayout_2->addWidget(btnEqual, 3, 2, 1, 1);

        btnPlus = new QPushButton(widget);
        btnPlus->setObjectName("btnPlus");

        gridLayout_2->addWidget(btnPlus, 3, 4, 1, 1);

        btnMul = new QPushButton(widget);
        btnMul->setObjectName("btnMul");

        gridLayout_2->addWidget(btnMul, 1, 4, 1, 1);

        btnDiv = new QPushButton(widget);
        btnDiv->setObjectName("btnDiv");

        gridLayout_2->addWidget(btnDiv, 0, 4, 1, 1);


        verticalLayout->addWidget(widget);

        pushButton_theme = new QPushButton(centralwidget);
        pushButton_theme->setObjectName("pushButton_theme");
        pushButton_theme->setEnabled(true);

        verticalLayout->addWidget(pushButton_theme, 0, Qt::AlignmentFlag::AlignLeft);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btn6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        btn8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        btn1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        btnClear->setText(QCoreApplication::translate("MainWindow", "\320\241", nullptr));
        btn7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        btn5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        btn2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        btnMinus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        btn4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        btn0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btn9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        btn3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        btnEqual->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        btnPlus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        btnMul->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        btnDiv->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_theme->setText(QCoreApplication::translate("MainWindow", "Theme", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
