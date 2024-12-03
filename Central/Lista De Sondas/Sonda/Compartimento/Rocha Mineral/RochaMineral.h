#ifndef ROCHAMINERAL_H_INCLUDED
#define ROCHAMINERAL_H_INCLUDED


typedef struct{
    int Valor;
    double Peso;
} RochaMineral;


void InicializaRocha(RochaMineral* rocha, double Peso, int Valor);

void ImprimeRocha(RochaMineral *Rocha);

void setPesoRocha(RochaMineral *Rocha, double Peso);
double getPesoRocha(RochaMineral *Rocha);

void setValor(RochaMineral *Rocha, int Valor);
int getValor(RochaMineral *Rocha);


#endif // ROCHAMINERAL_H_INCLUDED