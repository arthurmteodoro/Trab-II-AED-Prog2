/*================================================================================================*/
/*              Trabalho II de Programação II e Algoritmos e Estruturas de Dados I                */
/*                Nome : Arthur Alexsander Martins Teodo      Matrícula : 0022427                 */
/*                Nome : Saulo Ricardo Dias Fernandes         Matrícula : 0021581                 */
/*                                         Data: 10/07/2016                                       */
/*================================================================================================*/

#ifndef FILA
#define FILA

typedef struct fila *Fila;

/*======================================================================================*/
/*                                    OPERACOES CRIADAS                                 */
/*======================================================================================*/
extern Fila criaFila(void);
extern void insereFila(Fila f, int valor);
extern int retiraFila(Fila f);
extern int vaziaFila(Fila f);
extern void destroiFila(Fila f);

#endif