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
#include "pilha.h"

struct nodoPilha
{
	int valor;
	struct nodoPilha *prox;
};

typedef struct nodoPilha *NodoPilha;

struct pilha
{
	int tam;
	NodoPilha inicio;
};

/*======================================================================================*/
/*                                  FUNÇÕES DA PILHA                                    */
/*======================================================================================*/

/*======================================================================================*/
/* CRIA PILHA                                                                           */
/* IN = VOID                                                                            */
/* OUT = PONTEIRO PARA PILHA                                                            */
/*======================================================================================*/
Pilha criaPilha(void)
{
	Pilha stack = (Pilha) malloc(sizeof(struct pilha));
	stack->tam = 0;
	stack->inicio = NULL;
	return stack;
}

/*======================================================================================*/
/* INSERE VALOR NA PILHA                                                                */
/* IN = VALOR A SER INSERIDO, PILHA A INSERIR                                           */
/* OUT = VOID                                                                           */
/*======================================================================================*/
void inserePilha(Pilha stack, int valor)
{
	NodoPilha novoNodo = (NodoPilha) malloc(sizeof(struct nodoPilha));
	novoNodo->valor = valor;
	if(vaziaPilha(stack))
	{
		novoNodo->prox = NULL;
		stack->inicio = novoNodo;
		stack->tam++;
		return;
	}
	novoNodo->prox = stack->inicio;
	stack->inicio = novoNodo;
	stack->tam++;
	return;
}

/*======================================================================================*/
/* RETIRA UM ELEMENTO DA PILHA                                                          */
/* IN = PONTEIRO PARA PILHA                                                             */
/* OUT = VALOR RETIRADO                                                                 */
/*======================================================================================*/
int retirarPilha(Pilha stack)
{
	if(!vaziaPilha(stack))
	{
		NodoPilha retirar = stack->inicio;
		int valor = retirar->valor;
		/*Caso existir somente um elemento da pilha*/
		if(stack->tam == 1)
		{
			free(retirar);
			stack->inicio = NULL;
			stack->tam--;
			return valor;
		}
		stack->inicio = retirar->prox;
		free(retirar);
		stack->tam--;
		return valor;
	}
	return 0;
}

/*======================================================================================*/
/* VERIFICA SE A PILHA ESTA VAZIA                                                       */
/* IN = PONTEIRO PARA PILHA                                                             */
/* OUT = VALOR SE ESTA VAZIA                                                            */
/*======================================================================================*/
int vaziaPilha(Pilha stack)
{
	return (stack->tam == 0);
}

/*======================================================================================*/
/* OLHA O ELEMENTO DO TOPO DA PILHA                                                     */
/* IN = PONTEIRO PARA PILHA                                                             */
/* OUT = VALOR DO TOPO DA PILHA                                                         */
/*======================================================================================*/
int consultaPilha(Pilha stack)
{
	if(!vaziaPilha(stack))
	{
		return (stack->inicio->valor);
	}
	return 0;
}

/*======================================================================================*/
/* DESTROI A PILHA                                                                      */
/* IN = PONTEIRO PARA PILHA                                                             */
/* OUT = VOID                                                                           */
/*======================================================================================*/
void destroiPilha(Pilha stack)
{
	if(!vaziaPilha(stack))
	{
		while(!vaziaPilha(stack))
		{
			retirarPilha(stack);
		}
	}
}