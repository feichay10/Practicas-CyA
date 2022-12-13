CC=g++
CXXFLAGS=-g -std=c++14 -Wall

OBJS = p03_calculator.o functions.o symbol.o alphabet.o strings.o language.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p03_calculator ${OBJS}

clean: 
	rm -rf *.o p03_calculator