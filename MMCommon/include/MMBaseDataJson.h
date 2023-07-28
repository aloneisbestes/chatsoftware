#ifndef __MM_BASE_DATA_JSON_H__
#define __MM_BASE_DATA_JSON_H__

#include "MMBaseData.h"
#include <memory>
#ifdef QT_CORE_LIB
#include <QJsonObject>
#define MMJson QJsonObject
#else
#include <jsoncpp/json/json.h>
#define MMJson Json::Value
#endif // QT_VERSION
#include <cstring>

class MMBaseDataJson : public MMBaseData {
public:
    void setJsonstr(std::shared_ptr<char> jsonstr) { m_jsonstr=jsonstr; }
    std::shared_ptr<char> getJsonstr() const { return m_jsonstr; }

    void setJsonroot(MMJson &josnroot) { m_jsonroot=josnroot; }
    const MMJson &getJsonroot() const { return m_jsonroot; }

    void setLen(int len) { m_len=len; }
    int getLen() const { return m_len; }

private:
    std::shared_ptr<char> m_jsonstr;      // json字符串
    int m_len;  // json字符串的长度
    MMJson m_jsonroot;     // json
};

#endif // __MM_BASE_DATA_JSON_H__
