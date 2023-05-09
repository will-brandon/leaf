# Makefile
#
# Type:		GNU Makefile
# Author:	Will Brandon
# Date:		May 9, 2023
#
# Builds the project for the given operating system.
#
# Usage:	make

# The 'all' main target should not be used.
all:
	@printf "Don't use the 'all' target. You must select an operating system target.\n"

# Build the project for OS X.
os-x:
	printf "Thats better"

# All targets in this Makefile are phony (they are not file names).
.PHONY: all os-x
