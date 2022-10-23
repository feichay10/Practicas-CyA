CC=g++
CXXFLAGS=-g -std=c++14 -Wall

OBJS = p04_code_analyzer.o FileOperations.o Variables.o Loops.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p04_code_analyzer ${OBJS}

clean: 
	rm -rf *.o p04_code_analyzer