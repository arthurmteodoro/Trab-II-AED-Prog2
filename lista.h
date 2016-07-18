/*Nomes : Arthur Alexsander Martins Teodoro           Matrícula : 0022427*/
/*        Saulo Ricardo Dias Fernandes                Matrícula : 0021581*/
/*Data: 02/06/2016*/

#ifndef _Lista_Simples
#define _Lista_Simples

typedef struct lista *Lista;

extern Lista criaLista(void);
extern Lista destroiLista(Lista l);
extern void insereNaLista(Lista l, float valor);
extern void retiraLista(Lista l, int pos);
extern void insereInicioLista(Lista l, float valor);
extern int vaziaLista(Lista l);
extern void printaLista(Lista l);
extern void mudaValorLista(Lista l, int pos, float valor);
extern int existeNaLista(Lista l, float valor);
extern float pegaMenorValor(Lista l);
extern int tamanhoLista(Lista l);
extern float pegaValorLista(Lista l, int pos);
extern int pegaPosLista(Lista l, float valor);

#endif