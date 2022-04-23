/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "menubutton.h"
#include "titlelabel.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *schedule;
    QWidget *widget_2;
    QToolButton *sche_setbtn;
    QToolButton *sche_addbtn;
    TitleLabel *label;
    QToolButton *pomodorobtn;
    QWidget *workflow;
    QWidget *widget_3;
    QToolButton *work_setbtn;
    QToolButton *work_addbtn;
    TitleLabel *label_2;
    QWidget *quadrant;
    QWidget *widget;
    TitleLabel *label_3;
    QWidget *datagram;
    QWidget *widget_4;
    TitleLabel *label_4;
    QWidget *set;
    QWidget *widget_5;
    TitleLabel *label_5;
    QWidget *menu;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    MenuButton *schedulebtn;
    MenuButton *workflowbtn;
    MenuButton *quadrantbtn;
    MenuButton *datagrambtn;
    MenuButton *setbtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(480, 800);
        MainWindow->setMinimumSize(QSize(480, 800));
        MainWindow->setMaximumSize(QSize(480, 800));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 481, 741));
        schedule = new QWidget();
        schedule->setObjectName(QString::fromUtf8("schedule"));
        widget_2 = new QWidget(schedule);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 481, 51));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 180, 255);\n"
""));
        sche_setbtn = new QToolButton(widget_2);
        sche_setbtn->setObjectName(QString::fromUtf8("sche_setbtn"));
        sche_setbtn->setGeometry(QRect(410, 0, 51, 51));
        sche_setbtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border-image: url(:/menu/res/titleset.png)\357\274\233\n"
"}\n"
""));
        sche_addbtn = new QToolButton(widget_2);
        sche_addbtn->setObjectName(QString::fromUtf8("sche_addbtn"));
        sche_addbtn->setGeometry(QRect(350, 0, 51, 51));
        sche_addbtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border-image: url(:/menu/res/add.png)\357\274\233\n"
"}\n"
""));
        label = new TitleLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 481, 51));
        label->setAlignment(Qt::AlignCenter);
        pomodorobtn = new QToolButton(widget_2);
        pomodorobtn->setObjectName(QString::fromUtf8("pomodorobtn"));
        pomodorobtn->setGeometry(QRect(20, 0, 51, 51));
        pomodorobtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border-image: url(:/menu/res/pomodoro.png)\357\274\233\n"
"}\n"
""));
        label->raise();
        sche_setbtn->raise();
        sche_addbtn->raise();
        pomodorobtn->raise();
        stackedWidget->addWidget(schedule);
        workflow = new QWidget();
        workflow->setObjectName(QString::fromUtf8("workflow"));
        widget_3 = new QWidget(workflow);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(0, 0, 481, 51));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 180, 255);\n"
""));
        work_setbtn = new QToolButton(widget_3);
        work_setbtn->setObjectName(QString::fromUtf8("work_setbtn"));
        work_setbtn->setGeometry(QRect(410, 0, 51, 51));
        work_setbtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border-image: url(:/menu/res/titleset.png)\357\274\233\n"
"}\n"
""));
        work_addbtn = new QToolButton(widget_3);
        work_addbtn->setObjectName(QString::fromUtf8("work_addbtn"));
        work_addbtn->setGeometry(QRect(350, 0, 51, 51));
        work_addbtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border-image: url(:/menu/res/add.png)\357\274\233\n"
"}\n"
""));
        label_2 = new TitleLabel(widget_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 0, 161, 51));
        label_2->setFrameShadow(QFrame::Plain);
        label_2->setTextFormat(Qt::AutoText);
        label_2->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(workflow);
        quadrant = new QWidget();
        quadrant->setObjectName(QString::fromUtf8("quadrant"));
        widget = new QWidget(quadrant);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 481, 51));
        widget->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 180, 255);\n"
""));
        label_3 = new TitleLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 0, 481, 51));
        label_3->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(quadrant);
        datagram = new QWidget();
        datagram->setObjectName(QString::fromUtf8("datagram"));
        widget_4 = new QWidget(datagram);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(0, 0, 481, 51));
        widget_4->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 180, 255);\n"
""));
        label_4 = new TitleLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 0, 481, 51));
        label_4->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(datagram);
        set = new QWidget();
        set->setObjectName(QString::fromUtf8("set"));
        widget_5 = new QWidget(set);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(0, 0, 481, 51));
        widget_5->setStyleSheet(QString::fromUtf8("background-color: rgb(42, 180, 255);\n"
""));
        label_5 = new TitleLabel(widget_5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 0, 481, 51));
        label_5->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(set);
        menu = new QWidget(centralwidget);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setGeometry(QRect(0, 740, 481, 61));
        horizontalLayoutWidget = new QWidget(menu);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 481, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        schedulebtn = new MenuButton(horizontalLayoutWidget);
        schedulebtn->setObjectName(QString::fromUtf8("schedulebtn"));
        schedulebtn->setMinimumSize(QSize(85, 45));
        schedulebtn->setMaximumSize(QSize(85, 45));
        schedulebtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border-image: url(:/menu/res/schedule.png);\n"
"}\n"
"QToolButton::checked{\n"
"	border-image: url(:/menu/res/schedule_press.png);\n"
"}"));
        schedulebtn->setIconSize(QSize(45, 45));

        horizontalLayout->addWidget(schedulebtn);

        workflowbtn = new MenuButton(horizontalLayoutWidget);
        workflowbtn->setObjectName(QString::fromUtf8("workflowbtn"));
        workflowbtn->setMinimumSize(QSize(85, 0));
        workflowbtn->setMaximumSize(QSize(85, 45));
        workflowbtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border-image: url(:/menu/res/workflow.png);\n"
"}\n"
"QToolButton::checked{\n"
"	border-image: url(:/menu/res/workflow_press.png);\n"
"}"));

        horizontalLayout->addWidget(workflowbtn);

        quadrantbtn = new MenuButton(horizontalLayoutWidget);
        quadrantbtn->setObjectName(QString::fromUtf8("quadrantbtn"));
        quadrantbtn->setMinimumSize(QSize(85, 0));
        quadrantbtn->setMaximumSize(QSize(85, 45));
        quadrantbtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border-image: url(:/menu/res/quadrant.png);\n"
"}\n"
"QToolButton::checked{\n"
"	border-image: url(:/menu/res/quadrant_press.png)\n"
"}"));

        horizontalLayout->addWidget(quadrantbtn);

        datagrambtn = new MenuButton(horizontalLayoutWidget);
        datagrambtn->setObjectName(QString::fromUtf8("datagrambtn"));
        datagrambtn->setMinimumSize(QSize(85, 0));
        datagrambtn->setMaximumSize(QSize(85, 45));
        datagrambtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border-image: url(:/menu/res/datagram.png);\n"
"}\n"
"QToolButton::checked{\n"
"	border-image: url(:/menu/res/datagram_press.png);\n"
"}"));

        horizontalLayout->addWidget(datagrambtn);

        setbtn = new MenuButton(horizontalLayoutWidget);
        setbtn->setObjectName(QString::fromUtf8("setbtn"));
        setbtn->setMinimumSize(QSize(85, 0));
        setbtn->setMaximumSize(QSize(85, 45));
        setbtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border-image: url(:/menu/res/set.png);\n"
"}\n"
"QToolButton::checked{\n"
"	border-image: url(:/menu/res/set_press.png);\n"
"}"));

        horizontalLayout->addWidget(setbtn);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        sche_setbtn->setText(QString());
        sche_addbtn->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\346\227\245\347\250\213", nullptr));
        pomodorobtn->setText(QString());
        work_setbtn->setText(QString());
        work_addbtn->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\345\267\245\344\275\234\346\265\201", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\351\207\215\350\246\201\347\264\247\346\200\245\345\233\233\350\261\241\351\231\220", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\346\212\245\350\241\250", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        schedulebtn->setText(QString());
        workflowbtn->setText(QString());
        quadrantbtn->setText(QString());
        datagrambtn->setText(QString());
        setbtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
