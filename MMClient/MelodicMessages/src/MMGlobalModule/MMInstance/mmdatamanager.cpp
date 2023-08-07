#include "mmdatamanager.h"
#include "mmlogindata.h"

MMDataManager *MMDataManager::__ins=nullptr;

MMDataManager::MMDataManager(QObject *parent)
    : QObject{parent}
{
    m_userData=new MMUserData;
}

MMDataManager::~MMDataManager()
{
    delete m_userData;
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

const MMUserData &MMDataManager::getUserData() const
{
    return *m_userData;
}

bool MMDataManager::getIsConnChatServer() const
{
    return m_isConnChatSever;
}
