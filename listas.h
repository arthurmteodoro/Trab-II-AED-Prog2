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

/*================================================================================================*/
/*                                        LISTA ARESTA                                            */
/*================================================================================================*/
extern ListaAresta criaListaAresta(void);
extern void insereListaAresta(ListaAresta l, NodoVertice partida, NodoVertice chegada, int identificador);
extern int vaziaListaAresta(ListaAresta l);
extern NodoVertice existeListaVertice(ListaVertice l, int identificador);
extern void retiraListaAresta(ListaAresta l, int identificador);
extern int tamanhoListaAresta(ListaAresta l);
extern void destroiListaAresta(ListaAresta l);
extern int idListaAresta(NodoAresta aresta);
extern NodoVertice idChegadaListaVertice(ListaAresta l, int idAresta);
extern NodoVertice idPartidaListaVertice(ListaAresta l, int idAresta);

/*================================================================================================*/
/*                                        LISTA ESTRELA                                           */
/*================================================================================================*/
extern ListaEstrela criaListaEstrela(void);
extern void insereListaEstrela(ListaEstrela l, NodoAresta aresta);
extern int vaziaListaEstrela(ListaEstrela l);
extern NodoEstrela existeListaEstrela(ListaEstrela l, NodoAresta nodo);
extern void retiraListaEstrela(ListaEstrela l, NodoAresta nodo);
extern int tamanhoListaEstrela(ListaEstrela l);	
extern void destroiListaEstrela(ListaEstrela l);
extern NodoAresta nodoListaEstrela(ListaEstrela l, int pos);


#endif