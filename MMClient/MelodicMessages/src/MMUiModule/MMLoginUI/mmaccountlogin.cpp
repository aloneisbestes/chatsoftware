#include "mmaccountlogin.h"
#include "ui_mmaccountlogin.h"
#include "mmsystemglobal.h"
#include <QDebug>

// 系统图标
#define MM_SYSTEM_ICON_PATH             ":/Global/wechat_icon.png"
// 账号图标
#define MM_SYSTEM_ACCOUNT_ICON_PATH     ":/Login/login_account_icon.png"
// 密码图标
#define MM_SYSTEM_PASSWORD_ICON_PATH    ":/Login/login_password_icon.png"

MMAccountLogin::MMAccountLogin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MMAccountLogin)
{
    ui->setupUi(this);

    initMMAccountLoginUI();

    initEventHandle();
}

MMAccountLogin::~MMAccountLogin()
{
    delete ui;
}

void MMAccountLogin::slotHandlerLogin()
{
    // 获取用户名
    QString account=ui->edit_account->text();
    if (account.isEmpty()) {
        qDebug() << "用户名不能为空";
        return ;
    }

    // 获取密码
    QString passwd=ui->edit_password->text();
    if (passwd.isEmpty()) {
        qDebug() << "密码不能为空";
        return ;
    }

    emit signalHandlerLogin(account, passwd);
}

void MMAccountLogin::initMMAccountLoginUI()
{
    initSubassembly();

    initFont();
}

void MMAccountLogin::initSubassembly()
{
    // int tmpWidth=0;
    int tmpHeight=0;
    double zoomHeight=MMSystemGlobal::instance()->m_dZoomHeight;
    double zoomWidth=MMSystemGlobal::instance()->m_dZoomWidth;
    int leftMargin=0, rightMargin=0, topMargin=0, bottomMargin=0;
    int margin=0;

    margin=10*zoomHeight;
    ui->verticalLayout_7->setSpacing(margin);
    /************* 设置图标 *************/
    tmpHeight=60*zoomHeight;
    ui->widget->setFixedHeight(tmpHeight);
    // 设置图标大小
    m_iconSize=60*zoomHeight;
    ui->label_mm_icon->setFixedSize(QSize(m_iconSize, m_iconSize));
    // 设置图标
    QIcon icon(MM_SYSTEM_ICON_PATH);
    ui->label_mm_icon->setPixmap(icon.pixmap(m_iconSize,m_iconSize));

    // 设置用户名
    m_iconSize=24*zoomHeight;
    ui->label_account_icon->setFixedSize(QSize(m_iconSize,m_iconSize));
    icon = QIcon(MM_SYSTEM_ACCOUNT_ICON_PATH);
    ui->label_account_icon->setPixmap(icon.pixmap(m_iconSize, m_iconSize));

    // 设置密码
    ui->label_password_icon->setFixedSize(QSize(m_iconSize,m_iconSize));
    icon = QIcon(MM_SYSTEM_PASSWORD_ICON_PATH);
    ui->label_password_icon->setPixmap(icon.pixmap(m_iconSize, m_iconSize));

    /************* 登录输入和按钮 *************/
    // 设置内边距
    leftMargin=rightMargin=10*zoomHeight;
    topMargin=bottomMargin=10*zoomHeight;
    ui->verticalLayout_2->setContentsMargins(leftMargin, topMargin, rightMargin, bottomMargin);

    // 设置高度
    tmpHeight=50*zoomHeight;
    ui->widget_4->setFixedHeight(tmpHeight);
    ui->widget_6->setFixedHeight(tmpHeight);
    ui->btn_login->setFixedHeight(tmpHeight);

    // 设置用户名和密码内边距和控件距离
    leftMargin=rightMargin=15*zoomWidth;
    ui->horizontalLayout_3->setContentsMargins(leftMargin,0,rightMargin,0);
    ui->horizontalLayout_4->setContentsMargins(leftMargin,0,rightMargin,0);
    margin=8*zoomHeight;
    ui->horizontalLayout_3->setSpacing(margin);
    ui->horizontalLayout_4->setSpacing(margin);

    // 设置用户名密码登录按钮之间的边距
    margin=20*zoomHeight;
    ui->verticalLayout_2->setSpacing(margin);
}

void MMAccountLogin::initFont()
{
    double zoomWidth=MMSystemGlobal::instance()->m_dZoomWidth;
    QFont tmpFont;
    tmpFont.setFamily("冬青黑体");
    int fontSize;

    // 设置用户名密码框
    fontSize=18*zoomWidth;
    tmpFont.setPixelSize(fontSize);
    ui->edit_account->setFont(tmpFont);
    ui->edit_password->setFont(tmpFont);

    // 设置登录按钮字体
    fontSize=20*zoomWidth;
    tmpFont.setPixelSize(fontSize);
    ui->btn_login->setFont(tmpFont);
}

void MMAccountLogin::initEventHandle()
{
    connect(ui->btn_login, &QPushButton::clicked, this, &MMAccountLogin::slotHandlerLogin);
}
