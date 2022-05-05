/********************************************************************************
** Form generated from reading UI file 'addschedule.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSCHEDULE_H
#define UI_ADDSCHEDULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddSchedule
{
public:
    QWidget *mask;
    QWidget *widget;
    QPushButton *finish;
    QLineEdit *lineEdit;
    QTextEdit *textEdit;
    QPushButton *add_wf_item;
    QLabel *label;
    QTimeEdit *begintime;
    QLabel *label_2;
    QTimeEdit *endtime;

    void setupUi(QWidget *AddSchedule)
    {
        if (AddSchedule->objectName().isEmpty())
            AddSchedule->setObjectName(QString::fromUtf8("AddSchedule"));
        AddSchedule->resize(480, 800);
        AddSchedule->setMinimumSize(QSize(480, 800));
        AddSchedule->setMaximumSize(QSize(480, 800));
        mask = new QWidget(AddSchedule);
        mask->setObjectName(QString::fromUtf8("mask"));
        mask->setGeometry(QRect(0, 0, 480, 800));
        mask->setMinimumSize(QSize(480, 800));
        mask->setMaximumSize(QSize(480, 800));
        mask->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background:rgba(0,0,0,0.5);\n"
"}"));
        widget = new QWidget(mask);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(80, 210, 320, 170));
        widget->setMinimumSize(QSize(320, 170));
        widget->setMaximumSize(QSize(320, 170));
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget{\n"
"	background-color: white;\n"
"	border: 1px solid gray;\n"
"	border-radius:30px;\n"
"    font:25px; \n"
"    font-family: Segoe UI;\n"
"    text-align : left;\n"
"}\n"
""));
        finish = new QPushButton(widget);
        finish->setObjectName(QString::fromUtf8("finish"));
        finish->setGeometry(QRect(110, 120, 101, 35));
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
        lineEdit->setGeometry(QRect(40, 30, 101, 21));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border:1px solid white;\n"
"border-bottom-color: gray;\n"
"background-color:white;\n"
"}\n"
""));
        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(40, 60, 141, 23));
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
        add_wf_item->setGeometry(QRect(190, 30, 111, 41));
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
        label->setGeometry(QRect(40, 90, 111, 21));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: white;\n"
"}\n"
""));
        begintime = new QTimeEdit(widget);
        begintime->setObjectName(QString::fromUtf8("begintime"));
        begintime->setGeometry(QRect(80, 90, 51, 22));
        begintime->setStyleSheet(QString::fromUtf8("QTimeEdit{\n"
"border:1px solid white;\n"
"background-color:white;\n"
"border-bottom-color: gray;\n"
"font:15px; \n"
"}\n"
"QTimeEdit::up-button{\n"
"background-color:white;\n"
"}\n"
"QTimeEdit::down-button{\n"
"background-color:white;\n"
"}"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 90, 12, 21));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: white;\n"
"}\n"
""));
        endtime = new QTimeEdit(widget);
        endtime->setObjectName(QString::fromUtf8("endtime"));
        endtime->setGeometry(QRect(150, 90, 61, 22));
        endtime->setStyleSheet(QString::fromUtf8("QTimeEdit{\n"
"border:1px solid white;\n"
"background-color:white;\n"
"border-bottom-color: gray;\n"
"font:15px; \n"
"}\n"
"QTimeEdit::up-button{\n"
"background-color:white;\n"
"}\n"
"QTimeEdit::down-button{\n"
"background-color:white;\n"
"}"));

        retranslateUi(AddSchedule);

        QMetaObject::connectSlotsByName(AddSchedule);
    } // setupUi

    void retranslateUi(QWidget *AddSchedule)
    {
        AddSchedule->setWindowTitle(QApplication::translate("AddSchedule", "Form", nullptr));
        finish->setText(QApplication::translate("AddSchedule", "\345\256\214\346\210\220", nullptr));
        add_wf_item->setText(QApplication::translate("AddSchedule", "\344\273\216\345\267\245\344\275\234\346\265\201\344\270\255\351\200\211\345\217\226", nullptr));
        label->setText(QApplication::translate("AddSchedule", "\346\227\266\351\227\264\357\274\232              ~ ", nullptr));
        label_2->setText(QApplication::translate("AddSchedule", "~", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddSchedule: public Ui_AddSchedule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSCHEDULE_H
