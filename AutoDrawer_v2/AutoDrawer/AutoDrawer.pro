QT += core gui
QT += concurrent
QT += network
QT += testlib

win32 {
    LIBS += -lUser32
}
linux-g++ {
    LIBS += -lX11
}
macx {

}

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += debug

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    consolewindow.cpp \
    custompattern.cpp \
    downloadthemes.cpp \
    infowindow.cpp \
    main.cpp \
    autodrawer.cpp \
    messagewindow.cpp \
    previewwindow.cpp \
    settingswindow.cpp \
    themeeditor.cpp

HEADERS += \
    autodrawer.h \
    consolewindow.h \
    custompattern.h \
    downloadthemes.h \
    infowindow.h \
    messagewindow.h \
    previewwindow.h \
    settingswindow.h \
    themeeditor.h

FORMS += \
    autodrawer.ui \
    consolewindow.ui \
    custompattern.ui \
    downloadthemes.ui \
    infowindow.ui \
    messagewindow.ui \
    previewwindow.ui \
    settingswindow.ui \
    themeeditor.ui

TRANSLATIONS += \
    AutoDrawer_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#LIBS += -L$$PWD/UGlobalHotkey -UGlobalHotkey.lib
#LIBS += -L$$PWD/UGlobalHotkey -UGlobalHotkey.dll

RESOURCES += \
    resources.qrc

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/UGlobalHotkey/release/ -lUGlobalHotkey
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/UGlobalHotkey/debug/ -lUGlobalHotkey
#else:unix: LIBS += -L$$PWD/UGlobalHotkey/ -lUGlobalHotkey

#INCLUDEPATH += $$PWD/UGlobalHotkey
#DEPENDPATH += $$PWD/UGlobalHotkey
