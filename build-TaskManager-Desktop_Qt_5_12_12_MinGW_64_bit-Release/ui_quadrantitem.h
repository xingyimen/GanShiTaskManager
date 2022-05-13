/********************************************************************************
** Form generated from reading UI file 'quadrantitem.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUADRANTITEM_H
#define UI_QUADRANTITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuadrantItem
{
public:
    QPushButton *qua_item;

    void setupUi(QWidget *QuadrantItem)
    {
        if (QuadrantItem->objectName().isEmpty())
            QuadrantItem->setObjectName(QString::fromUtf8("QuadrantItem"));
        QuadrantItem->resize(50, 50);
        QuadrantItem->setMinimumSize(QSize(50, 50));
        QuadrantItem->setMaximumSize(QSize(50, 50));
        qua_item = new QPushButton(QuadrantItem);
        qua_item->setObjectName(QString::fromUtf8("qua_item"));
        qua_item->setGeometry(QRect(0, 0, 50, 50));
        qua_item->setMinimumSize(QSize(50, 50));
        qua_item->setMaximumSize(QSize(50, 50));
        qua_item->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border: 1px solid gray;\n"
"	background-color: rgb(181, 225, 250);\n"
"	border-radius:0px;\n"
"    font:12px; \n"
"    font-family: Segoe UI;\n"
"}"));

        retranslateUi(QuadrantItem);

        QMetaObject::connectSlotsByName(QuadrantItem);
    } // setupUi

    void retranslateUi(QWidget *QuadrantItem)
    {
        QuadrantItem->setWindowTitle(QApplication::translate("QuadrantItem", "Form", nullptr));
        qua_item->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QuadrantItem: public Ui_QuadrantItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUADRANTITEM_H
