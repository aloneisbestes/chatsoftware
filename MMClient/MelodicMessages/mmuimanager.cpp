#include "mmuimanager.h"


MMUIManager *MMUIManager::__ins=nullptr;

MMUIManager::MMUIManager(QObject *parent)
    : QObject{parent}
{

}

MMUIManager *MMUIManager::instance()
{
    if (MMUIManager::__ins == nullptr) {
        MMUIManager::__ins = new MMUIManager;
    }

    return MMUIManager::__ins;
}

void MMUIManager::disInstance()
{
    if (MMUIManager::__ins != nullptr) {
        delete MMUIManager::__ins;
    }
}
