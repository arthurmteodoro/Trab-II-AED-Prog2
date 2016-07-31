gcc -Wall ordenacao.c -o ordenacao

echo ===== Ordenando com 500 elementos =====
./ordenacao 500 > 500.out

echo ===== Ordenando com 1000 elementos =====
./ordenacao 1000 > 1000.out

echo ===== Ordenando com 10000 elementos =====
./ordenacao 10000 > 10000.out

echo ===== Ordenando com 100000 elementos =====
./ordenacao 100000 > 100000.out

echo ===== Ordenando com 300000 elementos =====
./ordenacao 300000 > 300000.out
