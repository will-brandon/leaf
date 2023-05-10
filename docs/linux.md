# Leaf on mac OS X x64 Architecture

### By Will Brandon
May 10, 2023

---

## Overview
Building the Leaf project comes in three parts.

 1. Acquire any prerequisite software.
 2. Build the libraries.
 3. Build the Leaf source code.

These three steps must be performed in order.


## Prerequisite Software

 * GNU Make (can be installed with apt)
 * OpenGL (can be installed with apt)


## Building Libraries
To build all libraries at once, use the GNU Makefile in the project root.

    make lib-linux

To build libraries individually, use the GNU Makefile in the build-scripts/libs/lib-linux directory and specify the library to build.

    make -C ./build-scripts/libs/lib-linux sdl
    make -C ./build-scripts/libs/lib-linux bgfx


## Building Leaf

To build the Leaf source code, use the GNU Makefile in the project root.

    make leaf-linux
