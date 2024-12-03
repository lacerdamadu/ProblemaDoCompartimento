#include "ListaSondas.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void FazListaVazia(TSondas* Sondas){
    Sondas->Primeiro = InicioArranjo;
    Sondas->Ultimo = Sondas->Primeiro;
}
void InsereSonda(TSondas* Sondas, Sonda* sonda){
    if (Sondas->Ultimo == MaxTam){
        return 0; /* lista cheia */
    }
    Sondas->sonda[Sondas->Ultimo++] = *sonda;
    return 1;
}
int ImprimeSonda(TSondas* Sondas){
    int i;
    for (i = Sondas->Primeiro; i < Sondas->Ultimo; i++){
        ImprimiLista(&Sondas->sonda->CompartmentoS);
        printf("%d\n", Sondas->sonda->Identificador);
}
}
    