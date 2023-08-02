#include "mmloginui.h"
#include "ui_mmloginui.h"
#include "mmcommon.h"
#include "mmsystemglobal.h"
#include <QMouseEvent>

static QString __qrcodeIcon=":/Global/QRcode_icon.png";
static QString __accountIcon=":/Global/account_icon.png";

MMLoginUI::MMLoginUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MMLoginUI)
{
    ui->setupUi(this);

    m_width=430;
    m_height=360;

    m_nowType=MMLoginUIType::LoginUIType_Account;
    ui->stackedWidget->setCurrentIndex(m_nowType);

    initMMLoginDialogUI();
}

MMLoginUI::~MMLoginUI()
{
    delete ui;
}

void MMLoginUI::mousePressEvent(QMouseEvent *event)
{
    // 鼠标点击
    if (event->button() == Qt::LeftButton)
    {
        m_buttonType=Qt::LeftButton;
        QRect titleRect=rect();
        //titleRect.setBottom(titleRect.top() + 48);
        if (titleRect.contains(event->pos()))
        {
            m_isMove=true;
            m_startPoint=event->globalPos();
            m_winTopLeftPoint=this->frameGeometry().topLeft();
        }
    }
}

void MMLoginUI::mouseMoveEvent(QMouseEvent *event)
{
    // 鼠标移动
    if (m_buttonType == Qt::LeftButton)
    {
        if (m_isMove)
        {
         // 如果是移动状态，计算出新的位置
         QPoint distance=event->globalPos() - m_startPoint;
         move(m_winTopLeftPoint + distance);
        }
    }
}

void MMLoginUI::mouseReleaseEvent(QMouseEvent *event)
{
    // 鼠标释放
    Q_UNUSED(event)
    if (m_buttonType == Qt::LeftButton) // 鼠标左键按下，并且鼠标当前要在按键上
    {
        m_isMove=false;
        m_buttonType=Qt::NoButton;
    }
}

void MMLoginUI::slotLoginUIChange()
{
    if (m_nowType == MMLoginUIType::LoginUIType_Account) {
        m_nowType=MMLoginUIType::LoginUIType_QRCode;
        ui->btnQRCode->setIcon(QIcon(__accountIcon));
    }
    else {
        m_nowType=MMLoginUIType::LoginUIType_Account;
        ui->btnQRCode->setIcon(QIcon(__qrcodeIcon));
    }
    ui->stackedWidget->setCurrentIndex(m_nowType);
}

void MMLoginUI::initMMLoginDialogUI()
{
    // 设置对话框无边框
    setWindowFlags(Qt::FramelessWindowHint);
    // 设置对话框背景透明
    setAttribute(Qt::WA_TranslucentBackground);
    // 设置背景阴影部分
    setWindowShadow(this, ui->widget);

    initSubassembly();

    initFont();

    initEventHandle();
}

void MMLoginUI::initSubassembly()
{
    double zoomWidth=MMSystemGlobal::instance()->m_dZoomWidth;
    double zoomHeight=MMSystemGlobal::instance()->m_dZoomHeight;
    int tmpWidth=0, tmpHeight=0;

    // 设置窗口大小
    tmpWidth=m_width*zoomWidth;
    tmpHeight=m_height*zoomHeight;
    this->setFixedSize(QSize(tmpWidth, tmpHeight));

    // 设置关闭按钮
    tmpWidth=20*zoomWidth;
    ui->btn_close->setIconSize(QSize(tmpWidth,tmpWidth));
    ui->btn_close->setIcon(QIcon(__close_icon_path[MM_PushButtonState::MMPushButtonState_Normal]));
    ui->btn_close->setBOriginal(false);
    ui->btn_close->setIconNormal(QIcon(__close_icon_path[MM_PushButtonState::MMPushButtonState_Normal]));
    ui->btn_close->setIconHover(QIcon(__close_icon_path[MM_PushButtonState::MMPushButtonState_Hover]));
    ui->btn_close->setIconPressed(QIcon(__close_icon_path[MM_PushButtonState::MMPushButtonState_Pressed]));

    int rightMargin=10*zoomWidth;
    ui->horizontalLayout_2->setContentsMargins(0,0,rightMargin,0);

    tmpWidth=24*zoomWidth;
    ui->btnQRCode->setFixedSize(QSize(tmpWidth,tmpWidth));

    // 初始化二维码
    tmpWidth=200*zoomWidth;
    QIcon icon=QIcon(":/Global/testQRImage.jpg");
    ui->qrcodeLabel->setFixedSize(QSize(tmpWidth,tmpWidth));
    ui->qrcodeLabel->setPixmap(icon.pixmap(QSize(tmpWidth,tmpWidth)));
}

void MMLoginUI::initFont()
{
    int fontSize=15;
    setMMFont(fontSize, ui->btnRegister);
}

void MMLoginUI::initEventHandle()
{
    connect(ui->btn_close, &QPushButton::clicked, this, &MMLoginUI::signalLogout);
    connect(ui->btnQRCode, &QToolButton::clicked, this, &MMLoginUI::slotLoginUIChange);
}
