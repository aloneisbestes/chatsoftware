#ifndef __MM_BASEDATA_H__
#define __MM_BASEDATA_H__

#include "../../include/MMProtocol.h"
#include <memory>
#include <jsoncpp/json/json.h>

class MMBaseData {
public:
    MMBaseData();
    ~MMBaseData();

    void setMMHeader(const MM_STHeader &header);
    const MM_STHeader &getMMHeader() const { return m_header; }

    void setJsonstr(std::shared_ptr<char *> jsonstr) { m_jsonstr=jsonstr; }
    std::shared_ptr<char*> getJsonstr() const { return m_jsonstr; }

    void setJsonroot(const Json::Value &josnroot) { m_jsonroot=josnroot; }
    const Json::Value &getJsonroot() const { return m_jsonroot; }

    void setLen(int len) { m_len=len; }
    int getLen() const { return m_len; }

protected:
    // 创建json str
    virtual void createJsonstr()=0;
    // 解析json str
    virtual void parseJsonstr()=0;

private:
    MM_STHeader m_header;
    std::shared_ptr<char*> m_jsonstr;      // json字符串
    int m_len;  // json字符串的长度
    Json::Value m_jsonroot;     // json
};

#endif // __MM_BASEDATA_H__