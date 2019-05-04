#-------------------------------------------------
#
# Project created by QtCreator 2018-12-27T15:39:57
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PassVault
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        passvault.cpp \
    login.cpp \
    show_accounts.cpp \
    new_account.cpp \
    about.cpp \
    new_user.cpp \
    delete_password.cpp \
    update_password.cpp

HEADERS += \
        passvault.h \
    login.h \
    show_accounts.h \
    new_account.h \
    about.h \
    new_user.h \
    delete_password.h \
    update_password.h

FORMS += \
        passvault.ui \
    login.ui \
    show_accounts.ui \
    new_account.ui \
    about.ui \
    new_user.ui \
    delete_password.ui \
    update_password.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
