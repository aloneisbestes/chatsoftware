#ifndef __MM_BASEDATA_H__
#define __MM_BASEDATA_H__

#include <cstring>
#include "MMProtocol.h"

class MMBaseData {
public:
    MMBaseData(MMUInt32 mainCmd=MMMainCmd_None, MMUInt32 subCmd=MMMainCmd_None)
    {
        m_header.mainCmd=mainCmd;
        m_header.subCmd=subCmd;
        std::memset(&m_header, 0, MMSTHEADER_SIZE);
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

protected:
    // 创建数据
    virtual void createData()=0;
    // 解析数据
    virtual void parseData()=0;

private:
    MM_STHeader m_header;
};

#endif // __MM_BASEDATA_H__
