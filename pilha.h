/*================================================================================================*/
/*              Trabalho II de Programação II e Algoritmos e Estruturas de Dados I                */
/*                Nome : Arthur Alexsander Martins Teodo      Matrícula : 0022427                 */
/*                Nome : Saulo Ricardo Dias Fernandes         Matrícula : 0021581                 */
/*                                         Data: 10/07/2016                                       */
/*================================================================================================*/

#ifndef PILHA
#define PILHA

typedef struct pilha *Pilha;

/*======================================================================================*/
/*                                    OPERACOES CRIADAS                                 */
/*======================================================================================*/
extern Pilha criaPilha(void);
extern void inserePilha(Pilha stack, int valor);
extern int retirarPilha(Pilha stack);
extern int vaziaPilha(Pilha stack);
extern int consultaPilha(Pilha stack);
extern void destroiPilha(Pilha stack);

#endif