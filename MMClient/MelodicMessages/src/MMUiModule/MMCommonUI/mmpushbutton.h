#ifndef MMPUSHBUTTON_H
#define MMPUSHBUTTON_H

/* 公共自定义按钮 */

#include <QPushButton>
#include <QIcon>

class MMPushButton : public QPushButton
{
public:
    MMPushButton(QWidget *parent=nullptr);
    ~MMPushButton();

    bool bOriginal() const;
    void setBOriginal(bool newBOriginal=false);

    QIcon iconNormal() const;
    void setIconNormal(const QIcon &newIconNormal);

    QIcon iconHover() const;
    void setIconHover(const QIcon &newIconHover);

    QIcon iconPressed() const;
    void setIconPressed(const QIcon &newIconPressed);

protected:
    virtual void enterEvent(QEvent *event)override;
    virtual void leaveEvent(QEvent *event)override;
    virtual void mousePressEvent(QMouseEvent *event)override;
    virtual void mouseReleaseEvent(QMouseEvent *event)override;

private:
    QIcon m_iconNormal;
    QIcon m_iconHover;
    QIcon m_iconPressed;
    bool m_bOriginal;   // 是否使用原来的按钮, true: 原来的按钮，false: 自定义按钮
};

#endif // MMPUSHBUTTON_H
