#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "algoritmos.h"

int main(void)
{
	Grafo g = GGcarregaGrafo("grafo7.txt");

	coloracaoGulosa(g,6);
	/*int vertice, aresta;
	vertice = 2;
	for(aresta = GAprimaAresta(g,vertice); aresta != 0; aresta = GAproxAresta(g,vertice,aresta))
	{
		printf("Aresta = %d Vizinho = %d\n", aresta, GVvizinho(g,aresta,vertice));
	}*/

	GGdestroiGrafo(g);
	return 0;
}