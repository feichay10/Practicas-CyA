text0 = 
text1 = Se procedera a compilar la práctica...
text2 = Modo de empleo:
text3 = ./multbigint 
text4 = Se ha eliminado el fichero ejecutable y los ficheros objetos.

CC=g++
CXXFLAGS=-g -std=c++14 -Wall

OBJS = multbigint.o bigint.o

all: ${OBJS}
	@echo $(text0)
	@echo $(text1)
	$(CC) $(CXXFLAGS) -o multbigint ${OBJS}
	
	clang-format -style=google -i *.h *.cc

	@echo $(text0)
	@echo $(text2)
	@echo $(text3)

clean: 
	rm -rf *.o multbigint
	@echo $(text4)