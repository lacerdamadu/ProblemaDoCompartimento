#include <stdio.h>
#include <time.h>
#include "Central.h"

int main(){
    TSondas Sondas;
    EntradaPorArquivo(&Sondas);
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    // Código que você quer medir o tempo de execução
    for (long i = 0; i < 1000000000; i++);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %.2f segundos\n", cpu_time_used);

    return 0;
}