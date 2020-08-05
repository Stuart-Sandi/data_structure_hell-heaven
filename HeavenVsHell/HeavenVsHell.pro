QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Arbol_BB.cpp \
    ListaDoble_Personas.cpp \
    Listas_Cargadas.cpp \
    Lugar.cpp \
    SMTP.cpp \
    Ventana_Arbol.cpp \
    Ventana_Arbol_Leaves.cpp \
    Ventana_Condenacion.cpp \
    Ventana_Consultas_Acciones.cpp \
    Ventana_Creacion.cpp \
    Ventana_SumarAcciones.cpp \
    funcionesArchivos.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Arbol_BB.h \
    Data.h \
    ListaDoble_Personas.h \
    Listas_Cargadas.h \
    Lugar.h \
    Nodo_Arbol.h \
    Persona.h \
    SMTP.h \
    Ventana_Arbol.h \
    Ventana_Arbol_Leaves.h \
    Ventana_Condenacion.h \
    Ventana_Consultas_Acciones.h \
    Ventana_Creacion.h \
    Ventana_SumarAcciones.h \
    funcionesArchivos.h \
    mainwindow.h

FORMS += \
    Ventana_Arbol.ui \
    Ventana_Arbol_Leaves.ui \
    Ventana_Condenacion.ui \
    Ventana_Consultas_Acciones.ui \
    Ventana_Creacion.ui \
    Ventana_SumarAcciones.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Imagenes.qrc

DISTFILES +=
