CC=g++
CXXFLAGS=-g -std=c++14 -Wall

OBJS = src/p01_strings.o src/functions.o src/symbol.o src/alphabet.o src/chain.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p01_strings ${OBJS}

clean: 
	rm -rf src/*.o main*