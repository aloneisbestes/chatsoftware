#include "mmbuttonset.h"
#include "ui_mmbuttonset.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

MMButtonSet::MMButtonSet(MMButtonSetType type, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MMButtonSet)
{
    ui->setupUi(this);

    m_type=type;

    if (m_type == MMButtonSetType_Horizontal)
        m_layout=new QHBoxLayout;
    else
        m_layout=new QVBoxLayout;

    m_layout->setContentsMargins(0,0,0,0);

    ui->scrollAreaWidgetContents->setLayout(m_layout);
}

MMButtonSet::~MMButtonSet()
{
    delete ui;
}

void MMButtonSet::setMargin(int left, int top, int right, int bottom)
{
    m_layout->setContentsMargins(left, top, right, bottom);
}

void MMButtonSet::setSpacing(int spacing)
{
    m_layout->setSpacing(spacing);
}

int MMButtonSet::getSpacing() const
{
    return m_layout->spacing();
}

void MMButtonSet::addButton(QAbstractButton *button)
{
    m_layout->addWidget(button);
    m_buttonList.push_back(button);
}

void MMButtonSet::delButton(QAbstractButton *button)
{

}

void MMButtonSet::delButton(int idx)
{

}

void MMButtonSet::setFixedSize(const QSize &size)
{
    QWidget::setFixedSize(size);
    for (auto &it : m_buttonList) {
        if (m_type == MMButtonSetType_Vertical)
            it->setFixedWidth(size.width());
        else
            it->setFixedWidth(size.height());
    }
}

void MMButtonSet::setFixedHeight(int height)
{
    QWidget::setFixedHeight(height);
    for (auto &it : m_buttonList) {
        if (m_type == MMButtonSetType_Horizontal)
            it->setFixedHeight(height);
    }
}

int MMButtonSet::getHeight() const
{
    return this->height();
}

void MMButtonSet::setFixedWidth(int w)
{
    QWidget::setFixedWidth(w);
    for (auto &it : m_buttonList) {
        if (m_type == MMButtonSetType_Vertical)
            it->setFixedWidth(w);
    }
}

int MMButtonSet::getWidth() const
{
    return this->width();
}
