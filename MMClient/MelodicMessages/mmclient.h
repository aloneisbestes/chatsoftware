#ifndef MMCLIENT_H
#define MMCLIENT_H

#include <QWidget>

namespace Ui {
class MMClient;
}

/**
 * @brief The MMClient class
 * 主页面类
 */

typedef enum _en_MMClientUIPageType
{
    MMClientUIPageType_Login,
}MM_ENCleintUIPageType;

class MMClient : public QWidget
{
    Q_OBJECT

public:
    explicit MMClient(QWidget *parent = nullptr);
    ~MMClient();

private:
    Ui::MMClient *ui;
    MM_ENCleintUIPageType m_nowPage;
};

#endif // MMCLIENT_H
