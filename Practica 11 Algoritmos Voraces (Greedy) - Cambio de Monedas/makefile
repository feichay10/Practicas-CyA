text0 = 
text1 = Se procedera a compilar la práctica...
text2 = Modo de empleo:
text3 = ./cambiomonedas
text4 = Se ha eliminado el fichero ejecutable y los ficheros objetos.

CC=g++
CXXFLAGS=-g -std=c++14 -Wall

OBJS = cambiomonedas.o monedero.o

all: ${OBJS}
	@echo $(text0)
	@echo $(text1)
	$(CC) $(CXXFLAGS) -o cambiomonedas ${OBJS}
	@echo $(text0)
	@echo $(text2)
	@echo $(text3)

clean: 
	rm -rf src/*.o cambiomonedas
	@echo $(text4)