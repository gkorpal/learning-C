# Explicitly set the C compiler
CC = gcc

# The CFLAGS variable sets compile flags for gcc:
#  -std=c99  use the C99 standard language definition
#  -Wall     Recommended compiler warnings
#  -g        Generate debugging information
CFLAGS = -std=c99 -Wall -g

# the build source and target executable:
SOURCES = rollingStrings.c
TARGET = rollingStrings

# running just make should do the same as make all
all: $(TARGET)

# Makefile will build the executable named TARGET. 
# $@	The file name of the target.
# $^	The names of all the dependencies separated 
# 	by spaces, but with duplicate names removed. 
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $@ $^

	
# Phony will make sure that cleanup actions are executed
# even if there is a file named "clean"
.PHONY: clean

clean:
	rm -f $(TARGET)
