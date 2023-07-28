#ifndef __MM_BASE_DATA_JSON_H__
#define __MM_BASE_DATA_JSON_H__

#include "MMBaseData.h"
#include <memory>
#ifdef QT_CORE_LIB
#include <QJsonObject>
#define MMJson QJsonObject
#define isExist(arg) contains(arg)
#else
#include <jsoncpp/json/json.h>
#define MMJson Json::Value
#define isExist(arg) isMember(arg)
#endif // QT_VERSION
#include <cstring>

class MMBaseDataJson : public MMBaseData {
public:
    MMBaseDataJson(MMUInt32 mainCmd=MMMainCmd_None, MMUInt32 subCmd=MMMainCmd_None);
    ~MMBaseDataJson();

    void setJsonstr(std::shared_ptr<char> jsonstr, int len);
    std::shared_ptr<char> getJsonstr()const;
    int getLen() const;

    void setJsonroot(MMJson &jsonroot);
    const MMJson &getJsonroot()const;

protected:
    // 创建数据
    virtual void createData()=0;
    // 解析数据
    virtual void parseData()=0;
    // 解析json数据
    virtual bool parseJsonData();
    // 创建json数据
    virtual void createJsonData();
private:
    std::shared_ptr<char> m_jsonstr;      // json字符串
    int m_len;  // json字符串的长度
    MMJson m_jsonroot;     // json
};

#endif // __MM_BASE_DATA_JSON_H__
