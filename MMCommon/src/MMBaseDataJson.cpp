#include "MMBaseDataJson.h"

MMBaseDataJson::MMBaseDataJson(MMUInt32 mainCmd, MMUInt32 subCmd)
    : MMBaseData(mainCmd, subCmd)
{

}

MMBaseDataJson::~MMBaseDataJson()
{

}

void MMBaseDataJson::setJsonstr(const std::string &jsonstr)
{
    m_jsonstr=jsonstr;
    parseJsonData();
}

void MMBaseDataJson::setJsonstr(const char *jsonstr)
{
    m_jsonstr=jsonstr;
    parseJsonData();
}

const std::string &MMBaseDataJson::getJsonstr() const
{
    return m_jsonstr;
}

void MMBaseDataJson::setJsonroot(QJsonObject &jsonroot)
{
    m_jsonroot=jsonroot;
    createJsonData();
}

const QJsonObject &MMBaseDataJson::getJsonroot() const
{
    return m_jsonroot;
}

void MMBaseDataJson::setData(const char *data)
{
    setJsonstr(data);
}

#ifdef QT_CORE_LIB
QByteArray MMBaseDataJson::createJson(QJsonObject &jsonroot)
{
    //QJsonParseError jsonError;
    //QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonroot.toUtf8(), &jsonError);
    return QByteArray();
}
#else
std::string MMBaseDataJson::createJson(MMJson &jsonroot) {

}
#endif


MMJson MMBaseDataJson::parseJson(const char *jsonstr, bool &isSuccess)
{
    MMJson root;
#ifdef QT_CORE_LIB
    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonstr, &jsonError);

    if (jsonError.error == QJsonParseError::NoError) {
        root=jsonDoc.object();
    }
    else {
        Q_ASSERT_X(jsonError.error == QJsonParseError::NoError,
                   "static func MMBaseDataJson::parseJson", "parse json error");
    }

#else
#endif // QT_CORE_LIB

    return root;
}

void MMBaseDataJson::parseJsonData()
{

}

void MMBaseDataJson::createJsonData()
{

}

bool MMBaseDataJson::isParseSuccess() const
{
    return m_isParseSuccess;
}
