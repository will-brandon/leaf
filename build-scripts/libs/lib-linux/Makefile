# Makefile
#
# Type:		GNU Makefile
# Author:	Will Brandon
# Date:		May 10, 2023
#
# Builds libraries for the project for the Linux architecture.
#
# Usage:	make


# Define the architecture name.
ARCNAME = linux

# Define a path to the library root.
LIBSDIR = ../../../libs


# This target is the default. It will build all libraries.
all: sdl bgfx

# This target will clean all library builds.
clean: clean-sdl clean-bgfx

# This target will build the SDL library.
sdl:
	mkdir -p $(LIBSDIR)/SDL3/build/$(ARCNAME)
	cmake -S $(LIBSDIR)/SDL3 -B $(LIBSDIR)/SDL3/build/$(ARCNAME)
	cmake --build $(LIBSDIR)/SDL3/build/$(ARCNAME)
	cmake --install $(LIBSDIR)/SDL3/build/$(ARCNAME)

# Cleans the SDL build.
clean-sdl:
	rm -rf $(LIBSDIR)/SDL3/build/$(ARCNAME)

# This target will build the BGFX library. Note that it also builds BX and BIMG.
bgfx:
	make -C $(LIBSDIR)/bgfx $(ARCNAME)

# Cleans the BGFX build.
clean-bgfx:
	rm -rf $(LIBSDIR)/bgfx/.build/*linux*

# All targets in this Makefile are phony (they are not file names).
.PHONY: all clean sdl bgfx
