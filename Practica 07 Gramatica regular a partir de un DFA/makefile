text0 = 
text1 = Se procedera a compilar la práctica...
text2 = Modo de empleo:
text3 = ./p07_dfa2grammar input.fa output.gra
text4 = Se ha eliminado el fichero ejecutable y los ficheros objetos.

CC=g++
CXXFLAGS=-g -std=c++14 -Wall

OBJS = src/p07_dfa2grammar.o src/symbol.o src/alphabet.o src/transition.o src/state.o src/automata.o src/grammar.o

all: ${OBJS}
	@echo $(text0)
	@echo $(text1)
	$(CC) $(CXXFLAGS) -o p07_dfa2grammar ${OBJS}
	@echo $(text0)
	@echo $(text2)
	@echo $(text3)

clean: 
	rm -rf src/*.o p07_dfa2grammar
	@echo $(text4)