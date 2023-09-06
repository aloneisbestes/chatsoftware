#include <QApplication>
#include "mmsystemglobal.h"
#include "mmcommon.h"
#include "mmuimanager.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifndef MM_DEBUG
    if (MMSystemGlobal::instance()->m_isFileLogOpen == true) {
        qInstallMessageHandler(customMessageHandler);
    }
#endif // MM_DEBUG

    MMQRegisterMetaType();
    MMSystemGlobal::instance()->init();

    MMUIManager::instance()->toLogin();

    return a.exec();
}
