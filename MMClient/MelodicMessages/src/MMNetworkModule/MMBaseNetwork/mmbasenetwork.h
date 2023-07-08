    #ifndef MMBASENETWORK_H
#define MMBASENETWORK_H

#include <QObject>

class QTcpSocket;

class MMBaseNetwork : public QObject
{
    Q_OBJECT
public:
    explicit MMBaseNetwork(QObject *parent = nullptr);

signals:


private:
    QTcpSocket *m_baseSocket;
};

#endif // MMBASENETWORK_H
