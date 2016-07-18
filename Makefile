all:
	gcc -Wall -o pilha.o -c pilha.c
	gcc -Wall -o fila.o -c fila.c
	gcc -Wall -o listaVertice.o -c listaVertice.c
	gcc -Wall -o listaAresta.o -c listaAresta.c
	gcc -Wall -o listaEstrela.o -c listaEstrela.c
	gcc -Wall -o grafo.o -c grafo.c
	gcc -Wall -o main.out grafo.o listaVertice.o listaEstrela.o listaAresta.o pilha.o fila.o main.c

run:
	./main.out	
