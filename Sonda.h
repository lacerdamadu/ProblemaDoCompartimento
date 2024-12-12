#ifndef SONDA_H_
#define SONDA_H_

#include "Compartimento.h"

typedef struct {
    int Identificador;
    Compartimento CompartmentoS;

} Sonda;

void InicializaSonda(Sonda *NovaSonda, int Identificador, double PesoMax);
void ImprimeSonda(Sonda NovaSonda);
#endif