#ifndef CENTRAL_H_
#define CENTRAL_H_
#define STRING 100

#include "ListaSondas.h"


int EntradaPorArquivo(TSondas *Sondas);
void Redistribuicao(TSondas *Sondas, Sonda *temporaria, int tamanho, int elementos[]);
void combinacao_simples(int tamanho, int r, int x[], int next, int k, int **matind);
int Fatorial(int n);
int Combinacao(int n, int k);
int CalculaNumCombinacoes(int n);


#endif