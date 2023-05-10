# Makefile
#
# Type:		GNU Makefile
# Author:	Will Brandon
# Date:		May 10, 2023
#
# Recursively builds and links the entire project for the Linux architecture.
#
# Usage:	make


# Define the architecture name.
ARCNAME = linux

# Define the compiler program, C++ version, optimization level, and accepted warnings.
CC = g++
CFLAGS = -std=c++17 -O0 -Wall

# Define a path to the library root, source root, binary object root, and executable output.
LIBSDIR = ../../../libs
SRCDIR = ../../../src
OBJDIR = ../../../build/obj
EXECDIR = ../../../build/bin

# Define the name of the executable.
EXEC = test

# Define manual libraries.
MANUAL_LIBS = \
	$(LIBSDIR)/bgfx/.build/linux64_gcc/bin/*.a \
	$(LIBSDIR)/SDL3/build/$(ARCNAME)/libSDL3.so


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
# directory tree.
link:
	$(CC) $(CFLAGS) $(MANUAL_LIBS) $(shell find $(OBJDIR) -name *.o) -o $(EXECDIR)/$(EXEC)

# All targets in this Makefile are phony (they are not file names).
.PHONY: all outdirs compile link
