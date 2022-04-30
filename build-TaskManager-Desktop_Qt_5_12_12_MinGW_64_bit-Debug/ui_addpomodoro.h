/********************************************************************************
** Form generated from reading UI file 'addpomodoro.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPOMODORO_H
#define UI_ADDPOMODORO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddPomodoro
{
public:
    QWidget *mask;
    QWidget *widget;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QPushButton *add_qd_item;
    QPushButton *add_wf_item;
    QLabel *label;
    QPushButton *begin;

    void setupUi(QWidget *AddPomodoro)
    {
        if (AddPomodoro->objectName().isEmpty())
            AddPomodoro->setObjectName(QString::fromUtf8("AddPomodoro"));
        AddPomodoro->resize(480, 800);
        AddPomodoro->setMinimumSize(QSize(480, 800));
        AddPomodoro->setMaximumSize(QSize(480, 800));
        mask = new QWidget(AddPomodoro);
        mask->setObjectName(QString::fromUtf8("mask"));
        mask->setGeometry(QRect(0, 0, 480, 800));
        mask->setMinimumSize(QSize(480, 800));
        mask->setMaximumSize(QSize(480, 800));
        mask->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background:rgba(0,0,0,0.5);\n"
"}"));
        widget = new QWidget(mask);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 220, 350, 170));
        widget->setMinimumSize(QSize(350, 170));
        widget->setMaximumSize(QSize(350, 170));
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
        lineEdit->setGeometry(QRect(30, 30, 100, 20));
        lineEdit->setMinimumSize(QSize(100, 20));
        lineEdit->setMaximumSize(QSize(100, 20));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border:1px solid white;\n"
"border-bottom-color: gray;\n"
"background-color:white;\n"
"}\n"
""));
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(30, 60, 121, 22));
        textEdit->setMinimumSize(QSize(0, 22));
        textEdit->setMaximumSize(QSize(16777215, 21));
        textEdit->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"border:1px solid white;\n"
"border-bottom-color: gray;\n"
"background-color:white;\n"
"}\n"
"\n"
""));
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        add_qd_item = new QPushButton(widget);
        add_qd_item->setObjectName(QString::fromUtf8("add_qd_item"));
        add_qd_item->setGeometry(QRect(250, 30, 75, 40));
        add_qd_item->setMinimumSize(QSize(75, 40));
        add_qd_item->setMaximumSize(QSize(75, 40));
        add_qd_item->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid gray;\n"
"	background-color: white;\n"
"	border-radius:15px;\n"
"    font:12px; \n"
"    font-family: Segoe UI;\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: gray;\n"
"}"));
        add_wf_item = new QPushButton(widget);
        add_wf_item->setObjectName(QString::fromUtf8("add_wf_item"));
        add_wf_item->setGeometry(QRect(170, 30, 75, 40));
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
        label->setGeometry(QRect(30, 90, 221, 16));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: white;\n"
"}\n"
""));
        begin = new QPushButton(widget);
        begin->setObjectName(QString::fromUtf8("begin"));
        begin->setGeometry(QRect(120, 120, 100, 35));
        begin->setMinimumSize(QSize(100, 35));
        begin->setMaximumSize(QSize(100, 35));
        begin->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid gray;\n"
"	background-color: white;\n"
"	border-radius:12px;\n"
"    font:20px; \n"
"    font-family: Segoe UI;\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: gray;\n"
"}"));

        retranslateUi(AddPomodoro);

        QMetaObject::connectSlotsByName(AddPomodoro);
    } // setupUi

    void retranslateUi(QWidget *AddPomodoro)
    {
        AddPomodoro->setWindowTitle(QApplication::translate("AddPomodoro", "Form", nullptr));
        add_qd_item->setText(QApplication::translate("AddPomodoro", "\345\233\233\350\261\241\351\231\220", nullptr));
        add_wf_item->setText(QApplication::translate("AddPomodoro", "\345\267\245\344\275\234\346\265\201", nullptr));
        label->setText(QApplication::translate("AddPomodoro", "\344\270\223\346\263\250\346\227\266\351\227\264\357\274\23225min     \344\274\221\346\201\257\346\227\266\351\227\264\357\274\23225min", nullptr));
        begin->setText(QApplication::translate("AddPomodoro", "\345\274\200\345\247\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPomodoro: public Ui_AddPomodoro {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPOMODORO_H
