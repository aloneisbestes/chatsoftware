#ifndef MMUIMANAGER_H
#define MMUIMANAGER_H

#include <QObject>

class MMUIManager : public QObject
{
    Q_OBJECT
public:
    static MMUIManager* instance();
    static void disInstance();
    ~MMUIManager();


private:
    static MMUIManager *__ins;

private:
    explicit MMUIManager(QObject *parent = nullptr);
};

#endif // MMUIMANAGER_H
