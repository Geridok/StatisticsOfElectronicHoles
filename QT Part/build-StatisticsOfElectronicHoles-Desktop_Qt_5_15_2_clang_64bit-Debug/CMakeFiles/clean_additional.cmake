# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/StatisticsOfElectronicHoles_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/StatisticsOfElectronicHoles_autogen.dir/ParseCache.txt"
  "StatisticsOfElectronicHoles_autogen"
  )
endif()
