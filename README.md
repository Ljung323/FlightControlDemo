# FlightControlDemo
demo application for flight control with MAVSDK

## Demo
Tested with PX4 SITL for Gazebo on macOS Catalina v10.15.4  
(horizontal move is executed by double click)  

https://user-images.githubusercontent.com/82586164/115368269-e2e11180-a201-11eb-83e1-2d4f1adf9fc9.mp4

## Features
- Takeoff
- Move horizontally
- Change altitude
- Land
- Show aircaft information

## Requirement
- [MAVSDK](https://mavsdk.mavlink.io/develop/en/getting_started/installation.html)

## Architecture
This project respects Clean Architecture.  

#### Domain Layer
This layer includes domain objects and usecases.  
Usecases define the set of UAV actions.

#### Presentation Layer
This layer includes presenters and interfaces for drivers.

#### Framework Layer
Since the view is written as qml resources, this layer includes drivers for UAV control.  
Drivers provide the concrete codes with a certain type of API(ex. MAVSDK, MAVLINK).

## TODO
- [ ] adding test
- [ ] refactoring
