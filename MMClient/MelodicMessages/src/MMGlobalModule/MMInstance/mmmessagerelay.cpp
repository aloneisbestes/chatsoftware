#include "mmmessagerelay.h"

MMMessageRelay *MMMessageRelay::__ins=nullptr;

MMMessageRelay::MMMessageRelay(QObject *parent)
    : QObject{parent}
{

}

MMMessageRelay::~MMMessageRelay()
{

}

MMMessageRelay *MMMessageRelay::instance()
{
    if (MMMessageRelay::__ins==nullptr) {
        MMMessageRelay::__ins=new MMMessageRelay;
    }

    return MMMessageRelay::__ins;
}

void MMMessageRelay::disInstance()
{
    if (MMMessageRelay::__ins)
        MMMessageRelay::__ins->deleteLater();
    MMMessageRelay::__ins=nullptr;
}
