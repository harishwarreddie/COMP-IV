CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra  -Werror -pedantic 
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

all: NBody NBody.a test

NBody: main.o Universe.o CelestialBody.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(SFML_LIBS)

NBody.a: Universe.o CelestialBody.o
	ar rcs $@ $^

main.o: main.cpp Universe.hpp CelestialBody.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

Universe.o: Universe.cpp Universe.hpp CelestialBody.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

CelestialBody.o: CelestialBody.cpp CelestialBody.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: test.cpp Universe.o CelestialBody.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(SFML_LIBS)

lint:
	cpplint *.cpp *.hpp

clean:
	rm -f *.o NBody NBody.a test

.PHONY: all clean lint