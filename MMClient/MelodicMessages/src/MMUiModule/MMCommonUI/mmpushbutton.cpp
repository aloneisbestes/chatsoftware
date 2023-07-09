#include "mmpushbutton.h"
#include <QFocusEvent>
#include <QDebug>
#include <QMouseEvent>

MMPushButton::MMPushButton(QWidget *parent)
    :QPushButton(parent)
{
    m_bOriginal=true;
}

MMPushButton::~MMPushButton()
{

}

bool MMPushButton::bOriginal() const
{
    return m_bOriginal;
}

void MMPushButton::setBOriginal(bool newBOriginal)
{
    m_bOriginal = newBOriginal;
}

void MMPushButton::enterEvent(QEvent *event)
{
    //qDebug() << "enterEvent";
    if (m_bOriginal==false) {
        this->setIcon(QIcon(m_iconHover));
    }
    QPushButton::enterEvent(event);
}

void MMPushButton::leaveEvent(QEvent *event)
{
    //qDebug() << "leaveEvent";
    if (m_bOriginal==false) {
        this->setIcon(QIcon(m_iconNormal));
    }
    QPushButton::leaveEvent(event);
}

void MMPushButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        if (m_bOriginal == false) {
            this->setIcon(m_iconPressed);
        }
    }

    QPushButton::mousePressEvent(event);
}

void MMPushButton::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        if (m_bOriginal == false) {
            this->setIcon(m_iconNormal);
        }
    }
    QPushButton::mouseReleaseEvent(event);
}

QIcon MMPushButton::iconPressed() const
{
    return m_iconPressed;
}

void MMPushButton::setIconPressed(const QIcon &newIconPressed)
{
    m_iconPressed = newIconPressed;
}

QIcon MMPushButton::iconHover() const
{
    return m_iconHover;
}

void MMPushButton::setIconHover(const QIcon &newIconHover)
{
    m_iconHover = newIconHover;
}

QIcon MMPushButton::iconNormal() const
{
    return m_iconNormal;
}

void MMPushButton::setIconNormal(const QIcon &newIconNormal)
{
    m_iconNormal = newIconNormal;
}


