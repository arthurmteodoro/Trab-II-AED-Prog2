/*================================================================================================*/
/*              Trabalho II de Programação II e Algoritmos e Estruturas de Dados I                */
/*                Nome : Arthur Alexsander Martins Teodo      Matrícula : 0022427                 */
/*                Nome : Saulo Ricardo Dias Fernandes         Matrícula : 0021581                 */
/*                                         Data: 10/07/2016                                       */
/*================================================================================================*/

/*================================================================================================*/
/*                                      BIBLIOTECAS                                               */
/*================================================================================================*/
#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"
#include "lista.h"
#include "pilha.h"
#include "algoritmos.h"

void buscaProfundidade(Grafo g, int partida)
{
	int i, v, a, w;
	Pilha pilha = criaPilha();
	Lista listaBrancos = criaLista();
	Lista listaPretos = criaLista();
	Lista listaVisitados = criaLista();

	for(i = GVprimeiroVertice(g); i != 0; i = GVproximoVertice(g, i))
	{
		insereNaLista(listaBrancos, i);
	}

	printf("Todas os vértices estão brancos.\n");
	printf("Nenhuma aresta foi visitada.\n");

	v = partida;
	printf("O vertice %d está cinza.\n", v);
	inserePilha(pilha, v);
	retiraLista(listaBrancos, pegaPosLista(listaBrancos, v));
	
	while(!vaziaPilha(pilha))
	{
		v = retirarPilha(pilha);
		printf("Vertice %d ativado.\n", v);
		for(a = GAprimaSaida(g,v); a != 0; a = GAproxSaida(g,v,a))
		{
			insereNaLista(listaVisitados, a);
			printf("A aresta %d foi visitada.\n", a);
			w = GVvizinho(g,a,v);
			if(existeNaLista(listaBrancos, w))
			{
				inserePilha(pilha, w);
				printf("O vertice %d está cinza.\n", w);
				retiraLista(listaBrancos, pegaPosLista(listaBrancos, w));
			}
		}
		insereNaLista(listaPretos, v);
		printf("O vertice %d está preto.\n", v);
		printf("Vertice %d desativado.\n", v);
	}
	destroiLista(listaBrancos);
	destroiLista(listaPretos);
	destroiPilha(pilha);
}