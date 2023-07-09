#include <QApplication>


#define UI_TEST
#ifdef UI_TEST
#include "MMLoginUI/mmlogindialog.h"
int uiTest();
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#ifdef UI_TEST
    int ret = uiTest();
    if (ret == -1) {
        return ret;
    }
#endif

    return a.exec();
}

#ifdef UI_TEST
int uiTest() {
#if 1
    MMLoginDialog *loginUI=new MMLoginDialog;
    int ret = loginUI->exec();
    if (ret == QDialog::Rejected) {
        return -1;
    }
#endif // LoginUI
}
#endif
