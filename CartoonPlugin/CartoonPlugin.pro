######################################################################
# Automatically generated by qmake (3.1) Tue Jul 26 20:25:11 2022
######################################################################

TEMPLATE = lib
TARGET = CartoonPlugin
CONFIG += plugin
INCLUDEPATH += . ../ImageEditor

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += cartoon_plugin.h
SOURCES += cartoon_plugin.cpp

unix: !mac {
    INCLUDEPATH += /usr/include/opencv4
    LIBS += -L/usr/include/opencv/lib -lopencv_core -l opencv_imgproc
}
