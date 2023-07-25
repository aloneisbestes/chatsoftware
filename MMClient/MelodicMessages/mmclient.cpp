#include "mmclient.h"
#include "ui_mmclient.h"

MMClient::MMClient(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MMClient)
{
    ui->setupUi(this);
}

MMClient::~MMClient()
{
    delete ui;
}
