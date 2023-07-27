#include "mmdatabase.h"
#include <cstring>

MMDataBase::MMDataBase(MMUInt32 mainCmd, MMUInt32 subCmd)
{
    std::memset(&m_header, 0, MMSTHEADER_SIZE);
    m_header.mainCmd=mainCmd;
    m_header.subCmd=subCmd;
}

MMDataBase::~MMDataBase()
{

}

MM_STHeader &MMDataBase::header()
{
    return m_header;
}

void MMDataBase::setHeader(const MM_STHeader &newHeader)
{
    memcpy(&m_header, &newHeader, MMSTHEADER_SIZE);
}
