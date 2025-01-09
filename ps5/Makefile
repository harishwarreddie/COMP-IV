CC = g++
CFLAGS = --std=c++17 -Wall -Werror -pedantic -g
LIB = -Wall -Werror -pedantic -lsfml-system -lboost_unit_test_framework

OBJECTS= EDistance.o

all: EDistance test EDistance.a

EDistance: main.o $(OBJECTS)
	$(CC) main.o $(OBJECTS) -o EDistance $(LIB)

test: test.o $(OBJECTS)
	$(CC) test.o $(OBJECTS) -o test $(LIB)

main.o: main.cpp EDistance.hpp
	$(CC) -c main.cpp  $(CFLAGS)


EDistance.o: EDistance.cpp EDistance.hpp
	$(CC) -c EDistance.cpp $(CFLAGS)
	
test.o: test.cpp EDistance.hpp
	$(CC) -c test.cpp $(CFLAGS)

EDistance.a: main.o
	ar rcs EDistance.a main.o

clean:
	rm *.o
	rm EDistance
	rm test
