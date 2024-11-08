# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++11 -Wall

# Source files
SRC = person.cpp covid_negative.cpp covid_positive.cpp room_check.cpp main.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable name
EXEC = quarantine_center

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean up object files and executable
clean:
	rm -f $(OBJ) $(EXEC)

.PHONY: all clean
