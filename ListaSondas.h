#ifndef LISTASONDAS_H_
#define LISTASONDAS_H_
#define InicioArranjo 0
#define MaxTam 3
#include "Sonda.h"

typedef struct {
    Sonda sonda[MaxTam];
    int Primeiro, Ultimo;
} TSondas; 

void FazListaVazia(TSondas* Sondas);
int InsereSonda(TSondas* Sondas, Sonda* sonda);
int ImprimiSondas(TSondas *Sondas);

#endif