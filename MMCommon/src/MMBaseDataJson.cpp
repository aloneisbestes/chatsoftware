#include "MMBaseDataJson.h"

MMBaseDataJson::MMBaseDataJson(MMUInt32 mainCmd, MMUInt32 subCmd)
    : MMBaseData(mainCmd, subCmd)
{

}

MMBaseDataJson::~MMBaseDataJson()
{

}

void MMBaseDataJson::setJsonstr(std::shared_ptr<char> jsonstr, int len)
{
    m_jsonstr=jsonstr;
    m_len=len;
    parseData();
}

std::shared_ptr<char> MMBaseDataJson::getJsonstr() const
{
    return m_jsonstr;
}

int MMBaseDataJson::getLen() const
{
    return m_len;
}

void MMBaseDataJson::setJsonroot(QJsonObject &jsonroot)
{
    m_jsonroot=jsonroot;
    createData();
}

const QJsonObject &MMBaseDataJson::getJsonroot() const
{
    return m_jsonroot;
}
