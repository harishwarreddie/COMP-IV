CXX = g++
CXXFLAGS =  -std=c++17 -Wall -Wextra -Werror -pedantic
SFML_LIBS = -Wall -Werror -pedantic -lsfml-graphics -lsfml-window -lsfml-system  -lsfml-audio

# Executable name
EXEC = Sokoban

# Source files
SOURCES = main.cpp Sokoban.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Header files
HEADERS = Sokoban.hpp

# Test files
TEST_SOURCES = test.cpp Sokoban.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
TEST_EXEC = test

# Default target
all: $(EXEC) Sokoban.a $(TEST_EXEC)

# Linking the executable
$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC) $(SFML_LIBS)

# Compiling source files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Creating static library
Sokoban.a: Sokoban.o
	ar rcs $@ $^

# Building and running tests
$(TEST_EXEC): $(TEST_OBJECTS)
	$(CXX) $(TEST_OBJECTS) -o $(TEST_EXEC) $(SFML_LIBS)
	./$(TEST_EXEC)

# Linting
lint:
	cpplint  $(SOURCES) $(HEADERS) $(TEST_SOURCES)

# Cleaning up
clean:
	rm -f $(EXEC) $(OBJECTS) Sokoban.a $(TEST_EXEC) $(TEST_OBJECTS)

.PHONY: all lint clean