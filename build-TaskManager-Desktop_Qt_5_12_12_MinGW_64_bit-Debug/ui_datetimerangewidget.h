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
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DateTimeRangeWidget
{
public:
    QLabel *label_starttime;
    QLabel *label_endtime;
    QLabel *label_text;

    void setupUi(QWidget *DateTimeRangeWidget)
    {
        if (DateTimeRangeWidget->objectName().isEmpty())
            DateTimeRangeWidget->setObjectName(QString::fromUtf8("DateTimeRangeWidget"));
        DateTimeRangeWidget->resize(480, 100);
        DateTimeRangeWidget->setStyleSheet(QString::fromUtf8("QWidget#DateTimeRangeWidget{\n"
"background-color : rgb(244, 244, 244);\n"
"}"));
        label_starttime = new QLabel(DateTimeRangeWidget);
        label_starttime->setObjectName(QString::fromUtf8("label_starttime"));
        label_starttime->setGeometry(QRect(10, 10, 81, 40));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_starttime->sizePolicy().hasHeightForWidth());
        label_starttime->setSizePolicy(sizePolicy);
        label_starttime->setMaximumSize(QSize(200, 16777215));
        label_starttime->setAlignment(Qt::AlignCenter);
        label_endtime = new QLabel(DateTimeRangeWidget);
        label_endtime->setObjectName(QString::fromUtf8("label_endtime"));
        label_endtime->setGeometry(QRect(10, 50, 81, 40));
        sizePolicy.setHeightForWidth(label_endtime->sizePolicy().hasHeightForWidth());
        label_endtime->setSizePolicy(sizePolicy);
        label_endtime->setMaximumSize(QSize(16777215, 16777215));
        label_endtime->setAlignment(Qt::AlignCenter);
        label_text = new QLabel(DateTimeRangeWidget);
        label_text->setObjectName(QString::fromUtf8("label_text"));
        label_text->setGeometry(QRect(120, 10, 341, 81));
        sizePolicy.setHeightForWidth(label_text->sizePolicy().hasHeightForWidth());
        label_text->setSizePolicy(sizePolicy);
        label_text->setStyleSheet(QString::fromUtf8("QLabel#label_text{\n"
"	background-color: white;\n"
"    border: 1px solid gray;\n"
"	border-radius:15px;\n"
"    font:25px; \n"
"    font-family: Segoe UI;\n"
"}\n"
""));
        label_text->setAlignment(Qt::AlignCenter);

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
