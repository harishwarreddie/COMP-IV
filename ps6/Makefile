compiler = g++
flags_c = -g -std=c++0x -Wall -Werror -pedantic
flags_S = -Wall -Werror -pedantic -lsfml-graphics -lsfml-window -lsfml-system
lboost = -lboost_unit_test_framework

all: TextWriter test TextWriter.a lint

lint:
	cpplint --filter=-runtime/references,-build/c++14 --root=. *.hpp *.cpp

TextWriter: TextWriter.o RandWriter.o
	$(compiler) TextWriter.o RandWriter.o -o TextWriter $(flags_S)

test: test.o RandWriter.o
	$(compiler) $(flags_c) test.o RandWriter.o -o test $(lboost)

TextWriter.o: TextWriter.cpp RandWriter.hpp
	$(compiler) -c TextWriter.cpp $(flags_c)

RandWriter.o: RandWriter.cpp RandWriter.hpp
	$(compiler) -c RandWriter.cpp $(flags_c)

test.o: test.cpp RandWriter.hpp
	$(compiler) -c test.cpp $(flags_c)

TextWriter.a: RandWriter.o TextWriter.o
	ar rcs TextWriter.a RandWriter.o TextWriter.o

clean:
	rm -f *.o *.gch TextWriter test TextWriter.a

.PHONY: all clean lint