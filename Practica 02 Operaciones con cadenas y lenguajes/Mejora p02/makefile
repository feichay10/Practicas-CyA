CC=g++
CXXFLAGS=-g -std=c++14 -Wall

OBJS = src/p02_languages.o src/functions.o src/symbol.o src/alphabet.o src/chain.o src/language.o 

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p02_languages ${OBJS}

clean: 
	rm -rf src/*.o main*