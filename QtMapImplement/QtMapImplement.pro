QT += core gui widgets quick location positioning

CONFIG += c++17

# Uncomment the following line to disable deprecated APIs before Qt 6.0.0
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += \
    main.cpp \
    projectmodel.cpp

HEADERS += \
    projectmodel.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    qml.qrc
