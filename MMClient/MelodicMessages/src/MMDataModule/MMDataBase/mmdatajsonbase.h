#ifndef MMDATAJSONBASE_H
#define MMDATAJSONBASE_H

#include "mmdatabase.h"
#include <QJsonObject>

class MMDataJsonBase : public MMDataBase
{
public:
    MMDataJsonBase(MMUInt32 mainCmd=MMMainCmd_None, MMUInt32 subCmd=MMMainCmd_None);
    ~MMDataJsonBase();

    const QJsonObject &jsonroot() const;
    void setJsonroot(const QJsonObject &newJsonroot);

    const QString &josnstr() const;
    void setJosnstr(const QString &newJosnstr);

protected:
    // 解析和创建json数据
    virtual void parseData()=0;
    virtual void createData()=0;

protected:
    bool parseJsonData();
    void createJsonData();

private:
    QJsonObject m_jsonroot;
    QString m_jsonstr;
};

#endif // MMDATAJSONBASE_H
