#include "mmlogindialog.h"
#include "ui_mmlogindialog.h"
#include "mmcommon.h"
#include "mmsystemglobal.h"
#include <QMouseEvent>
#include <QDebug>

MMLoginDialog::MMLoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MMLoginDialog)
{
    ui->setupUi(this);

    // 设置对话框无边框
    setWindowFlags(Qt::FramelessWindowHint);
    // 设置对话框背景透明
    setAttribute(Qt::WA_TranslucentBackground);
    // 设置背景阴影部分
    setWindowShadow(this, ui->widget);

#ifdef __APPLE__
    initInputEdit();
#endif // __APPLE__

    // 初始化界面
    initMMLoginDialogUI();

    // 初始化事件，信号与槽
    initEventHandle();

    // 给自己安装事件监听器
    installEventFilter(this);
}

MMLoginDialog::~MMLoginDialog()
{
    delete ui;
}

void MMLoginDialog::slotHandlerLogin(QString account, QString passwd)
{
    qDebug() << "登录处理";
}

void MMLoginDialog::initMMLoginDialogUI()
{
    // 初始化组件
    initSubassembly();

    // 初始化字体
    initFont();
}

void MMLoginDialog::initSubassembly()
{
    int width, height;
    int rightMargin;
    int topMargin;
    double zoomWidth=MMSystemGlobal::instance()->m_dZoomWidth;
    double zoomHeight=MMSystemGlobal::instance()->m_dZoomHeight;

    Q_UNUSED(zoomHeight);
    /************* 设置窗口本身大小 *************/
    width=310*zoomHeight;
    height=380*zoomHeight;
    this->setFixedSize(QSize(width, height));

    // 关闭按钮
    width=18*zoomWidth;
     ui->btn_close->setIcon(QIcon(__close_icon_path[MM_PushButtonState::MMPushButtonState_Normal]));
    ui->btn_close->setBOriginal(false);
    ui->btn_close->setIconSize(QSize(width,width));
    ui->btn_close->setIconNormal(QIcon(__close_icon_path[MM_PushButtonState::MMPushButtonState_Normal]));
    ui->btn_close->setIconHover(QIcon(__close_icon_path[MM_PushButtonState::MMPushButtonState_Hover]));
    ui->btn_close->setIconPressed(QIcon(__close_icon_path[MM_PushButtonState::MMPushButtonState_Pressed]));

    // 设置关闭按钮中布局的内边距
    rightMargin=10*zoomWidth;
    topMargin=8*zoomWidth;
    ui->horizontalLayout->setContentsMargins(0,topMargin,rightMargin,0);

    // 窗口顶部widget
    ui->wdg_top->setFixedHeight(width+topMargin);

}

void MMLoginDialog::initFont()
{

}

void MMLoginDialog::initEventHandle()
{
    // 关闭按钮事件
    connect(ui->btn_close, &QPushButton::clicked, this, [&](){
        this->reject();
    });

    connect(ui->wdg_account_login, &MMAccountLogin::signalHandlerLogin, this, &MMLoginDialog::slotHandlerLogin);
}

bool MMLoginDialog::eventFilter(QObject* watched,QEvent* event)
{
    if (watched && watched == this)
    {
        if (event->type() == QEvent::MouseButtonPress)
        {
            // 鼠标点击
            //DebugPrint("mouse button press event.");
            QMouseEvent* mouseEvent=static_cast<QMouseEvent*>(event);
            if (mouseEvent->button() == Qt::LeftButton)
            {
                m_buttonType=Qt::LeftButton;
                QRect titleRect=rect();
                //titleRect.setBottom(titleRect.top() + 48);
                if (titleRect.contains(mouseEvent->pos()))
                {
                    m_isMove=true;
                    m_startPoint=mouseEvent->globalPos();
                    m_winTopLeftPoint=this->frameGeometry().topLeft();
                }
            }
        }

        if (event->type() == QEvent::MouseMove)
        {
            // 鼠标移动
            QMouseEvent* mouseEvent=static_cast<QMouseEvent*>(event);
            if (m_buttonType == Qt::LeftButton)
            {
                if (m_isMove)
                {
                    // 如果是移动状态，计算出新的位置
                    QPoint distance=mouseEvent->globalPos() - m_startPoint;
                    move(m_winTopLeftPoint + distance);
                }
            }
        }

        if (event->type() == QEvent::MouseButtonRelease)
        {
            // 鼠标释放
            QMouseEvent* mouseEvent=static_cast<QMouseEvent*>(event);
            Q_UNUSED(mouseEvent)
            if (m_buttonType == Qt::LeftButton) // 鼠标左键按下，并且鼠标当前要在按键上
            {
                m_isMove=false;
                m_buttonType=Qt::NoButton;
            }
            // 这里不用返回true表示信号已经处理，因为css样式中还要显示样式，需要把这个信号继续往下传递
        }
    }

    return QDialog::eventFilter(watched, event);
}

#ifdef __APPLE__
void MMLoginDialog::initInputEdit()
{
    // 去掉mac下选中输入框的蓝色边框
    // ui->passwdInput->setAttribute(Qt::WA_MacShowFocusRect, 0);
}
#endif // __APPLE__

