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
	aux->sementeArestas = 0;
	aux->sementeVertices = 0;
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
	insereListaVertice(p->Vertices,p->sementeVertices+1);
	p->sementeVertices++;
	p->numVertices++;
	return p->sementeVertices;
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
		NodoVertice partida = existeListaVertice(p->Vertices,v1);
		NodoVertice chegada = existeListaVertice(p->Vertices,v2);
		if(v1 == v2)
		{
			p->numArestas++;
			p->sementeArestas++;
			incrementaGrau(partida,2);
			insereListaAresta(p->Arestas,existeListaVertice(p->Vertices,v1),existeListaVertice(p->Vertices,v2),p->sementeArestas);
			insereListaEstrela(idEstrelaListaVertice(p->Vertices,v1),existeListaAresta(p->Arestas,p->sementeArestas));
			return p->sementeArestas;
		}
		p->numArestas++;
		p->sementeArestas++;
		incrementaGrau(chegada,1);
		incrementaGrau(partida,1);
		insereListaAresta(p->Arestas,existeListaVertice(p->Vertices,v1),existeListaVertice(p->Vertices,v2),p->sementeArestas);
		insereListaEstrela(idEstrelaListaVertice(p->Vertices,v1),existeListaAresta(p->Arestas,p->sementeArestas));
		insereListaEstrela(idEstrelaListaVertice(p->Vertices,v2),existeListaAresta(p->Arestas,p->sementeArestas));
		return p->sementeArestas;
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
		incrementaGrau(partida,-1);
		incrementaGrau(chegada,-1);
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
	if(GBexisteIdVertice(p,v1))
	{
		for(i = 1; i <= tamanhoListaVertice(p->Vertices); i++)
		{
			if(idListaVertice(posListaVertice(p->Vertices,i)) > v1)
			{
				return idListaVertice(posListaVertice(p->Vertices,i));
			}
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
	if(GBexisteIdAresta(p,a1))
	{
		int i;
		for(i = 1; i <= tamanhoListaAresta(p->Arestas); i++)
		{
			if(idListaAresta(posListaAresta(p->Arestas,i)) > a1)
			{
				return idListaAresta(posListaAresta(p->Arestas,i));
			}
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
	FILE *entrada = fopen(file,"rt");
	Grafo grafo = GGcriaGrafo();
	int vertices, arestas, idVertice, seedVertice, seedAresta, contVertices = 1, contArestas = 1;
	int omega, alfa, idAresta, arestaCriada, verticeCriado,i;
	fscanf(entrada,"%d %d", &vertices, &arestas);
	fscanf(entrada,"%d %d", &seedVertice, &seedAresta);
	for(i = 1; i <= vertices; i++)
	{
		fscanf(entrada,"%d",&idVertice);
		while(contVertices != idVertice)
		{
			verticeCriado = GVcriaVertice(grafo);
			GVdestroiVertice(grafo,verticeCriado);
			contVertices++;
		}
		verticeCriado = GVcriaVertice(grafo);
		contVertices++;
	}
	for(i = 1; i <= arestas; i++)
	{
		fscanf(entrada,"%d %d %d",&idAresta, &alfa, &omega);
		while(contArestas != idAresta)
		{
			arestaCriada = GAcriaAresta(grafo,verticeCriado,verticeCriado);
			GAdestroiAresta(grafo,arestaCriada);
			contArestas++;
		}
		arestaCriada = GAcriaAresta(grafo,alfa,omega);
		contArestas++;
	}
	fclose(entrada);
	return grafo;
}

/*======================================================================================*/
/* SALVA GRAFO                                                                          */
/* IN = P, F(NOME DO ARQUIVO)                                                           */
/* OUT = B                                                                              */
/*======================================================================================*/
int GBsalvaGrafo(Grafo p, char *file)
{
	FILE *saida = fopen(file,"wt");
	int i;
	fprintf(saida, "%d %d\n", GInumeroVertices(p), GInumeroArestas(p));
	fprintf(saida, "%d %d\n", p->sementeVertices, p->sementeArestas);
	for(i = GVprimeiroVertice(p); i != 0; i = GVproximoVertice(p,i))
	{
		fprintf(saida, "%d\n", i);
	}
	for(i = GAprimeiraAresta(p); i != 0; i = GAproximaAresta(p,i))
	{
		fprintf(saida, "%d %d %d\n", i, GValfa(p,i), GVomega(p,i));
	}
	fclose(saida);
	return 1;
}

/*======================================================================================*/
/* PEGA GRAU                                                                            */
/* IN = P, V                                                                            */
/* OUT = I (GRAU DO VERTICE)                                                            */
/*======================================================================================*/
int GIpegaGrau(Grafo p, int v)
{
	if(GBexisteIdVertice(p,v))
	{
		NodoVertice vertice = existeListaVertice(p->Vertices,v);
		return consultaGrau(vertice);
	}
	return 0;
}

/*======================================================================================*/
/* PEGA A PRIMEIRA ARESTA                                                               */
/* IN = P, V                                                                            */
/* OUT = A1 (PRIMEIRA ARESTA)                                                           */
/*======================================================================================*/
int GAprimaAresta(Grafo p, int v)
{
	if(GBexisteIdVertice(p,v))
	{
		ListaEstrela estrela = idEstrelaListaVertice(p->Vertices, v);
		return idListaAresta(nodoListaEstrela(estrela, 1));
	}
	return 0;
}

/*======================================================================================*/
/* PEGA A PROXIMA ARESTA                                                                */
/* IN = P, V, A1                                                                        */
/* OUT = A2 (PROXIMA ARESTA)                                                            */
/*======================================================================================*/
int GAproxAresta(Grafo p, int v, int a)
{
	if(GBexisteIdVertice(p,v) && GBexisteIdAresta(p,a))
	{
		int i;
		ListaEstrela estrela = idEstrelaListaVertice(p->Vertices, v);
		NodoAresta aux;
		for(i = 1; i <= tamanhoListaEstrela(estrela); i++)
		{
			aux = nodoListaEstrela(estrela,i);
			if(a < idListaAresta(aux))
			{
				return idListaAresta(aux);
			}
		}
	}
	return 0;
}

/*======================================================================================*/
/* PEGA A PRIMEIRA ARESTA DE ENTRADA                                                    */
/* IN = P, V                                                                            */
/* OUT = A1 (PRIMEIRA ARESTA)                                                           */
/*======================================================================================*/
int GAprimaEntrada(Grafo p, int v)
{
  if(GBexisteIdVertice(p,v))
  {
  	ListaEstrela estrela = idEstrelaListaVertice(p->Vertices, v);
  	NodoAresta aux;
  	int i, idA, idV;
  	for(i = 1; i <= tamanhoListaEstrela(estrela); i++)
  	{
  		aux = nodoListaEstrela(estrela,i);
  		idA = idListaAresta(aux);
  		idV = idListaVertice(idChegadaListaAresta(p->Arestas,idA));
  		if(idV == v)
  		{
  			return idA;
  		}
  	}
  	return 0;
  }
  return 0;
}

/*======================================================================================*/
/* PEGA A PROXIMA ARESTA DE ENTRADA                                                     */
/* IN = P, V, A1                                                                            */
/* OUT = A2 (PROXIMA ARESTA)                                                            */
/*======================================================================================*/
int GAproxEntrada(Grafo p, int v, int a1)
{
  if(GBexisteIdVertice(p,v) && GBexisteIdAresta(p,a1))
  {
  	ListaEstrela estrela = idEstrelaListaVertice(p->Vertices, v);
  	NodoAresta aux;
  	int i, idA, idV;
  	for(i = 1; i <= tamanhoListaEstrela(estrela); i++)
  	{
  		aux = nodoListaEstrela(estrela,i);
  		idA = idListaAresta(aux);
  		idV = idListaVertice(idChegadaListaAresta(p->Arestas,idA));
  		if((idV == v) && (idA > a1))
  		{
  			return idA;
  		}
  	}
  	return 0;
  }
  return 0;
}

/*======================================================================================*/
/* PEGA A PRIMEIRA ARESTA DE SAIDA                                                      */
/* IN = P, V                                                                            */
/* OUT = A1 (PRIMEIRA ARESTA)                                                           */
/*======================================================================================*/
int GAprimaSaida(Grafo p, int v)
{
  if(GBexisteIdVertice(p,v))
  {
  	ListaEstrela estrela = idEstrelaListaVertice(p->Vertices, v);
  	NodoAresta aux;
  	int i, idA, idV;
  	for(i = 1; i <= tamanhoListaEstrela(estrela); i++)
  	{
  		aux = nodoListaEstrela(estrela,i);
  		idA = idListaAresta(aux);
  		idV = idListaVertice(idPartidaListaAresta(p->Arestas,idA));
  		if(idV == v)
  		{
  			return idA;
  		}
  	}
  	return 0;
  }
  return 0;
}

/*======================================================================================*/
/* PEGA A PROXIMA ARESTA DE SAIDA                                                       */
/* IN = P, V, A1                                                                        */
/* OUT = A2 (PROXIMA ARESTA)                                                            */
/*======================================================================================*/
int GAproxSaida(Grafo p, int v, int a1)
{
  if(GBexisteIdVertice(p,v))
  {
  	ListaEstrela estrela = idEstrelaListaVertice(p->Vertices, v);
  	NodoAresta aux;
  	int i, idA, idV;
  	for(i = 1; i <= tamanhoListaEstrela(estrela); i++)
  	{
  		aux = nodoListaEstrela(estrela,i);
  		idA = idListaAresta(aux);
  		idV = idListaVertice(idPartidaListaAresta(p->Arestas,idA));
  		if((idV == v) && (idA > a1))
  		{
  			return idA;
  		}
  	}
  	return 0;
  }
  return 0;
}

/*======================================================================================*/
/* VERIFICA SE É UM LAÇO                                                                */
/* IN = P,A                                                                             */
/* OUT = BOOL                                                                           */
/*======================================================================================*/
int GBarestaLaco(Grafo p, int a)
{
	if(GBexisteIdAresta(p,a))
	{
		int alfa, omega;
		alfa = idListaVertice(idChegadaListaAresta(p->Arestas,a));
		omega = idListaVertice(idPartidaListaAresta(p->Arestas,a));
		if(alfa == omega)
		{
			return 1;
		}
		return 0;
	}	
	return 0;
}

/*======================================================================================*/
/* PEGA O VERTICE DE PARTIDA DA ARESTA                                                  */
/* IN = P, A                                                                            */
/* OUT = V                                                                              */
/*======================================================================================*/
int GValfa(Grafo p, int a)
{
	if(GBexisteIdAresta(p,a))
	{
		return idListaVertice(idPartidaListaAresta(p->Arestas,a));
	}
	return 0;
}

/*======================================================================================*/
/* PEGA O VERTICE DE CHEGADA DA ARESTA                                                  */
/* IN = P, A                                                                            */
/* OUT = V                                                                              */
/*======================================================================================*/
int GVomega(Grafo p, int a)
{
	if(GBexisteIdAresta(p,a))
	{
		return idListaVertice(idChegadaListaAresta(p->Arestas,a));
	}
	return 0;
}

/*======================================================================================*/
/* PEGA O VERTICE VIZINHO DA ARESTA                                                     */
/* IN = P, A, V1                                                                        */
/* OUT = V2                                                                             */
/*======================================================================================*/
int GVvizinho(Grafo p, int a, int v1)
{
	if(GBexisteIdAresta(p,a) && (GBexisteIdVertice(p,v1)))
	{
		int alfa, omega;
		alfa = idListaVertice(idChegadaListaAresta(p->Arestas,a));
		omega = idListaVertice(idPartidaListaAresta(p->Arestas,a));	
		if(alfa == v1)
		{
			return omega;
		}
		if(omega == v1)
		{
			return alfa;
		}
		return 0;
	}
	return 0;
}