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
#include <time.h>

struct medida
{
	double tempo, comparacoes, trocas;
};

typedef struct medida *medidas;

/*================================================================================================*/
/*                                    PROTOTIPO DAS FUNÇÕES                                       */
/*================================================================================================*/
void preencheVetor (unsigned long int *v, int t);
void copiaVetor (unsigned long int *c, unsigned long int *v, int t);
int ordenadoCorretamente (unsigned long int *v, int t);
int realizaVerificacao(unsigned long int i, unsigned long int j, long int *verificacoes);
void realizaTrocas(unsigned long int *v, int i, int j, long int *trocas);
void ordenacaoBolha(unsigned long int *v, int tam, medidas m);
void ordenacaoInsercao(unsigned long int *v, int tam, medidas m);
void Particao(unsigned long int *v, int esq, int dir, int *I, int *J, long int *troca, long int *comp);
void ordenacaoQuicksort(unsigned long int *v, int esq, int dir, long int *comp, long int *troca);
int pegaMediana(int esq, int dir);
void ordenacaoQuicksortTurbinado(unsigned long int *v, int esq, int dir, long int *comp, long int *troca);
void insercaoTurbinado(unsigned long int *v, int inicio, int fim, long int *trocas, long int*comps);
void Quicksort(unsigned long int *v, int tam, medidas m);
void QuicksortTurbinado(unsigned long int *v, int tam, medidas m);

/*================================================================================================*/
/*                                         FUNÇÃO MAIN                                             */
/*================================================================================================*/
int main(int argc, char const *argv[])
{
	/*Declaração das variaveis*/
	unsigned long int* vetor;
	unsigned long int* copia1;
	unsigned long int* copia2;
	unsigned long int* copia3;
	unsigned long int* copia4;
	double tempo_medio1=0.0, comparacoes_medias1=0.0, trocas_medias1=0.0;
	double tempo_medio2=0.0, comparacoes_medias2=0.0, trocas_medias2=0.0;
	double tempo_medio3=0.0, comparacoes_medias3=0.0, trocas_medias3=0.0;
	double tempo_medio4=0.0, comparacoes_medias4=0.0, trocas_medias4=0.0;
	int exec, tam;
	medidas m1, m2, m3, m4;

	/*verificacao se os argumentos estao corretos*/
	if(argc != 2)
	{
		printf("Usar ./ordenacao <tamanho>\n");
		return 1;
	}
	tam = atoi(argv[1]);

	/*Alocacao das estruturas */
	m1 = (medidas) malloc (sizeof (struct medida));
	m2 = (medidas) malloc (sizeof (struct medida));
	m3 = (medidas) malloc (sizeof (struct medida));
	m4 = (medidas) malloc (sizeof (struct medida));
	vetor = (unsigned long int*) malloc(tam*sizeof(unsigned long int));
	copia1 = (unsigned long int*) malloc(tam*sizeof(unsigned long int));
	copia2 = (unsigned long int*) malloc(tam*sizeof(unsigned long int));
	copia3 = (unsigned long int*) malloc(tam*sizeof(unsigned long int));
	copia4 = (unsigned long int*) malloc(tam*sizeof(unsigned long int));

	for(exec = 1; exec <= 3; exec++)
	{
		printf("INICIO DA EXECUCAO %d\n\n", exec);

		/*Preenche o vetores*/
		printf ("Preenchendo vetor aleatoriamente \n");
		preencheVetor(vetor, tam);
		if(!vetor)
		{
			printf("ERRO - Falta de memória\n");
			return 1;
		}

		/*Copia os vetores para ordenar por vários métodos*/
		printf("Realizando a copia dos vetores\n");
		copiaVetor(copia1,vetor,tam);
		if(!copia1)
		{
			printf("ERRO - Falta de memória\n");
			return 1;
		}
		copiaVetor(copia2,vetor,tam);
		if(!copia2)
		{
			printf("ERRO - Falta de memória\n");
			return 1;
		}
		copiaVetor(copia3,vetor,tam);
		if(!copia3)
		{
			printf("ERRO - Falta de memória\n");
			return 1;
		}
		copiaVetor(copia4,vetor,tam);
		if(!copia4)
		{
			printf("ERRO - Falta de memória\n");
			return 1;
		}

		/*==================================Ordenacao por Bolha================================*/
		printf("\n====== Ordenando com o método da bolha ======\n");
		ordenacaoBolha(copia1,tam,m1);
		if(ordenadoCorretamente(copia1, tam))
		{
			printf ("Vetor ordenado corretamente\n");
			tempo_medio1 = tempo_medio1 + m1->tempo;
			comparacoes_medias1 = comparacoes_medias1 + m1->comparacoes;
			trocas_medias1 = trocas_medias1 + m1->trocas;
			printf("Quantidade de trocas %.2lf\n", m1->trocas);
			printf("Tempo gasto %lf\n", m1->tempo);
			printf("Quantidade de comparacoes %.2lf\n", m1->comparacoes);
		}
		else
			printf("ERRO: Vetor nao ordenado\n");
		
		/*=============================Ordenacao por Insercao===================================*/
		printf("\n====== Ordenando com o método da insercao ======\n");
		ordenacaoInsercao(copia2,tam,m2);
		if(ordenadoCorretamente(copia2, tam))
		{
			printf ("Vetor ordenado corretamente\n");
			tempo_medio2 = tempo_medio2 + m2->tempo;
			comparacoes_medias2 = comparacoes_medias2 + m2->comparacoes;
			trocas_medias2 = trocas_medias2 + m2->trocas;
			printf("Quantidade de trocas %.2lf\n", m2->trocas);
			printf("Tempo gasto %lf\n", m2->tempo);
			printf("Quantidade de comparacoes %.2lf\n", m2->comparacoes);
		}
		else
			printf("ERRO: Vetor nao ordenado\n");

		/*===============================Ordenacao por Quicksort=================================*/
		printf("\n====== Ordenando com quicksort por mediana de tres sorteios ======\n");
		Quicksort(copia3,tam,m3);
		if(ordenadoCorretamente(copia3, tam))
		{
			printf ("Vetor ordenado corretamente\n");
			tempo_medio3 = tempo_medio3 + m3->tempo;
			comparacoes_medias3 = comparacoes_medias3 + m3->comparacoes;
			trocas_medias3 = trocas_medias3 + m3->trocas;
			printf("Quantidade de trocas %.2lf\n", m3->trocas);
			printf("Tempo gasto %lf\n", m3->tempo);
			printf("Quantidade de comparacoes %.2lf\n", m3->comparacoes);
		}
		else
			printf("ERRO: Vetor nao ordenado\n");	

		/*===========================Ordenacao por Quicksort Turbinado=============================*/
		printf("\n====== Ordenando com quicksort turbinado ======\n");
		QuicksortTurbinado(copia4,tam,m4);
		if(ordenadoCorretamente(copia4, tam))
		{
			printf ("Vetor ordenado corretamente\n");
			tempo_medio4 = tempo_medio4 + m4->tempo;
			comparacoes_medias4 = comparacoes_medias4 + m4->comparacoes;
			trocas_medias4 = trocas_medias4 + m4->trocas;
			printf("Quantidade de trocas %.2lf\n", m4->trocas);
			printf("Tempo gasto %lf\n", m4->tempo);
			printf("Quantidade de comparacoes %.2lf\n", m4->comparacoes);
		}
		else
			printf("ERRO: Vetor nao ordenado\n");

		printf("FIM DA EXECUCAO %d\n", exec);
		printf ("\n\n");
	}

	/*Calculando a media*/
	tempo_medio1 = tempo_medio1 / 3.0;
	comparacoes_medias1 = comparacoes_medias1 / 3.0;
	trocas_medias1 = trocas_medias1 / 3.0;

	tempo_medio2 = tempo_medio2 / 3.0;
	comparacoes_medias2 = comparacoes_medias2 / 3.0;
	trocas_medias2 = trocas_medias2 / 3.0;

	tempo_medio3 = tempo_medio3 / 3.0;
	comparacoes_medias3 = comparacoes_medias3 / 3.0;
	trocas_medias3 = trocas_medias3 / 3.0;

	tempo_medio4 = tempo_medio4 / 3.0;
	comparacoes_medias4 = comparacoes_medias4 / 3.0;
	trocas_medias4 = trocas_medias4 / 3.0;

	/*Mostra os resultados*/
	printf("=======================================================================\n");
	printf("ORDENADO USANDO BOLHA\n");
	printf("Tempo medio gasto na ordenacao considerando %d execucoes: %f segundos \n", 3, tempo_medio1);
	printf("Medias da comparacoes na ordenacao considerando %d execucoes: %f comparacoes \n", 3, comparacoes_medias1);
	printf("Medias das trocas na ordenacao considerando %d execucoes: %f trocas \n", 3, trocas_medias1);
	printf("=======================================================================\n");
	printf("\n\n");
	printf("=======================================================================\n");
	printf("ORDENADO USANDO INSERCAO\n");
	printf("Tempo medio gasto na ordenacao considerando %d execucoes: %f segundos \n", 3, tempo_medio2);
	printf("Medias da comparacoes na ordenacao considerando %d execucoes: %f comparacoes \n", 3, comparacoes_medias2);
	printf("Medias das trocas na ordenacao considerando %d execucoes: %f trocas \n", 3, trocas_medias2);
	printf("=======================================================================\n");
	printf("\n\n");
	printf("=======================================================================\n");
	printf("ORDENADO USANDO QUICKSORT\n");
	printf("Tempo medio gasto na ordenacao considerando %d execucoes: %f segundos \n", 3, tempo_medio3);
	printf("Medias da comparacoes na ordenacao considerando %d execucoes: %f comparacoes \n", 3, comparacoes_medias3);
	printf("Medias das trocas na ordenacao considerando %d execucoes: %f trocas \n", 3, trocas_medias3);
	printf("=======================================================================\n");
	printf("\n\n");
	printf("=======================================================================\n");
	printf("ORDENADO USANDO QUICKSORT TURBINADO\n");
	printf("Tempo medio gasto na ordenacao considerando %d execucoes: %f segundos \n", 3, tempo_medio4);
	printf("Medias da comparacoes na ordenacao considerando %d execucoes: %f comparacoes \n", 3, comparacoes_medias4);
	printf("Medias das trocas na ordenacao considerando %d execucoes: %f trocas \n", 3, trocas_medias4);
	printf("=======================================================================\n");

	/*Desaloca as estruturas e vetores*/
	if(m1)
		free(m1);
	if(m2)
		free(m2);
	if(m3)
		free(m3);
	if(m4)
		free(m4);
	if(vetor)
		free(vetor);
	if(copia1)
		free(copia1);
	if(copia2)
		free(copia2);
	if(copia3)
		free(copia3);
	if(copia4)
		free(copia4);

	return 0;
}

/*======================================================================================*/
/* PREENCHE VETOR                                                                       */
/* IN = PONTEIRO PARA VETOR E TAMANHO                                                   */
/* OUT = VOID                                                                           */
/*======================================================================================*/
void preencheVetor (unsigned long int *v, int t)
{	
	int i;
	
	srand(time(NULL));
	
	for(i = 0; i < t; i++)
	{
		v[i] = (rand() /(double)RAND_MAX) * t;
	}
}

/*======================================================================================*/
/* COPIA OS VETORES                                                                     */
/* IN = PONTEIRO PARA VETOR DESTINO, VETOR ORIGINAL E TAMANHO                           */
/* OUT = VOID                                                                           */
/*======================================================================================*/
void copiaVetor (unsigned long int *c, unsigned long int *v, int t)
{
	int i;
	for(i = 0; i < t-1; i++)
	{	
		c[i] = v[i];
	}
}

/*======================================================================================*/
/* VERIFICA SE O VETOR ESTA ORDENADO                                                    */
/* IN = PONTEIRO PARA VETOR E TAMANHO                                                   */
/* OUT = BOOL                                                                           */
/*======================================================================================*/
int ordenadoCorretamente (unsigned long int *v, int t)
{
	int i;
	for(i = 0; i < t-1; i++) /*vefifica se o vetor foi ordenado corretamente*/
	{
		if (v[i] > v[i+1])
			return 0;
	}
	return 1;
}

/*======================================================================================*/
/* REALIZA A VERIFICACAO DOS VALORES                                                    */
/* IN = VETOR, INDICE I, INDICE J, QUANTIDADE DE VERIFICACOES                           */
/* OUT = VOID                                                                           */
/*======================================================================================*/
int realizaVerificacao(unsigned long int i, unsigned long int j, long int *verificacoes)
{
	*verificacoes = *verificacoes + 1;
	if(i > j)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


/*======================================================================================*/
/* REALIZA A TROCA DOS VALORES                                                          */
/* IN = VETOR, INDICE I, INDICE J, QUANTIDADE DE TROCAS                                 */
/* OUT = VOID                                                                           */
/*======================================================================================*/
void realizaTrocas(unsigned long int *v, int i, int j, long int *trocas)
{
	unsigned long int aux = v[j];
	v[j] = v[i];
	v[i] = aux;
	*trocas = *trocas + 1;
}

/*======================================================================================*/
/* ORDENACAO PELA BOLHA                                                                 */
/* IN = VETOR, QUANTIDADE DE TROCAS E COMPARACOES                                       */
/* OUT = VOID                                                                           */
/*======================================================================================*/
void ordenacaoBolha(unsigned long int *v, int tam, medidas m)
{
	int i, j;
	long int troca = 0, comp = 0;
	double start, finish, elapsed;

	start = (double)clock()/CLOCKS_PER_SEC;

	for (i = tam-1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if(realizaVerificacao(v[j],v[j+1],&comp))
			{
				realizaTrocas(v,j,j+1,&troca);
			}
		}
	}		
	finish=(double)clock()/CLOCKS_PER_SEC;
	elapsed = finish - start;

	m->tempo = elapsed;
	m->comparacoes = comp;
	m->trocas = troca;
}	

/*======================================================================================*/
/* ORDENACAO POR INSERCAO                                                               */
/* IN = VETOR, TAMANHO E ESTRUTURA DE DADOS                                             */
/* OUT = VOID                                                                           */
/*======================================================================================*/
void ordenacaoInsercao(unsigned long int *v, int tam, medidas m)
{
	int i, j;
	double start, finish, elapsed;
	long int troca = 0, comp = 0;

	start = (double)clock()/CLOCKS_PER_SEC;

	for(i = 1; i < tam; i++)
	{
		j = i;
		while(j > 0 && realizaVerificacao(v[j-1],v[j],&comp))
		{
			realizaTrocas(v,j-1,j,&troca);
			j--;
		}
	}	

	finish=(double)clock()/CLOCKS_PER_SEC;
	elapsed = finish - start;

	m->tempo = elapsed;
	m->comparacoes = comp;
	m->trocas = troca;
}

/*======================================================================================*/
/* PARTICAO DO QUICKSORT                                                                */
/* IN = VETOR, ESQ, DIR, &I, &J, ED                                                     */
/* OUT = VOID                                                                           */
/*======================================================================================*/
void Particao(unsigned long int *v, int esq, int dir, int *I, int *J, long int *troca, long int *comp)
{
	int i, j, pivo;
	long int Troca = *troca, Comp = *comp;

	i = esq;
	j = dir;

	pivo = v[pegaMediana(esq,dir)];

	do
	{
		while(realizaVerificacao(pivo,v[i],&Comp))
			i++;
		while(realizaVerificacao(v[j],pivo,&Comp))
			j--;
		if(i <= j)
		{
			realizaTrocas(v,j,i,&Troca);
			i++;
			j--;
		}
	}while(i <= j);	

	*I = i;
	*J = j;
	*troca = Troca;
	*comp = Comp;
}

/*======================================================================================*/
/* ORDENA POR QUICKSORT                                                                 */
/* IN = VETOR, ESQ, DIR                                                                 */
/* OUT = VOID                                                                           */
/*======================================================================================*/
void ordenacaoQuicksort(unsigned long int *v, int esq, int dir, long int *comp, long int *troca)
{
	int i, j;

	Particao(v,esq,dir,&i,&j,*&troca,*&comp);
	if(esq < j)
		ordenacaoQuicksort(v,esq,j,*&troca,*&comp);
	if(i < dir)
		ordenacaoQuicksort(v,i,dir,*&troca,*&comp);
}

/*======================================================================================*/
/* QUICKSORT                                                                            */
/* IN = VETOR, TAM, MEDIDAS                                                             */
/* OUT = VOID                                                                           */
/*======================================================================================*/
void Quicksort(unsigned long int *v, int tam, medidas m)
{
	long int comp = 0, troca = 0;
	double inicio, fim, tempo;

	inicio = (double)clock()/CLOCKS_PER_SEC;
	ordenacaoQuicksort(v,0,tam-1,&comp,&troca);
	fim = (double)clock()/CLOCKS_PER_SEC;

	tempo = fim - inicio;
	m->tempo = tempo;
	m->comparacoes = comp;
	m->trocas = troca;
}

/*======================================================================================*/
/* PEGA PIVO MEDIANA                                                                    */
/* IN = ESQ, DIR                                                                        */
/* OUT = INDICE                                                                         */
/*======================================================================================*/
int pegaMediana(int esq, int dir)
{
	srand(time(NULL));
	int i, j, pivo;
	unsigned long int aux;

	unsigned long int *v = (unsigned long int*) malloc(sizeof(unsigned long int)*3);
  v[0]= (esq + rand()%((dir+1)-esq));
  v[1]= (esq + rand()%((dir+1)-esq));
  v[2]= (esq + rand()%((dir+1)-esq));

	for(i = 1; i < 3; i++)
	{
		j = i;
		while(j > 0 && v[j-1] > v[j])
		{
			aux = v[j];
			v[j] = v[j-1];
			v[j-1] = aux;
			j--;
		}
	}	

	pivo = v[1];
	free(v);
	return pivo;
}

/*======================================================================================*/
/* ORDENA POR QUICKSORT TURBINADO                                                       */
/* IN = VETOR, ESQ, DIR                                                                 */
/* OUT = VOID                                                                           */
/*======================================================================================*/
void ordenacaoQuicksortTurbinado(unsigned long int *v, int esq, int dir, long int *comp, long int *troca)
{
	int i, j;

	if((dir-esq) <= 40)
	{
		insercaoTurbinado(v,esq,dir,*&troca,&*comp);
	}
	else
	{
		Particao(v,esq,dir,&i,&j,*&troca,*&comp);
		if(esq < j)
			ordenacaoQuicksortTurbinado(v,esq,j,*&troca,*&comp);
		if(i < dir)
			ordenacaoQuicksortTurbinado(v,i,dir,*&troca,*&comp);
	}
}

/*======================================================================================*/
/* QUICKSORT TURBINADO                                                                  */
/* IN = VETOR, TAM, MEDIDAS                                                             */
/* OUT = VOID                                                                           */
/*======================================================================================*/
void QuicksortTurbinado(unsigned long int *v, int tam, medidas m)
{
	long int comp = 0, troca = 0;
	double inicio, fim, tempo;

	inicio = (double)clock()/CLOCKS_PER_SEC;
	ordenacaoQuicksortTurbinado(v,0,tam-1,&comp,&troca);
	fim = (double)clock()/CLOCKS_PER_SEC;

	tempo = fim - inicio;
	m->tempo = tempo;
	m->comparacoes = comp;
	m->trocas = troca;
}

/*======================================================================================*/
/* ORDENACAO POR INSERCAO PARA QUICKSORT TURBINADO                                      */
/* IN = VETOR, INICIO, FIM, TROCAS E COMPARACOES                                        */
/* OUT = VOID                                                                           */
/*======================================================================================*/
void insercaoTurbinado(unsigned long int *v, int inicio, int fim, long int *trocas, long int*comps)
{
	int i, j;
	long int troca = *trocas, comp = *comps;

	for(i = inicio+1; i <= fim; i++)
	{
		j = i;
		while(j > 0 && realizaVerificacao(v[j-1],v[j],&comp))
		{
			realizaTrocas(v,j-1,j,&troca);
			j--;
		}
	}	
	*trocas = troca;
	*comps = comp;
}