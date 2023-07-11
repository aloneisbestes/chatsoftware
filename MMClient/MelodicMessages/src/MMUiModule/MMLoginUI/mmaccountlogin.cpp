#include "mmaccountlogin.h"
#include "ui_mmaccountlogin.h"
#include "mmsystemglobal.h"

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
}

MMAccountLogin::~MMAccountLogin()
{
    delete ui;
}

void MMAccountLogin::initMMAccountLoginUI()
{
    initSubassembly();

    initFont();

    initEventHandle();
}

void MMAccountLogin::initSubassembly()
{
    int tmpWidth=0;
    int tmpHeight=0;
    double zoomHeight=MMSystemGlobal::instance()->m_dZoomHeight;
    double zoomWidth=MMSystemGlobal::instance()->m_dZoomWidth;
    /************* 设置图标 *************/
    tmpHeight=70*zoomHeight;
    ui->widget->setFixedHeight(tmpHeight);
    // 设置图标大小
    m_iconSize=60*zoomWidth;
    ui->label_mm_icon->setFixedSize(QSize(m_iconSize, m_iconSize));
    // 设置图标
    QIcon icon(MM_SYSTEM_ICON_PATH);
    ui->label_mm_icon->setPixmap(icon.pixmap(m_iconSize,m_iconSize));

    // 设置用户名
    m_iconSize=24*zoomWidth;
    ui->label_account_icon->setFixedSize(QSize(m_iconSize,m_iconSize));
    icon = QIcon(MM_SYSTEM_ACCOUNT_ICON_PATH);
    ui->label_account_icon->setPixmap(icon.pixmap(m_iconSize, m_iconSize));

    // 设置密码
    ui->label_password_icon->setFixedSize(QSize(m_iconSize,m_iconSize));
    icon = QIcon(MM_SYSTEM_PASSWORD_ICON_PATH);
    ui->label_password_icon->setPixmap(icon.pixmap(m_iconSize, m_iconSize));
}

void MMAccountLogin::initFont()
{

}

void MMAccountLogin::initEventHandle()
{

}
