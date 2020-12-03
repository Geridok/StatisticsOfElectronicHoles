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

set(SRC ../SiliconCore/gnuplot.h ../SiliconCore/Silicon.cpp ../SiliconCore/Silicon.h ../SiliconCore/vemath.cpp ../SiliconCore/vemath.h ../SiliconCore/vemath.cpp)
add_library(Vectozavr ${SRC})

add_executable(StatisticsOfElectronicHoles
    main.cpp
    application.cpp
    application.h
    application.ui
    adapterforvectozavr.cpp
    adapterforvectozavr.h
    qcustomplot.cpp
    qcustomplot.h
  )

target_link_libraries(StatisticsOfElectronicHoles PRIVATE Vectozavr Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::PrintSupport)
