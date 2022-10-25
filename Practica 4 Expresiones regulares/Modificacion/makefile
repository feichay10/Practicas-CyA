CC=g++
CXXFLAGS=-g -std=c++14 -Wall

OBJS = p04_code_analyzer.o fileoperations.o comments.o variables.o loops.o return.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p04_code_analyzer ${OBJS}

clean: 
	rm -rf *.o p04_code_analyzer