#ifndef CENTRAL_H_
#define CENTRAL_H_
#define STRING 100

#include "ListaSondas.h"


int EntradaPorArquivo(TSondas *Sondas);
void Redistribuicao(TSondas *Sondas, Sonda *temporaria, RochaMineral elementosparacombinacao[], int tamanhodoselementos);
void gerarCombinacoes(Sonda *atual, RochaMineral elementosparacombinacao[], int tamanhodoselementos, int r, int indicedoauxiliar, RochaMineral auxiliar[], int i);
void gerarTodasCombinacoes(Sonda *atual, RochaMineral elementosparacombinacao[], int tamanhodoselementos);

#endif