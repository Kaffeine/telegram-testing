QT = core network qml

TEMPLATE = lib
TARGET   = TelegramQt$${QT_MAJOR_VERSION}QmlPlugin
VERSION = 0.2.0

include(../../options.pri)

CONFIG += c++11

DEFINES += TELEGRAMQT_QML_LIBRARY

SOURCES = plugin.cpp
OTHER_FILES += CMakeLists.txt

INCLUDEPATH += ../../TelegramQt
SOURCES += \
    DeclarativeAuthOperation.cpp \
    DeclarativeClient.cpp \
    DeclarativeClientOperator.cpp \
    DeclarativeMessageSender.cpp \
    DeclarativeOperation.cpp \
    DeclarativePeerInfo.cpp \
    DeclarativeRsaKey.cpp \
    DeclarativeSettings.cpp \

HEADERS += \
    DeclarativeAuthOperation.hpp \
    DeclarativeClient.hpp \
    DeclarativeClientOperator.hpp \
    DeclarativeMessageSender.hpp \
    DeclarativeOperation.hpp \
    DeclarativePeerInfo.hpp \
    DeclarativeRsaKey.hpp \
    DeclarativeSettings.hpp \

target.path += $$INSTALL_QML_IMPORT_DIR/TelegramQt
INSTALLS += target

LIBS += -lssl -lcrypto -lz
LIBS += -L$$OUT_PWD/../../TelegramQt
LIBS += -lTelegramQt$${QT_MAJOR_VERSION}

qmlIndexFiles.files += qmldir plugins.qmltypes
qmlIndexFiles.path += $$target.path
INSTALLS += qmlIndexFiles
