#ifndef MMACCOUNTLOGINUI_H
#define MMACCOUNTLOGINUI_H

#include <QWidget>

namespace Ui {
class MMAccountLoginUI;
}

class MMAccountLoginUI : public QWidget
{
    Q_OBJECT

public:
    explicit MMAccountLoginUI(QWidget *parent = nullptr);
    ~MMAccountLoginUI();

signals:
    void signalLoginSuccess();

protected slots:
    void slotAccountLogin();

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
    Ui::MMAccountLoginUI *ui;
};

#endif // MMACCOUNTLOGINUI_H
