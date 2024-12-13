#include <stdio.h>
#include <time.h>
#include "Central.h"
#define TAMANHOMAX 1000000000

int main(){
    TSondas Sondas;
    EntradaPorArquivo(&Sondas);
    clock_t comeco, final;
    double tempofinal;

    comeco = clock();

    for (long i = 0; i < 1000000000; i++);
    final = clock();

    tempofinal = ((double) (final - comeco)) / CLOCKS_PER_SEC;
    printf("Tempo de execucao: %.2f segundos\n", tempofinal);

    return 0;
}