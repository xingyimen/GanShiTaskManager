/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QLabel *label;
    QWidget *widget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_pwd;
    QLineEdit *lineEdit_mail;
    QPushButton *pushButton;

    void setupUi(QWidget *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(480, 800);
        Register->setMinimumSize(QSize(480, 800));
        Register->setMaximumSize(QSize(480, 800));
        label = new QLabel(Register);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 50, 151, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setBold(false);
        font.setItalic(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel#label{\n"
"    font:40px; \n"
"    font-family: \345\271\274\345\234\206;\n"
"}\n"
""));
        widget = new QWidget(Register);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 480, 800));
        widget->setMinimumSize(QSize(480, 800));
        widget->setMaximumSize(QSize(480, 800));
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget{\n"
"background-color : rgb(244, 244, 244);\n"
"}"));
        verticalLayoutWidget = new QWidget(widget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(90, 140, 291, 221));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_username = new QLineEdit(verticalLayoutWidget);
        lineEdit_username->setObjectName(QString::fromUtf8("lineEdit_username"));
        lineEdit_username->setMinimumSize(QSize(0, 45));
        lineEdit_username->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border:1px solid rgb(244, 244, 244);\n"
"border-bottom-color: gray;\n"
"background-color:rgb(244, 244, 244);\n"
"font:15px; \n"
"font-family: Arial;\n"
"}\n"
""));

        verticalLayout->addWidget(lineEdit_username);

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

        lineEdit_mail = new QLineEdit(verticalLayoutWidget);
        lineEdit_mail->setObjectName(QString::fromUtf8("lineEdit_mail"));
        lineEdit_mail->setMinimumSize(QSize(0, 45));
        lineEdit_mail->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"border:1px solid rgb(244, 244, 244);\n"
"border-bottom-color: gray;\n"
"background-color:rgb(244, 244, 244);\n"
"font:15px; \n"
"font-family: Arial;\n"
"}\n"
""));

        verticalLayout->addWidget(lineEdit_mail);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 700, 131, 41));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
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
        widget->raise();
        label->raise();

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QWidget *Register)
    {
        Register->setWindowTitle(QApplication::translate("Register", "Form", nullptr));
        label->setText(QApplication::translate("Register", "\346\263\250\345\206\214", nullptr));
        pushButton->setText(QApplication::translate("Register", "\346\263\250\345\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
