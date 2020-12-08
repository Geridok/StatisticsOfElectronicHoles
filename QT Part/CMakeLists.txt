cmake_minimum_required(VERSION 3.5)

project(StatisticsOfElectronicHoles LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)


set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets  PrintSupport REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets PrintSupport REQUIRED)

set(SRC ../SiliconCore/Silicon.cpp ../SiliconCore/Silicon.h ../Time/Time.h ../Time/Time.cpp ../SiliconCore/FermiDirac.cpp ../SiliconCore/FermiDirac.h)
add_library(Vectozavr ${SRC})

add_executable(StatisticsOfElectronicHoles
    main.cpp
    application.cpp
    application.h
    application.ui
    qcustomplot.cpp
    qcustomplot.h
    qcpdocumentobject.cpp
    qcpdocumentobject.h
    Icons.qrc
    savewindow.cpp
    savewindow.h
    savewindow.ui
    information.cpp
    information.h
    information.ui
  )

target_link_libraries(StatisticsOfElectronicHoles PRIVATE Vectozavr Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::PrintSupport)
