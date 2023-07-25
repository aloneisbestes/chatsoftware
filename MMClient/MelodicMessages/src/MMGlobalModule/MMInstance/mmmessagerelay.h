#ifndef MMMESSAGERELAY_H
#define MMMESSAGERELAY_H

#include <QObject>

/**
 * @brief The MMMessageRelay class
 * 该类主要用于做消息转发
 */

class MMMessageRelay : public QObject
{
    Q_OBJECT
public:
    ~MMMessageRelay();

    static MMMessageRelay *instance();
    static void disInstance();

private:
    static MMMessageRelay *__ins;

private:
    explicit MMMessageRelay(QObject *parent = nullptr);
    MMMessageRelay(const MMMessageRelay &other)=delete;
    void operator =(const MMMessageRelay &other)=delete;
};

#endif // MMMESSAGERELAY_H
