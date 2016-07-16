/*================================================================================================*/
/*              Trabalho II de Programação II e Algoritmos e Estruturas de Dados I                */
/*                Nome : Arthur Alexsander Martins Teodo      Matrícula : 0022427                 */
/*                Nome : Saulo Ricardo Dias Fernandes         Matrícula : 0021581                 */
/*                                         Data: 10/07/1016                                       */
/*================================================================================================*/

/*================================================================================================*/
/*                                      BIBLIOTECAS                                               */
/*================================================================================================*/
#include <stdlib.h>
#include <stdio.h>
#include "listas.h"

struct nodoAresta
{
	int identificador;
	struct nodoVertice *partida;
	struct nodoVertice *chegada;
	struct nodoAresta *prox;
	struct nodoAresta *ant;
};

struct listaAresta
{
	int tam;
	NodoAresta inicio;
	NodoAresta fim;
};

/*================================================================================================*/
/*                                      FUNÇÕES DA LISTA ARESTA                                   */
/*================================================================================================*/


/*================================================================================================*/
/* CRIA LISTA ARESTA                                                                              */
/* IN : VOID                                                             OUT : PONTEIRO PARA LISTA*/
/*================================================================================================*/
ListaAresta criaListaAresta(void)
{
	ListaAresta aux = (ListaAresta) malloc(sizeof(struct listaAresta));
	aux->tam = 0;
	aux->inicio = NULL;
	aux->fim = NULL;
	return aux;
}

/*================================================================================================*/
/* INSERE NODO ARESTA                                                                             */
/* IN : VERTICE ENTRADA E SAIDA, PONTEIRO PARA LISTA                                    OUT : VOID*/
/*================================================================================================*/
void insereListaAresta(ListaAresta l, NodoVertice partida, NodoVertice chegada, int identificador)
{
	NodoAresta aux = (NodoAresta) malloc(sizeof(struct nodoAresta));
	aux->partida = partida;
	aux->chegada = chegada;
	aux->identificador = identificador;
	/*caso especial = lista vazia*/
	if(vaziaListaAresta(l))
	{
		l->inicio = aux;
		l->fim = aux;
		l->tam++;
		aux->prox = NULL;
		aux->ant = NULL;
		return;
	}
	aux->ant = l->fim;
	l->fim->prox = aux;
	aux->prox = NULL;
	l->fim = aux;
	l->tam++;
	return;
}

/*================================================================================================*/
/* VERIFICA SE A LISTA ESTA VAZIA                                                                 */
/* IN : PONTEIRO PARA LISTA                                                             OUT : BOOL*/
/*================================================================================================*/
int vaziaListaAresta(ListaAresta l)
{
	return(l->tam == 0);
}

/*================================================================================================*/
/* VERIFICA SE EXISTE NA LISTA                                                                    */
/* IN : PONTEIRO PARA LISTA, IDENTIFICADOR                                OUT : PONTEIRO PARA NODO*/
/*================================================================================================*/
NodoAresta existeListaAresta(ListaAresta l, int identificador)
{
	if(!vaziaListaAresta(l))
	{
		NodoAresta aux;
		for(aux = l->inicio; aux != NULL; aux = aux->prox)
		{
			if(aux->identificador == identificador)
			{
				return aux;
			}
		}
	}
	return NULL;
}

/*================================================================================================*/
/* RETIRA DA LISTA                                                                                */
/* IN : PONTEIRO PARA LISTA, IDENTIFICADOR                                              OUT : VOID*/
/*================================================================================================*/
void retiraListaAresta(ListaAresta l, int identificador)
{
	if(!vaziaListaAresta(l))
	{
		NodoAresta aux = existeListaAresta(l,identificador);
		if(aux != NULL)
		{
			/*Caso for o unico elemento*/
			if(l->inicio->prox == NULL)
			{
				free(aux);
				l->inicio = NULL;
				l->fim = NULL;
				l->tam--;
				return;
			}
			/*Caso for no inicio*/
			if(aux->ant == NULL)
			{
				aux->prox->ant = NULL;
				l->inicio = aux->prox;
				free(aux);
				l->tam--;
				return;
			}
			/*Caso for no fim*/
			if(aux->prox == NULL)
			{
				aux->ant->prox = NULL;
				l->fim = aux->ant;
				free(aux);
				l->tam--;			
				return;
			}
			/*Retirar do meio*/
			aux->ant->prox = aux->prox;
			aux->prox->ant = aux->ant;
			free(aux);
			l->tam--;
			return;
		}
	}	
}

/*================================================================================================*/
/* TAMANHO DA LISTA                                                                               */
/* IN : PONTEIRO PARA LISTA                                                              OUT : TAM*/
/*================================================================================================*/
int tamanhoListaAresta(ListaAresta l)
{
	return (l->tam);
}

/*================================================================================================*/
/* DESTROI LISTA                                                                                  */
/* IN : PONTEIRO PARA LISTA                                                             OUT : VOID*/
/*================================================================================================*/
void destroiListaAresta(ListaAresta l)
{
	int identificador;
	while(!vaziaListaAresta(l))
	{
		identificador = l->inicio->identificador;
		retiraListaAresta(l,identificador);
	}
}

/*================================================================================================*/
/* RETORNA ID ARESTA                                                                              */
/* IN : PONTEIRO PARA NODOARESTA                                                          OUT : ID*/
/*================================================================================================*/
int idListaAresta(NodoAresta aresta)
{
	return (aresta->identificador);
}

/*================================================================================================*/
/* RETORNA NODO ARESTA DE CHEGADA                                                                 */
/* IN : IDARESTA, LISTAARESTA                                                    OUT : NODOCHEGADA*/
/*================================================================================================*/
NodoVertice idChegadaListaAresta(ListaAresta l, int idAresta)
{
	if(!vaziaListaAresta(l))
	{
		NodoAresta aux = existeListaAresta(l,idAresta);
		if(aux != NULL)
		{
			return aux->chegada;
		}
	}
	return NULL;
}

/*================================================================================================*/
/* RETORNA NODO ARESTA DE PARTIDA                                                                 */
/* IN : IDARESTA, LISTAARESTA                                                    OUT : NODOCHEGADA*/
/*================================================================================================*/
NodoVertice idPartidaListaAresta(ListaAresta l, int idAresta)
{
	if(!vaziaListaAresta(l))
	{
		NodoAresta aux = existeListaAresta(l,idAresta);
		if(aux != NULL)
		{
			return aux->partida;
		}
	}
	return NULL;
}

/*================================================================================================*/
/* RETORNA NODO POS                                                                               */
/* IN : POS, LISTAARESTA                                                          OUT : NODOARESTA*/
/*================================================================================================*/
NodoAresta posListaAresta(ListaAresta l, int pos)
{
	if(!vaziaListaAresta(l))
	{
		NodoAresta aux;
		for(aux = l->inicio; pos != 1; aux = aux->prox)
		{
			pos--;
		}
		return aux;
	}
	return NULL;
}