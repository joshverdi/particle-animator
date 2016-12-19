#-------------------------------------------------
#
# Project created by QtCreator 2016-10-28T08:51:58
#
#-------------------------------------------------

QT       += core widgets
QT       *= xml opengl
QT       -= gui

TARGET = raw
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app
LIBS *= -lglut -lGLU

CONFIG(debug, debug|release){LIBS *= -L/usr/lib -lQGLViewer}
else  {LIBS *= -L/usr/lib -lQGLViewer}

SOURCES += main.cpp \
    viewer.cpp \
    ioraw.cpp \
    utils.cpp \
    CGLA/Vec3i.cpp \
    CGLA/Vec3f.cpp \
    CGLA/Vec2i.cpp \
    CGLA/Vec2f.cpp \
    CGLA/TableTrigonometry.cpp \
    CGLA/Quaternion.cpp \
    CGLA/Mat4x4f.cpp \
    CGLA/Mat3x3f.cpp \
    CGLA/Mat2x2f.cpp \
    particle.cpp

HEADERS += \
    viewer.h \
    ioraw.h \
    utils.h \
    main.h \
    CGLA/ArgExtracter.h \
    CGLA/Vec4uc.h \
    CGLA/Vec4f.h \
    CGLA/Vec3usi.h \
    CGLA/Vec3uc.h \
    CGLA/Vec3i.h \
    CGLA/Vec3f.h \
    CGLA/Vec3d.h \
    CGLA/Vec3Hf.h \
    CGLA/Vec2i.h \
    CGLA/Vec2f.h \
    CGLA/Vec1f.h \
    CGLA/UnitVector.h \
    CGLA/TableTrigonometry.h \
    CGLA/RootSolvers.h \
    CGLA/Quaternion.h \
    CGLA/Mat4x4f.h \
    CGLA/Mat3x4f.h \
    CGLA/Mat3x3f.h \
    CGLA/Mat2x3f.h \
    CGLA/Mat2x2f.h \
    CGLA/Mat1x4f.h \
    CGLA/Mat1x3f.h \
    CGLA/Map.h \
    CGLA/Filter.h \
    CGLA/ExceptionStandard.h \
    CGLA/CommonDefs.h \
    CGLA/CGLA.h \
    CGLA/BitMask.h \
    CGLA/ArithVec.h \
    CGLA/ArithSqMat.h \
    CGLA/ArithMat.h \
    particle.h
