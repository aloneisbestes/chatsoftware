#ifndef MMDATABASE_H
#define MMDATABASE_H

#include <QJsonObject>
#include "MMProtocol.h"

/* 所有json数据的基类 */

class MMDataBase
{
public:
    MMDataBase();
    ~MMDataBase();

    QJsonObject jsonRoot() const;
    void setJsonRoot(const QJsonObject &newJsonRoot);

    QString jsonString() const;
    void setJsonString(const QString &newJsonString);

    MM_STHeader &header();
    void setHeader(const MM_STHeader &newHeader);

    // 解析和创建json数据和json字符串
    virtual void parseData()=0;
    virtual void createData()=0;

private:
    QJsonObject m_jsonRoot;
    QString m_jsonString;
    MM_STHeader m_header;
};

#endif // MMDATABASE_H
