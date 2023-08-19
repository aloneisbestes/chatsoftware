#include "mmuimanager.h"
#include "mmloginui.h"
#include "mmdistroysystem.h"
#include "mmclient.h"
#include <QApplication>
#include <QDebug>

MMUIManager *MMUIManager::__ins=nullptr;

MMUIManager::MMUIManager(QObject *parent)
    : QObject{parent}
{
    m_loginUI=nullptr;
}

MMUIManager *MMUIManager::instance()
{
    if (MMUIManager::__ins == nullptr) {
        MMUIManager::__ins = new MMUIManager;
    }

    return MMUIManager::__ins;
}

void MMUIManager::disInstance()
{
    if (MMUIManager::__ins != nullptr) {
        delete MMUIManager::__ins;
    }
}

MMUIManager::~MMUIManager()
{

}

void MMUIManager::toLogin()
{
    if (m_loginUI == nullptr) {
        m_loginUI=new MMLoginUI();
        connect(m_loginUI, &MMLoginUI::signalLogout, this, &MMUIManager::slotLoginout);
        connect(m_loginUI, &MMLoginUI::signalLoginSuccess, this, &MMUIManager::slotLoginSuccess);
    }
    m_loginUI->show();
}

void MMUIManager::quitApplation()
{
    // 保存资源
    // ..............

    // 清理资源
    MMDistroySystem::instance()->disAllInstance();
    MMDistroySystem::disInstanc();

    // 退出程序
    QApplication::quit();
}

void MMUIManager::slotLoginSuccess()
{
    qDebug() << "login success";
    // 登录成功显示界面
    m_loginUI->deleteLater();   // 删除登录界面

    // 进入界面
    m_clientUI=new MMClient();
    m_clientUI->show();
}

void MMUIManager::slotLoginout()
{
    if (m_loginUI) {
        m_loginUI->deleteLater();
        m_loginUI=nullptr;
    }

    // 退出登录界面
    quitApplation();
}

void MMUIManager::slotClientQuit()
{
    if (m_clientUI) {
        m_clientUI->deleteLater();
        m_clientUI=nullptr;
    }

    quitApplation();
}
