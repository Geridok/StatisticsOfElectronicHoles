# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ivanilin/CLionProjects/SiliconCore

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ivanilin/CLionProjects/SiliconCore/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SiliconCore.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SiliconCore.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SiliconCore.dir/flags.make

CMakeFiles/SiliconCore.dir/main.cpp.o: CMakeFiles/SiliconCore.dir/flags.make
CMakeFiles/SiliconCore.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivanilin/CLionProjects/SiliconCore/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SiliconCore.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SiliconCore.dir/main.cpp.o -c /Users/ivanilin/CLionProjects/SiliconCore/main.cpp

CMakeFiles/SiliconCore.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SiliconCore.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivanilin/CLionProjects/SiliconCore/main.cpp > CMakeFiles/SiliconCore.dir/main.cpp.i

CMakeFiles/SiliconCore.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SiliconCore.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivanilin/CLionProjects/SiliconCore/main.cpp -o CMakeFiles/SiliconCore.dir/main.cpp.s

CMakeFiles/SiliconCore.dir/Silicon.cpp.o: CMakeFiles/SiliconCore.dir/flags.make
CMakeFiles/SiliconCore.dir/Silicon.cpp.o: ../Silicon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ivanilin/CLionProjects/SiliconCore/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SiliconCore.dir/Silicon.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SiliconCore.dir/Silicon.cpp.o -c /Users/ivanilin/CLionProjects/SiliconCore/Silicon.cpp

CMakeFiles/SiliconCore.dir/Silicon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SiliconCore.dir/Silicon.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ivanilin/CLionProjects/SiliconCore/Silicon.cpp > CMakeFiles/SiliconCore.dir/Silicon.cpp.i

CMakeFiles/SiliconCore.dir/Silicon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SiliconCore.dir/Silicon.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ivanilin/CLionProjects/SiliconCore/Silicon.cpp -o CMakeFiles/SiliconCore.dir/Silicon.cpp.s

# Object files for target SiliconCore
SiliconCore_OBJECTS = \
"CMakeFiles/SiliconCore.dir/main.cpp.o" \
"CMakeFiles/SiliconCore.dir/Silicon.cpp.o"

# External object files for target SiliconCore
SiliconCore_EXTERNAL_OBJECTS =

SiliconCore: CMakeFiles/SiliconCore.dir/main.cpp.o
SiliconCore: CMakeFiles/SiliconCore.dir/Silicon.cpp.o
SiliconCore: CMakeFiles/SiliconCore.dir/build.make
SiliconCore: libvemath.dylib
SiliconCore: CMakeFiles/SiliconCore.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ivanilin/CLionProjects/SiliconCore/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable SiliconCore"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SiliconCore.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SiliconCore.dir/build: SiliconCore

.PHONY : CMakeFiles/SiliconCore.dir/build

CMakeFiles/SiliconCore.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SiliconCore.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SiliconCore.dir/clean

CMakeFiles/SiliconCore.dir/depend:
	cd /Users/ivanilin/CLionProjects/SiliconCore/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ivanilin/CLionProjects/SiliconCore /Users/ivanilin/CLionProjects/SiliconCore /Users/ivanilin/CLionProjects/SiliconCore/cmake-build-debug /Users/ivanilin/CLionProjects/SiliconCore/cmake-build-debug /Users/ivanilin/CLionProjects/SiliconCore/cmake-build-debug/CMakeFiles/SiliconCore.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SiliconCore.dir/depend

