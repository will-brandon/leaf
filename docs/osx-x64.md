# Leaf on OS X x64 Architecture

### By Will Brandon
May 10, 2023


## Overview
Building the Leaf project requires four steps.

 1. Acquire any prerequisite software
 2. Clone the Git submodule libraries
 3. Build the libraries
 4. Build the Leaf source code

These three steps must be performed in order.


## Cloning Git Submodule Libraries
To acquire the library Git submodules, first initialize the submodule schematic, then update the submodules to clone them. Both operations should be performed in the project root.

    git submodule init
    git submodule update


## Prerequisite Software

 * Git (If you have cloned this project you probably have Git installed)
 * GNU Make (Can be installed with Homebrew)
 * Metal (Should be installed on all Apple machines by default)


## Building Libraries
To build all libraries at once, use the GNU Makefile in the project root.

    make lib-osx-x64

To build libraries individually, use the GNU Makefile in the ./build-scripts/libs/lib-osx-x64/ directory and specify the library to build.

    make -C ./build-scripts/libs/lib-osx-x64 sdl
    make -C ./build-scripts/libs/lib-osx-x64 bgfx


## Building Leaf Source Code

To build the Leaf source code, use the GNU Makefile in the project root.

    make leaf-osx-x64
