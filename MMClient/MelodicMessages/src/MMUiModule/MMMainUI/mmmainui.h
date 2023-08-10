#ifndef MMMAINUI_H
#define MMMAINUI_H

#include <QWidget>

namespace Ui {
class MMMainUI;
}

class MMMainUI : public QWidget
{
    Q_OBJECT

public:
    explicit MMMainUI(QWidget *parent = nullptr);
    ~MMMainUI();

private:
    Ui::MMMainUI *ui;
};

#endif // MMMAINUI_H
