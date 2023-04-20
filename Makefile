# GNU Makefile
#
# Author:	William R. Brandon
# Date:		Apr 20, 2023
#
# Recursively builds and links the entire project.
#
# Usage:	make

CC = g++
OLVL = 0
CFLAGS = -std=c++20 -O$(OLVL) -Wall

LIBS = -lSDL2

SRCDIR = ./src
OUTDIR = ./bin
EXEC = ./bin/test

all: compile link

compile:
	make -C $(SRCDIR)

link:
	$(CC) $(CFLAGS) $(LIBS) $(shell find $(OUTDIR) -name *.o) -o $(EXEC)

clean:
	rm -rf $(OUTDIR)/*
	rm -f $(EXEC)

.PHONY: all compile link clean
