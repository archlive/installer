#-------------------------------------------------
#
# Project created by QtCreator 2019-01-05T00:01:18
#
#-------------------------------------------------

QT += core
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG  += c++11 # mobility
TARGET   = arch-install
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += src src/ui

SOURCES += src/main.cpp \
           src/ui/Installer.cpp \
           src/ui/PageLocale.cpp \
           src/ui/PageAccount.cpp \
           src/ui/PageBootloader.cpp \
           src/ui/PageDesktopMgr.cpp \
           src/ui/PageDisplayMgr.cpp \
           src/ui/PageDrive.cpp \
           src/ui/PageKbLayout.cpp \
           src/ui/PageKbModel.cpp \
           src/ui/PageKbVariant.cpp \
           src/ui/PageKernel.cpp \
           src/ui/PagePartition.cpp \
           src/ui/PageShell.cpp \
           src/ui/PageSubZone.cpp \
           src/ui/PageTime.cpp \
           src/ui/PageUtils.cpp \
           src/ui/PageVirtualBox.cpp \
           src/ui/PageZone.cpp \
    src/Locale.cpp
HEADERS += src/ui/Installer.h \
           src/ui/PageLocale.h \
           src/ui/PageAccount.h \
           src/ui/PageBootloader.h \
           src/ui/PageDesktopMgr.h \
           src/ui/PageDisplayMgr.h \
           src/ui/PageDrive.h \
           src/ui/PageKbLayout.h \
           src/ui/PageKbModel.h \
           src/ui/PageKbVariant.h \
           src/ui/PageKernel.h \
           src/ui/PagePartition.h \
           src/ui/PageShell.h \
           src/ui/PageSubZone.h \
           src/ui/PageTime.h \
           src/ui/PageUtils.h \
           src/ui/PageVirtualBox.h \
           src/ui/PageZone.h \
    src/Locale.h
FORMS   += src/ui/Installer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += resources/resources.qrc

DISTFILES +=
