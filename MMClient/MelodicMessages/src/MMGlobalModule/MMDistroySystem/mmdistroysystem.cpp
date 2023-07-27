#include "mmdistroysystem.h"
#include "mmlogindata.h"
#include "mmdatamanager.h"
#include "mmmessagerelay.h"

MMDistroySystem *MMDistroySystem::__ins=nullptr;

MMDistroySystem::~MMDistroySystem()
{

}

MMDistroySystem *MMDistroySystem::instance()
{
    if (MMDistroySystem::__ins == nullptr) {
        MMDistroySystem::__ins=new MMDistroySystem;
    }
    return MMDistroySystem::__ins;
}

void MMDistroySystem::disAllInstance()
{
    UserInfoData::disInstance();
    MMDataManager::disInstance();
    MMMessageRelay::disInstance();
}

MMDistroySystem::MMDistroySystem()
{
    if (MMDistroySystem::__ins) {
        delete MMDistroySystem::__ins;
    }
}
