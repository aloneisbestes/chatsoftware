#include "mmdatajsonbase.h"
#include <QJsonDocument>
#include <QDebug>

MMDataJsonBase::MMDataJsonBase(MMUInt32 mainCmd, MMUInt32 subCmd)
    : MMDataBase(mainCmd, subCmd)
{

}

MMDataJsonBase::~MMDataJsonBase()
{

}

const QJsonObject &MMDataJsonBase::jsonroot() const
{
    return m_jsonroot;
}

void MMDataJsonBase::setJsonroot(const QJsonObject &newJsonroot)
{
    m_jsonroot = newJsonroot;
    createData();
}

const QString &MMDataJsonBase::josnstr() const
{
    return m_jsonstr;
}

void MMDataJsonBase::setJosnstr(const QString &newJsonstr)
{
    m_jsonstr = newJsonstr;
    parseData();
}

bool MMDataJsonBase::parseJsonData()
{
    // 解析json
    QJsonParseError createError;
    QJsonDocument jsonDoc=QJsonDocument::fromJson(m_jsonstr.toUtf8(), &createError);

    m_jsonroot=jsonDoc.object();

    if (createError.error == QJsonParseError::NoError) {
        return true;
    }
    else {
        Q_ASSERT_X(createError.error == QJsonParseError::NoError, "MMDataJsonBase::parseJsonData", "parse json error");
        return false;
    }
}

void MMDataJsonBase::createJsonData()
{
    // 创建json
    QJsonDocument jsonDoc(m_jsonroot);
    // QJsonDocument::Indented : 格式化json
    // QJsonDocument::Compact  : 不格式化json
    m_jsonstr=jsonDoc.toJson(QJsonDocument::Compact);
}
