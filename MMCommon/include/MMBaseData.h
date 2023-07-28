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

    void setMMHeader(const MM_STHeader &header);
    const MM_STHeader &getMMHeader() const { return m_header; }

protected:
    // 创建数据
    virtual void createData()=0;
    // 解析数据
    virtual void parseData()=0;

private:
    MM_STHeader m_header;
};

#endif // __MM_BASEDATA_H__
