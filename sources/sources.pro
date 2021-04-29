QT += quick

CONFIG += c++11

TARGET = FlightControlDemo

SOURCES += \
        Flight/Domain/ChangeAltitudeUsecase.cpp \
        Flight/Domain/ConnectionUsecase.cpp \
        Flight/Domain/HorizontalMoveUsecase.cpp \
        Flight/Domain/LandUsecase.cpp \
        Flight/Domain/Position.cpp \
        Flight/Domain/TakeoffUsecase.cpp \
        Flight/Framework/AircraftInfoDriverForMAVSDK.cpp \
        Flight/Framework/ChangeAltitudeDriverForMAVSDK.cpp \
        Flight/Framework/ConnectionDriverForMAVSDK.cpp \
        Flight/Framework/HorizontalMoveDriverForMAVSDK.cpp \
        Flight/Framework/LandDriverForMAVSDK.cpp \
        Flight/Framework/TakeoffDriverForMAVSDK.cpp \
        Flight/Presentation/DriverProtocol/AircraftInfoDriverProtocol.cpp \
        Flight/Presentation/DriverProtocol/ChangeAltitudeDriverProtocol.cpp \
        Flight/Presentation/DriverProtocol/ConnectionDriverProtocol.cpp \
        Flight/Presentation/DriverProtocol/HorizontalMoveDriverProtocol.cpp \
        Flight/Presentation/DriverProtocol/LandDriverProtocol.cpp \
        Flight/Presentation/DriverProtocol/TakeoffDriverProtocol.cpp \
        Flight/Presentation/Presenter/FlightPresenter.cpp \
        Flight/Presentation/Presenter/HomePresenter.cpp \
        main.cpp

RESOURCES += ../resources/qml/qml.qrc \
    ../resources/images/image.qrc

HEADERS += \
    Flight/Domain/ChangeAltitudeUsecase.h \
    Flight/Domain/ConnectionUsecase.h \
    Flight/Domain/FlightAction.h \
    Flight/Domain/FlightInfo.h \
    Flight/Domain/HorizontalMoveUsecase.h \
    Flight/Domain/LandUsecase.h \
    Flight/Domain/Position.h \
    Flight/Domain/TakeoffUsecase.h \
    Flight/Framework/AircraftInfoDriverForMAVSDK.h \
    Flight/Framework/ChangeAltitudeDriverForMAVSDK.h \
    Flight/Framework/ConnectionDriverForMAVSDK.h \
    Flight/Framework/HorizontalMoveDriverForMAVSDK.h \
    Flight/Framework/LandDriverForMAVSDK.h \
    Flight/Framework/TakeoffDriverForMAVSDK.h \
    Flight/Presentation/DriverProtocol/AircraftInfoDriverProtocol.h \
    Flight/Presentation/DriverProtocol/ChangeAltitudeDriverProtocol.h \
    Flight/Presentation/DriverProtocol/ConnectionDriverProtocol.h \
    Flight/Presentation/DriverProtocol/HorizontalMoveDriverProtocol.h \
    Flight/Presentation/DriverProtocol/LandDriverProtocol.h \
    Flight/Presentation/DriverProtocol/TakeoffDriverProtocol.h \
    Flight/Presentation/Presenter/FlightPresenter.h \
    Flight/Presentation/Presenter/HomePresenter.h

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

INCLUDEPATH += $$PWD/../../../../usr/local/Cellar/mavsdk/0.39.0/include
DEPENDPATH += $$PWD/../../../../usr/local/Cellar/mavsdk/0.39.0/include
