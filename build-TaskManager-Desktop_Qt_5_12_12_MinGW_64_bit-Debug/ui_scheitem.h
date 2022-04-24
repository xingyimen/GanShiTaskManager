/********************************************************************************
** Form generated from reading UI file 'scheitem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCHEITEM_H
#define UI_SCHEITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ScheItem
{
public:
    QWidget *widget;
    QTimeEdit *starttime;
    QTimeEdit *endtime;
    QLineEdit *title;
    QTextEdit *description;
    QFrame *line;

    void setupUi(QWidget *ScheItem)
    {
        if (ScheItem->objectName().isEmpty())
            ScheItem->setObjectName(QString::fromUtf8("ScheItem"));
        ScheItem->resize(380, 110);
        ScheItem->setMinimumSize(QSize(380, 110));
        ScheItem->setMaximumSize(QSize(380, 110));
        ScheItem->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color: rgb(255, 255, 255)\357\274\233\n"
"	border-color: rgb(147, 147, 147);\n"
"}\n"
""));
        widget = new QWidget(ScheItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 380, 110));
        widget->setMinimumSize(QSize(380, 110));
        widget->setMaximumSize(QSize(380, 110));
        widget->setStyleSheet(QString::fromUtf8(""));
        starttime = new QTimeEdit(widget);
        starttime->setObjectName(QString::fromUtf8("starttime"));
        starttime->setGeometry(QRect(30, 20, 81, 31));
        starttime->setStyleSheet(QString::fromUtf8("QTimeEdit{\n"
"border:0px solid white;\n"
"background-color:white;\n"
"}\n"
"QTimeEdit::up-button{\n"
"background-color:white;\n"
"}\n"
"QTimeEdit::down-button{\n"
"background-color:white;\n"
"}"));
        endtime = new QTimeEdit(widget);
        endtime->setObjectName(QString::fromUtf8("endtime"));
        endtime->setGeometry(QRect(30, 60, 81, 31));
        endtime->setStyleSheet(QString::fromUtf8("QTimeEdit{\n"
"border:0px solid white;\n"
"background-color:white;\n"
"}\n"
"QTimeEdit::up-button{\n"
"background-color:white;\n"
"}\n"
"QTimeEdit::down-button{\n"
"background-color:white;\n"
"}"));
        title = new QLineEdit(widget);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(140, 20, 211, 31));
        title->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border:0px solid white;\n"
"background-color:white;\n"
"}"));
        description = new QTextEdit(widget);
        description->setObjectName(QString::fromUtf8("description"));
        description->setGeometry(QRect(140, 50, 211, 51));
        description->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"border:0px solid white;\n"
"background-color:white;\n"
"}"));
        line = new QFrame(widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(110, 10, 5, 90));
        line->setStyleSheet(QString::fromUtf8("QFrame#line{\n"
"	background-color: rgb(255, 255, 255);\n"
"    color:white;\n"
"    border-left: 2px dotted rgb(42, 180, 255);\n"
"\n"
"}"));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(1);
        line->setFrameShape(QFrame::VLine);

        retranslateUi(ScheItem);

        QMetaObject::connectSlotsByName(ScheItem);
    } // setupUi

    void retranslateUi(QWidget *ScheItem)
    {
        ScheItem->setWindowTitle(QApplication::translate("ScheItem", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ScheItem: public Ui_ScheItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCHEITEM_H
