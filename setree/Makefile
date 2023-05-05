CC = g++
CFLAGS = -std=c++11 -Wall -Wextra -Werror
INCLUDES = -I.

# list all source files here
SOURCES = Set.cpp Node.cpp test.cpp

# list all object files here
OBJECTS = $(SOURCES:.cpp=.o)

# name of executable file
EXECUTABLE = test

.PHONY: clean

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJECTS) -o $(EXECUTABLE)

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
