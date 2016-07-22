/*================================================================================================*/
/*              Trabalho II de Programação II e Algoritmos e Estruturas de Dados I                */
/*                Nome : Arthur Alexsander Martins Teodo      Matrícula : 0022427                 */
/*                Nome : Saulo Ricardo Dias Fernandes         Matrícula : 0021581                 */
/*                                         Data: 10/07/2016                                       */
/*================================================================================================*/

/*================================================================================================*/
/*                                      BIBLIOTECAS                                               */
/*================================================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "grafo.h"
#include "pilha.h"

typedef struct vetVertice
{
	int idVertice;
	int cor;
} *VetVertice;

/*Declaracao de funcoes estaticas*/
static int pegaCorVertice(VetVertice vet, int tam, int idVertice);
static void coloreVertice(VetVertice vet, int tam, int idVertice, int cor);

void coloracaoGulosa(Grafo g, int k)
{
	/*Cria um grafo de backup*/
	GBsalvaGrafo(g,"guardaGrafo.txt");
	Grafo grafo = GGcarregaGrafo("guardaGrafo.txt");
	remove("guardaGrafo.txt");

	/*Declaracao de variaveis e EDs*/
	int i, corVizinho, vertice, menorGrau, aresta, encontrouMenor,menorCor, verticeVizinho, tamanho = GInumeroVertices(grafo);
	Pilha pilha = criaPilha();
	VetVertice vertices = (VetVertice) malloc(sizeof(struct vetVertice)*tamanho);
	vertice = GVprimeiroVertice(grafo);
	/*Colore como neutro todos os vertices*/
	vertices[0].idVertice = vertice;
	vertices[0].cor = 0;
	for(i = 1; i < tamanho; i++)
	{
		vertices[i].idVertice = GVproximoVertice(grafo,vertice);
		vertices[i].cor = 0;
		vertice = GVproximoVertice(grafo,vertice);
	}

	/*Definicao da ordem de coloracao*/
	while(GInumeroVertices(grafo) != 0)
	{
		menorGrau = INT_MAX;
		for(i = GVprimeiroVertice(grafo); i != 0; i = GVproximoVertice(grafo,i))
		{
			if(GIpegaGrau(grafo,i) < menorGrau)
			{
				menorGrau = GIpegaGrau(grafo,i);
				vertice = i;
			}
		}
		GVdestroiVertice(grafo,vertice);
		inserePilha(pilha,vertice);
	}
	GGdestroiGrafo(grafo);

	/*Colore os vertices*/
	while(!vaziaPilha(pilha))
	{
		vertice = retirarPilha(pilha);
		if(GIpegaGrau(g,vertice) >= k)
		{
			printf("Não existe solução\n");
			return;
		}
		encontrouMenor = 0;
		menorCor = 1;
		int achouIgual = 0;
		while(!encontrouMenor)
		{
			achouIgual = 0;
			for(aresta = GAprimaAresta(g,vertice); aresta != 0; aresta = GAproxAresta(g,vertice,aresta))
			{
				verticeVizinho = GVvizinho(g,aresta,vertice);
				corVizinho = pegaCorVertice(vertices,tamanho,verticeVizinho);
				if(menorCor == corVizinho)
				{
					achouIgual = 1;
				}
			}
			if(achouIgual)
			{
				menorCor++;
			}
			else
			{
				encontrouMenor = 1;
			}
		}
		coloreVertice(vertices,tamanho,vertice,menorCor);
	}

	for(i = 0; i < tamanho; i++)
	{
		printf("Vertice %d possui a cor %d\n", vertices[i].idVertice, vertices[i].cor);
	}
}

int pegaCorVertice(VetVertice vet, int tam, int idVertice)
{
	int i;
	for(i = 0; i < tam; i++)
	{
		if(vet[i].idVertice == idVertice)
		{
			return vet[i].cor;
		}
	}
	return -1;
}

void coloreVertice(VetVertice vet, int tam, int idVertice, int cor)
{
	int i;
	for(i = 0; i < tam; i++)
	{
		if(vet[i].idVertice == idVertice)
		{
			vet[i].cor = cor;
			return;
		}
	}	
}