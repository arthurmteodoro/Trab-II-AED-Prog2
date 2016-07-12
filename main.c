#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "listas.h"

int main(void)
{
	Grafo g;
	g = GGcriaGrafo();
	printf("Vertice %d Criado\n", GVcriaVertice(g));
	printf("Vertice %d Criado\n", GVcriaVertice(g));
	printf("Vertice %d Criado\n", GVcriaVertice(g));
	printf("Aresta %d Criada \n", GAcriaAresta(g,1,2));
	printf("Aresta %d Criada \n", GAcriaAresta(g,2,1));
	printf("Aresta %d Criada \n", GAcriaAresta(g,1,3));
	printf("IDVERTICE %d\n", GBexisteIdVertice(g,1));
	printf("IDVERTICE %d\n", GBexisteIdVertice(g,5));
	printf("IDAresta %d\n", GBexisteIdAresta(g,1));
	printf("IDAresta %d\n", GBexisteIdAresta(g,5));
	printf("aresta 1-2 %d\n", GBexisteArestaDir(g,1,2));
	printf("aresta 3-1 %d\n", GBexisteArestaDir(g,3,1));
	printf("Aresta nao DIr 3-1 %d\n", GBexisteAresta(g,3,1));
	printf("Aresta nao DIr 2-1 %d\n", GBexisteAresta(g,2,1));
	printf("Aresta nao DIr 5-1 %d\n", GBexisteAresta(g,5,1));
	printf("ID aresta 1-2 %d\n", GApegaArestaDir(g,1,2));
	printf("ID aresta 1-3 %d\n", GApegaArestaDir(g,1,3));
	printf("ID aresta 3-5 %d\n", GApegaArestaDir(g,3,5));	
	printf("ID pegaaresta 3-1 %d\n", GApegaAresta(g,3,1));
	printf("ID pegaaresta 3-5 %d\n", GApegaAresta(g,3,5));
	printf("Primeiro Vertice %d\n", GVprimeiroVertice(g));
	printf("Vertice depois de 2 %d\n", GVproximoVertice(g,2));
	printf("Vertice depois de 3 %d\n", GVproximoVertice(g,3));
	//printf("%d \n", GAdestroiAresta(g,1));
	//printf("IDAresta %d\n", GBexisteIdAresta(g,1));
	GGdestroiGrafo(g);
	return 0;
}