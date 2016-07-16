#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(void)
{
	Grafo g = GGcarregaGrafo("saida1.txt");
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
	GVdestroiVertice(g,1);
	GBsalvaGrafo(g,"saida2.txt");
	GGdestroiGrafo(g);
	g = GGcarregaGrafo("saida2.txt");
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
