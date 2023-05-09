# Makefile
#
# Type:		GNU Makefile
# Author:	Will Brandon
# Date:		April 28, 2023
#
# Recursively builds the source code for the entire project.
#
# Usage:	make


# Define the compiler program, C++ version, optimization level, and accepted warnings.
CC = g++
CFLAGS = -std=c++17 -O0 -Wall

# Define a path back to the project root.
PROJECTROOT = ../../../..

# Define a path the binary object root for the source directory built by this Makefile.
OBJDIR = $(PROJECTROOT)/build/obj/window/managed/sdl

# Get a list of all subdirectories.
SUBDIRS := $(wildcard */.)

# Create a list of source file names and ther corresponding object file names.
SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

# Define any includes.
INCLUDES =	-I $(PROJECTROOT)/libs/bx/include \
			-I $(PROJECTROOT)/libs/bgfx/include \
			-I $(PROJECTROOT)/libs/bimg/include \
			-I $(PROJECTROOT)/libs/SDL3/include


# This target is the default. It will create output directories, recursively build any
# subdirectories, and compile the source code at the current source level into binary objects.
all: outdirs $(SUBDIRS) $(OBJS)

# This target will create the directories for the produced output if they do not already exist.
outdirs:
	mkdir -p $(OBJDIR)

# This target which applies to all subdirectories will call a Makefile within the subdirectory if it
# exists.
$(SUBDIRS):
	@echo "Checking subdir: $@"
	@if [ -f $@/Makefile ]; then \
  		echo "Using sub-make: $@/Makefile"; \
  		make -C $@; \
  	fi

# This target will compile each source C++ file into an object file in the proper mirrored directory
# and name in the binary object tree.
%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(OBJDIR)/$@

# All targets in this Makefile are phony (they are not file names).
.PHONY: all outdirs $(SUBDIRS)
