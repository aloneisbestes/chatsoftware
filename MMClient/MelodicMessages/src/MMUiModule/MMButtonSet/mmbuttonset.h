#ifndef MMBUTTONSET_H
#define MMBUTTONSET_H

#include <QWidget>
#include <QLayout>
#include <QAbstractButton>

namespace Ui {
class MMButtonSet;
}

class MMButtonSet : public QWidget
{
    Q_OBJECT

public:
    // 类型
    enum MMButtonSetType
    {
        MMButtonSetType_Horizontal=1,   // 水平布局
        MMButtonSetType_Vertical        // 垂直布局
    };

public:
    explicit MMButtonSet(MMButtonSetType type=MMButtonSetType_Horizontal, QWidget *parent = nullptr);
    ~MMButtonSet();

    void setMargin(int left, int top, int right, int bottom);
    void setSpacing(int spacing);
    int getSpacing() const;

    void addButton(QAbstractButton *button);
    void delButton(QAbstractButton *button);
    void delButton(int idx);

    void setFixedSize(const QSize &size);
    void setFixedHeight(int height);
    int getHeight()const;
    void setFixedWidth(int w);
    int getWidth()const;

private:
    Ui::MMButtonSet *ui;
    QLayout *m_layout;
    QList<QAbstractButton *> m_buttonList;
    MMButtonSetType m_type;
};

#endif // MMBUTTONSET_H
