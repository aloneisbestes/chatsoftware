#ifndef __MM_BASEDATA_H__
#define __MM_BASEDATA_H__

#include <cstring>
#include "MMProtocol.h"
#include <string>


class MMBaseData {
public:
    typedef void (MMBaseData::*MMFuncPtr)();

public:
    MMBaseData(MMUInt32 mainCmd=MMMainCmd_None, MMUInt32 subCmd=MMMainCmd_None)
    {
        m_header.mainCmd=mainCmd;
        m_header.subCmd=subCmd;
        std::memset(&m_header, 0, MMSTHEADER_SIZE);
        m_parseFunc=nullptr;
        m_createFunc=nullptr;
    }

    ~MMBaseData() {}

    void setMMHeader(const MM_STHeader &header)
    {
        std::memcpy(&m_header, &header, MMSTHEADER_SIZE);
    }
    MM_STHeader &getMMHeader(){ return m_header; }

    /**
     * @brief setData
     * 该函数为纯虚函数，在子类中必须重写，并且需要明确设置该函数设置的数据，否则建议空实现
     * 而且该函数设置的是子类中需要解析的数据
     * @param data
     */
    virtual void setData(const char *data)=0;

    /**
     * @brief setData
     * 该函数为纯虚函数，在子类中必须重写，并且需要明确获取子类中得数据，否则建议子类中私有存在
     * @param data
     */
    virtual const char *getConstData() const = 0;
    virtual char *getData() = 0; 

    // 创建数据
    virtual void createData()
    {
        if (m_createFunc == nullptr) {
            // Q_ASSERT_X(m_createFunc != nullptr, "MMBaseData::createData", "The creation function pointer is not set");
            return ;
        }
        (this->*m_createFunc)();
    }

    // 解析数据
    virtual void parseData()
    {
        if (m_parseFunc == nullptr) {
            // Q_ASSERT_X(m_createFunc != nullptr, "MMBaseData::createData", "The creation function pointer is not set");
            return ;
        }
        (this->*m_parseFunc)();
    }

protected:
    void setMMParseFuncPtr(MMFuncPtr parseFunc=nullptr) { m_parseFunc=parseFunc; }
    void setMMCreateFuncPtr(MMFuncPtr createFunc=nullptr) { m_createFunc=createFunc; }

private:
    MM_STHeader m_header;
    MMFuncPtr m_parseFunc;
    MMFuncPtr m_createFunc;
};

#endif // __MM_BASEDATA_H__
