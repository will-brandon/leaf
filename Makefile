# Makefile
#
# Type:		GNU Makefile
# Author:	Will Brandon
# Date:		May 9, 2023
#
# Builds the Leaf project for the given operating system.
#
# Usage:	make


# Define a path to the build script root and build output root.
SCRIPTDIR=./build-scripts
BUILDDIR = ./build


# The 'all' target should not be used.
all:
	@printf "The 'all' target should not be used.\n"

# This target will clean up the output by removing all generated objects and executables.
clean:
	rm -rf $(BUILDDIR)/*

# This target builds all the libraries for the project for the target operating system with the
# given name. This is a wildcard target that captures all operating system names.
lib-%:
	make -C $(SCRIPTDIR)/libs/$@ all

# This target builds the Leaf project for the target operating system with the given name. This is a
# wildcard target that captures all operating system names.
leaf-%:
	make -C $(SCRIPTDIR)/leaf/$@ all

# All targets in this Makefile are phony (they are not file names).
.PHONY: all clean %
