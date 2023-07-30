#ifndef MMUIMANAGER_H
#define MMUIMANAGER_H

#include <QObject>

class MMLoginUI;

class MMUIManager : public QObject
{
    Q_OBJECT
public:
    static MMUIManager* instance();
    static void disInstance();
    ~MMUIManager();

    void toLogin();

    void quitApplation();

protected slots:
    void slotLoginSuccess();
    void slotLoginout();


private:
    static MMUIManager *__ins;

private:
    explicit MMUIManager(QObject *parent = nullptr);
    MMLoginUI *m_loginUI;
};

#endif // MMUIMANAGER_H
