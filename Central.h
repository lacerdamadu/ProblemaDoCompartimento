#ifndef CENTRAL_H_
#define CENTRAL_H_
#define STRING 100

#include "ListaSondas.h"


int EntradaPorArquivo(TSondas *Sondas);
void Redistribuicao(TSondas *Sondas, Sonda *temporaria, int tamanho, int elementos[]);
/*int Fatorial(int n);
int Combinacao(int n, int k);
int CalculaNumCombinacoes(int n);*/
void todas_combinacoes(int n);
void combinacao_simples(int n, int r, int x[], int next, int k, int **matrizindices, int *index);

#endif