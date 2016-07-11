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
#include "listas.h"

struct nodoEstrela
{
	struct nodoAresta *aresta;
	struct nodoEstrela *prox;
	struct nodoEstrela *ant;
};

struct listaEstrela
{
	int tam;
	NodoEstrela inicio;
	NodoEstrela fim;
};

/*================================================================================================*/
/*                                      FUNÇÕES DA LISTA ESTRELA                                  */
/*================================================================================================*/


/*================================================================================================*/
/* CRIA LISTA ESTRELA                                                                             */
/* IN : VOID                                                             OUT : PONTEIRO PARA LISTA*/
/*================================================================================================*/
ListaEstrela criaListaEstrela(void)
{
	ListaEstrela aux = (ListaEstrela) malloc(sizeof(struct listaEstrela));
	aux->tam = 0;
	aux->inicio = NULL;
	aux->fim = NULL;
	return aux;
}

/*================================================================================================*/
/* INSERE NODO ESTRELA                                                                            */
/* IN : PONTEIRO PARA ARESTA, PONTEIRO PARA LISTA                                       OUT : VOID*/
/*================================================================================================*/
void insereListaEstrela(ListaEstrela l, NodoAresta aresta)
{
	NodoEstrela aux = (NodoEstrela) malloc(sizeof(struct nodoEstrela));
	aux->aresta = aresta;
	/*caso especial = lista vazia*/
	if(vaziaListaEstrela(l))
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
int vaziaListaEstrela(ListaEstrela l)
{
	return(l->tam == 0);
}

/*================================================================================================*/
/* VERIFICA SE EXISTE NA LISTA                                                                    */
/* IN : PONTEIRO PARA LISTA, IDENTIFICADOR                                OUT : PONTEIRO PARA NODO*/
/*================================================================================================*/
NodoEstrela existeListaEstrela(ListaEstrela l, NodoAresta nodo)
{
	if(!vaziaListaEstrela(l))
	{
		NodoEstrela aux;
		for(aux = l->inicio; aux != NULL; aux = aux->prox)
		{
			if(aux->aresta == nodo)
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
void retiraListaEstrela(ListaEstrela l, NodoAresta nodo)
{
	if(!vaziaListaEstrela(l))
	{
		NodoEstrela aux = existeListaEstrela(l,nodo);
		if(aux != NULL)
		{
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
				l->fim = aux;
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
int tamanhoListaEstrela(ListaEstrela l)
{
	return (l->tam);
}

/*================================================================================================*/
/* DESTROI LISTA                                                                                  */
/* IN : PONTEIRO PARA LISTA                                                             OUT : VOID*/
/*================================================================================================*/
void destroiListaEstrela(ListaEstrela l)
{
	while(!vaziaListaEstrela(l))
	{
		NodoAresta aresta = l->inicio->aresta;
		retiraListaEstrela(l,aresta);
	}
}

/*================================================================================================*/
/* RETORNA NODO ESTRELA                                                                           */
/* IN : POS, LISTA ESTRELA                                                       OUT : NODOESTRELA*/
/*================================================================================================*/
NodoAresta nodoListaEstrela(ListaEstrela l, int pos)
{
	if(!vaziaListaEstrela(l))
	{
		NodoEstrela aux;
		for(aux = l->inicio; pos != 1; aux = aux->prox)
		{
			pos--;
		}
		return aux->aresta;
	}
	return NULL;
}