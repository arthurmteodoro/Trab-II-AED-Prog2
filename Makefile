all:
	gcc -Wall -o listaVertice.o -c listaVertice.c
	gcc -Wall -o listaAresta.o -c listaAresta.c
	gcc -Wall -o listaEstrela.o -c listaEstrela.c

run:
	./main	