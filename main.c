#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(void)
{
	Grafo g = GGcriaGrafo();
	printf("Vertice %d Criado\n", GVcriaVertice(g));
	printf("Vertice %d Criado\n", GVcriaVertice(g));
	printf("Vertice %d Criado\n", GVcriaVertice(g));
	printf("Aresta %d Criada \n", GAcriaAresta(g,1,2));
	printf("Aresta %d Criada \n", GAcriaAresta(g,2,1));
	printf("Aresta %d Criada \n", GAcriaAresta(g,1,3));
	printf("Aresta %d Criada \n", GAcriaAresta(g,3,2));
	printf("Aresta %d Criada \n", GAcriaAresta(g,3,1));
	printf("Aresta %d Criada \n", GAcriaAresta(g,2,2));
	printf("IDVERTICE %d\n", GBexisteIdVertice(g,1));
	printf("IDVERTICE %d\n", GBexisteIdVertice(g,5));
	printf("IDAresta %d\n", GBexisteIdAresta(g,1));
	printf("IDAresta %d\n", GBexisteIdAresta(g,5));
	printf("aresta 1-2 %d\n", GBexisteArestaDir(g,1,2));
	printf("aresta 3-1 %d\n", GBexisteArestaDir(g,3,1));
	printf("Aresta nao DIr 3-1 %d\n", GBexisteAresta(g,1,3));
	printf("Aresta nao DIr 2-1 %d\n", GBexisteAresta(g,2,1));
	printf("Aresta nao DIr 5-1 %d\n", GBexisteAresta(g,5,1));
	printf("ID Aresta 1-2 %d\n", GApegaArestaDir(g,1,2));
	printf("ID aresta 1-3 %d\n", GApegaArestaDir(g,1,3));
	printf("ID aresta 3-1 %d\n", GApegaArestaDir(g,3,1));
	printf("ID aresta 3-5 %d\n", GApegaArestaDir(g,3,5));	
	printf("ID pegaaresta 3-1 %d\n", GApegaAresta(g,3,1));
	printf("ID pegaaresta 1-3 %d\n", GApegaAresta(g,1,3));
	printf("ID pegaaresta 3-5 %d\n", GApegaAresta(g,3,5));
	printf("Primeiro Vertice %d\n", GVprimeiroVertice(g));
	printf("Vertice depois de 2 %d\n", GVproximoVertice(g,2));
	printf("Vertice depois de 3 %d\n", GVproximoVertice(g,3));
	printf("Primeiro Aresta %d\n", GAprimeiraAresta(g));
	printf("Aresta depois de 2 %d\n", GAproximaAresta(g,2));
	printf("Aresta depois de 3 %d\n", GAproximaAresta(g,3));
	printf("Aresta depois de 4 %d\n", GAproximaAresta(g,4));
	printf("A prima aresta do vertice 3 é %d\n",GAprimaAresta(g,3));
	printf("Aresta depois da 3 do vertice 3 é %d\n",GAproxAresta(g,3,3));
	printf("A primeira entrada do vertice 1 é %d\n",GAprimaEntrada(g,1));
	printf("Entrada depois da 2a aresta do vertice 1 é %d\n",GAproxEntrada(g,1,2));
	printf("A primeira saida do vertice 1 é %d\n",GAprimaSaida(g,1));
	printf("Entrada depois da 2a aresta do vertice 1 é %d\n",GAproxSaida(g,1,2));
	printf("O grau do vertice 2 é %d\n",GIpegaGrau(g,2));
	printf("A aresta 6 é um laço ? %d\n",GBarestaLaco(g,6));
	printf("A aresta 2 é um laço ? %d\n",GBarestaLaco(g,2));
	printf("O vertice alfa da aresta 4 é %d\n",GValfa(g,4));
	printf("O vertice alfa da aresta 6 é %d\n",GValfa(g,6));
	printf("O vertice omega da aresta 1 é %d\n",GVomega(g,1));
	printf("O vertice omega da aresta 3 é %d\n",GVomega(g,3));
	printf("o Vizinho do vertice 3 da aresta 4 é %d\n",GVvizinho(g,4,3));
	printf("o Vizinho do vertice 3 da aresta 1 é %d\n",GVvizinho(g,5,3));
	printf("O grau do vertice 1 eh : %d\n", GIpegaGrau(g,1));
	printf("O grau do vertice 2 eh : %d\n", GIpegaGrau(g,2));
	printf("O grau do vertice 3 eh : %d\n", GIpegaGrau(g,3));
	printf("=====================================================\n");
	int a;
	for(a = GAprimeiraAresta(g); a != 0; a = GAproximaAresta(g,a))
	{
		printf("%d -> %d\n", GValfa(g,a), GVomega(g,a));
	}
	GVdestroiVertice(g,1);
	printf("=====================================================\n");
	for(a = GAprimeiraAresta(g); a != 0; a = GAproximaAresta(g,a))
	{
		printf("%d -> %d\n", GValfa(g,a), GVomega(g,a));
	}
	printf("=====================================================\n");
	printf("O grau do vertice 1 eh : %d\n", GIpegaGrau(g,1));
	printf("O grau do vertice 2 eh : %d\n", GIpegaGrau(g,2));
	printf("O grau do vertice 3 eh : %d\n", GIpegaGrau(g,3));
	GGdestroiGrafo(g);
	return 0;
}
