/*================================================================================================*/
/*              Trabalho II de Programação II e Algoritmos e Estruturas de Dados I                */
/*                Nome : Arthur Alexsander Martins Teodo      Matrícula : 0022427                 */
/*                Nome : Saulo Ricardo Dias Fernandes         Matrícula : 0021581                 */
/*                                         Data: 10/07/1016                                       */
/*================================================================================================*/

#ifndef GRAFO_TRABII
#define GRAFO_TRABII

typedef struct grafo *Grafo;

/*======================================================================================*/
/*                                    OPERACOES CRIADAS                                 */
/*======================================================================================*/
extern Grafo GGcriaGrafo(void);
extern Grafo GGdestroiGrafo(Grafo p);
extern int GVcriaVertice(Grafo p);
extern int GAcriaAresta(Grafo p, int v1, int v2);
extern int GVdestroiVertice(Grafo g, int v);
extern int GAdestroiAresta(Grafo p, int a);
extern int GBexisteIdVertice(Grafo p, int v);
extern int GBexisteIdAresta(Grafo p, int a);
extern int GBexisteArestaDir(Grafo p, int v1, int v2);
extern int GBexisteAresta(Grafo p, int v1, int v2);
extern int GApegaArestaDir(Grafo p, int v1, int v2);
extern int GApegaAresta(Grafo p, int v1, int v2);
extern int GVprimeiroVertice(Grafo p);
extern int GVproximoVertice(Grafo p, int v1);
extern int GAprimeiraAresta(Grafo p);
extern int GAproximaAresta(Grafo p, int a1);
extern int GInumeroVertices(Grafo p);
extern int GInumeroVerticesMax(Grafo p);
extern int GInumeroArestas(Grafo p);
extern int GInumeroArestasMax(Grafo p);
extern Grafo GGcarregaGrafo(char *file);

#endif