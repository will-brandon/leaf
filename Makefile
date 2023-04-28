# Makefile
#
# Type:		GNU Makefile
# Author:	Will Brandon
# Date:		Apr 28, 2023
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
INSTALLED_LIBS = -lSDL2
MANUAL_LIBS = ./libs/bgfx/.build/osx-x64/bin/*.a
FRAMEWORKS = -framework Cocoa -framework IOKit -framework Metal -framework QuartzCore

# This target is the default. It will create output directories, compile, and link.
all: outdirs compile link

# This target will create the directories for the produced output if they do not already exist.
outdirs:
	mkdir -p $(OBJDIR)
	mkdir -p $(EXECDIR)

# This target will recursively compile the source code using the Makefile in the source directory.
compile:
	make -C $(SRCDIR)

# This target will link all the objects into an executable. Find all objects in the binary output
#directory tree.
link:
	$(CC) $(CFLAGS) $(INSTALLED_LIBS) $(MANUAL_LIBS) $(FRAMEWORKS) \
		$(shell find $(OBJDIR) -name *.o) -o $(EXECDIR)/$(EXEC)

# This target will clean up the output by removing all generated objects and executables.
clean:
	rm -rf $(OBJDIR)/*
	rm -rf $(EXECDIR)/*

# All targets in this Makefile are phony (they are not file names).
.PHONY: all outdirs compile link clean
