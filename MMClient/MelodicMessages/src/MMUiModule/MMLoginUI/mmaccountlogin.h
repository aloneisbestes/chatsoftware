#ifndef MMACCOUNTLOGIN_H
#define MMACCOUNTLOGIN_H

#include <QWidget>

namespace Ui {
class MMAccountLogin;
}

class MMAccountLogin : public QWidget
{
    Q_OBJECT

public:
    explicit MMAccountLogin(QWidget *parent = nullptr);
    ~MMAccountLogin();

private:
    // 初始化登录界面
    void initMMAccountLoginUI();
    // 初始化组件
    void initSubassembly();
    // 初始化字体
    void initFont();
    // 初始化事件处理，信号与槽
    void initEventHandle();

private:
    Ui::MMAccountLogin *ui;

private:
    int m_iconSize;
};

#endif // MMACCOUNTLOGIN_H
