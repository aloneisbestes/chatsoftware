#include "MMOtherData.h"
#ifdef QT_CORE_LIB
#include <QtCore/qglobal.h>
#endif // QT_CORE_LIB

MMOtherData::MMOtherData(MMUInt32 mainCmd, MMUInt32 subCmd)
    : MMBaseData(mainCmd, subCmd)
{

}

MMOtherData::~MMOtherData()
{

}

void MMOtherData::setData(const char *data)
{
#ifdef QT_CORE_LIB
    Q_UNUSED(data);
#endif // QT_CORE_LIB
}

void MMOtherData::createData()
{

}

void MMOtherData::parseData()
{

}
