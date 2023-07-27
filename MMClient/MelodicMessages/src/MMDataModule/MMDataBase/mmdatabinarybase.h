#ifndef MMDATABINARYBASE_H
#define MMDATABINARYBASE_H

#include "mmdatabase.h"

class MMDataBinaryBase : public MMDataBase
{
public:
    MMDataBinaryBase(MMUInt32 mainCmd=MMMainCmd_None, MMUInt32 subCmd=MMMainCmd_None);
    ~MMDataBinaryBase();

    int len() const;

    void *binaryData();
    /**
     * @brief setBinaryData
     * @param newBinaryData 若newBinaryData为nullptr，则就是申请len长度的空间
     * @param len 大小或长度
     */
    void setBinaryData(void *newBinaryData, int len);

protected:
    // 解析和创建二进制数据
    virtual void parseData()=0;
    virtual void createData()=0;

private:
    void *m_binaryData;
    int m_len;
};

#endif // MMDATABINARYBASE_H
