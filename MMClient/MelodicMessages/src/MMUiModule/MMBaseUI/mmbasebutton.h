#ifndef MMBASEBUTTON_H
#define MMBASEBUTTON_H

#include <QPushButton>

class MMBaseButton : public QPushButton
{
    Q_OBJECT

public:
    MMBaseButton(QWidget *parent = nullptr);
    virtual ~MMBaseButton();
};

#endif // MMBASEBUTTON_H
