#include "RochaMineral.h"
#include <stdio.h>

void InicializaRocha(RochaMineral* Rocha, double Peso, int Valor, int id){
    setPesoRocha(Rocha, Peso);
    setValor(Rocha, Valor);
    setId(Rocha, id);
}

void ImprimeRocha(RochaMineral *Rocha){
    printf("Peso: %.0lf\n", Rocha->Peso);
    printf("Valor: %d\n", Rocha->Valor);
}

void setPesoRocha(RochaMineral *Rocha, double Peso){
    Rocha->Peso = Peso;
}
double getPesoRocha(RochaMineral *Rocha){
    return(Rocha->Peso);
}

void setValor(RochaMineral *Rocha, int Valor){
    Rocha->Valor = Valor;
}
int getValor(RochaMineral *Rocha){
    return(Rocha->Valor);
}

void setId(RochaMineral *Rocha, int id){
    Rocha->id = id;
}
int getId(RochaMineral *Rocha){
    return(Rocha->id);
}