all:
	gcc -Wall -o listaVertice.o -c listaVertice.c
	gcc -Wall -o listaAresta.o -c listaAresta.c
	gcc -Wall -o listaEstrela.o -c listaEstrela.c
	gcc -Wall -o grafo.o -c grafo.c
	gcc -Wall -o main grafo.o listaVertice.o listaEstrela.o listaAresta.o main.c

run:
	./main	