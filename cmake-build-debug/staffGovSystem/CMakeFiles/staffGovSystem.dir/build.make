# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /snap/clion/138/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/138/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tangkun/github/cppStudy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tangkun/github/cppStudy/cmake-build-debug

# Include any dependencies generated for this target.
include staffGovSystem/CMakeFiles/staffGovSystem.dir/depend.make

# Include the progress variables for this target.
include staffGovSystem/CMakeFiles/staffGovSystem.dir/progress.make

# Include the compile flags for this target's objects.
include staffGovSystem/CMakeFiles/staffGovSystem.dir/flags.make

staffGovSystem/CMakeFiles/staffGovSystem.dir/source/main.cpp.o: staffGovSystem/CMakeFiles/staffGovSystem.dir/flags.make
staffGovSystem/CMakeFiles/staffGovSystem.dir/source/main.cpp.o: ../staffGovSystem/source/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tangkun/github/cppStudy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object staffGovSystem/CMakeFiles/staffGovSystem.dir/source/main.cpp.o"
	cd /home/tangkun/github/cppStudy/cmake-build-debug/staffGovSystem && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/staffGovSystem.dir/source/main.cpp.o -c /home/tangkun/github/cppStudy/staffGovSystem/source/main.cpp

staffGovSystem/CMakeFiles/staffGovSystem.dir/source/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/staffGovSystem.dir/source/main.cpp.i"
	cd /home/tangkun/github/cppStudy/cmake-build-debug/staffGovSystem && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tangkun/github/cppStudy/staffGovSystem/source/main.cpp > CMakeFiles/staffGovSystem.dir/source/main.cpp.i

staffGovSystem/CMakeFiles/staffGovSystem.dir/source/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/staffGovSystem.dir/source/main.cpp.s"
	cd /home/tangkun/github/cppStudy/cmake-build-debug/staffGovSystem && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tangkun/github/cppStudy/staffGovSystem/source/main.cpp -o CMakeFiles/staffGovSystem.dir/source/main.cpp.s

staffGovSystem/CMakeFiles/staffGovSystem.dir/source/workerManager.cpp.o: staffGovSystem/CMakeFiles/staffGovSystem.dir/flags.make
staffGovSystem/CMakeFiles/staffGovSystem.dir/source/workerManager.cpp.o: ../staffGovSystem/source/workerManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tangkun/github/cppStudy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object staffGovSystem/CMakeFiles/staffGovSystem.dir/source/workerManager.cpp.o"
	cd /home/tangkun/github/cppStudy/cmake-build-debug/staffGovSystem && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/staffGovSystem.dir/source/workerManager.cpp.o -c /home/tangkun/github/cppStudy/staffGovSystem/source/workerManager.cpp

staffGovSystem/CMakeFiles/staffGovSystem.dir/source/workerManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/staffGovSystem.dir/source/workerManager.cpp.i"
	cd /home/tangkun/github/cppStudy/cmake-build-debug/staffGovSystem && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tangkun/github/cppStudy/staffGovSystem/source/workerManager.cpp > CMakeFiles/staffGovSystem.dir/source/workerManager.cpp.i

staffGovSystem/CMakeFiles/staffGovSystem.dir/source/workerManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/staffGovSystem.dir/source/workerManager.cpp.s"
	cd /home/tangkun/github/cppStudy/cmake-build-debug/staffGovSystem && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tangkun/github/cppStudy/staffGovSystem/source/workerManager.cpp -o CMakeFiles/staffGovSystem.dir/source/workerManager.cpp.s

staffGovSystem/CMakeFiles/staffGovSystem.dir/source/worker.cpp.o: staffGovSystem/CMakeFiles/staffGovSystem.dir/flags.make
staffGovSystem/CMakeFiles/staffGovSystem.dir/source/worker.cpp.o: ../staffGovSystem/source/worker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tangkun/github/cppStudy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object staffGovSystem/CMakeFiles/staffGovSystem.dir/source/worker.cpp.o"
	cd /home/tangkun/github/cppStudy/cmake-build-debug/staffGovSystem && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/staffGovSystem.dir/source/worker.cpp.o -c /home/tangkun/github/cppStudy/staffGovSystem/source/worker.cpp

staffGovSystem/CMakeFiles/staffGovSystem.dir/source/worker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/staffGovSystem.dir/source/worker.cpp.i"
	cd /home/tangkun/github/cppStudy/cmake-build-debug/staffGovSystem && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tangkun/github/cppStudy/staffGovSystem/source/worker.cpp > CMakeFiles/staffGovSystem.dir/source/worker.cpp.i

staffGovSystem/CMakeFiles/staffGovSystem.dir/source/worker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/staffGovSystem.dir/source/worker.cpp.s"
	cd /home/tangkun/github/cppStudy/cmake-build-debug/staffGovSystem && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tangkun/github/cppStudy/staffGovSystem/source/worker.cpp -o CMakeFiles/staffGovSystem.dir/source/worker.cpp.s

staffGovSystem/CMakeFiles/staffGovSystem.dir/source/employee.cpp.o: staffGovSystem/CMakeFiles/staffGovSystem.dir/flags.make
staffGovSystem/CMakeFiles/staffGovSystem.dir/source/employee.cpp.o: ../staffGovSystem/source/employee.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tangkun/github/cppStudy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object staffGovSystem/CMakeFiles/staffGovSystem.dir/source/employee.cpp.o"
	cd /home/tangkun/github/cppStudy/cmake-build-debug/staffGovSystem && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/staffGovSystem.dir/source/employee.cpp.o -c /home/tangkun/github/cppStudy/staffGovSystem/source/employee.cpp

staffGovSystem/CMakeFiles/staffGovSystem.dir/source/employee.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/staffGovSystem.dir/source/employee.cpp.i"
	cd /home/tangkun/github/cppStudy/cmake-build-debug/staffGovSystem && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tangkun/github/cppStudy/staffGovSystem/source/employee.cpp > CMakeFiles/staffGovSystem.dir/source/employee.cpp.i

staffGovSystem/CMakeFiles/staffGovSystem.dir/source/employee.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/staffGovSystem.dir/source/employee.cpp.s"
	cd /home/tangkun/github/cppStudy/cmake-build-debug/staffGovSystem && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tangkun/github/cppStudy/staffGovSystem/source/employee.cpp -o CMakeFiles/staffGovSystem.dir/source/employee.cpp.s

staffGovSystem/CMakeFiles/staffGovSystem.dir/source/boss.cpp.o: staffGovSystem/CMakeFiles/staffGovSystem.dir/flags.make
staffGovSystem/CMakeFiles/staffGovSystem.dir/source/boss.cpp.o: ../staffGovSystem/source/boss.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tangkun/github/cppStudy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object staffGovSystem/CMakeFiles/staffGovSystem.dir/source/boss.cpp.o"
	cd /home/tangkun/github/cppStudy/cmake-build-debug/staffGovSystem && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/staffGovSystem.dir/source/boss.cpp.o -c /home/tangkun/github/cppStudy/staffGovSystem/source/boss.cpp

staffGovSystem/CMakeFiles/staffGovSystem.dir/source/boss.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/staffGovSystem.dir/source/boss.cpp.i"
	cd /home/tangkun/github/cppStudy/cmake-build-debug/staffGovSystem && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tangkun/github/cppStudy/staffGovSystem/source/boss.cpp > CMakeFiles/staffGovSystem.dir/source/boss.cpp.i

staffGovSystem/CMakeFiles/staffGovSystem.dir/source/boss.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/staffGovSystem.dir/source/boss.cpp.s"
	cd /home/tangkun/github/cppStudy/cmake-build-debug/staffGovSystem && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tangkun/github/cppStudy/staffGovSystem/source/boss.cpp -o CMakeFiles/staffGovSystem.dir/source/boss.cpp.s

staffGovSystem/CMakeFiles/staffGovSystem.dir/source/manager.cpp.o: staffGovSystem/CMakeFiles/staffGovSystem.dir/flags.make
staffGovSystem/CMakeFiles/staffGovSystem.dir/source/manager.cpp.o: ../staffGovSystem/source/manager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tangkun/github/cppStudy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object staffGovSystem/CMakeFiles/staffGovSystem.dir/source/manager.cpp.o"
	cd /home/tangkun/github/cppStudy/cmake-build-debug/staffGovSystem && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/staffGovSystem.dir/source/manager.cpp.o -c /home/tangkun/github/cppStudy/staffGovSystem/source/manager.cpp

staffGovSystem/CMakeFiles/staffGovSystem.dir/source/manager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/staffGovSystem.dir/source/manager.cpp.i"
	cd /home/tangkun/github/cppStudy/cmake-build-debug/staffGovSystem && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tangkun/github/cppStudy/staffGovSystem/source/manager.cpp > CMakeFiles/staffGovSystem.dir/source/manager.cpp.i

staffGovSystem/CMakeFiles/staffGovSystem.dir/source/manager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/staffGovSystem.dir/source/manager.cpp.s"
	cd /home/tangkun/github/cppStudy/cmake-build-debug/staffGovSystem && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tangkun/github/cppStudy/staffGovSystem/source/manager.cpp -o CMakeFiles/staffGovSystem.dir/source/manager.cpp.s

# Object files for target staffGovSystem
staffGovSystem_OBJECTS = \
"CMakeFiles/staffGovSystem.dir/source/main.cpp.o" \
"CMakeFiles/staffGovSystem.dir/source/workerManager.cpp.o" \
"CMakeFiles/staffGovSystem.dir/source/worker.cpp.o" \
"CMakeFiles/staffGovSystem.dir/source/employee.cpp.o" \
"CMakeFiles/staffGovSystem.dir/source/boss.cpp.o" \
"CMakeFiles/staffGovSystem.dir/source/manager.cpp.o"

# External object files for target staffGovSystem
staffGovSystem_EXTERNAL_OBJECTS =

staffGovSystem/staffGovSystem: staffGovSystem/CMakeFiles/staffGovSystem.dir/source/main.cpp.o
staffGovSystem/staffGovSystem: staffGovSystem/CMakeFiles/staffGovSystem.dir/source/workerManager.cpp.o
staffGovSystem/staffGovSystem: staffGovSystem/CMakeFiles/staffGovSystem.dir/source/worker.cpp.o
staffGovSystem/staffGovSystem: staffGovSystem/CMakeFiles/staffGovSystem.dir/source/employee.cpp.o
staffGovSystem/staffGovSystem: staffGovSystem/CMakeFiles/staffGovSystem.dir/source/boss.cpp.o
staffGovSystem/staffGovSystem: staffGovSystem/CMakeFiles/staffGovSystem.dir/source/manager.cpp.o
staffGovSystem/staffGovSystem: staffGovSystem/CMakeFiles/staffGovSystem.dir/build.make
staffGovSystem/staffGovSystem: staffGovSystem/CMakeFiles/staffGovSystem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tangkun/github/cppStudy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable staffGovSystem"
	cd /home/tangkun/github/cppStudy/cmake-build-debug/staffGovSystem && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/staffGovSystem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
staffGovSystem/CMakeFiles/staffGovSystem.dir/build: staffGovSystem/staffGovSystem

.PHONY : staffGovSystem/CMakeFiles/staffGovSystem.dir/build

staffGovSystem/CMakeFiles/staffGovSystem.dir/clean:
	cd /home/tangkun/github/cppStudy/cmake-build-debug/staffGovSystem && $(CMAKE_COMMAND) -P CMakeFiles/staffGovSystem.dir/cmake_clean.cmake
.PHONY : staffGovSystem/CMakeFiles/staffGovSystem.dir/clean

staffGovSystem/CMakeFiles/staffGovSystem.dir/depend:
	cd /home/tangkun/github/cppStudy/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tangkun/github/cppStudy /home/tangkun/github/cppStudy/staffGovSystem /home/tangkun/github/cppStudy/cmake-build-debug /home/tangkun/github/cppStudy/cmake-build-debug/staffGovSystem /home/tangkun/github/cppStudy/cmake-build-debug/staffGovSystem/CMakeFiles/staffGovSystem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : staffGovSystem/CMakeFiles/staffGovSystem.dir/depend

