# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/franspaco/programs/clion-2016.3.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/franspaco/programs/clion-2016.3.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/franspaco/Documents/Tec/Sem4/Sistemas/TC2004Class/Entregas/Evaluacion1 - Correcciones"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/franspaco/Documents/Tec/Sem4/Sistemas/TC2004Class/Entregas/Evaluacion1 - Correcciones/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/PrimerParcial.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PrimerParcial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PrimerParcial.dir/flags.make

CMakeFiles/PrimerParcial.dir/main.cpp.o: CMakeFiles/PrimerParcial.dir/flags.make
CMakeFiles/PrimerParcial.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/franspaco/Documents/Tec/Sem4/Sistemas/TC2004Class/Entregas/Evaluacion1 - Correcciones/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PrimerParcial.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PrimerParcial.dir/main.cpp.o -c "/home/franspaco/Documents/Tec/Sem4/Sistemas/TC2004Class/Entregas/Evaluacion1 - Correcciones/main.cpp"

CMakeFiles/PrimerParcial.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PrimerParcial.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/franspaco/Documents/Tec/Sem4/Sistemas/TC2004Class/Entregas/Evaluacion1 - Correcciones/main.cpp" > CMakeFiles/PrimerParcial.dir/main.cpp.i

CMakeFiles/PrimerParcial.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PrimerParcial.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/franspaco/Documents/Tec/Sem4/Sistemas/TC2004Class/Entregas/Evaluacion1 - Correcciones/main.cpp" -o CMakeFiles/PrimerParcial.dir/main.cpp.s

CMakeFiles/PrimerParcial.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/PrimerParcial.dir/main.cpp.o.requires

CMakeFiles/PrimerParcial.dir/main.cpp.o.provides: CMakeFiles/PrimerParcial.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/PrimerParcial.dir/build.make CMakeFiles/PrimerParcial.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/PrimerParcial.dir/main.cpp.o.provides

CMakeFiles/PrimerParcial.dir/main.cpp.o.provides.build: CMakeFiles/PrimerParcial.dir/main.cpp.o


# Object files for target PrimerParcial
PrimerParcial_OBJECTS = \
"CMakeFiles/PrimerParcial.dir/main.cpp.o"

# External object files for target PrimerParcial
PrimerParcial_EXTERNAL_OBJECTS =

PrimerParcial: CMakeFiles/PrimerParcial.dir/main.cpp.o
PrimerParcial: CMakeFiles/PrimerParcial.dir/build.make
PrimerParcial: CMakeFiles/PrimerParcial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/franspaco/Documents/Tec/Sem4/Sistemas/TC2004Class/Entregas/Evaluacion1 - Correcciones/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PrimerParcial"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PrimerParcial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PrimerParcial.dir/build: PrimerParcial

.PHONY : CMakeFiles/PrimerParcial.dir/build

CMakeFiles/PrimerParcial.dir/requires: CMakeFiles/PrimerParcial.dir/main.cpp.o.requires

.PHONY : CMakeFiles/PrimerParcial.dir/requires

CMakeFiles/PrimerParcial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PrimerParcial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PrimerParcial.dir/clean

CMakeFiles/PrimerParcial.dir/depend:
	cd "/home/franspaco/Documents/Tec/Sem4/Sistemas/TC2004Class/Entregas/Evaluacion1 - Correcciones/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/franspaco/Documents/Tec/Sem4/Sistemas/TC2004Class/Entregas/Evaluacion1 - Correcciones" "/home/franspaco/Documents/Tec/Sem4/Sistemas/TC2004Class/Entregas/Evaluacion1 - Correcciones" "/home/franspaco/Documents/Tec/Sem4/Sistemas/TC2004Class/Entregas/Evaluacion1 - Correcciones/cmake-build-debug" "/home/franspaco/Documents/Tec/Sem4/Sistemas/TC2004Class/Entregas/Evaluacion1 - Correcciones/cmake-build-debug" "/home/franspaco/Documents/Tec/Sem4/Sistemas/TC2004Class/Entregas/Evaluacion1 - Correcciones/cmake-build-debug/CMakeFiles/PrimerParcial.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/PrimerParcial.dir/depend

