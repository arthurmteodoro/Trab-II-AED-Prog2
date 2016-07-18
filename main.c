#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(void)
{
	Grafo g = GGcarregaGrafo("entrada1.txt");
	int a;
	for(a = GVprimeiroVertice(g); a != 0; a = GVproximoVertice(g,a))
	{
		printf("%d - ", a);
	}
	printf("\n");
	for(a = GAprimeiraAresta(g); a != 0; a = GAproximaAresta(g,a))
	{
		printf("%d = %d -> %d\n", a,GValfa(g,a), GVomega(g,a));
	}
	printf("========================================================\n");
	GVdestroiVertice(g,5);
	int novoVertice1 = GVcriaVertice(g);
	int novoVertice2 = GVcriaVertice(g);
	GAcriaAresta(g,novoVertice1,novoVertice2);
	for(a = GVprimeiroVertice(g); a != 0; a = GVproximoVertice(g,a))
	{
		printf("%d - ", a);
	}
	printf("\n");
	for(a = GAprimeiraAresta(g); a != 0; a = GAproximaAresta(g,a))
	{
		printf("%d = %d -> %d\n", a,GValfa(g,a), GVomega(g,a));
	}
	GGdestroiGrafo(g);
	return 0;
}
