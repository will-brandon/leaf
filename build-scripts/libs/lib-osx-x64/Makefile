# Makefile
#
# Type:		GNU Makefile
# Author:	Will Brandon
# Date:		May 9, 2023
#
# Builds libraries for the project for the macOS X x64 architecture.
#
# Usage:	make


# Define a path to the library root.
LIBSDIR = ../../../libs


# This target is the default. It will build all libraries.
all: sdl bgfx

# This target will clean all library builds.
clean: clean-sdl clean-bgfx

# This target will build the SDL library.
sdl:
	mkdir -p $(LIBSDIR)/SDL3/build/os-x64
#cmake --build -S $(LIBSDIR)/SDL3/build/os-x64 -B $(LIBSDIR)/SDL3/build/os-x64
#cmake --install -S $(LIBSDIR)/SDL3/build/os-x64 -B $(LIBSDIR)/SDL3/build/os-x64

# Cleans the SDL build.
clean-sdl:
	rm -rf $(LIBSDIR)/SDL3/build/os-x64

# This target will build the BGFX library. Note that it also builds BX and BIMG.
bgfx:
	make -C $(LIBSDIR)/bgfx osx-x64

# Cleans the BGFX build.
clean-bgfx:
	rm -rf $(LIBSDIR)/bgfx/.build/osx-x64

# All targets in this Makefile are phony (they are not file names).
.PHONY: all clean sdl bgfx
