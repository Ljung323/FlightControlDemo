QT += quick

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        sources/Flight/Domain/AircraftInfoUsecase.cpp \
        sources/Flight/Domain/ChangeAltitudeUsecase.cpp \
        sources/Flight/Domain/ConnectionUsecase.cpp \
        sources/Flight/Domain/HorizontalMoveUsecase.cpp \
        sources/Flight/Domain/LandUsecase.cpp \
        sources/Flight/Domain/TakeoffUsecase.cpp \
        sources/Flight/Framework/AirfractInfoDriver.cpp \
        sources/Flight/Framework/ChangeAltitudeDriver.cpp \
        sources/Flight/Framework/ConnectionDriver.cpp \
        sources/Flight/Framework/HorizontalMoveDriver.cpp \
        sources/Flight/Framework/LandDriver.cpp \
        sources/Flight/Framework/TakeoffDriver.cpp \
        sources/Flight/Presentation/DriverProtocol/AirfractInfoDriverProtocol.cpp \
        sources/Flight/Presentation/DriverProtocol/ChangeAltitudeDriverProtocol.cpp \
        sources/Flight/Presentation/DriverProtocol/ConnectionDriverProtocol.cpp \
        sources/Flight/Presentation/DriverProtocol/HorizontalMoveDriverProtocol.cpp \
        sources/Flight/Presentation/DriverProtocol/LandDriverProtocol.cpp \
        sources/Flight/Presentation/DriverProtocol/TakeoffDriverProtocol.cpp \
        sources/Flight/Presentation/Presenter/FlightPresenter.cpp \
        sources/Flight/Presentation/Presenter/HomePresenter.cpp \
        sources/main.cpp

RESOURCES += resources/qml/qml.qrc \
    resources/images/image.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    sources/Flight/Domain/AircraftInfoUsecase.h \
    sources/Flight/Domain/ChangeAltitudeUsecase.h \
    sources/Flight/Domain/ConnectionUsecase.h \
    sources/Flight/Domain/HorizontalMoveUsecase.h \
    sources/Flight/Domain/LandUsecase.h \
    sources/Flight/Domain/TakeoffUsecase.h \
    sources/Flight/Framework/AirfractInfoDriver.h \
    sources/Flight/Framework/ChangeAltitudeDriver.h \
    sources/Flight/Framework/ConnectionDriver.h \
    sources/Flight/Framework/HorizontalMoveDriver.h \
    sources/Flight/Framework/LandDriver.h \
    sources/Flight/Framework/TakeoffDriver.h \
    sources/Flight/Presentation/DriverProtocol/AirfractInfoDriverProtocol.h \
    sources/Flight/Presentation/DriverProtocol/ChangeAltitudeDriverProtocol.h \
    sources/Flight/Presentation/DriverProtocol/ConnectionDriverProtocol.h \
    sources/Flight/Presentation/DriverProtocol/HorizontalMoveDriverProtocol.h \
    sources/Flight/Presentation/DriverProtocol/LandDriverProtocol.h \
    sources/Flight/Presentation/DriverProtocol/TakeoffDriverProtocol.h \
    sources/Flight/Presentation/Presenter/FlightPresenter.h \
    sources/Flight/Presentation/Presenter/HomePresenter.h

LIBS += /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_action.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_calibration.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_camera.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_failure.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_follow_me.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_ftp.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_geofence.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_gimbal.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_info.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_log_files.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_manual_control.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_mavlink_passthrough.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_mission_raw.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_mission.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_mocap.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_offboard.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_param.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_server_utility.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_server.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_shell.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_telemetry.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_tracking_server.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_transponder.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk_tune.0.39.0.dylib \
    /usr/local/Cellar/mavsdk/0.39.0/lib/libmavsdk.0.39.0.dylib

INCLUDEPATH += $$PWD/../../../usr/local/Cellar/mavsdk/0.39.0/include
DEPENDPATH += $$PWD/../../../usr/local/Cellar/mavsdk/0.39.0/include
