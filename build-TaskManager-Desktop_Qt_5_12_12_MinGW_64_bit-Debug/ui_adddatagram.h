/********************************************************************************
** Form generated from reading UI file 'adddatagram.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDATAGRAM_H
#define UI_ADDDATAGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddDatagram
{
public:
    QWidget *mask;
    QWidget *widget;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QPushButton *add_wf_item;
    QLabel *label;
    QPushButton *finish;
    QDateTimeEdit *dateTimeEdit;

    void setupUi(QWidget *AddDatagram)
    {
        if (AddDatagram->objectName().isEmpty())
            AddDatagram->setObjectName(QString::fromUtf8("AddDatagram"));
        AddDatagram->resize(480, 800);
        AddDatagram->setMinimumSize(QSize(480, 800));
        AddDatagram->setMaximumSize(QSize(480, 800));
        mask = new QWidget(AddDatagram);
        mask->setObjectName(QString::fromUtf8("mask"));
        mask->setGeometry(QRect(0, -10, 480, 800));
        mask->setMinimumSize(QSize(480, 800));
        mask->setMaximumSize(QSize(480, 800));
        mask->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background:rgba(0,0,0,0.5);\n"
"}"));
        widget = new QWidget(mask);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(90, 240, 310, 200));
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
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 30, 101, 21));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border:1px solid white;\n"
"border-bottom-color: gray;\n"
"background-color:white;\n"
"}\n"
""));
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 100, 261, 21));
        textEdit->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"border:1px solid white;\n"
"border-bottom-color: gray;\n"
"background-color:white;\n"
"}\n"
"\n"
""));
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        add_wf_item = new QPushButton(widget);
        add_wf_item->setObjectName(QString::fromUtf8("add_wf_item"));
        add_wf_item->setGeometry(QRect(210, 30, 75, 40));
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
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 60, 61, 21));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: white;\n"
"}\n"
""));
        finish = new QPushButton(widget);
        finish->setObjectName(QString::fromUtf8("finish"));
        finish->setGeometry(QRect(110, 140, 100, 35));
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
        dateTimeEdit = new QDateTimeEdit(widget);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(80, 60, 111, 22));
        dateTimeEdit->setStyleSheet(QString::fromUtf8("QDateTimeEdit{\n"
"border:1px solid white;\n"
"background-color:white;\n"
"}\n"
"QDateTimeEdit::up-button{\n"
"background-color:white;\n"
"}\n"
"QDateTimeEdit::down-button{\n"
"background-color:white;\n"
"}"));

        retranslateUi(AddDatagram);

        QMetaObject::connectSlotsByName(AddDatagram);
    } // setupUi

    void retranslateUi(QWidget *AddDatagram)
    {
        AddDatagram->setWindowTitle(QApplication::translate("AddDatagram", "Form", nullptr));
        add_wf_item->setText(QApplication::translate("AddDatagram", "\345\267\245\344\275\234\346\265\201", nullptr));
        label->setText(QApplication::translate("AddDatagram", "\346\210\252\346\255\242\346\227\266\351\227\264\357\274\232", nullptr));
        finish->setText(QApplication::translate("AddDatagram", "\345\256\214\346\210\220", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDatagram: public Ui_AddDatagram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDATAGRAM_H
