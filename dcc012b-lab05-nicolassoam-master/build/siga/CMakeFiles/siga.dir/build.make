# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /ice/Downloads/cmake-3.23.1-linux-x86_64/bin/cmake

# The command to remove a file.
RM = /ice/Downloads/cmake-3.23.1-linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /ice/lab05/dcc012b-lab05-nicolassoam

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /ice/lab05/dcc012b-lab05-nicolassoam/build

# Include any dependencies generated for this target.
include siga/CMakeFiles/siga.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include siga/CMakeFiles/siga.dir/compiler_depend.make

# Include the progress variables for this target.
include siga/CMakeFiles/siga.dir/progress.make

# Include the compile flags for this target's objects.
include siga/CMakeFiles/siga.dir/flags.make

siga/CMakeFiles/siga.dir/src/estudante.cc.o: siga/CMakeFiles/siga.dir/flags.make
siga/CMakeFiles/siga.dir/src/estudante.cc.o: ../siga/src/estudante.cc
siga/CMakeFiles/siga.dir/src/estudante.cc.o: siga/CMakeFiles/siga.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/ice/lab05/dcc012b-lab05-nicolassoam/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object siga/CMakeFiles/siga.dir/src/estudante.cc.o"
	cd /ice/lab05/dcc012b-lab05-nicolassoam/build/siga && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT siga/CMakeFiles/siga.dir/src/estudante.cc.o -MF CMakeFiles/siga.dir/src/estudante.cc.o.d -o CMakeFiles/siga.dir/src/estudante.cc.o -c /ice/lab05/dcc012b-lab05-nicolassoam/siga/src/estudante.cc

siga/CMakeFiles/siga.dir/src/estudante.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/siga.dir/src/estudante.cc.i"
	cd /ice/lab05/dcc012b-lab05-nicolassoam/build/siga && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /ice/lab05/dcc012b-lab05-nicolassoam/siga/src/estudante.cc > CMakeFiles/siga.dir/src/estudante.cc.i

siga/CMakeFiles/siga.dir/src/estudante.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/siga.dir/src/estudante.cc.s"
	cd /ice/lab05/dcc012b-lab05-nicolassoam/build/siga && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /ice/lab05/dcc012b-lab05-nicolassoam/siga/src/estudante.cc -o CMakeFiles/siga.dir/src/estudante.cc.s

siga/CMakeFiles/siga.dir/src/hash.cc.o: siga/CMakeFiles/siga.dir/flags.make
siga/CMakeFiles/siga.dir/src/hash.cc.o: ../siga/src/hash.cc
siga/CMakeFiles/siga.dir/src/hash.cc.o: siga/CMakeFiles/siga.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/ice/lab05/dcc012b-lab05-nicolassoam/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object siga/CMakeFiles/siga.dir/src/hash.cc.o"
	cd /ice/lab05/dcc012b-lab05-nicolassoam/build/siga && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT siga/CMakeFiles/siga.dir/src/hash.cc.o -MF CMakeFiles/siga.dir/src/hash.cc.o.d -o CMakeFiles/siga.dir/src/hash.cc.o -c /ice/lab05/dcc012b-lab05-nicolassoam/siga/src/hash.cc

siga/CMakeFiles/siga.dir/src/hash.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/siga.dir/src/hash.cc.i"
	cd /ice/lab05/dcc012b-lab05-nicolassoam/build/siga && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /ice/lab05/dcc012b-lab05-nicolassoam/siga/src/hash.cc > CMakeFiles/siga.dir/src/hash.cc.i

siga/CMakeFiles/siga.dir/src/hash.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/siga.dir/src/hash.cc.s"
	cd /ice/lab05/dcc012b-lab05-nicolassoam/build/siga && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /ice/lab05/dcc012b-lab05-nicolassoam/siga/src/hash.cc -o CMakeFiles/siga.dir/src/hash.cc.s

siga/CMakeFiles/siga.dir/src/metrics.cc.o: siga/CMakeFiles/siga.dir/flags.make
siga/CMakeFiles/siga.dir/src/metrics.cc.o: ../siga/src/metrics.cc
siga/CMakeFiles/siga.dir/src/metrics.cc.o: siga/CMakeFiles/siga.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/ice/lab05/dcc012b-lab05-nicolassoam/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object siga/CMakeFiles/siga.dir/src/metrics.cc.o"
	cd /ice/lab05/dcc012b-lab05-nicolassoam/build/siga && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT siga/CMakeFiles/siga.dir/src/metrics.cc.o -MF CMakeFiles/siga.dir/src/metrics.cc.o.d -o CMakeFiles/siga.dir/src/metrics.cc.o -c /ice/lab05/dcc012b-lab05-nicolassoam/siga/src/metrics.cc

siga/CMakeFiles/siga.dir/src/metrics.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/siga.dir/src/metrics.cc.i"
	cd /ice/lab05/dcc012b-lab05-nicolassoam/build/siga && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /ice/lab05/dcc012b-lab05-nicolassoam/siga/src/metrics.cc > CMakeFiles/siga.dir/src/metrics.cc.i

siga/CMakeFiles/siga.dir/src/metrics.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/siga.dir/src/metrics.cc.s"
	cd /ice/lab05/dcc012b-lab05-nicolassoam/build/siga && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /ice/lab05/dcc012b-lab05-nicolassoam/siga/src/metrics.cc -o CMakeFiles/siga.dir/src/metrics.cc.s

siga/CMakeFiles/siga.dir/src/siga.cc.o: siga/CMakeFiles/siga.dir/flags.make
siga/CMakeFiles/siga.dir/src/siga.cc.o: ../siga/src/siga.cc
siga/CMakeFiles/siga.dir/src/siga.cc.o: siga/CMakeFiles/siga.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/ice/lab05/dcc012b-lab05-nicolassoam/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object siga/CMakeFiles/siga.dir/src/siga.cc.o"
	cd /ice/lab05/dcc012b-lab05-nicolassoam/build/siga && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT siga/CMakeFiles/siga.dir/src/siga.cc.o -MF CMakeFiles/siga.dir/src/siga.cc.o.d -o CMakeFiles/siga.dir/src/siga.cc.o -c /ice/lab05/dcc012b-lab05-nicolassoam/siga/src/siga.cc

siga/CMakeFiles/siga.dir/src/siga.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/siga.dir/src/siga.cc.i"
	cd /ice/lab05/dcc012b-lab05-nicolassoam/build/siga && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /ice/lab05/dcc012b-lab05-nicolassoam/siga/src/siga.cc > CMakeFiles/siga.dir/src/siga.cc.i

siga/CMakeFiles/siga.dir/src/siga.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/siga.dir/src/siga.cc.s"
	cd /ice/lab05/dcc012b-lab05-nicolassoam/build/siga && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /ice/lab05/dcc012b-lab05-nicolassoam/siga/src/siga.cc -o CMakeFiles/siga.dir/src/siga.cc.s

# Object files for target siga
siga_OBJECTS = \
"CMakeFiles/siga.dir/src/estudante.cc.o" \
"CMakeFiles/siga.dir/src/hash.cc.o" \
"CMakeFiles/siga.dir/src/metrics.cc.o" \
"CMakeFiles/siga.dir/src/siga.cc.o"

# External object files for target siga
siga_EXTERNAL_OBJECTS =

siga/libsiga.a: siga/CMakeFiles/siga.dir/src/estudante.cc.o
siga/libsiga.a: siga/CMakeFiles/siga.dir/src/hash.cc.o
siga/libsiga.a: siga/CMakeFiles/siga.dir/src/metrics.cc.o
siga/libsiga.a: siga/CMakeFiles/siga.dir/src/siga.cc.o
siga/libsiga.a: siga/CMakeFiles/siga.dir/build.make
siga/libsiga.a: siga/CMakeFiles/siga.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/ice/lab05/dcc012b-lab05-nicolassoam/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libsiga.a"
	cd /ice/lab05/dcc012b-lab05-nicolassoam/build/siga && $(CMAKE_COMMAND) -P CMakeFiles/siga.dir/cmake_clean_target.cmake
	cd /ice/lab05/dcc012b-lab05-nicolassoam/build/siga && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/siga.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
siga/CMakeFiles/siga.dir/build: siga/libsiga.a
.PHONY : siga/CMakeFiles/siga.dir/build

siga/CMakeFiles/siga.dir/clean:
	cd /ice/lab05/dcc012b-lab05-nicolassoam/build/siga && $(CMAKE_COMMAND) -P CMakeFiles/siga.dir/cmake_clean.cmake
.PHONY : siga/CMakeFiles/siga.dir/clean

siga/CMakeFiles/siga.dir/depend:
	cd /ice/lab05/dcc012b-lab05-nicolassoam/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /ice/lab05/dcc012b-lab05-nicolassoam /ice/lab05/dcc012b-lab05-nicolassoam/siga /ice/lab05/dcc012b-lab05-nicolassoam/build /ice/lab05/dcc012b-lab05-nicolassoam/build/siga /ice/lab05/dcc012b-lab05-nicolassoam/build/siga/CMakeFiles/siga.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : siga/CMakeFiles/siga.dir/depend

