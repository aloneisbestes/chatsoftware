#ifndef MMDATAMANAGER_H
#define MMDATAMANAGER_H

#include <QObject>

class MMDataManager : public QObject
{
    Q_OBJECT
public:
    ~MMDataManager();

    static MMDataManager *instance();
    static void disInstance();

private:
    static MMDataManager *__ins;

private:
    explicit MMDataManager(QObject *parent = nullptr);
    MMDataManager(const MMDataManager &other)=delete;
    void operator =(const MMDataManager &other)=delete;
};

#endif // MMDATAMANAGER_H
