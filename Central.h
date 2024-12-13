#ifndef CENTRAL_H_
#define CENTRAL_H_
#define STRING 100

#include "ListaSondas.h"


int EntradaPorArquivo(TSondas *Sondas);
void Redistribuicao(TSondas *Sondas, Sonda *temporaria, int tamanho);
int ** TodasCombinacoes(int n);
void CombinacaoSimples(int n, int r, int x[], int next, int k, int **matrizindices, int *index);

#endif