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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lxt/Desktop/sysy_compiler_tnameplz

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lxt/Desktop/sysy_compiler_tnameplz/out/build

# Include any dependencies generated for this target.
include src/AST2IR/CMakeFiles/AST2IR.dir/depend.make

# Include the progress variables for this target.
include src/AST2IR/CMakeFiles/AST2IR.dir/progress.make

# Include the compile flags for this target's objects.
include src/AST2IR/CMakeFiles/AST2IR.dir/flags.make

src/AST2IR/CMakeFiles/AST2IR.dir/AST2IR.cpp.o: src/AST2IR/CMakeFiles/AST2IR.dir/flags.make
src/AST2IR/CMakeFiles/AST2IR.dir/AST2IR.cpp.o: ../../src/AST2IR/AST2IR.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lxt/Desktop/sysy_compiler_tnameplz/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/AST2IR/CMakeFiles/AST2IR.dir/AST2IR.cpp.o"
	cd /home/lxt/Desktop/sysy_compiler_tnameplz/out/build/src/AST2IR && /usr/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AST2IR.dir/AST2IR.cpp.o -c /home/lxt/Desktop/sysy_compiler_tnameplz/src/AST2IR/AST2IR.cpp

src/AST2IR/CMakeFiles/AST2IR.dir/AST2IR.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AST2IR.dir/AST2IR.cpp.i"
	cd /home/lxt/Desktop/sysy_compiler_tnameplz/out/build/src/AST2IR && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lxt/Desktop/sysy_compiler_tnameplz/src/AST2IR/AST2IR.cpp > CMakeFiles/AST2IR.dir/AST2IR.cpp.i

src/AST2IR/CMakeFiles/AST2IR.dir/AST2IR.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AST2IR.dir/AST2IR.cpp.s"
	cd /home/lxt/Desktop/sysy_compiler_tnameplz/out/build/src/AST2IR && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lxt/Desktop/sysy_compiler_tnameplz/src/AST2IR/AST2IR.cpp -o CMakeFiles/AST2IR.dir/AST2IR.cpp.s

# Object files for target AST2IR
AST2IR_OBJECTS = \
"CMakeFiles/AST2IR.dir/AST2IR.cpp.o"

# External object files for target AST2IR
AST2IR_EXTERNAL_OBJECTS =

../lib/libAST2IR.a: src/AST2IR/CMakeFiles/AST2IR.dir/AST2IR.cpp.o
../lib/libAST2IR.a: src/AST2IR/CMakeFiles/AST2IR.dir/build.make
../lib/libAST2IR.a: src/AST2IR/CMakeFiles/AST2IR.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lxt/Desktop/sysy_compiler_tnameplz/out/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/libAST2IR.a"
	cd /home/lxt/Desktop/sysy_compiler_tnameplz/out/build/src/AST2IR && $(CMAKE_COMMAND) -P CMakeFiles/AST2IR.dir/cmake_clean_target.cmake
	cd /home/lxt/Desktop/sysy_compiler_tnameplz/out/build/src/AST2IR && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AST2IR.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/AST2IR/CMakeFiles/AST2IR.dir/build: ../lib/libAST2IR.a

.PHONY : src/AST2IR/CMakeFiles/AST2IR.dir/build

src/AST2IR/CMakeFiles/AST2IR.dir/clean:
	cd /home/lxt/Desktop/sysy_compiler_tnameplz/out/build/src/AST2IR && $(CMAKE_COMMAND) -P CMakeFiles/AST2IR.dir/cmake_clean.cmake
.PHONY : src/AST2IR/CMakeFiles/AST2IR.dir/clean

src/AST2IR/CMakeFiles/AST2IR.dir/depend:
	cd /home/lxt/Desktop/sysy_compiler_tnameplz/out/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lxt/Desktop/sysy_compiler_tnameplz /home/lxt/Desktop/sysy_compiler_tnameplz/src/AST2IR /home/lxt/Desktop/sysy_compiler_tnameplz/out/build /home/lxt/Desktop/sysy_compiler_tnameplz/out/build/src/AST2IR /home/lxt/Desktop/sysy_compiler_tnameplz/out/build/src/AST2IR/CMakeFiles/AST2IR.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/AST2IR/CMakeFiles/AST2IR.dir/depend
