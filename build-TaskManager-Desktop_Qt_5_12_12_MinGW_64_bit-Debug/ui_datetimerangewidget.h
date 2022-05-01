/********************************************************************************
** Form generated from reading UI file 'datetimerangewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATETIMERANGEWIDGET_H
#define UI_DATETIMERANGEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DateTimeRangeWidget
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_starttime;
    QLabel *label_endtime;
    QHBoxLayout *horizontalLayout;
    QLabel *label_text;

    void setupUi(QWidget *DateTimeRangeWidget)
    {
        if (DateTimeRangeWidget->objectName().isEmpty())
            DateTimeRangeWidget->setObjectName(QString::fromUtf8("DateTimeRangeWidget"));
        DateTimeRangeWidget->resize(503, 122);
        gridLayout_2 = new QGridLayout(DateTimeRangeWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinimumSize);
        label_starttime = new QLabel(DateTimeRangeWidget);
        label_starttime->setObjectName(QString::fromUtf8("label_starttime"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_starttime->sizePolicy().hasHeightForWidth());
        label_starttime->setSizePolicy(sizePolicy);
        label_starttime->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(label_starttime, 0, 0, 1, 1);

        label_endtime = new QLabel(DateTimeRangeWidget);
        label_endtime->setObjectName(QString::fromUtf8("label_endtime"));
        sizePolicy.setHeightForWidth(label_endtime->sizePolicy().hasHeightForWidth());
        label_endtime->setSizePolicy(sizePolicy);
        label_endtime->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(label_endtime, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_text = new QLabel(DateTimeRangeWidget);
        label_text->setObjectName(QString::fromUtf8("label_text"));
        sizePolicy.setHeightForWidth(label_text->sizePolicy().hasHeightForWidth());
        label_text->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label_text);


        gridLayout_2->addLayout(horizontalLayout, 0, 1, 1, 1);


        retranslateUi(DateTimeRangeWidget);

        QMetaObject::connectSlotsByName(DateTimeRangeWidget);
    } // setupUi

    void retranslateUi(QWidget *DateTimeRangeWidget)
    {
        DateTimeRangeWidget->setWindowTitle(QApplication::translate("DateTimeRangeWidget", "Form", nullptr));
        label_starttime->setText(QApplication::translate("DateTimeRangeWidget", "123", nullptr));
        label_endtime->setText(QApplication::translate("DateTimeRangeWidget", "456", nullptr));
        label_text->setText(QApplication::translate("DateTimeRangeWidget", "789", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DateTimeRangeWidget: public Ui_DateTimeRangeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATETIMERANGEWIDGET_H
