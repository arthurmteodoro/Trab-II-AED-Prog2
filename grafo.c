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
#include "listas.h"
#include "grafo.h"

struct grafo
{
	int numVertices, numArestas;
	int sementeVertices, sementeArestas;
	ListaVertice Vertices;
	ListaAresta Arestas;
};

/*======================================================================================*/
/*                               FUNÇÕES DO TRABALHO                                    */
/*======================================================================================*/

/*======================================================================================*/
/* CRIA GRAFO                                                                           */
/* IN = VOID                                                                            */
/* OUT = P (PONTEIRO PARA GRAFO)                                                        */
/*======================================================================================*/
Grafo GGcriaGrafo(void)
{
	Grafo aux = (Grafo) malloc(sizeof(struct grafo));
	aux->numVertices = 0;
	aux->numArestas = 0;
	aux->sementeArestas = 1;
	aux->sementeVertices = 1;
	aux->Vertices = criaListaVertice();
	aux->Arestas = criaListaAresta();
	return aux;
}

/*======================================================================================*/
/* DESTROI GRAFO                                                                        */
/* IN = P(PONTEIRO PARA GRAFO)                                                          */
/* OUT = P                                                                              */
/*======================================================================================*/
Grafo GGdestroiGrafo(Grafo p)
{
	destroiListaVertice(p->Vertices);
	destroiListaAresta(p->Arestas);
	free(p);
	p = NULL;
	return p;
}

/*======================================================================================*/
/* CRIA VERTICE                                                                         */
/* IN = P(PONTEIRO PARA GRAFO)                                                          */
/* OUT = V(IDENTIFICADOR VERTICE)                                                       */
/*======================================================================================*/
int GVcriaVertice(Grafo p)
{
	insereListaVertice(p->Vertices,p->sementeVertices);
	p->sementeVertices++;
	p->numVertices++;
	return p->sementeVertices-1;
}

/*======================================================================================*/
/* CRIA ARESTA                                                                          */
/* IN = P, V1, V2                                                                       */
/* OUT = A(IDENTIFICADOR ARESTA )                                                       */
/*======================================================================================*/

int GAcriaAresta(Grafo p, int v1, int v2)
{
	if((GBexisteIdVertice(p,v1))&&(GBexisteIdVertice(p,v2)))
	{
		insereListaAresta(p->Arestas,existeListaVertice(p->Vertices,v1),existeListaVertice(p->Vertices,v2),p->sementeArestas);
		insereListaEstrela(idEstrelaListaVertice(p->Vertices,v1),existeListaAresta(p->Arestas,p->sementeArestas));
		insereListaEstrela(idEstrelaListaVertice(p->Vertices,v2),existeListaAresta(p->Arestas,p->sementeArestas));
		p->numArestas++;
		p->sementeArestas++;
		return p->sementeArestas-1;
	}
	return 0;
}

/*======================================================================================*/
/* DESTROI VERTICE                                                                      */
/* IN = P, V                                                                            */
/* OUT = V                                                                              */
/*======================================================================================*/
int GVdestroiVertice(Grafo p, int v)
{
	NodoAresta aux;
	ListaEstrela estrela = idEstrelaListaVertice(p->Vertices,v);
	while(!vaziaListaEstrela(estrela))
	{
		aux = nodoListaEstrela(estrela,1);
		GAdestroiAresta(p,idListaAresta(aux));
	}
	retiraListaVertice(p->Vertices,v);
	return 0;
}

/*======================================================================================*/
/* DESTROI ARESTA                                                                       */
/* IN = P, A                                                                            */
/* OUT = A                                                                              */
/*======================================================================================*/
int GAdestroiAresta(Grafo p, int a)
{
	if(GBexisteIdAresta(p,a))
	{
		NodoVertice partida = idPartidaListaAresta(p->Arestas,a);
		NodoVertice chegada = idChegadaListaAresta(p->Arestas,a);
		ListaEstrela alfa = idEstrelaListaVertice(p->Vertices,idListaVertice(partida));
		ListaEstrela omega = idEstrelaListaVertice(p->Vertices,idListaVertice(chegada));
		NodoAresta aux = existeListaAresta(p->Arestas,a);
		retiraListaEstrela(alfa,aux);
		retiraListaEstrela(omega,aux);
		retiraListaAresta(p->Arestas,a);
		return 0;
	}
	return 1;
}

/*======================================================================================*/
/* EXISTE ID VERTICE                                                                    */
/* IN = P, V                                                                            */
/* OUT = B(BOOLEANO)                                                                    */
/*======================================================================================*/
int GBexisteIdVertice(Grafo p, int v)
{
	if(existeListaVertice(p->Vertices,v) != NULL)
	{
		return 1;
	}
	return 0;
}

/*======================================================================================*/
/* EXISTE ID ARESTA                                                                     */
/* IN = P, A                                                                            */
/* OUT = B(BOOLEANO)                                                                    */
/*======================================================================================*/
int GBexisteIdAresta(Grafo p, int a)
{
	if(existeListaAresta(p->Arestas,a) != NULL)
	{
		return 1;
	}
	return 0;
}

/*======================================================================================*/
/* EXISTE ARESTA DIRIGIDA                                                               */
/* IN = P, V1, V2                                                                       */
/* OUT = B(BOOLEANO)                                                                    */
/*======================================================================================*/
int GBexisteArestaDir(Grafo p, int v1, int v2)
{
	if(GBexisteIdVertice(p,v1) && GBexisteIdVertice(p,v2))
	{
		int i;
		NodoAresta aux;
		NodoVertice partida, chegada;
		for(i = 1; i <= tamanhoListaAresta(p->Arestas); i++)
		{
			aux = posListaAresta(p->Arestas,i);
			chegada = idChegadaListaAresta(p->Arestas,idListaAresta(aux));
			partida = idPartidaListaAresta(p->Arestas,idListaAresta(aux));
			if(v1 == idListaVertice(partida) && v2 == idListaVertice(chegada))
			{
				return 1;
			}
		}
	}
	return 0;
}

/*======================================================================================*/
/* EXISTE ARESTA                                                                        */
/* IN = P, V1, V2                                                                       */
/* OUT = B(BOOLEANO)                                                                    */
/*======================================================================================*/
int GBexisteAresta(Grafo p, int v1, int v2)
{
	if(GBexisteIdVertice(p,v1) && GBexisteIdVertice(p,v2))
	{
		int i;
		NodoAresta aux;
		NodoVertice partida, chegada;
		for(i = 1; i <= tamanhoListaAresta(p->Arestas); i++)
		{
			aux = posListaAresta(p->Arestas,i);
			chegada = idChegadaListaAresta(p->Arestas,idListaAresta(aux));
			partida = idPartidaListaAresta(p->Arestas,idListaAresta(aux));
			if((v1 == idListaVertice(partida) && v2 == idListaVertice(chegada))||
				 (v2 == idListaVertice(partida) && v1 == idListaVertice(chegada)))
			{
				return 1;
			}
		}
	}
	return 0;
}

/*======================================================================================*/
/* PEGA ARESTA DIRIGIDA                                                                 */
/* IN = P, V1, V2                                                                       */
/* OUT = A                                                                              */
/*======================================================================================*/
int GApegaArestaDir(Grafo p, int v1, int v2)
{
	if(GBexisteIdVertice(p,v1) && GBexisteIdVertice(p,v2))
	{
		int i;
		NodoAresta aux;
		NodoVertice partida, chegada;
		for(i = 1; i <= tamanhoListaAresta(p->Arestas); i++)
		{
			aux = posListaAresta(p->Arestas,i);
			chegada = idChegadaListaAresta(p->Arestas,idListaAresta(aux));
			partida = idPartidaListaAresta(p->Arestas,idListaAresta(aux));
			if(v1 == idListaVertice(partida) && v2 == idListaVertice(chegada))
			{
				return idListaAresta(aux);
			}
		}
	}
	return 0;
}

/*======================================================================================*/
/* EXISTE ARESTA                                                                        */
/* IN = P, V1, V2                                                                       */
/* OUT = A                                                                              */
/*======================================================================================*/
int GApegaAresta(Grafo p, int v1, int v2)
{
	if(GBexisteIdVertice(p,v1) && GBexisteIdVertice(p,v2))
	{
		int i;
		NodoAresta aux;
		NodoVertice partida, chegada;
		for(i = 1; i <= tamanhoListaAresta(p->Arestas); i++)
		{
			aux = posListaAresta(p->Arestas,i);
			chegada = idChegadaListaAresta(p->Arestas,idListaAresta(aux));
			partida = idPartidaListaAresta(p->Arestas,idListaAresta(aux));
			if((v1 == idListaVertice(partida) && v2 == idListaVertice(chegada))||
				 (v2 == idListaVertice(partida) && v1 == idListaVertice(chegada)))
			{
				return idListaAresta(aux);
			}
		}
	}
	return 0;
}

/*======================================================================================*/
/* PRIMEIRO VERTICE                                                                     */
/* IN = P                                                                               */
/* OUT = V                                                                              */
/*======================================================================================*/
int GVprimeiroVertice(Grafo p)
{
	if(!vaziaListaVertice(p->Vertices))
	{
		return idListaVertice(posListaVertice(p->Vertices,1));
	}
	return 0;
}

/*======================================================================================*/
/* PROXIMO VERTICE                                                                      */
/* IN = P, V1                                                                           */
/* OUT = V2                                                                             */
/*======================================================================================*/
int GVproximoVertice(Grafo p, int v1)
{
	int i;
	for(i = 1; i <= tamanhoListaVertice(p->Vertices); i++)
	{
		if(idListaVertice(posListaVertice(p->Vertices,i)) > v1)
		{
			return idListaVertice(posListaVertice(p->Vertices,i));
		}
	}
	return 0;
}

/*======================================================================================*/
/* PRIMEIRA ARESTA                                                                      */
/* IN = P                                                                               */
/* OUT = A                                                                              */
/*======================================================================================*/
int GAprimeiraAresta(Grafo p)
{
	if(!vaziaListaAresta(p->Arestas))
	{
		return idListaAresta(posListaAresta(p->Arestas,1));
	}
	return 0;
}

/*======================================================================================*/
/* PROXIMA ARESTA                                                                       */
/* IN = P, A1                                                                           */
/* OUT = A2                                                                             */
/*======================================================================================*/
int GAproximaAresta(Grafo p, int a1)
{
	int i;
	for(i = 1; i <= tamanhoListaAresta(p->Arestas); i++)
	{
		if(idListaAresta(posListaAresta(p->Arestas,i)) > a1)
		{
			return idListaAresta(posListaAresta(p->Arestas,i));
		}
	}
	return 0;
}

/*======================================================================================*/
/* NUMERO DE VERTICES                                                                   */
/* IN = P                                                                               */
/* OUT = NUMERO DE VERTICES                                                             */
/*======================================================================================*/
int GInumeroVertices(Grafo p)
{
	return tamanhoListaVertice(p->Vertices);
}

/*======================================================================================*/
/* NUMERO DE VERTICES MAX                                                               */
/* IN = P                                                                               */
/* OUT = NUMERO DE VERTICES MAX                                                         */
/*======================================================================================*/
int GInumeroVerticesMax(Grafo p)
{
	return INT_MAX;
}

/*======================================================================================*/
/* NUMERO DE ARESTAS                                                                    */
/* IN = P                                                                               */
/* OUT = NUMERO DE ARESTAS                                                             */
/*======================================================================================*/
int GInumeroArestas(Grafo p)
{
	return tamanhoListaAresta(p->Arestas);
}

/*======================================================================================*/
/* NUMERO DE ARESTAS MAX                                                                */
/* IN = P                                                                               */
/* OUT = NUMERO DE ARESTAS MAX                                                          */
/*======================================================================================*/
int GInumeroArestasMax(Grafo p)
{
	return INT_MAX;
}

/*======================================================================================*/
/* CARREGA GRAFO                                                                        */
/* IN = F(NOME DO ARQUIVO)                                                              */
/* OUT = PONTEIRO PARA GRAFO                                                            */
/*======================================================================================*/
Grafo GGcarregaGrafo(char *file)
{
 /*	FILE *Arq = fopen(file,"rt");
	Grafo g = criaGrafo();
	int i,id, partida, chegada, arestas, vertices, seedArestas, seedVertices;
	fscanf("%d %d",&vertices, &arestas)
	fscanf("%d %d",&seedVertices, &seedArestas);
	for(i = 1; i <= vertices; i++)
	{
		fscanf("%d", &id);
		//GVcriaVertice(g,id)
	}*/
	return NULL;
}

/*======================================================================================*/
/* SALVA GRAFO                                                                          */
/* IN = P, F(NOME DO ARQUIVO)                                                           */
/* OUT = B                                                                              */
/*======================================================================================*/
int GBsalvaGrafo(Grafo p, char *file)
{
	return 1;
}

/*======================================================================================*/
/* PEGA GRAU                                                                            */
/* IN = P, V                                                                            */
/* OUT = I (GRAU DO VERTICE)                                                            */
/*======================================================================================*/
int GIpegaGrau(Grafo p, int v)
{
	ListaEstrela estrela = idEstrelaListaVertice(p->Vertices, v);
	return tamanhoListaEstrela(estrela);
}

/*======================================================================================*/
/* PEGA A PRIMEIRA ARESTA                                                               */
/* IN = P, V                                                                            */
/* OUT = A1 (PRIMEIRA ARESTA)                                                           */
/*======================================================================================*/
int GAprimaAresta(Grafo p, int v)
{
	ListaEstrela estrela = idEstrelaListaVertice(p->Vertices, v);
	return idListaAresta(nodoListaEstrela(estrela, 1));
}

/*======================================================================================*/
/* PEGA A PROXIMA ARESTA                                                                */
/* IN = P, V, A1                                                                        */
/* OUT = A2 (PROXIMA ARESTA)                                                            */
/*======================================================================================*/
int GAproxAresta(Grafo p, int v, int a)
{
	int i;
	ListaEstrela estrela = idEstrelaListaVertice(p->Vertices, v);
	NodoAresta aux;
	for(i = 1; i <= tamanhoListaEstrela(estrela); i++)
	{
		aux = nodoListaEstrela(estrela,i);
		if(a > idListaAresta(aux))
		{
			return idListaAresta(aux);
		}
	}
	return 0;
}