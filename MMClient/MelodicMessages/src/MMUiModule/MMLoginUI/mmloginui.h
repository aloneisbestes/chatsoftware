#ifndef MMLOGINUI_H
#define MMLOGINUI_H

#include <QWidget>

namespace Ui {
class MMLoginUI;
}

class MMLoginUI : public QWidget
{
    Q_OBJECT

private:
    enum MMLoginUIType{
        LoginUIType_Account=0,  // 用户名密码登录界面
        LoginUIType_QRCode      // 二维码登录界面
    };

public:
    explicit MMLoginUI(QWidget *parent = nullptr);
    ~MMLoginUI();

    void setQRImage(const QString &QRImage);

protected:
    virtual void mousePressEvent(QMouseEvent *event)override;
    virtual void mouseMoveEvent(QMouseEvent *event)override;
    virtual void mouseReleaseEvent(QMouseEvent *event)override;


signals:
    void signalLogout();    // 退出登录页面信号

protected slots:
    void slotLoginUIChange();

private:
    // 初始化登录界面
    void initMMLoginDialogUI();
    // 初始化组件
    void initSubassembly();
    // 初始化字体
    void initFont();
    // 初始化事件处理，信号与槽
    void initEventHandle();

private:
    bool m_isMove;
    QPoint m_startPoint;
    QPoint m_winTopLeftPoint;
    int m_buttonType;
    int m_width;
    int m_height;
    MMLoginUIType m_nowType;    // 当前页面

private:
    Ui::MMLoginUI *ui;
};

#endif // MMLOGINUI_H
