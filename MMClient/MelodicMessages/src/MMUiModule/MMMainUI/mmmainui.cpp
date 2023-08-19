#include "mmmainui.h"
#include "ui_mmmainui.h"

MMMainUI::MMMainUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MMMainUI)
{
    ui->setupUi(this);
}

MMMainUI::~MMMainUI()
{
    delete ui;
}
