# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/parallels/WORK/ASVK4/GeneticAlgTask

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/parallels/WORK/ASVK4/GeneticAlgTask/build

# Include any dependencies generated for this target.
include CMakeFiles/Genetic_Algorithm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Genetic_Algorithm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Genetic_Algorithm.dir/flags.make

CMakeFiles/Genetic_Algorithm.dir/main.cpp.o: CMakeFiles/Genetic_Algorithm.dir/flags.make
CMakeFiles/Genetic_Algorithm.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/WORK/ASVK4/GeneticAlgTask/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Genetic_Algorithm.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Genetic_Algorithm.dir/main.cpp.o -c /home/parallels/WORK/ASVK4/GeneticAlgTask/main.cpp

CMakeFiles/Genetic_Algorithm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Genetic_Algorithm.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/WORK/ASVK4/GeneticAlgTask/main.cpp > CMakeFiles/Genetic_Algorithm.dir/main.cpp.i

CMakeFiles/Genetic_Algorithm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Genetic_Algorithm.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/WORK/ASVK4/GeneticAlgTask/main.cpp -o CMakeFiles/Genetic_Algorithm.dir/main.cpp.s

CMakeFiles/Genetic_Algorithm.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Genetic_Algorithm.dir/main.cpp.o.requires

CMakeFiles/Genetic_Algorithm.dir/main.cpp.o.provides: CMakeFiles/Genetic_Algorithm.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Genetic_Algorithm.dir/build.make CMakeFiles/Genetic_Algorithm.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Genetic_Algorithm.dir/main.cpp.o.provides

CMakeFiles/Genetic_Algorithm.dir/main.cpp.o.provides.build: CMakeFiles/Genetic_Algorithm.dir/main.cpp.o


CMakeFiles/Genetic_Algorithm.dir/Genetic.cpp.o: CMakeFiles/Genetic_Algorithm.dir/flags.make
CMakeFiles/Genetic_Algorithm.dir/Genetic.cpp.o: ../Genetic.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/WORK/ASVK4/GeneticAlgTask/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Genetic_Algorithm.dir/Genetic.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Genetic_Algorithm.dir/Genetic.cpp.o -c /home/parallels/WORK/ASVK4/GeneticAlgTask/Genetic.cpp

CMakeFiles/Genetic_Algorithm.dir/Genetic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Genetic_Algorithm.dir/Genetic.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/WORK/ASVK4/GeneticAlgTask/Genetic.cpp > CMakeFiles/Genetic_Algorithm.dir/Genetic.cpp.i

CMakeFiles/Genetic_Algorithm.dir/Genetic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Genetic_Algorithm.dir/Genetic.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/WORK/ASVK4/GeneticAlgTask/Genetic.cpp -o CMakeFiles/Genetic_Algorithm.dir/Genetic.cpp.s

CMakeFiles/Genetic_Algorithm.dir/Genetic.cpp.o.requires:

.PHONY : CMakeFiles/Genetic_Algorithm.dir/Genetic.cpp.o.requires

CMakeFiles/Genetic_Algorithm.dir/Genetic.cpp.o.provides: CMakeFiles/Genetic_Algorithm.dir/Genetic.cpp.o.requires
	$(MAKE) -f CMakeFiles/Genetic_Algorithm.dir/build.make CMakeFiles/Genetic_Algorithm.dir/Genetic.cpp.o.provides.build
.PHONY : CMakeFiles/Genetic_Algorithm.dir/Genetic.cpp.o.provides

CMakeFiles/Genetic_Algorithm.dir/Genetic.cpp.o.provides.build: CMakeFiles/Genetic_Algorithm.dir/Genetic.cpp.o


CMakeFiles/Genetic_Algorithm.dir/MainCycle.cpp.o: CMakeFiles/Genetic_Algorithm.dir/flags.make
CMakeFiles/Genetic_Algorithm.dir/MainCycle.cpp.o: ../MainCycle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/parallels/WORK/ASVK4/GeneticAlgTask/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Genetic_Algorithm.dir/MainCycle.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Genetic_Algorithm.dir/MainCycle.cpp.o -c /home/parallels/WORK/ASVK4/GeneticAlgTask/MainCycle.cpp

CMakeFiles/Genetic_Algorithm.dir/MainCycle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Genetic_Algorithm.dir/MainCycle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/parallels/WORK/ASVK4/GeneticAlgTask/MainCycle.cpp > CMakeFiles/Genetic_Algorithm.dir/MainCycle.cpp.i

CMakeFiles/Genetic_Algorithm.dir/MainCycle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Genetic_Algorithm.dir/MainCycle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/parallels/WORK/ASVK4/GeneticAlgTask/MainCycle.cpp -o CMakeFiles/Genetic_Algorithm.dir/MainCycle.cpp.s

CMakeFiles/Genetic_Algorithm.dir/MainCycle.cpp.o.requires:

.PHONY : CMakeFiles/Genetic_Algorithm.dir/MainCycle.cpp.o.requires

CMakeFiles/Genetic_Algorithm.dir/MainCycle.cpp.o.provides: CMakeFiles/Genetic_Algorithm.dir/MainCycle.cpp.o.requires
	$(MAKE) -f CMakeFiles/Genetic_Algorithm.dir/build.make CMakeFiles/Genetic_Algorithm.dir/MainCycle.cpp.o.provides.build
.PHONY : CMakeFiles/Genetic_Algorithm.dir/MainCycle.cpp.o.provides

CMakeFiles/Genetic_Algorithm.dir/MainCycle.cpp.o.provides.build: CMakeFiles/Genetic_Algorithm.dir/MainCycle.cpp.o


# Object files for target Genetic_Algorithm
Genetic_Algorithm_OBJECTS = \
"CMakeFiles/Genetic_Algorithm.dir/main.cpp.o" \
"CMakeFiles/Genetic_Algorithm.dir/Genetic.cpp.o" \
"CMakeFiles/Genetic_Algorithm.dir/MainCycle.cpp.o"

# External object files for target Genetic_Algorithm
Genetic_Algorithm_EXTERNAL_OBJECTS =

Genetic_Algorithm: CMakeFiles/Genetic_Algorithm.dir/main.cpp.o
Genetic_Algorithm: CMakeFiles/Genetic_Algorithm.dir/Genetic.cpp.o
Genetic_Algorithm: CMakeFiles/Genetic_Algorithm.dir/MainCycle.cpp.o
Genetic_Algorithm: CMakeFiles/Genetic_Algorithm.dir/build.make
Genetic_Algorithm: CMakeFiles/Genetic_Algorithm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/parallels/WORK/ASVK4/GeneticAlgTask/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Genetic_Algorithm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Genetic_Algorithm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Genetic_Algorithm.dir/build: Genetic_Algorithm

.PHONY : CMakeFiles/Genetic_Algorithm.dir/build

CMakeFiles/Genetic_Algorithm.dir/requires: CMakeFiles/Genetic_Algorithm.dir/main.cpp.o.requires
CMakeFiles/Genetic_Algorithm.dir/requires: CMakeFiles/Genetic_Algorithm.dir/Genetic.cpp.o.requires
CMakeFiles/Genetic_Algorithm.dir/requires: CMakeFiles/Genetic_Algorithm.dir/MainCycle.cpp.o.requires

.PHONY : CMakeFiles/Genetic_Algorithm.dir/requires

CMakeFiles/Genetic_Algorithm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Genetic_Algorithm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Genetic_Algorithm.dir/clean

CMakeFiles/Genetic_Algorithm.dir/depend:
	cd /home/parallels/WORK/ASVK4/GeneticAlgTask/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/parallels/WORK/ASVK4/GeneticAlgTask /home/parallels/WORK/ASVK4/GeneticAlgTask /home/parallels/WORK/ASVK4/GeneticAlgTask/build /home/parallels/WORK/ASVK4/GeneticAlgTask/build /home/parallels/WORK/ASVK4/GeneticAlgTask/build/CMakeFiles/Genetic_Algorithm.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Genetic_Algorithm.dir/depend

