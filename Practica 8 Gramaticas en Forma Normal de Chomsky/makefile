text0 = 
text1 = Se procedera a compilar la práctica...
text2 = Modo de empleo:
text3 = ./p08_Grammar2CNF input.fa output.gra || p08_Grammar2CNF input.gra output.gra
text4 = Se ha eliminado el fichero ejecutable y los ficheros objetos.

CC=g++
CXXFLAGS=-g -std=c++14 -Wall

OBJS = src/p08_Grammar2CNF.o src/symbol.o src/alphabet.o src/transition.o src/state.o src/automata.o src/grammar.o

all: ${OBJS}
	@echo $(text0)
	@echo $(text1)
	$(CC) $(CXXFLAGS) -o p08_Grammar2CNF ${OBJS}
	@echo $(text0)
	@echo $(text2)
	@echo $(text3)

clean: 
	rm -rf src/*.o p08_Grammar2CNF
	@echo $(text4)