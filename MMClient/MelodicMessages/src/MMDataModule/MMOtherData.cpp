#include "MMOtherData.h"
#include <QtCore/qglobal.h>

MMOtherData::MMOtherData(MMUInt32 mainCmd, MMUInt32 subCmd)
    : MMBaseData(mainCmd, subCmd)
{

}

MMOtherData::~MMOtherData()
{

}

void MMOtherData::setData(const char *data)
{
    Q_UNUSED(data);
}

const char *MMOtherData::getConstData() const
{
    return nullptr;
}

char *MMOtherData::getData()
{
    return nullptr;
} 
