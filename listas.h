/*================================================================================================*/
/*              Trabalho II de Programação II e Algoritmos e Estruturas de Dados I                */
/*                Nome : Arthur Alexsander Martins Teodo      Matrícula : 0022427                 */
/*                Nome : Saulo Ricardo Dias Fernandes         Matrícula : 0021581                 */
/*                                         Data: 10/07/1016                                       */
/*================================================================================================*/

#ifndef LISTAS_TRAB

#define LISTAS_TRAB

typedef struct nodoVertice *NodoVertice;
typedef struct nodoAresta *NodoAresta;
typedef struct nodoEstrela *NodoEstrela;
typedef struct listaVertice *ListaVertice;
typedef struct listaAresta *ListaAresta;
typedef struct listaEstrela *ListaEstrela;

/*================================================================================================*/
/*                                        LISTA VERTICE                                           */
/*================================================================================================*/
extern ListaVertice criaListaVertice(void);
extern void insereListaVertice(ListaVertice l, int identificador);
extern int vaziaListaVertice(ListaVertice l);
extern NodoVertice existeListaVertice(ListaVertice l, int identificador);
extern void retiraListaVertice(ListaVertice l, int identificador);
extern int tamanhoListaVertice(ListaVertice l);
extern void destroiListaVertice(ListaVertice l);
extern int idListaVertice(NodoVertice vertice);
extern ListaEstrela idEstrelaListaVertice(ListaVertice l, int idVertice);
extern NodoVertice posListaVertice(ListaVertice l, int pos);

/*================================================================================================*/
/*                                        LISTA ARESTA                                            */
/*================================================================================================*/
extern ListaAresta criaListaAresta(void);
extern void insereListaAresta(ListaAresta l, NodoVertice partida, NodoVertice chegada, int identificador);
extern int vaziaListaAresta(ListaAresta l);
extern NodoAresta existeListaAresta(ListaAresta l, int identificador);
extern void retiraListaAresta(ListaAresta l, int identificador);
extern int tamanhoListaAresta(ListaAresta l);
extern void destroiListaAresta(ListaAresta l);
extern int idListaAresta(NodoAresta aresta);
extern NodoVertice idChegadaListaAresta(ListaAresta l, int idAresta);
extern NodoVertice idPartidaListaAresta(ListaAresta l, int idAresta);
extern NodoAresta posListaAresta(ListaAresta l, int pos);

/*================================================================================================*/
/*                                        LISTA ESTRELA                                           */
/*================================================================================================*/
extern ListaEstrela criaListaEstrela(void);
extern void insereListaEstrela(ListaEstrela l, NodoAresta aresta);
extern int vaziaListaEstrela(ListaEstrela l);
extern NodoEstrela existeListaEstrela(ListaEstrela l, NodoAresta nodo);
extern int tamanhoListaEstrela(ListaEstrela l);	
extern void destroiListaEstrela(ListaEstrela l);
extern NodoAresta nodoListaEstrela(ListaEstrela l, int pos);
extern NodoEstrela posListaEstrela(ListaEstrela l, int pos);


#endif