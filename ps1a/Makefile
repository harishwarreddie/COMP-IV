CXX = g++
CXXFLAGS = -std=c++11 -Wall -Werror -pedantic -g
LDFLAGS = -lboost_unit_test_framework

.PHONY: all clean

all: test PhotoMagic PhotoMagic.a

test: test.cpp FibLFSR.o
	$(CXX) $(CXXFLAGS) -o test test.cpp FibLFSR.o $(LDFLAGS)

PhotoMagic: main.o FibLFSR.o
	$(CXX) $(CXXFLAGS) -o PhotoMagic main.o FibLFSR.o

main.o: main.cpp FibLFSR.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

FibLFSR.o: FibLFSR.cpp FibLFSR.hpp
	$(CXX) $(CXXFLAGS) -c FibLFSR.cpp

PhotoMagic.a: FibLFSR.o
	ar rcs PhotoMagic.a FibLFSR.o

clean:
	rm -f *.o test PhotoMagic PhotoMagic.a
