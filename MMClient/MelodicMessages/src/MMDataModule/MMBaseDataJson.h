#ifndef __MM_BASE_DATA_JSON_H__
#define __MM_BASE_DATA_JSON_H__

#include "MMBaseData.h"
#include <memory>
#include <QJsonObject>
#include <QJsonDocument>
#include <cstring>

class MMBaseDataJson : public MMBaseData {
public:
    MMBaseDataJson(MMUInt32 mainCmd=MMMainCmd_None, MMUInt32 subCmd=MMMainCmd_None);
    virtual ~MMBaseDataJson();


    void setJsonstr(const std::string &jsonstr);
    void setJsonstr(const char *jsonstr);
    const std::string &getJsonstr()const;

    void setJsonroot(const QJsonObject &jsonroot);
    const QJsonObject &getJsonroot()const;

    virtual void setData(const char *data);
    virtual const char *getConstData() const override;
    virtual char *getData()override; 

public:
    static QByteArray createJson(QJsonObject &jsonroot);

    static QJsonObject parseJson(const char *jsonstr, bool &isSuccess);

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
    QJsonObject m_jsonroot;     // json
    bool m_isParseSuccess;  // 是否解析成功
};

#endif // __MM_BASE_DATA_JSON_H__
