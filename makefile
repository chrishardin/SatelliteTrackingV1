# Define the target file
TARGET = main

# Define the C++ compiler
CXX = g++

# Define the C++ flags
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic

# Define the source files
SOURCES = ${wildcard *.cpp}

# Define the object files
OBJECTS = $(SOURCES:.cpp=.o)

# Define the target
TARGET = main

# Define the default target
all: $(TARGET)

# Link the object files to create the target
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@

# Compile the source files to create the object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up the files generated by the makefile
clean:
	rm -f $(OBJECTS) $(TARGET)

# Run the file
run:
	./main