#ifndef MMDATAMANAGER_H
#define MMDATAMANAGER_H

#include <QObject>

class MMUserData;

class MMDataManager : public QObject
{
    Q_OBJECT
public:
    ~MMDataManager();

    static MMDataManager *instance();
    static void disInstance();

    // 用户个人信息
    const MMUserData &getUserData() const;
    // 获取是否连接服务端
    bool getIsConnChatServer() const;

private:
    MMUserData *m_userData;     // 用户信息
    bool m_isConnChatSever;  //是否连接服务端

private:
    static MMDataManager *__ins;

private:
    explicit MMDataManager(QObject *parent = nullptr);
    MMDataManager(const MMDataManager &other)=delete;
    void operator =(const MMDataManager &other)=delete;
};

#endif // MMDATAMANAGER_H
