# Makefile for Pentaflake

CXX = g++
CXXFLAGS = -std=c++17 -Wall -Werror -pedantic
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
TARGET = Penta

all: $(TARGET)

$(TARGET): main.o penta.o
	$(CXX) $(CXXFLAGS) main.o penta.o -o $(TARGET) $(LIBS)

main.o: main.cpp penta.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

penta.o: penta.cpp penta.hpp
	$(CXX) $(CXXFLAGS) -c penta.cpp

clean:
	rm -f *.o $(TARGET)