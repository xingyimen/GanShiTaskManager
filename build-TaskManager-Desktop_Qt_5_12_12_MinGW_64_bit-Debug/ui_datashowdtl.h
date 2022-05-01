/********************************************************************************
** Form generated from reading UI file 'datashowdtl.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATASHOWDTL_H
#define UI_DATASHOWDTL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dataShowDtl
{
public:
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QWidget *widget;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QDateEdit *dateEdit;
    QToolButton *toolButton_date;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *dataShowDtl)
    {
        if (dataShowDtl->objectName().isEmpty())
            dataShowDtl->setObjectName(QString::fromUtf8("dataShowDtl"));
        dataShowDtl->resize(481, 786);
        verticalLayoutWidget_2 = new QWidget(dataShowDtl);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 240, 481, 541));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(dataShowDtl);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 0, 481, 51));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(481, 51));
        label_4->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(42, 180, 255);\n"
"    font:25px; \n"
"    font-family: \345\271\274\345\234\206;\n"
"    font-weight:bold;\n"
"    color:white;\n"
" \n"
"}\n"
""));
        label_4->setAlignment(Qt::AlignCenter);
        widget = new QWidget(dataShowDtl);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 67, 481, 161));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetFixedSize);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        dateEdit = new QDateEdit(widget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setMinimumSize(QSize(155, 30));
        dateEdit->setCalendarPopup(true);

        horizontalLayout->addWidget(dateEdit);

        toolButton_date = new QToolButton(widget);
        toolButton_date->setObjectName(QString::fromUtf8("toolButton_date"));
        sizePolicy.setHeightForWidth(toolButton_date->sizePolicy().hasHeightForWidth());
        toolButton_date->setSizePolicy(sizePolicy);
        toolButton_date->setMinimumSize(QSize(30, 30));
        toolButton_date->setStyleSheet(QString::fromUtf8("border-image: url(:/menu/res/date.svg);"));

        horizontalLayout->addWidget(toolButton_date);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 50, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 2, 0, 1, 1);


        retranslateUi(dataShowDtl);

        QMetaObject::connectSlotsByName(dataShowDtl);
    } // setupUi

    void retranslateUi(QWidget *dataShowDtl)
    {
        dataShowDtl->setWindowTitle(QApplication::translate("dataShowDtl", "Form", nullptr));
        label_4->setText(QApplication::translate("dataShowDtl", "\346\225\260\346\215\256\346\212\245\350\241\250", nullptr));
        toolButton_date->setText(QApplication::translate("dataShowDtl", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dataShowDtl: public Ui_dataShowDtl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATASHOWDTL_H
