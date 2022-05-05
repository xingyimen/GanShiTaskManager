/********************************************************************************
** Form generated from reading UI file 'workorrelax_sde.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKORRELAX_SDE_H
#define UI_WORKORRELAX_SDE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_workOrrelax_sde
{
public:
    QLabel *label;
    QLCDNumber *lcdNumber;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_pause;
    QPushButton *pushButton_stop;
    QLabel *label_pp;
    QWidget *widget;

    void setupUi(QWidget *workOrrelax_sde)
    {
        if (workOrrelax_sde->objectName().isEmpty())
            workOrrelax_sde->setObjectName(QString::fromUtf8("workOrrelax_sde"));
        workOrrelax_sde->resize(480, 800);
        workOrrelax_sde->setMinimumSize(QSize(480, 800));
        workOrrelax_sde->setMaximumSize(QSize(480, 800));
        label = new QLabel(workOrrelax_sde);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 40, 301, 41));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAutoFillBackground(false);
        lcdNumber = new QLCDNumber(workOrrelax_sde);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(130, 290, 211, 91));
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setSegmentStyle(QLCDNumber::Filled);
        gridLayoutWidget = new QWidget(workOrrelax_sde);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(80, 580, 311, 31));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_pause = new QPushButton(gridLayoutWidget);
        pushButton_pause->setObjectName(QString::fromUtf8("pushButton_pause"));

        gridLayout->addWidget(pushButton_pause, 0, 0, 1, 1);

        pushButton_stop = new QPushButton(gridLayoutWidget);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));

        gridLayout->addWidget(pushButton_stop, 0, 1, 1, 1);

        label_pp = new QLabel(workOrrelax_sde);
        label_pp->setObjectName(QString::fromUtf8("label_pp"));
        label_pp->setGeometry(QRect(120, 240, 231, 41));
        QFont font1;
        font1.setPointSize(12);
        label_pp->setFont(font1);
        widget = new QWidget(workOrrelax_sde);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 480, 800));
        widget->raise();
        label->raise();
        lcdNumber->raise();
        gridLayoutWidget->raise();
        label_pp->raise();

        retranslateUi(workOrrelax_sde);

        QMetaObject::connectSlotsByName(workOrrelax_sde);
    } // setupUi

    void retranslateUi(QWidget *workOrrelax_sde)
    {
        workOrrelax_sde->setWindowTitle(QApplication::translate("workOrrelax_sde", "Form", nullptr));
        label->setText(QApplication::translate("workOrrelax_sde", "TextLabel", nullptr));
        pushButton_pause->setText(QApplication::translate("workOrrelax_sde", "\346\232\202\345\201\234", nullptr));
        pushButton_stop->setText(QApplication::translate("workOrrelax_sde", "\345\201\234\346\255\242", nullptr));
        label_pp->setText(QApplication::translate("workOrrelax_sde", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class workOrrelax_sde: public Ui_workOrrelax_sde {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKORRELAX_SDE_H
