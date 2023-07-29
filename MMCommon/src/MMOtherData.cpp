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

void MMOtherData::createData()
{

}

void MMOtherData::parseData()
{

}
