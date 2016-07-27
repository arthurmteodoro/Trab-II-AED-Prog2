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
int realizaVerificacao(unsigned long int *v, int i, int j, long int *verificacoes);
void realizaTrocas(unsigned long int *v, int i, int j, long int *trocas);
void ordenacaoBolha(unsigned long int *v, int tam, medidas m);
void ordenacaoInsercao(unsigned long int *v, int tam, medidas m);

/*================================================================================================*/
/*                                         FUNÇÃO MAIN                                             */
/*================================================================================================*/
int main(int argc, char const *argv[])
{
	/*Declaracao das variaveis*/
	unsigned long int* vetor;
	unsigned long int* copia;
	double tempo_medio=0.0, comparacoes_medias=0.0, trocas_medias=0.0;
	int exec, execucoes, tam, metodo;
	medidas m;

	/*Usa valores de entrada para configurar metodo de ordenacao, tamanho e quantidade de execucoes*/
	if(argc < 4)
	{
		printf("ERRO - Usar ./ordenacao <metodo> <tam> <execucoes>\n");
	}
	else
	{
		metodo = atoi(argv[1]);
		tam = atoi(argv[2]);
		execucoes = atoi(argv[3]);
	}

	/*Cria os vetores e a estrutura que armazena os dados*/
	m = (medidas) malloc (sizeof (struct medida));
	vetor = (unsigned long int*) malloc(tam*sizeof(unsigned long int));
	copia = (unsigned long int*) malloc(tam*sizeof(unsigned long int));

	/*Realiza as execucoes*/
	for(exec = 1; exec <= execucoes; exec = exec + 1)
	{
		
		printf ("EXECUCAO %d \n\n", exec);
		
		printf ("Preenchendo vetor aleatoriamente \n");
		preencheVetor (vetor, tam);
	
		printf ("Copiando vetor\n");
		copiaVetor (copia, vetor, tam);
	
		if(metodo == 1)
		{
			printf("Odenando com o método da bolha\n");
			ordenacaoBolha(copia,tam,m);
		}
		if(metodo == 2)
		{
			printf("Odenando com o método da insercao\n");
			ordenacaoInsercao(copia,tam,m);
		}
		if(metodo == 3)
		{
			printf("Ordenando com quicksort por mediana de tres sorteios\n");
		}
		if(metodo == 4)
		{
			printf("Ordenando com quicksort turbinado\n");
		}
	
		printf ("Verificando se o vetor foi ordenado corretamente\n");
		
		if(ordenadoCorretamente(copia, tam))
		{
			printf ("Vetor ordenado corretamente\n");
			tempo_medio = tempo_medio + m->tempo;
			comparacoes_medias = comparacoes_medias + m->comparacoes;
			trocas_medias = trocas_medias + m->trocas;
			printf("Quantidade de trocas %.2lf\n", m->trocas);
			printf("Tempo gasto %lf\n", m->tempo);
			printf("Quantidade de comparacoes %.2lf\n", m->comparacoes);
		}
		else
			printf("ERRO: Vetor nao ordenado\n");
			
		printf ("\n\n");
	}

	tempo_medio = tempo_medio / (double)execucoes;
	comparacoes_medias = comparacoes_medias / (double)execucoes;
	trocas_medias = trocas_medias / (double)execucoes;
	
	/*Mostra os resultados*/
	printf("=======================================================================\n");
	if(metodo == 1)
	{
		printf("Odenando com o método da bolha\n");
	}
	if(metodo == 2)
	{
		printf("Odenando com o método da insercao\n");
	}
	if(metodo == 3)
	{
		printf("Ordenando com quicksort por mediana de tres sorteios\n");
	}
	if(metodo == 4)
	{
		printf("Ordenando com quicksort turbinado\n");
	}
	printf("Tempo medio gasto na ordenacao considerando %d execucoes: %f segundos \n", execucoes, tempo_medio);
	printf("Medias da comparacoes na ordenacao considerando %d execucoes: %f comparacoes \n", execucoes, comparacoes_medias);
	printf("Medias das trocas na ordenacao considerando %d execucoes: %f trocas \n", execucoes, trocas_medias);
	printf("=======================================================================\n");

	/*Desaloca os vetores*/
	free(vetor);
	free(copia);
	free (m);
	
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
	for(i = 0; i < t-1; i++) //vefifica se o vetor foi ordenado corretamente
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
int realizaVerificacao(unsigned long int *v, int i, int j, long int *verificacoes)
{
	*verificacoes = *verificacoes + 1;
	if(v[i] > v[j])
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
			if(realizaVerificacao(v,j,j+1,&comp))
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
		while(j > 0 && realizaVerificacao(v,j-1,j,&comp))
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