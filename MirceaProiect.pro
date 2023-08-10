QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CLI.cpp \
    Controller.cpp \
    FilteringCriteria.cpp \
    Jewelry_Product.cpp \
    Repository.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../../Downloads/Mircea OOP Project/CLI.h \
    ../../Downloads/Mircea OOP Project/Controller.h \
    ../../Downloads/Mircea OOP Project/FilteringCriteria.h \
    ../../Downloads/Mircea OOP Project/Jewelry_Product.h \
    ../../Downloads/Mircea OOP Project/Repository.h \
    CLI.h \
    Controller.h \
    FilteringCriteria.h \
    Jewelry_Product.h \
    Repository.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
