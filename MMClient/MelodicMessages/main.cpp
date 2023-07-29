#include <QApplication>
#include "MMSystemGlobal.h"
#include "mmcommon.h"

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

    return a.exec();
}
