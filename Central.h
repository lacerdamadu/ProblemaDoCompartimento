#ifndef CENTRAL_H_
#define CENTRAL_H_
#define STRING 100

#include "ListaSondas.h"


int EntradaPorArquivo(TSondas *Sondas);
void Redistribuicao(TSondas *Sondas, TSondas *temporario, R elementosparacombinacao[], int tamanhodoselementos);
void gerarCombinacoes(int elementosparacombinacao[], int tamanhodoselementos, int r, int indicedoauxiliar, int auxiliar[], int i)
void gerarTodasCombinacoes(int elementosparacombinacao[], int tamanhodoselementos);

#endif