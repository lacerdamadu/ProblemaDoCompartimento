#include "Sonda.h"
#include <stdio.h>

void InicializaSonda(Sonda *NovaSonda, int Identificador, double PesoMax){
    CriaListaRocha(&NovaSonda->CompartmentoS, PesoMax);
    NovaSonda->Identificador = Identificador;
}