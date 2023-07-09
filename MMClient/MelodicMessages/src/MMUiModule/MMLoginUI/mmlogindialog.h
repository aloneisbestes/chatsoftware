#ifndef MMLOGINDIALOG_H
#define MMLOGINDIALOG_H

#include <QDialog>
#include <QPoint>

namespace Ui {
class MMLoginDialog;
}

class MMLoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MMLoginDialog(QWidget *parent = nullptr);
    ~MMLoginDialog();

private:
    // 初始化登录界面
    void initMMLoginDialogUI();
    // 初始化组件
    void initSubassembly();
    // 初始化字体
    void initFont();
    // 初始化事件处理，信号与槽
    void initEventHandle();

protected:
    // 重写event事件函数，实现移动
    bool eventFilter(QObject* watched, QEvent* event)override;

#ifdef __APPLE__
    // 初始化输入框
    void initInputEdit();
#endif // __APPLE__

private:
    Ui::MMLoginDialog *ui;

private:
    bool m_isMove;
    QPoint m_startPoint;
    QPoint m_winTopLeftPoint;
    int m_buttonType;
};

#endif // MMLOGINDIALOG_H
