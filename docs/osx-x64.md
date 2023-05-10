# Leaf on OS X x64 Architecture

### By Will Brandon
May 10, 2023


## Overview
Building the Leaf project comes in three parts.

 1. Acquire any prerequisite software.
 2. Build the libraries.
 3. Build the Leaf source code.

These three steps must be performed in order.


## Prerequisite Software

 * GNU Make (can be installed with Homebrew)
 * Metal (Should be installed on all Apple machines by default)


## Building Libraries
To build all libraries at once, use the GNU Makefile in the project root.

    make lib-osx-x64

To build libraries individually, use the GNU Makefile in the build-scripts/libs/lib-osx-x64 directory and specify the library to build.

    make -C ./build-scripts/libs/lib-osx-x64 sdl
    make -C ./build-scripts/libs/lib-osx-x64 bgfx


## Building Leaf

To build the Leaf source code, use the GNU Makefile in the project root.

    make leaf-osx-x64
