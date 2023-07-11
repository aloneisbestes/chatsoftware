/********************************************************************************
** Form generated from reading UI file 'mmlogindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MMLOGINDIALOG_H
#define UI_MMLOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mmaccountlogin.h"
#include "mmpushbutton.h"

QT_BEGIN_NAMESPACE

class Ui_MMLoginDialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QStackedWidget *stackedWidget;
    MMAccountLogin *wdg_account_login;
    QWidget *page_2;
    QWidget *wdg_top;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    MMPushButton *btn_close;

    void setupUi(QDialog *MMLoginDialog)
    {
        if (MMLoginDialog->objectName().isEmpty())
            MMLoginDialog->setObjectName(QString::fromUtf8("MMLoginDialog"));
        MMLoginDialog->resize(307, 382);
        verticalLayout = new QVBoxLayout(MMLoginDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(MMLoginDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setStyleSheet(QString::fromUtf8("QWidget#widget \n"
"{\n"
"	background-color: white;\n"
"	border-radius: 10px;\n"
"}"));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        stackedWidget = new QStackedWidget(widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        wdg_account_login = new MMAccountLogin();
        wdg_account_login->setObjectName(QString::fromUtf8("wdg_account_login"));
        stackedWidget->addWidget(wdg_account_login);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        stackedWidget->addWidget(page_2);

        verticalLayout_3->addWidget(stackedWidget);


        gridLayout->addLayout(verticalLayout_3, 2, 0, 1, 1);

        wdg_top = new QWidget(widget);
        wdg_top->setObjectName(QString::fromUtf8("wdg_top"));
        wdg_top->setMinimumSize(QSize(0, 0));
        horizontalLayout_4 = new QHBoxLayout(wdg_top);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btn_close = new MMPushButton(wdg_top);
        btn_close->setObjectName(QString::fromUtf8("btn_close"));
        btn_close->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	border: none;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ Global/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_close->setIcon(icon);
        btn_close->setIconSize(QSize(16, 16));

        horizontalLayout->addWidget(btn_close);


        horizontalLayout_4->addLayout(horizontalLayout);


        gridLayout->addWidget(wdg_top, 1, 0, 1, 1);


        verticalLayout->addWidget(widget);


        retranslateUi(MMLoginDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MMLoginDialog);
    } // setupUi

    void retranslateUi(QDialog *MMLoginDialog)
    {
        MMLoginDialog->setWindowTitle(QCoreApplication::translate("MMLoginDialog", "Dialog", nullptr));
        btn_close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MMLoginDialog: public Ui_MMLoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MMLOGINDIALOG_H
