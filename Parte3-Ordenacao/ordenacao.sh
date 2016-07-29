gcc -Wall ordenacao.c -o ordenacao

echo ===== Ordenando com bolha =====

echo Ordenando um vetor de 500 elementos
./ordenacao 1 500 3 >bolha500.out
echo Ordenando um vetor de 1000 elementos
./ordenacao 1 1000 3 >bolha1000.out
echo Ordenando um vetor de 10000 elementos
./ordenacao 1 10000 3 >bolha10000.out
echo Ordenando um vetor de 100000 elementos
./ordenacao 1 100000 3 >bolha100000.out
echo Ordenando um vetor de 300000 elementos
./ordenacao 1 300000 3 >bolha300000.out

echo ===== Ordenando por insercao =====

echo Ordenando um vetor de 500 elementos
./ordenacao 2 500 3 >insercao500.out
echo Ordenando um vetor de 1000 elementos
./ordenacao 2 1000 3 >insercao1000.out
echo Ordenando um vetor de 10000 elementos
./ordenacao 2 10000 3 >insercao10000.out
echo Ordenando um vetor de 100000 elementos
./ordenacao 2 100000 3 >insercao100000.out
echo Ordenando um vetor de 300000 elementos
./ordenacao 2 300000 3 >insercao300000.out

echo ===== Ordenando por Quicksort =====

echo Ordenando um vetor de 500 elementos
./ordenacao 3 500 3 >qs500.out
echo Ordenando um vetor de 1000 elementos
./ordenacao 3 1000 3 >qs1000.out
echo Ordenando um vetor de 10000 elementos
./ordenacao 3 10000 3 >qs10000.out
echo Ordenando um vetor de 100000 elementos
./ordenacao 3 100000 3 >qs100000.out
echo Ordenando um vetor de 300000 elementos
./ordenacao 3 300000 3 >qs300000.out

echo ===== Ordenando por Quicksort Turbinado =====

echo Ordenando um vetor de 500 elementos
./ordenacao 4 500 3 >qst500.out
echo Ordenando um vetor de 1000 elementos
./ordenacao 4 1000 3 >qst1000.out
echo Ordenando um vetor de 10000 elementos
./ordenacao 4 10000 3 >qst10000.out
echo Ordenando um vetor de 100000 elementos
./ordenacao 4 100000 3 >qst100000.out
echo Ordenando um vetor de 300000 elementos
./ordenacao 4 300000 3 >qst300000.out