#include "MMBaseDataJson.h"

MMBaseDataJson::MMBaseDataJson(MMUInt32 mainCmd, MMUInt32 subCmd)
    : MMBaseData(mainCmd, subCmd)
{
    MMBaseData::setMMCreateFuncPtr(reinterpret_cast<MMFuncPtr>(&MMBaseDataJson::createJsonData));
    MMBaseData::setMMParseFuncPtr(reinterpret_cast<MMFuncPtr>(&MMBaseDataJson::parseJsonData));
    m_isParseSuccess=false;
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
    if (jsonstr != nullptr)
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

const char *MMBaseDataJson::getConstData() const 
{
    if (getJsonstr().size() == 0)  
        return nullptr;
    return getJsonstr().c_str();
}

char *MMBaseDataJson::getData() 
{
    return nullptr;
}

QByteArray MMBaseDataJson::createJson(QJsonObject &jsonroot)
{
    //QJsonParseError jsonError;
    //QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonroot.toUtf8(), &jsonError);
    // Q_UNUSED(jsonroot);
    return jsonroot["abc"].toString().toStdString().c_str();
}


QJsonObject MMBaseDataJson::parseJson(const char *jsonstr, bool &isSuccess)
{
    QJsonObject root;
    QJsonParseError jsonError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonstr, &jsonError);

    if (jsonError.error == QJsonParseError::NoError) {
        root=jsonDoc.object();
        isSuccess=true;
    }
    else {
        Q_ASSERT(jsonError.error == QJsonParseError::NoError);
        isSuccess=false;
    }

    return root;
}

bool MMBaseDataJson::isParseSuccess() const
{
    return m_isParseSuccess;
}

void MMBaseDataJson::parseJsonData()
{
    if (!getJsonstr().empty()) {
        m_jsonroot = MMBaseDataJson::parseJson(getJsonstr().c_str(), m_isParseSuccess);
        if (m_isParseSuccess) {
            deserializedData();
        }
        else {
            Q_ASSERT(m_isParseSuccess==true);
        }
    }
}

void MMBaseDataJson::createJsonData()
{
    serializedData();
#ifdef QT_CORE_LIB
    QJsonDocument jsonDocument(m_jsonroot);
    m_jsonstr=jsonDocument.toJson(QJsonDocument::Compact).toStdString();
#else

#endif // QT_CORE_LIB
    getMMHeader().dataLen=m_jsonstr.size();
}
