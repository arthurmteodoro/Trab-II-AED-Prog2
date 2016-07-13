#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "listas.h"

int main(void)
{
	Grafo g;
	g = GGcriaGrafo();
	GVcriaVertice(g);
	GVcriaVertice(g);
	GVcriaVertice(g);
	GVcriaVertice(g);
	GAcriaAresta(g,1,3);
	GAcriaAresta(g,2,2);
	GAcriaAresta(g,4,3);
	GAcriaAresta(g,1,1);
	GAcriaAresta(g,1,4);
	GAdestroiAresta(g,2);
	GVdestroiVertice(g,2);
	GGdestroiGrafo(g);
	return 0;
}