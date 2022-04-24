/********************************************************************************
** Form generated from reading UI file 'workitem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKITEM_H
#define UI_WORKITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WorkItem
{
public:
    QWidget *widget;
    QPushButton *pushButton;
    QLineEdit *title;
    QTextEdit *description;

    void setupUi(QWidget *WorkItem)
    {
        if (WorkItem->objectName().isEmpty())
            WorkItem->setObjectName(QString::fromUtf8("WorkItem"));
        WorkItem->resize(412, 115);
        widget = new QWidget(WorkItem);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 400, 110));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(320, 40, 75, 24));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border:null;\n"
"background-color:white;\n"
"}\n"
"QPushButton::hover{\n"
"color:rgb(253,202,36);\n"
"}\n"
""));
        title = new QLineEdit(widget);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(30, 20, 113, 21));
        title->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border:0px solid white;\n"
"background-color:white;\n"
"}"));
        description = new QTextEdit(widget);
        description->setObjectName(QString::fromUtf8("description"));
        description->setGeometry(QRect(30, 40, 211, 61));
        description->setStyleSheet(QString::fromUtf8("QTextEdit{\n"
"border:0px solid white;\n"
"background-color:white;\n"
"}"));

        retranslateUi(WorkItem);

        QMetaObject::connectSlotsByName(WorkItem);
    } // setupUi

    void retranslateUi(QWidget *WorkItem)
    {
        WorkItem->setWindowTitle(QApplication::translate("WorkItem", "Form", nullptr));
        pushButton->setText(QApplication::translate("WorkItem", "\346\237\245\347\234\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WorkItem: public Ui_WorkItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKITEM_H
