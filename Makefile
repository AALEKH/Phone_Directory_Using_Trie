CXX=clang++
CXXFLAGS=-g -std=c++11 -Wall -pedantic
BIN=start

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CXX) -o $(BIN) $^

%.o: %.c
	$(CXX) $@ -c $<

run:
	./start

clean:
	rm -f *.o
	rm $(BIN)