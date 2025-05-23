QT += gui svg core widgets
QT += dtkcore

TARGET = dtk-svgc
CONFIG += c++11
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEFINES += QT_MESSAGELOGCONTEXT

isEmpty(PREFIX){
    PREFIX = /usr
}
isEmpty(BIN_INSTALL_DIR) {
    BIN_INSTALL_DIR=$${PREFIX}/lib/gxtk6
}
!isEmpty(DTK_STATIC_LIB){
    DEFINES += DTK_STATIC_LIB
}

SOURCES += main.cpp

target.path = $${BIN_INSTALL_DIR}

INSTALLS += target

CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../src/release/ -lgxtkwidget
else:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../src/debug/ -lgxtkwidget

#else:unix: LIBS += -L$$OUT_PWD/../../src/ -lgxtkwidget

INCLUDEPATH += $$PWD/../../src
INCLUDEPATH += $$PWD/../../src/util
DEPENDPATH += $$PWD/../../src
