QT       += core gui
QT += concurrent
QT += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    downloadthemes.cpp \
    infowindow.cpp \
    main.cpp \
    autodrawer.cpp \
    messagewindow.cpp \
    previewwindow.cpp \
    settingswindow.cpp

HEADERS += \
    autodrawer.h \
    downloadthemes.h \
    infowindow.h \
    messagewindow.h \
    previewwindow.h \
    settingswindow.h

FORMS += \
    autodrawer.ui \
    downloadthemes.ui \
    infowindow.ui \
    messagewindow.ui \
    previewwindow.ui \
    settingswindow.ui

TRANSLATIONS += \
    AutoDrawer_en_US.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
