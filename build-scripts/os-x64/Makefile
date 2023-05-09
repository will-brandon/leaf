# Makefile
#
# Type:		GNU Makefile
# Author:	Will Brandon
# Date:		April 28, 2023
#
# Recursively builds and links the entire project.
#
# Usage:	make


# Define the compiler program, C++ version, optimization level, and accepted warnings.
CC = g++
CFLAGS = -std=c++17 -O0 -Wall

# Define a path the source root, binary object root, and executable directories.
SRCDIR = ./src
OBJDIR = ./build/obj
EXECDIR = ./build/bin

# Define the name of the executable.
EXEC = test

# Define any installed libraries, manual libraries, and platform dependent frameworks.
MANUAL_LIBS = ./libs/bgfx/.build/osx-x64/bin/*.a ./libs/SDL3/build/os-x64/libSDL3.dylib
FRAMEWORKS = -framework Cocoa -framework IOKit -framework Metal -framework QuartzCore


# This target is the default. It will create output directories, compile, and link.
all: outdirs compile link

# This target will build all submodules / libraries.
libs: lib_bgfx lib_sdl

# This target will build the bgfx submodule. Note that it also builds bx and bimg.
lib_bgfx:
	make -C $(PROJECTROOT)/libs/bgfx/Makefile os-x64

# This target will build the SDL submodule. Note that it also builds bx and bimg.
lib_sdl:
	mkdir -p $(PROJECTROOT)/libs/SDL3/build/os-x64
	cmake --build $(PROJECTROOT)/libs/SDL3/build/os-x64 -B $(PROJECTROOT)/libs/SDL3/build/os-x64
	cmake --install $(PROJECTROOT)/libs/SDL3/build/os-x64 -B $(PROJECTROOT)/libs/SDL3/build/os-x64

# This target will create the directories for the produced output if they do not already exist.
outdirs:
	mkdir -p $(OBJDIR)
	mkdir -p $(EXECDIR)

# This target will recursively compile the source code using the Makefile in the source directory.
compile:
	make -C $(SRCDIR)

# This target will link all the objects into an executable. Find all objects in the binary output
# directory tree.
link:
	$(CC) $(CFLAGS) $(MANUAL_LIBS) $(FRAMEWORKS) \
		$(shell find $(OBJDIR) -name *.o) -o $(EXECDIR)/$(EXEC)

# This target will clean up the output by removing all generated objects and executables.
clean:
	rm -rf $(OBJDIR)/*
	rm -rf $(EXECDIR)/*

# All targets in this Makefile are phony (they are not file names).
.PHONY: all libs lib_bgfx lib_sdl outdirs compile link clean
