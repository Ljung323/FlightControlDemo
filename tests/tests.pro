QT += quick testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TARGET = FlightControlDemoUnitTest

TEMPLATE = app

SOURCES += \
        sources/FlightPresenterTest.cpp \
        ../sources/Flight/Domain/ChangeAltitudeUsecase.cpp \
        ../sources/Flight/Domain/ConnectionUsecase.cpp \
        ../sources/Flight/Domain/HorizontalMoveUsecase.cpp \
        ../sources/Flight/Domain/LandUsecase.cpp \
        ../sources/Flight/Domain/Position.cpp \
        ../sources/Flight/Domain/TakeoffUsecase.cpp \
        ../sources/Flight/Presentation/DriverProtocol/AircraftInfoDriverProtocol.cpp \
        ../sources/Flight/Presentation/DriverProtocol/ChangeAltitudeDriverProtocol.cpp \
        ../sources/Flight/Presentation/DriverProtocol/ConnectionDriverProtocol.cpp \
        ../sources/Flight/Presentation/DriverProtocol/HorizontalMoveDriverProtocol.cpp \
        ../sources/Flight/Presentation/DriverProtocol/LandDriverProtocol.cpp \
        ../sources/Flight/Presentation/DriverProtocol/TakeoffDriverProtocol.cpp \
        ../sources/Flight/Presentation/Presenter/FlightPresenter.cpp \
        ../sources/Flight/Presentation/Presenter/HomePresenter.cpp

HEADERS += \
    sources/FlightPresenterTest.h \
    ../sources/Flight/Domain/ChangeAltitudeUsecase.h \
    ../sources/Flight/Domain/ConnectionUsecase.h \
    ../sources/Flight/Domain/FlightAction.h \
    ../sources/Flight/Domain/FlightInfo.h \
    ../sources/Flight/Domain/HorizontalMoveUsecase.h \
    ../sources/Flight/Domain/LandUsecase.h \
    ../sources/Flight/Domain/Position.h \
    ../sources/Flight/Domain/TakeoffUsecase.h \
    ../sources/Flight/Presentation/DriverProtocol/AircraftInfoDriverProtocol.h \
    ../sources/Flight/Presentation/DriverProtocol/ChangeAltitudeDriverProtocol.h \
    ../sources/Flight/Presentation/DriverProtocol/ConnectionDriverProtocol.h \
    ../sources/Flight/Presentation/DriverProtocol/HorizontalMoveDriverProtocol.h \
    ../sources/Flight/Presentation/DriverProtocol/LandDriverProtocol.h \
    ../sources/Flight/Presentation/DriverProtocol/TakeoffDriverProtocol.h \
    ../sources/Flight/Presentation/Presenter/FlightPresenter.h \
    ../sources/Flight/Presentation/Presenter/HomePresenter.h

INCLUDEPATH += \
    ../sources
