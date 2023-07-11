/********************************************************************************
** Form generated from reading UI file 'mmaccountlogin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MMACCOUNTLOGIN_H
#define UI_MMACCOUNTLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MMAccountLogin
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_7;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_mm_icon;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_account_icon;
    QLineEdit *edit_account;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_password_icon;
    QLineEdit *edit_password;
    QWidget *widget_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btn_login;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget_3;

    void setupUi(QWidget *MMAccountLogin)
    {
        if (MMAccountLogin->objectName().isEmpty())
            MMAccountLogin->setObjectName(QString::fromUtf8("MMAccountLogin"));
        MMAccountLogin->resize(256, 326);
        MMAccountLogin->setStyleSheet(QString::fromUtf8("QWidget#MMAccountLogin\n"
"{\n"
"	background-color: #F2F5FC;\n"
"}"));
        gridLayout = new QGridLayout(MMAccountLogin);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(-1, -1, -1, 0);
        widget = new QWidget(MMAccountLogin);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_mm_icon = new QLabel(widget);
        label_mm_icon->setObjectName(QString::fromUtf8("label_mm_icon"));

        horizontalLayout->addWidget(label_mm_icon);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_7->addWidget(widget);

        widget_2 = new QWidget(MMAccountLogin);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_4 = new QWidget(widget_2);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setStyleSheet(QString::fromUtf8("QWidget#widget_4\n"
"{\n"
"	background-color: #FFFFFF;\n"
"	border-radius: 8px;\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(widget_4);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_account_icon = new QLabel(widget_4);
        label_account_icon->setObjectName(QString::fromUtf8("label_account_icon"));

        horizontalLayout_4->addWidget(label_account_icon);

        edit_account = new QLineEdit(widget_4);
        edit_account->setObjectName(QString::fromUtf8("edit_account"));
        edit_account->setStyleSheet(QString::fromUtf8("QLineEdit#edit_account\n"
"{\n"
"	border: none;\n"
"}"));

        horizontalLayout_4->addWidget(edit_account);


        verticalLayout_5->addLayout(horizontalLayout_4);


        verticalLayout_2->addWidget(widget_4);

        widget_6 = new QWidget(widget_2);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setStyleSheet(QString::fromUtf8("QWidget#widget_6\n"
"{\n"
"	background-color: #FFFFFF;\n"
"	border-radius: 8px;\n"
"}"));
        verticalLayout_6 = new QVBoxLayout(widget_6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_password_icon = new QLabel(widget_6);
        label_password_icon->setObjectName(QString::fromUtf8("label_password_icon"));

        horizontalLayout_3->addWidget(label_password_icon);

        edit_password = new QLineEdit(widget_6);
        edit_password->setObjectName(QString::fromUtf8("edit_password"));
        edit_password->setStyleSheet(QString::fromUtf8("QLineEdit#edit_password\n"
"{\n"
"	border: none;\n"
"}"));
        edit_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(edit_password);


        verticalLayout_6->addLayout(horizontalLayout_3);


        verticalLayout_2->addWidget(widget_6);

        widget_5 = new QWidget(widget_2);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        verticalLayout_4 = new QVBoxLayout(widget_5);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btn_login = new QPushButton(widget_5);
        btn_login->setObjectName(QString::fromUtf8("btn_login"));
        btn_login->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"	color: #FFFFFF;\n"
"	background-color: #4FE8FF;\n"
"	border-radius: 8px;\n"
"}\n"
"\n"
"QPushButton::hover\n"
"{\n"
"	background-color: #96EFFF;\n"
"}\n"
"\n"
"QPushButton::pressed\n"
"{\n"
"	background-color: #949698;\n"
"}"));

        horizontalLayout_2->addWidget(btn_login);


        verticalLayout_4->addLayout(horizontalLayout_2);


        verticalLayout_2->addWidget(widget_5);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        widget_3 = new QWidget(widget_2);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));

        horizontalLayout_5->addWidget(widget_3);


        verticalLayout_3->addLayout(horizontalLayout_5);

        verticalLayout_3->setStretch(0, 3);
        verticalLayout_3->setStretch(1, 1);

        verticalLayout_7->addWidget(widget_2);


        gridLayout->addLayout(verticalLayout_7, 0, 0, 1, 1);


        retranslateUi(MMAccountLogin);

        QMetaObject::connectSlotsByName(MMAccountLogin);
    } // setupUi

    void retranslateUi(QWidget *MMAccountLogin)
    {
        MMAccountLogin->setWindowTitle(QCoreApplication::translate("MMAccountLogin", "Form", nullptr));
        label_mm_icon->setText(QString());
        label_account_icon->setText(QString());
        label_password_icon->setText(QString());
        btn_login->setText(QCoreApplication::translate("MMAccountLogin", "\347\231\273  \345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MMAccountLogin: public Ui_MMAccountLogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MMACCOUNTLOGIN_H
