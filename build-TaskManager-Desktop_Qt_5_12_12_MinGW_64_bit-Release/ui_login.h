/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLabel *label_3;
    QWidget *widget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_name;
    QLineEdit *lineEdit_pwd;
    QLabel *label;
    QPushButton *pushButton_login;
    QPushButton *pushButton_register;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(480, 800);
        label_3 = new QLabel(login);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 60, 131, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setBold(false);
        font.setItalic(false);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("QLabel#label_3{\n"
"    font:40px; \n"
"    font-family: \345\271\274\345\234\206;\n"
"}\n"
""));
        widget = new QWidget(login);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 480, 800));
        widget->setMinimumSize(QSize(480, 800));
        widget->setMaximumSize(QSize(480, 800));
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget{\n"
"background-color : rgb(244, 244, 244);\n"
"}"));
        verticalLayoutWidget = new QWidget(widget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(90, 150, 301, 171));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_name = new QLineEdit(verticalLayoutWidget);
        lineEdit_name->setObjectName(QString::fromUtf8("lineEdit_name"));
        lineEdit_name->setMinimumSize(QSize(0, 45));
        lineEdit_name->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border:1px solid rgb(244, 244, 244);\n"
"border-bottom-color: gray;\n"
"background-color:rgb(244, 244, 244);\n"
"font:15px; \n"
"font-family: Arial;\n"
"}\n"
""));

        verticalLayout->addWidget(lineEdit_name);

        lineEdit_pwd = new QLineEdit(verticalLayoutWidget);
        lineEdit_pwd->setObjectName(QString::fromUtf8("lineEdit_pwd"));
        lineEdit_pwd->setMinimumSize(QSize(0, 45));
        lineEdit_pwd->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border:1px solid rgb(244, 244, 244);\n"
"border-bottom-color: gray;\n"
"background-color:rgb(244, 244, 244);\n"
"font:15px; \n"
"font-family: Arial;\n"
"}\n"
""));

        verticalLayout->addWidget(lineEdit_pwd);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 400, 329, 21));
        label->setMinimumSize(QSize(25, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setBold(false);
        font1.setItalic(false);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("QLabel#label{\n"
"    font:15px; \n"
"    font-family: Arial;\n"
"    color:gray;\n"
"}\n"
""));
        pushButton_login = new QPushButton(widget);
        pushButton_login->setObjectName(QString::fromUtf8("pushButton_login"));
        pushButton_login->setGeometry(QRect(160, 340, 160, 35));
        pushButton_login->setMinimumSize(QSize(160, 35));
        pushButton_login->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"border-radius:15px;\n"
"border-color:rgb(42, 180, 255);\n"
"background-color:rgb(42, 180, 255);\n"
"color:white;\n"
"font:20px; \n"
"font-family: \345\271\274\345\234\206;\n"
"}\n"
"QPushButton:hover{\n"
"background-color: rgb(181, 225, 250);\n"
"}"));
        pushButton_register = new QPushButton(widget);
        pushButton_register->setObjectName(QString::fromUtf8("pushButton_register"));
        pushButton_register->setGeometry(QRect(240, 400, 41, 21));
        pushButton_register->setMinimumSize(QSize(0, 21));
        pushButton_register->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_register{\n"
"border: rgb(244, 244, 244);\n"
"color: rgb(42, 180, 255);\n"
"font:15px; \n"
"font-family: Arial;\n"
"}\n"
"QPushButton#pushButton_register:hover{\n"
"color: rgb(181, 225, 250);\n"
"}"));
        widget->raise();
        label_3->raise();

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Form", nullptr));
        label_3->setText(QApplication::translate("login", "\347\231\273\345\275\225", nullptr));
        label->setText(QApplication::translate("login", "\346\262\241\346\234\211\350\264\246\345\217\267\357\274\237\346\235\245          \344\270\200\344\270\252\345\220\247\357\274\201", nullptr));
        pushButton_login->setText(QApplication::translate("login", "\347\231\273\345\275\225", nullptr));
        pushButton_register->setText(QApplication::translate("login", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
