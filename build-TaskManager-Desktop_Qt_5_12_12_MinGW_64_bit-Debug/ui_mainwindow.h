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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *schedule;
    QLabel *label;
    QToolButton *pomodorobtn;
    QToolButton *sche_addbtn;
    QToolButton *sche_setbtn;
    QScrollArea *ScheScrollArea;
    QWidget *ScheScrollAreaWidgetContents;
    QWidget *workflow;
    QLabel *label_2;
    QToolButton *work_addbtn;
    QToolButton *work_setbtn;
    QGraphicsView *WorkgraphicsView;
    QWidget *quadrant;
    QLabel *importance;
    QLabel *gridding;
    QLabel *urgency;
    QLabel *aday;
    QLabel *deadline;
    QLabel *label_3;
    QWidget *datagram;
    QLabel *label_4;
    QWidget *set;
    QPushButton *accountinfo;
    QPushButton *synchronize;
    QPushButton *reset;
    QPushButton *individuation;
    QPushButton *exit;
    QLabel *label_5;
    QWidget *menu;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QToolButton *schedulebtn;
    QToolButton *workflowbtn;
    QToolButton *quadrantbtn;
    QToolButton *datagrambtn;
    QToolButton *setbtn;

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
        label = new QLabel(schedule);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 481, 51));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(42, 180, 255);\n"
"    font:25px; \n"
"    font-family: \345\271\274\345\234\206;\n"
"    font-weight:bold;\n"
"    color:white;\n"
" \n"
"}\n"
""));
        label->setAlignment(Qt::AlignCenter);
        pomodorobtn = new QToolButton(schedule);
        pomodorobtn->setObjectName(QString::fromUtf8("pomodorobtn"));
        pomodorobtn->setGeometry(QRect(20, 0, 51, 51));
        pomodorobtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border-image: url(:/menu/res/pomodoro.png)\357\274\233\n"
"}\n"
""));
        sche_addbtn = new QToolButton(schedule);
        sche_addbtn->setObjectName(QString::fromUtf8("sche_addbtn"));
        sche_addbtn->setGeometry(QRect(340, 0, 51, 51));
        sche_addbtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border-image: url(:/menu/res/add.png)\357\274\233\n"
"}\n"
""));
        sche_setbtn = new QToolButton(schedule);
        sche_setbtn->setObjectName(QString::fromUtf8("sche_setbtn"));
        sche_setbtn->setGeometry(QRect(400, 0, 51, 51));
        sche_setbtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border-image: url(:/menu/res/titleset.png)\357\274\233\n"
"}\n"
""));
        ScheScrollArea = new QScrollArea(schedule);
        ScheScrollArea->setObjectName(QString::fromUtf8("ScheScrollArea"));
        ScheScrollArea->setGeometry(QRect(0, 50, 481, 691));
        ScheScrollArea->setWidgetResizable(true);
        ScheScrollAreaWidgetContents = new QWidget();
        ScheScrollAreaWidgetContents->setObjectName(QString::fromUtf8("ScheScrollAreaWidgetContents"));
        ScheScrollAreaWidgetContents->setGeometry(QRect(0, 0, 479, 689));
        ScheScrollArea->setWidget(ScheScrollAreaWidgetContents);
        stackedWidget->addWidget(schedule);
        workflow = new QWidget();
        workflow->setObjectName(QString::fromUtf8("workflow"));
        label_2 = new QLabel(workflow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 481, 51));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(42, 180, 255);\n"
"    font:25px; \n"
"    font-family: \345\271\274\345\234\206;\n"
"    font-weight:bold;\n"
"    color:white;\n"
" \n"
"}\n"
""));
        label_2->setFrameShadow(QFrame::Plain);
        label_2->setTextFormat(Qt::AutoText);
        label_2->setAlignment(Qt::AlignCenter);
        work_addbtn = new QToolButton(workflow);
        work_addbtn->setObjectName(QString::fromUtf8("work_addbtn"));
        work_addbtn->setGeometry(QRect(340, 0, 51, 51));
        work_addbtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border-image: url(:/menu/res/add.png)\357\274\233\n"
"}\n"
""));
        work_setbtn = new QToolButton(workflow);
        work_setbtn->setObjectName(QString::fromUtf8("work_setbtn"));
        work_setbtn->setGeometry(QRect(400, 0, 51, 51));
        work_setbtn->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"	border-image: url(:/menu/res/titleset.png)\357\274\233\n"
"}\n"
""));
        WorkgraphicsView = new QGraphicsView(workflow);
        WorkgraphicsView->setObjectName(QString::fromUtf8("WorkgraphicsView"));
        WorkgraphicsView->setGeometry(QRect(0, 50, 480, 690));
        WorkgraphicsView->setMinimumSize(QSize(480, 690));
        WorkgraphicsView->setMaximumSize(QSize(480, 690));
        WorkgraphicsView->setStyleSheet(QString::fromUtf8("QGraphicsView{\n"
"border:0px solid white;\n"
"background-color : rgb(244, 244, 244);\n"
"}"));
        WorkgraphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        WorkgraphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        WorkgraphicsView->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        WorkgraphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
        stackedWidget->addWidget(workflow);
        quadrant = new QWidget();
        quadrant->setObjectName(QString::fromUtf8("quadrant"));
        importance = new QLabel(quadrant);
        importance->setObjectName(QString::fromUtf8("importance"));
        importance->setGeometry(QRect(240, 150, 53, 16));
        importance->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font:15px; \n"
"    font-family: Segoe UI;\n"
"}\n"
" "));
        gridding = new QLabel(quadrant);
        gridding->setObjectName(QString::fromUtf8("gridding"));
        gridding->setGeometry(QRect(10, 150, 450, 450));
        gridding->setMinimumSize(QSize(450, 450));
        gridding->setMaximumSize(QSize(450, 450));
        gridding->setStyleSheet(QString::fromUtf8("QLabel#gridding{\n"
"border-image: url(:/menu/res/gridding.png);\n"
"}"));
        urgency = new QLabel(quadrant);
        urgency->setObjectName(QString::fromUtf8("urgency"));
        urgency->setGeometry(QRect(440, 350, 61, 21));
        urgency->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font:15px; \n"
"    font-family: Segoe UI;\n"
"}\n"
" "));
        aday = new QLabel(quadrant);
        aday->setObjectName(QString::fromUtf8("aday"));
        aday->setGeometry(QRect(360, 590, 31, 20));
        aday->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font:15px; \n"
"    font-family: Segoe UI;\n"
"    color:rgb(245,192,151);\n"
"}\n"
" "));
        deadline = new QLabel(quadrant);
        deadline->setObjectName(QString::fromUtf8("deadline"));
        deadline->setGeometry(QRect(410, 590, 61, 20));
        deadline->setStyleSheet(QString::fromUtf8("QLabel{\n"
"    font:15px; \n"
"    font-family: Segoe UI;\n"
"    color:rgb(248,89,89);\n"
"}\n"
" "));
        label_3 = new QLabel(quadrant);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 0, 481, 51));
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(42, 180, 255);\n"
"    font:25px; \n"
"    font-family: \345\271\274\345\234\206;\n"
"    font-weight:bold;\n"
"    color:white;\n"
" \n"
"}\n"
""));
        label_3->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(quadrant);
        gridding->raise();
        importance->raise();
        urgency->raise();
        aday->raise();
        deadline->raise();
        label_3->raise();
        datagram = new QWidget();
        datagram->setObjectName(QString::fromUtf8("datagram"));
        label_4 = new QLabel(datagram);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 0, 481, 51));
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
        stackedWidget->addWidget(datagram);
        set = new QWidget();
        set->setObjectName(QString::fromUtf8("set"));
        accountinfo = new QPushButton(set);
        accountinfo->setObjectName(QString::fromUtf8("accountinfo"));
        accountinfo->setGeometry(QRect(50, 80, 381, 101));
        accountinfo->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: white;\n"
"	border: 1px solid gray;\n"
"	border-radius:30px;\n"
"    font:25px; \n"
"    font-family: Segoe UI;\n"
"    text-align : left;\n"
"}\n"
"QPushButton:hover{\n"
"background-color: rgb(181, 225, 250);\n"
"}\n"
""));
        synchronize = new QPushButton(set);
        synchronize->setObjectName(QString::fromUtf8("synchronize"));
        synchronize->setGeometry(QRect(50, 200, 381, 101));
        synchronize->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: white;\n"
"	border: 1px solid gray;\n"
"	border-radius:30px;\n"
"    font:25px; \n"
"    font-family: Segoe UI;\n"
"    text-align : left;\n"
"}\n"
"QPushButton:hover{\n"
"background-color: rgb(181, 225, 250);\n"
"}\n"
""));
        reset = new QPushButton(set);
        reset->setObjectName(QString::fromUtf8("reset"));
        reset->setGeometry(QRect(50, 320, 381, 101));
        reset->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: white;\n"
"	border: 1px solid gray;\n"
"	border-radius:30px;\n"
"    font:25px; \n"
"    font-family: Segoe UI;\n"
"    text-align : left;\n"
"}\n"
"QPushButton:hover{\n"
"background-color: rgb(181, 225, 250);\n"
"}\n"
""));
        individuation = new QPushButton(set);
        individuation->setObjectName(QString::fromUtf8("individuation"));
        individuation->setGeometry(QRect(50, 440, 381, 101));
        individuation->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: white;\n"
"	border: 1px solid gray;\n"
"	border-radius:30px;\n"
"    font:25px; \n"
"    font-family: Segoe UI;\n"
"    text-align : left;\n"
"}\n"
"QPushButton:hover{\n"
"background-color: rgb(181, 225, 250);\n"
"}\n"
""));
        exit = new QPushButton(set);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(50, 560, 381, 101));
        exit->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: white;\n"
"	border: 1px solid gray;\n"
"	border-radius:30px;\n"
"    font:25px; \n"
"    font-family: Segoe UI;\n"
"    text-align : left;\n"
"}\n"
"QPushButton:hover{\n"
"background-color: rgb(181, 225, 250);\n"
"}\n"
""));
        label_5 = new QLabel(set);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(0, 0, 481, 51));
        label_5->setStyleSheet(QString::fromUtf8("QLabel{\n"
"	background-color: rgb(42, 180, 255);\n"
"    font:25px; \n"
"    font-family: \345\271\274\345\234\206;\n"
"    font-weight:bold;\n"
"    color:white;\n"
" \n"
"}\n"
""));
        label_5->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(set);
        menu = new QWidget(centralwidget);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setGeometry(QRect(0, 740, 481, 61));
        menu->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background-color :white\357\274\233\n"
"}"));
        horizontalLayoutWidget = new QWidget(menu);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 481, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        schedulebtn = new QToolButton(horizontalLayoutWidget);
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

        workflowbtn = new QToolButton(horizontalLayoutWidget);
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

        quadrantbtn = new QToolButton(horizontalLayoutWidget);
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

        datagrambtn = new QToolButton(horizontalLayoutWidget);
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

        setbtn = new QToolButton(horizontalLayoutWidget);
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

        stackedWidget->setCurrentIndex(1);
        accountinfo->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QApplication::translate("MainWindow", "\346\227\245\347\250\213", nullptr));
        pomodorobtn->setText(QString());
        sche_addbtn->setText(QString());
        sche_setbtn->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\345\267\245\344\275\234\346\265\201", nullptr));
        work_addbtn->setText(QString());
        work_setbtn->setText(QString());
        importance->setText(QApplication::translate("MainWindow", "\351\207\215\350\246\201", nullptr));
        gridding->setText(QString());
        urgency->setText(QApplication::translate("MainWindow", "\347\264\247\346\200\245", nullptr));
        aday->setText(QApplication::translate("MainWindow", "24h", nullptr));
        deadline->setText(QApplication::translate("MainWindow", "Deadline", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\351\207\215\350\246\201\347\264\247\346\200\245\345\233\233\350\261\241\351\231\220", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\346\225\260\346\215\256\346\212\245\350\241\250", nullptr));
        accountinfo->setText(QApplication::translate("MainWindow", "       \350\264\246\345\217\267", nullptr));
        synchronize->setText(QApplication::translate("MainWindow", "       \345\220\214\346\255\245\346\225\260\346\215\256", nullptr));
        reset->setText(QApplication::translate("MainWindow", "       \351\207\215\347\275\256", nullptr));
        individuation->setText(QApplication::translate("MainWindow", "       \344\270\252\346\200\247\345\214\226\350\256\276\347\275\256", nullptr));
        exit->setText(QApplication::translate("MainWindow", "       \351\200\200\345\207\272", nullptr));
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
