cmake_minimum_required(VERSION 3.16)
project(SiliconCore)

set(CMAKE_CXX_STANDARD 20)

add_library(vemath SHARED vemath.h vemath.cpp)

add_executable(SiliconCore main.cpp Silicon.cpp Silicon.h)
target_link_libraries(SiliconCore vemath)