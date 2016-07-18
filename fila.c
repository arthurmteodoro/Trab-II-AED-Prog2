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
#include "fila.h"

struct nodoFila
{
	int valor;
	struct nodoFila *prox;
	struct nodoFila *ant;
};

typedef struct nodoFila *NodoFila;

struct fila
{
	int tam;
	NodoFila entrada;
	NodoFila saida;
};

/*======================================================================================*/
/*                                  FUNÇÕES DA FILA                                     */
/*======================================================================================*/

/*======================================================================================*/
/* CRIA FILA                                                                            */
/* IN = VOID                                                                            */
/* OUT = PONTEIRO PARA FILA                                                             */
/*======================================================================================*/
Fila criaFila(void)
{
	Fila aux = (Fila) malloc(sizeof(struct fila));
	aux->tam = 0;
	aux->entrada = NULL;
	aux->saida = NULL;
	return aux;
}

/*======================================================================================*/
/* INSERE ELEMENTO NA FILA                                                              */
/* IN = FILA A INSERIR, VALOR SER INSERIDO                                              */
/* OUT = VOID                                                                           */
/*======================================================================================*/
void insereFila(Fila f, int valor)
{
	NodoFila aux = (NodoFila) malloc(sizeof(struct nodoFila));
	aux->valor = valor;
	/*Caso a fila esteva vazia*/
	if(vaziaFila(f))
	{
		f->entrada = aux;
		f->saida = aux;
		aux->prox = NULL;
		aux->ant = NULL;
		f->tam++;
		return;
	}
	aux->prox = f->entrada;
	aux->ant = NULL;
	f->entrada = aux;
	f->tam++;
}

/*======================================================================================*/
/* RETIRA UM ELEMENTO DA FILA                                                           */
/* IN = FILA QUE DESEJA RETIRAR ELEMENTO                                                */
/* OUT = VALOR RETIRADO                                                                 */
/*======================================================================================*/
int retiraFila(Fila f)
{
	if(!vaziaFila(f))
	{
		NodoFila aux = f->saida;
		int valor = aux->valor;
		if(f->tam == 1)
		{
			free(aux);
			f->entrada = NULL;
			f->saida = NULL;
			f->tam--;
			return valor;
		}
		f->saida = aux->ant;
		f->saida->prox = NULL;
		free(aux);
		f->tam--;
		return valor;
	}
	return 0;
}

/*======================================================================================*/
/* VERIFICA SE A FILA ESTA VAZIA                                                        */
/* IN = FILA QUE DESEJA VERIFICAR                                                       */
/* OUT = VALOR BOOLEANO                                                                 */
/*======================================================================================*/
int vaziaFila(Fila f)
{
	return (f->tam == 1);
}

/*======================================================================================*/
/* DESTROI FILA                                                                         */
/* IN = FILA QUE DESEJA DESTRUIR                                                        */
/* OUT = VOID                                                                           */
/*======================================================================================*/
void destroiFila(Fila f)
{
	if(f != NULL)
	{
		while(!vaziaFila(f))
		{
			retiraFila(f);
		}
		free(f);
		f = NULL;
	}
}