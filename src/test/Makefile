# GNU Makefile
#
# Author:	William R. Brandon
#
# Date:		Apr 20, 2023
#
# Recursively builds the source code for the entire project.
#
# Usage:	make

CC = g++
OLVL = 0
CFLAGS = -std=c++20 -O$(OLVL) -Wall

OUTDIR = ../../bin

SUBDIRS := $(wildcard */.)
SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp,%.o,$(SRCS))

all: outdir $(SUBDIRS) $(OBJS)

outdir:
	mkdir -p $(OUTDIR)

$(SUBDIRS):
	@echo "Checking subdir: $@"
	@if [ -f $@/Makefile ]; then \
  		echo "Using sub-make: $@/Makefile"; \
  		make -C $@; \
  	fi


%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $(OUTDIR)/$@

.PHONY: all outdir $(SUBDIRS)
