#ifndef MMSYSTEMGLOBAL_H
#define MMSYSTEMGLOBAL_H

#include <QObject>

class MMSystemGlobal : public QObject
{
    Q_OBJECT
public:
    ~MMSystemGlobal();

    static MMSystemGlobal *instance();

    double m_dWidth;
    double m_dHeight;

    double m_dZoomHeight;
    double m_dZoomWidth;
    double m_dZoom;

    double m_dDefaultWidth;
    double m_dDfaultHeight;

private:
    static MMSystemGlobal *__ins;

private:
    explicit MMSystemGlobal(QObject *parent = nullptr);
};

#endif // MMSYSTEMGLOBAL_H
