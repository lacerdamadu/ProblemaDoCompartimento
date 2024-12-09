#include "Sonda.h"
#include <stdio.h>

void InicializaSonda(Sonda *NovaSonda, int Identificador, double PesoMax){
    CriaListaRocha(&NovaSonda->CompartmentoS, PesoMax);
    NovaSonda->Identificador = Identificador;
}
void ImprimeSonda(Sonda NovaSonda){
    for(int i=0; i<3; i++){
    printf("Sonda: %d", NovaSonda.Identificador);
    }
}