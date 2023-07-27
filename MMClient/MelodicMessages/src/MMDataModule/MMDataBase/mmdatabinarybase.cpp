#include "mmdatabinarybase.h"
#include <cstring>

MMDataBinaryBase::MMDataBinaryBase(MMUInt32 mainCmd, MMUInt32 subCmd)
    : MMDataBase(mainCmd, subCmd)
{
    m_binaryData=nullptr;
    m_len=0;
}

MMDataBinaryBase::~MMDataBinaryBase()
{
    if (m_binaryData)
        delete static_cast<char*>(m_binaryData);
}

void *MMDataBinaryBase::binaryData()
{
    return m_binaryData;
}

void MMDataBinaryBase::setBinaryData(void *newBinaryData, int len)
{
    if (m_binaryData)
        delete static_cast<char*>(m_binaryData);
    m_len=len;
    m_binaryData=static_cast<void*>(new char[m_len]);

    if (newBinaryData)
    {
        std::memcpy(m_binaryData, newBinaryData, m_len);
        createData();
    }
}

int MMDataBinaryBase::len() const
{
    return m_len;
}
