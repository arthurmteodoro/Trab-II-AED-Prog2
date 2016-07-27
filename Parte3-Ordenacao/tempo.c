/* Esse código exemplifica como computar o tempo de execução de um procedimento/função usando a linguagem de programação C.

Foi compilado usando GCC verão 4.6.2 numa plataforma computacional com sistema operacional Win8 e arquitetura Intel x86/x86-64.

Autor: Mário Luiz Rodrigues Oliveira		 
Data: 12/07/2016

Esse código somente pode ser utilizado com autorização expressa do autor.
Os alunos do terceiro período do curso de Ciencia da Computacao do Insituto Federal de Minas Gerais (IFMG) - Campus Formiga estão autorizados a copiar, modificar, aperfeiçoar
e adaptá-lo para as suas necessidades desde que referenciada a fonte.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 300000

struct medida
{
	double tempo, comparacoes, trocas;
};

typedef struct medida *medidas;

void copia_vetor (unsigned long int *, unsigned long int *, int);
void bubble_sort (unsigned long int *, int, medidas);
void preenche_vetor (unsigned long int *, int );
int ordenado_corretamente (unsigned long int *, int);
void gravar_resultado (FILE *, double, double, double);


int main ()
{
	unsigned long int* vetor;
	unsigned long int* copia;
	double tempo_medio=0.0, comparacoes_medias=0.0, trocas_medias=0.0;
	int exec;
	medidas m;
	FILE *arquivo;
	
	#if defined VIDEO
		arquivo = stdout;
	#else
		arquivo = fopen ("resultados.txt", "wt");
		if (!arquivo)
		{
			printf ("Erro ao criar arquivo");
			exit (EXIT_FAILURE);
		}
	#endif
	
	m = (medidas) malloc (sizeof (struct medida));
	vetor = (unsigned long int*) malloc(TAM*sizeof(unsigned long int));
	copia = (unsigned long int*) malloc(TAM*sizeof(unsigned long int));
	
	if (!vetor)
	{
		printf ("Memoria insuficiente");
		exit (EXIT_FAILURE);
	}
	
	if (!copia)
	{
		printf ("Memoria insuficiente");
		exit (EXIT_FAILURE);
	}
	
	
	for ( exec = 1; exec <= EXECUCOES; exec = exec + 1)
	{
		
		printf ("EXECUCAO %d \n\n", exec);
		
		printf ("Preenchendo vetor aleatoriamente \n");
		preenche_vetor (vetor, TAM);
	
		printf ("Copiando vetor\n"); //permite chamar varios metodos de ordenacao na sequencia
		copia_vetor (copia, vetor, TAM);
	
		printf ("Ordenando vetor usando o metodo bubble sort\n");
		bubble_sort (copia, TAM, m);
	
		printf ("Verificando se o vetor foi ordenado corretamente\n");
		
		if (ordenado_corretamente (copia, TAM))
		{
			printf ("Vetor ordenado corretamente\n");
			tempo_medio = tempo_medio + m->tempo;
			comparacoes_medias = comparacoes_medias + m->comparacoes;
			trocas_medias = trocas_medias + m->trocas;
		}
		else
			printf("ERRO: Vetor nao ordenado\n");
			
		printf ("\n\n");
	}
	
	tempo_medio = tempo_medio / EXECUCOES;
	comparacoes_medias = comparacoes_medias / EXECUCOES;
	trocas_medias = trocas_medias / EXECUCOES;
	
	gravar_resultado (arquivo, tempo_medio, comparacoes_medias, trocas_medias);
	
	if (vetor)
		free(vetor);
		
	if (copia)
		free(copia);
	
	if (m)
		free (m);
	
	return 0;
}

void bubble_sort (unsigned long int *v, int t, medidas m)
{
	// A funcao clock (void) devolve o tempo de CPU decorrido desde o inicio da execucao do seu programa. O tempo eh medido em ciclos do relogio interno. 
	// Para obeter o tempo em segundos divida o valor retornado pela funcao clock pela constante CLOCKS_PER_SEC.
	
	double start, finish, elapsed, comparacoes=0.0, trocas=0.0;
	int i, j;
	unsigned long int aux;
	
	start=(double)clock()/CLOCKS_PER_SEC;
	
	for (i = t-1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			comparacoes = comparacoes + 1; //na especificacao do trabalho pede-se que essa funcionalidade seja implementada como uma funcao
			if (v[j] > v [j+1])
			{
				trocas = trocas + 1; //na especificacao do trabalho pede-se que essa funcionalidade seja implementada como uma funcao
				aux=v[j];
				v[j]=v[j+1];
				v[j+1]=aux;
			}
		}
	}
	
	finish=(double)clock()/CLOCKS_PER_SEC;
	
	elapsed = finish - start; //calcula o tempo gasto na execução da ordenacao
	
	m->tempo = elapsed;
	m->comparacoes = comparacoes;
	m->trocas = trocas;
}

void preenche_vetor (unsigned long int *v, int t)
{
	// A funcao time (time_t *x) retorna o total de segundos decorridos desde 01/01/1970. Essa funcao tambem atribui o valor retornado (em segundos)
	// a variavel cujo endereco é x (a menos que x seja NULL). Uso típico: instante = time (NULL)
	
	int i;
	
	srand (time(NULL)); // A funcao srand () configura a semente inicial para o gerador de numeros pseudo-aleatorio
	
	for (i = 0; i < t; i++)
	{
		v[i] = (rand() /(double)RAND_MAX) * t; //A constante RAND_MAX representa o valor maximo retornado pela funcao rand(), a qual gera numeros pseudo-aleatorios
	}
}

int ordenado_corretamente (unsigned long int *v, int t)
{
	int i;
	for (i = 0; i < t-1; i++) //vefifica se o vetor foi ordenado corretamente
	{
		if (v[i] > v[i+1])
			return 0;
	}
	
	return 1;
}

void copia_vetor (unsigned long int *c, unsigned long int *v, int t)
{
	int i;
	for (i = 0; i < t-1; i++)
	{	
		c[i] = v[i];
	}
}

void gravar_resultado (FILE *arquivo, double tempo_medio, double comparacoes_medias, double trocas_medias)
{
	fprintf (arquivo, "Tempo medio gasto na ordenacao considerando %d execucoes: %.2f segundos \n", EXECUCOES, tempo_medio);
	fprintf (arquivo, "Medias da comparacoes na ordenacao considerando %d execucoes: %.2f comparacoes \n", EXECUCOES, comparacoes_medias);
	fprintf (arquivo, "Medias das trocas na ordenacao considerando %d execucoes: %.2f trocas \n", EXECUCOES, trocas_medias);
}
