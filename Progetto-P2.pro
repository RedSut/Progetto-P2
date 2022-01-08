QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/Model/classi/dispersione.cpp \
    src/Model/classi/graficoPianoCartesiano.cpp \
    src/Model/classi/graficoSemplice.cpp \
    src/Model/classi/istogramma.cpp \
    src/Model/classi/linea.cpp \
    src/Model/classi/torta.cpp \
    src/main.cpp \
    src/Model/classi/barre.cpp \
    src/Model/classi/dispersione.cpp \
    src/Model/classi/grafico.cpp \
    src/Model/classi/graficoComplesso.cpp \
    src/Model/classi/graficoPianoCartesiano.cpp \
    src/Model/classi/graficoSemplice.cpp \
    src/Model/classi/istogramma.cpp \
    src/Model/classi/linea.cpp \
    src/Model/classi/torta.cpp \
    src/main.cpp

HEADERS += \
    src/Model/classi/dispersione.h \
    src/Model/classi/grafico.h \
    src/Model/classi/graficoPianoCartesiano.h \
    src/Model/classi/graficoSemplice.h \
    src/Model/classi/istogramma.h \
    src/Model/classi/linea.h \
    src/Model/classi/torta.h \
    src/Model/classi/barre.h \
    src/Model/classi/dispersione.h \
    src/Model/classi/grafico.h \
    src/Model/classi/graficoComplesso.h \
    src/Model/classi/graficoPianoCartesiano.h \
    src/Model/classi/graficoSemplice.h \
    src/Model/classi/istogramma.h \
    src/Model/classi/linea.h \
    src/Model/classi/torta.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    .gitignore \
    README.md
