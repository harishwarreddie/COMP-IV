CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra  -Werror -pedantic
LDFLAGS = -lboost_date_time -lboost_regex

TARGET = ps7
SRCS = ps7.cpp
OBJS = $(SRCS:.cpp=.o)

.PHONY: all clean lint

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

lint:
	cpplint *.cpp

clean:
	rm -f $(TARGET) $(OBJS)