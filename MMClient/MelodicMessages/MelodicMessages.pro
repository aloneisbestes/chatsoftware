QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets network

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mmcommon.cpp

HEADERS += \
    mmcommon.h

FORMS +=

INCLUDEPATH += src
INCLUDEPATH += src/MMUiModule
INCLUDEPATH += src/MMUiModule/MMCommonUI
INCLUDEPATH += src/MMNetworkModule
INCLUDEPATH += src/MMGlobalModule
INCLUDEPATH += src/MMDataModule
INCLUDEPATH += src/MMGlobalModule/MMSystemGlobal

include(src/MMUiModule/MMUiModule.pri)
include(src/MMNetworkModule/MMNetworkModule.pri)
include(src/MMGlobalModule/MMGlobalModule.pri)
include(src/MMDataModule/MMDataModule.pri)

# 设置构建目录
CONFIG(release, debug|release) {
    # Release模式构建目录
    DESTDIR = $$PWD/build/release
} else {
    # Debug模式构建目录
    DESTDIR = $$PWD/build/debug
}


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resource/resource.qrc