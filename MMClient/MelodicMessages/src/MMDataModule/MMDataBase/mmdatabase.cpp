#include "mmdatabase.h"
#include <string>

MMDataBase::MMDataBase()
{
    memset(&m_header, 0, MMSTHEADER_SIZE);
}

MMDataBase::~MMDataBase()
{

}

QJsonObject MMDataBase::jsonRoot() const
{
    return m_jsonRoot;
}

void MMDataBase::setJsonRoot(const QJsonObject &newJsonRoot)
{
    m_jsonRoot = newJsonRoot;
}

QString MMDataBase::jsonString() const
{
    return m_jsonString;
}

void MMDataBase::setJsonString(const QString &newJsonString)
{
    m_jsonString = newJsonString;
}

MM_STHeader &MMDataBase::header()
{
    return m_header;
}

void MMDataBase::setHeader(const MM_STHeader &newHeader)
{
    memcpy(&m_header, &newHeader, MMSTHEADER_SIZE);
}
