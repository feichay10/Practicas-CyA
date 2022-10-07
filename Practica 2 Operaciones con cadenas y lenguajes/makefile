CC=g++
CXXFLAGS=-g -std=c++14 -Wall

OBJS = p02_languages.o functions.o alphabet.o strings.o language.o

all: ${OBJS}
	$(CC) $(CXXFLAGS) -o p02_languages ${OBJS}

clean: 
	rm -rf *.o p02_languages