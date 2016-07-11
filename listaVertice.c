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

struct nodoVertice
{
	int identificador;
	ListaEstrela estrela;
	struct nodoVertice *prox;
	struct nodoVertice *ant;
};

struct listaVertice
{
	int tam;
	NodoVertice inicio;
	NodoVertice fim;
};

/*================================================================================================*/
/*                                      FUNÇÕES DA LISTA VERTICE                                  */
/*================================================================================================*/


/*================================================================================================*/
/* CRIA LISTA VERTICE                                                                             */
/* IN : VOID                                                             OUT : PONTEIRO PARA LISTA*/
/*================================================================================================*/
ListaVertice criaListaVertice(void)
{
	ListaVertice aux = (ListaVertice) malloc(sizeof(struct listaVertice));
	aux->tam = 0;
	aux->inicio = NULL;
	aux->fim = NULL;
	return aux;
}

/*================================================================================================*/
/* INSERE NODO VERTICE                                                                            */
/* IN : IDENTIFICADOR, PONTEIRO PARA LISTA                                              OUT : VOID*/
/*================================================================================================*/
void insereListaVertice(ListaVertice l, int identificador)
{
	NodoVertice aux = (NodoVertice) malloc(sizeof(struct nodoVertice));
	aux->identificador = identificador;
	aux->estrela = criaListaEstrela();
	/*caso especial = lista vazia*/
	if(vaziaListaVertice(l))
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
int vaziaListaVertice(ListaVertice l)
{
	return(l->tam == 0);
}

/*================================================================================================*/
/* VERIFICA SE EXISTE NA LISTA                                                                    */
/* IN : PONTEIRO PARA LISTA, IDENTIFICADOR                                OUT : PONTEIRO PARA NODO*/
/*================================================================================================*/
NodoVertice existeListaVertice(ListaVertice l, int identificador)
{
	if(!vaziaListaVertice(l))
	{
		NodoVertice aux;
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
void retiraListaVertice(ListaVertice l, int identificador)
{
	if(!vaziaListaVertice(l))
	{
		NodoVertice aux = existeListaVertice(l,identificador);
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
int tamanhoListaVertice(ListaVertice l)
{
	return (l->tam);
}

/*================================================================================================*/
/* DESTROI LISTA                                                                                  */
/* IN : PONTEIRO PARA LISTA                                                             OUT : VOID*/
/*================================================================================================*/
void destroiListaVertice(ListaVertice l)
{
	while(!vaziaListaVertice(l))
	{
		int identificador = l->inicio->identificador;
		retiraListaVertice(l,identificador);
	}
}

/*================================================================================================*/
/* RETORNA ID VERTICE                                                                             */
/* IN : PONTEIRO PARA NODOVERTICE                                                         OUT : ID*/
/*================================================================================================*/
int idListaVertice(NodoVertice vertice)
{
	return (vertice->identificador);
}

/*================================================================================================*/
/* RETORNA LISTA ESTRELA                                                                          */
/* IN : IDVERTICE, LISTAVERTICE                                                 OUT : LISTAESTRELA*/
/*================================================================================================*/
ListaEstrela idEstrelaListaVertice(ListaVertice l, int idVertice)
{
	if(!vaziaListaVertice(l))
	{
		NodoVertice aux = existeListaVertice(l,idVertice);
		if(aux != NULL)
		{
			return aux->estrela;
		}
	}
	return NULL;
}