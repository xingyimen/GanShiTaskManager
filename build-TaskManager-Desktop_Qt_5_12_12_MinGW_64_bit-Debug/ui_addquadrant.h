/********************************************************************************
** Form generated from reading UI file 'addquadrant.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDQUADRANT_H
#define UI_ADDQUADRANT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddQuadrant
{
public:
    QWidget *mask;
    QWidget *widget;
    QPushButton *add_wf_item;
    QPushButton *finish;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QLabel *label;
    QDateEdit *dateEdit;
    QTimeEdit *timeEdit;

    void setupUi(QWidget *AddQuadrant)
    {
        if (AddQuadrant->objectName().isEmpty())
            AddQuadrant->setObjectName(QString::fromUtf8("AddQuadrant"));
        AddQuadrant->resize(480, 800);
        AddQuadrant->setMinimumSize(QSize(480, 800));
        AddQuadrant->setMaximumSize(QSize(480, 800));
        mask = new QWidget(AddQuadrant);
        mask->setObjectName(QString::fromUtf8("mask"));
        mask->setGeometry(QRect(0, 0, 480, 800));
        mask->setMinimumSize(QSize(480, 800));
        mask->setMaximumSize(QSize(480, 800));
        mask->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background:rgba(0,0,0,0.5);\n"
"}"));
        widget = new QWidget(mask);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 250, 310, 200));
        widget->setMinimumSize(QSize(310, 200));
        widget->setMaximumSize(QSize(310, 200));
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget{\n"
"	background-color: white;\n"
"	border: 1px solid gray;\n"
"	border-radius:30px;\n"
"    font:25px; \n"
"    font-family: Segoe UI;\n"
"    text-align : left;\n"
"}\n"
""));
        add_wf_item = new QPushButton(widget);
        add_wf_item->setObjectName(QString::fromUtf8("add_wf_item"));
        add_wf_item->setGeometry(QRect(210, 20, 75, 40));
        add_wf_item->setMinimumSize(QSize(75, 40));
        add_wf_item->setMaximumSize(QSize(75, 40));
        add_wf_item->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid gray;\n"
"	background-color: white;\n"
"	border-radius:15px;\n"
"    font:12px; \n"
"    font-family: Segoe UI;\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: gray;\n"
"}"));
        finish = new QPushButton(widget);
        finish->setObjectName(QString::fromUtf8("finish"));
        finish->setGeometry(QRect(110, 150, 100, 35));
        finish->setMinimumSize(QSize(100, 35));
        finish->setMaximumSize(QSize(100, 35));
        finish->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid gray;\n"
"	background-color: white;\n"
"	border-radius:12px;\n"
"    font:20px; \n"
"    font-family: Segoe UI;\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: gray;\n"
"}"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 30, 113, 21));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border:1px solid white;\n"
"border-bottom-color: gray;\n"
"background-color:white;\n"
"}\n"
""));
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 110, 260, 21));
        textEdit->setMinimumSize(QSize(260, 21));
        textEdit->setMaximumSize(QSize(260, 21));
        textEdit->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"border:1px solid white;\n"
"border-bottom-color: gray;\n"
"background-color:white;\n"
"}\n"
"\n"
""));
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 60, 53, 16));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: white;\n"
"}"));
        dateEdit = new QDateEdit(widget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(90, 60, 81, 21));
        dateEdit->setStyleSheet(QString::fromUtf8("QDateEdit{\n"
"border:0px solid white;\n"
"background-color:white;\n"
"}\n"
"QDateEdit::up-button{\n"
"background-color:white;\n"
"}\n"
"QDateEdit::down-button{\n"
"background-color:white;\n"
"}"));
        timeEdit = new QTimeEdit(widget);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setGeometry(QRect(160, 60, 51, 21));
        timeEdit->setStyleSheet(QString::fromUtf8("QTimeEdit{\n"
"border:0px solid white;\n"
"background-color:white;\n"
"}\n"
""));
        finish->raise();
        lineEdit->raise();
        textEdit->raise();
        label->raise();
        dateEdit->raise();
        timeEdit->raise();
        add_wf_item->raise();

        retranslateUi(AddQuadrant);

        QMetaObject::connectSlotsByName(AddQuadrant);
    } // setupUi

    void retranslateUi(QWidget *AddQuadrant)
    {
        AddQuadrant->setWindowTitle(QApplication::translate("AddQuadrant", "Form", nullptr));
        add_wf_item->setText(QApplication::translate("AddQuadrant", "\345\267\245\344\275\234\346\265\201", nullptr));
        finish->setText(QApplication::translate("AddQuadrant", "\345\256\214\346\210\220", nullptr));
        label->setText(QApplication::translate("AddQuadrant", "\346\210\252\346\255\242\346\227\266\351\227\264\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddQuadrant: public Ui_AddQuadrant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDQUADRANT_H
