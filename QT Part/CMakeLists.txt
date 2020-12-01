cmake_minimum_required(VERSION 3.5)

project(StatisticsOfElectronicHoles LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(SRC ../SiliconCore/gnuplot.h ../SiliconCore/statisticsInSilicon.cpp ../SiliconCore/vemath.cpp ../SiliconCore/vemath.h)
#add_library(Vectozavr ${SRC})

add_executable(StatisticsOfElectronicHoles
    main.cpp
    application.cpp
    application.h
    application.ui
    graphics.qrc
    adapterforvectozavr.cpp
    adapterforvectozavr.h
  )

target_link_libraries(StatisticsOfElectronicHoles PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
