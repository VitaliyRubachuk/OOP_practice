QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    newobjectdialog.cpp \
    paymentlistwindow.cpp \
    st.payment.cpp \
    stpaymentdialog.cpp \
    student.cpp \
    studentinfowindow.cpp \
    studentlistwindow.cpp

HEADERS += \
    mainwindow.h \
    newobjectdialog.h \
    paymentlistwindow.h \
    person.h \
    st.payment.h \
    stpaymentdialog.h \
    student.h \
    studentinfowindow.h \
    studentlistwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
