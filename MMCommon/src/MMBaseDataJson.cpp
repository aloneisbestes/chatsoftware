#include "MMBaseDataJson.h"

MMBaseDataJson::MMBaseDataJson(MMUInt32 mainCmd, MMUInt32 subCmd)
    : MMBaseData(mainCmd, subCmd)
{
    MMBaseData::setMMCreateFuncPtr(reinterpret_cast<MMFuncPtr>(&MMBaseDataJson::createJsonData));
    MMBaseData::setMMParseFuncPtr(reinterpret_cast<MMFuncPtr>(&MMBaseDataJson::parseJsonData));
}

MMBaseDataJson::~MMBaseDataJson()
{

}

void MMBaseDataJson::setJsonstr(const std::string &jsonstr)
{
    m_jsonstr=jsonstr;
}

void MMBaseDataJson::setJsonstr(const char *jsonstr)
{
    m_jsonstr=jsonstr;
}

const std::string &MMBaseDataJson::getJsonstr() const
{
    return m_jsonstr;
}

void MMBaseDataJson::setJsonroot(const QJsonObject &jsonroot)
{
    m_jsonroot=jsonroot;
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
    // Q_UNUSED(jsonroot);
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
        isSuccess=true;
    }
    else {
        MMAssert(jsonError.error == QJsonParseError::NoError);
        isSuccess=false;
    }
#else
#endif // QT_CORE_LIB

    return root;
}

bool MMBaseDataJson::isParseSuccess() const
{
    return m_isParseSuccess;
}

void MMBaseDataJson::parseJsonData()
{
    bool isSuccess;
    MMBaseDataJson::parseJson(getJsonstr().c_str(), isSuccess);
    if (isSuccess) {

    }
    else {
        MMAssert(isSuccess==true);
    }
}

void MMBaseDataJson::createJsonData()
{

}
