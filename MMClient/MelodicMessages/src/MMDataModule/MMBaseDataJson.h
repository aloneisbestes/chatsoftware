#ifndef __MM_BASE_DATA_JSON_H__
#define __MM_BASE_DATA_JSON_H__

#include "MMBaseData.h"
#include <memory>
#ifdef QT_CORE_LIB
#include <QJsonObject>
#include <QJsonDocument>
#define MMJson QJsonObject
#define isExist(arg) contains(arg)
#define MMAssert(arg) Q_ASSERT(arg)
#else
#include <jsoncpp/json/json.h>
#include <assert.h>
#define MMJson Json::Value
#define isExist(arg) isMember(arg)
#define MMAssert(arg) assert(arg)
#endif // QT_VERSION
#include <cstring>

class MMBaseDataJson : public MMBaseData {
public:
    MMBaseDataJson(MMUInt32 mainCmd=MMMainCmd_None, MMUInt32 subCmd=MMMainCmd_None);
    virtual ~MMBaseDataJson();


    void setJsonstr(const std::string &jsonstr);
    void setJsonstr(const char *jsonstr);
    const std::string &getJsonstr()const;

    void setJsonroot(const MMJson &jsonroot);
    const MMJson &getJsonroot()const;

    virtual void setData(const char *data);
    virtual const char *getConstData() const override;
    virtual char *getData()override; 

public:
#ifdef QT_CORE_LIB
    static QByteArray createJson(MMJson &jsonroot);
#else
    static std::string createJson(MMJson &jsonroot);
#endif //

    static MMJson parseJson(const char *jsonstr, bool &isSuccess);

    /**
     * @brief isParseSuccess
     * 检测json解析是否成功
     * @return
     */
    bool isParseSuccess() const;

protected:
    // 将子类对象序列化为json数据
    virtual void serializedData()=0;

    // 将json数据序列表为子类对象中的数据
    virtual void deserializedData()=0;

private:
    // 解析json数据
    void parseJsonData();
    // 创建json数据
    void createJsonData();

private:
    std::string m_jsonstr;      // json字符串
    MMJson m_jsonroot;     // json
    bool m_isParseSuccess;  // 是否解析成功
};

#endif // __MM_BASE_DATA_JSON_H__
