#include "mmaccountloginui.h"
#include "ui_mmaccountloginui.h"
#include "mmsystemglobal.h"
#include "mmcommon.h"
#include "mmdatafacotry.h"
#include <QDebug>
#include "mmmessagerelay.h"

// 系统图标
#define MM_SYSTEM_ICON_PATH             ":/Global/wechat_icon.png"
// 账号图标
#define MM_SYSTEM_ACCOUNT_ICON_PATH     ":/Login/login_account_icon.png"
// 密码图标
#define MM_SYSTEM_PASSWORD_ICON_PATH    ":/Login/login_password_icon.png"

MMAccountLoginUI::MMAccountLoginUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MMAccountLoginUI)
{
    ui->setupUi(this);

    initMMAccountLoginUI();

#if __APPLE__
    ui->account->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->password->setAttribute(Qt::WA_MacShowFocusRect, false);
#endif //__APPLE__
}

MMAccountLoginUI::~MMAccountLoginUI()
{
    delete ui;
}

void MMAccountLoginUI::slotAccountLogin()
{
    //auto loginData=MMDataFacotry::createReqMMLoingData();
    MMUserData userData;
    std::string tmpStr;
    // 获取用户名
    tmpStr=ui->account->text().toStdString();
    if (tmpStr.empty()) {
        qDebug() << "MMAccountLoginUI::slotAccountLogin account is not exist";
        return;
    }
    userData.m_account=tmpStr;

    // 获取密码
    tmpStr=ui->password->text().toStdString();
    if (tmpStr.empty()) {
        qDebug() << "MMAccountLoginUI::slotAccountLogin password is not exist";
        return;
    }
    userData.m_password=tmpStr;

    auto loginData=MMDataFacotry::createReqMMLoingData(userData);

    // 发送登录请求
    emit MMMessageRelay::instance()->signalClientNetworkReq(loginData);
    emit signalLoginSuccess();
}

void MMAccountLoginUI::initMMAccountLoginUI()
{
    initSubassembly();

    initFont();

    initEventHandle();
}

void MMAccountLoginUI::initSubassembly()
{
    double zoomWidth=MMSystemGlobal::instance()->m_dZoomWidth;
    double zoomHeight=MMSystemGlobal::instance()->m_dZoomHeight;

    QIcon icon;
    int tmpWidth=0, tmpHeight=0;
    int leftMargin=0, rightMargin=0, topMargin=0, bottomMargin=0;
    int spacing=0;

    Q_UNUSED(topMargin)
    Q_UNUSED(bottomMargin)

    // 初始化控件之间的距离
    spacing=20*zoomHeight;
    ui->verticalLayout->setSpacing(spacing);

    // 初始化头像
    tmpWidth=50*zoomWidth;
    ui->userAvatar->setFixedSize(QSize(tmpWidth, tmpWidth));
    icon=QIcon(MM_SYSTEM_ICON_PATH);
    ui->userAvatar->setPixmap(icon.pixmap(QSize(tmpWidth,tmpWidth)));

    // 设置用户名和密码输入框
    tmpWidth=280*zoomWidth;
    tmpHeight=45*zoomHeight;
    ui->widget->setFixedSize(QSize(tmpWidth,tmpHeight));
    ui->widget_2->setFixedSize(QSize(tmpWidth,tmpHeight));
    ui->btnLogin->setFixedSize(QSize(tmpWidth,tmpHeight));

    leftMargin=rightMargin=10*zoomWidth;
    ui->horizontalLayout_6->setContentsMargins(leftMargin, 0, rightMargin, 0);
    ui->horizontalLayout_7->setContentsMargins(leftMargin, 0, rightMargin, 0);

    spacing=9*zoomWidth;
    ui->horizontalLayout_6->setSpacing(spacing);
    ui->horizontalLayout_7->setSpacing(spacing);

    tmpWidth=24*zoomWidth;
    ui->accountIcon->setFixedSize(QSize(tmpWidth,tmpWidth));
    icon=QIcon(MM_SYSTEM_ACCOUNT_ICON_PATH);
    ui->accountIcon->setPixmap(icon.pixmap(QSize(tmpWidth,tmpWidth)));
    ui->passwdIcon->setFixedSize(QSize(tmpWidth,tmpWidth));
    icon=QIcon(MM_SYSTEM_PASSWORD_ICON_PATH);
    ui->passwdIcon->setPixmap(icon.pixmap(QSize(tmpWidth,tmpWidth)));
}

void MMAccountLoginUI::initFont()
{
    int fontSize=20;
    setMMFont(fontSize, ui->account);
    setMMFont(fontSize, ui->password);
    setMMFont(fontSize, ui->btnLogin);
}

void MMAccountLoginUI::initEventHandle()
{
    connect(ui->btnLogin, &QToolButton::clicked, this, &MMAccountLoginUI::slotAccountLogin);
}
