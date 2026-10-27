/********************************************************************************
** Form generated from reading UI file 'Qtcalc.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTCALC_H
#define UI_QTCALC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtcalcClass
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTextBrowser *result;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btn4;
    QPushButton *btn5;
    QPushButton *btn8;
    QPushButton *btnm;
    QPushButton *btn7;
    QPushButton *btn2;
    QPushButton *btnp;
    QPushButton *btn1;
    QPushButton *btn9;
    QPushButton *btns;
    QPushButton *btn6;
    QPushButton *btn3;
    QPushButton *btnc;
    QPushButton *btn0;
    QPushButton *btne;
    QPushButton *btnd;

    void setupUi(QWidget *QtcalcClass)
    {
        if (QtcalcClass->objectName().isEmpty())
            QtcalcClass->setObjectName("QtcalcClass");
        QtcalcClass->resize(500, 534);
        verticalLayoutWidget = new QWidget(QtcalcClass);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(80, 40, 331, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        result = new QTextBrowser(verticalLayoutWidget);
        result->setObjectName("result");

        verticalLayout->addWidget(result);

        gridLayoutWidget = new QWidget(QtcalcClass);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(80, 130, 344, 321));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btn4 = new QPushButton(gridLayoutWidget);
        btn4->setObjectName("btn4");

        gridLayout->addWidget(btn4, 1, 0, 1, 1);

        btn5 = new QPushButton(gridLayoutWidget);
        btn5->setObjectName("btn5");

        gridLayout->addWidget(btn5, 1, 1, 1, 1);

        btn8 = new QPushButton(gridLayoutWidget);
        btn8->setObjectName("btn8");

        gridLayout->addWidget(btn8, 0, 1, 1, 1);

        btnm = new QPushButton(gridLayoutWidget);
        btnm->setObjectName("btnm");

        gridLayout->addWidget(btnm, 2, 3, 1, 1);

        btn7 = new QPushButton(gridLayoutWidget);
        btn7->setObjectName("btn7");

        gridLayout->addWidget(btn7, 0, 0, 1, 1);

        btn2 = new QPushButton(gridLayoutWidget);
        btn2->setObjectName("btn2");

        gridLayout->addWidget(btn2, 2, 1, 1, 1);

        btnp = new QPushButton(gridLayoutWidget);
        btnp->setObjectName("btnp");

        gridLayout->addWidget(btnp, 0, 3, 1, 1);

        btn1 = new QPushButton(gridLayoutWidget);
        btn1->setObjectName("btn1");

        gridLayout->addWidget(btn1, 2, 0, 1, 1);

        btn9 = new QPushButton(gridLayoutWidget);
        btn9->setObjectName("btn9");

        gridLayout->addWidget(btn9, 0, 2, 1, 1);

        btns = new QPushButton(gridLayoutWidget);
        btns->setObjectName("btns");

        gridLayout->addWidget(btns, 1, 3, 1, 1);

        btn6 = new QPushButton(gridLayoutWidget);
        btn6->setObjectName("btn6");

        gridLayout->addWidget(btn6, 1, 2, 1, 1);

        btn3 = new QPushButton(gridLayoutWidget);
        btn3->setObjectName("btn3");

        gridLayout->addWidget(btn3, 2, 2, 1, 1);

        btnc = new QPushButton(gridLayoutWidget);
        btnc->setObjectName("btnc");

        gridLayout->addWidget(btnc, 3, 0, 1, 1);

        btn0 = new QPushButton(gridLayoutWidget);
        btn0->setObjectName("btn0");

        gridLayout->addWidget(btn0, 3, 1, 1, 1);

        btne = new QPushButton(gridLayoutWidget);
        btne->setObjectName("btne");

        gridLayout->addWidget(btne, 3, 2, 1, 1);

        btnd = new QPushButton(gridLayoutWidget);
        btnd->setObjectName("btnd");

        gridLayout->addWidget(btnd, 3, 3, 1, 1);


        retranslateUi(QtcalcClass);

        QMetaObject::connectSlotsByName(QtcalcClass);
    } // setupUi

    void retranslateUi(QWidget *QtcalcClass)
    {
        QtcalcClass->setWindowTitle(QCoreApplication::translate("QtcalcClass", "Qtcalc", nullptr));
        result->setHtml(QCoreApplication::translate("QtcalcClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt; font-weight:700; font-style:italic;\">Welcome!</span></p></body></html>", nullptr));
        btn4->setText(QCoreApplication::translate("QtcalcClass", "4", nullptr));
        btn5->setText(QCoreApplication::translate("QtcalcClass", "5", nullptr));
        btn8->setText(QCoreApplication::translate("QtcalcClass", "8", nullptr));
        btnm->setText(QCoreApplication::translate("QtcalcClass", "*", nullptr));
        btn7->setText(QCoreApplication::translate("QtcalcClass", "7", nullptr));
        btn2->setText(QCoreApplication::translate("QtcalcClass", "2", nullptr));
        btnp->setText(QCoreApplication::translate("QtcalcClass", "+", nullptr));
        btn1->setText(QCoreApplication::translate("QtcalcClass", "1", nullptr));
        btn9->setText(QCoreApplication::translate("QtcalcClass", "9", nullptr));
        btns->setText(QCoreApplication::translate("QtcalcClass", "-", nullptr));
        btn6->setText(QCoreApplication::translate("QtcalcClass", "6", nullptr));
        btn3->setText(QCoreApplication::translate("QtcalcClass", "3", nullptr));
        btnc->setText(QCoreApplication::translate("QtcalcClass", "C", nullptr));
        btn0->setText(QCoreApplication::translate("QtcalcClass", "0", nullptr));
        btne->setText(QCoreApplication::translate("QtcalcClass", "ENTER", nullptr));
        btnd->setText(QCoreApplication::translate("QtcalcClass", "/", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtcalcClass: public Ui_QtcalcClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTCALC_H
