DESTDIR = ../../build/

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../SmartCalc_Calc.c \
    ../../SmartCalc_Math.c \
    ../../SmartCalc_Parse.c \
    ../../SmartCalc_PolishNotation.c \
    ../../SmartCalc_Validator.c \
    ../../Stack_func.c \
    ../../Credit_Calc.c \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    ../../SmartCalc.h \
    dialog.h \
    mainwindow.h \
    qcustomplot.h

FORMS += \
    dialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
