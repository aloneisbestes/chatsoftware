#include "mmdatamanager.h"

MMDataManager *MMDataManager::__ins=nullptr;

MMDataManager::MMDataManager(QObject *parent)
    : QObject{parent}
{

}

MMDataManager::~MMDataManager()
{

}

MMDataManager *MMDataManager::instance()
{
    if (MMDataManager::__ins == nullptr)
        MMDataManager::__ins = new MMDataManager;
    return MMDataManager::__ins;
}

void MMDataManager::disInstance()
{
    if (MMDataManager::__ins)
        MMDataManager::__ins->deleteLater();
    MMDataManager::__ins=nullptr;
}
