#ifndef ROCHAMINERAL_H_INCLUDED
#define ROCHAMINERAL_H_INCLUDED

typedef struct{
    int id;
    int Valor;
    double Peso;
} RochaMineral;


void InicializaRocha(RochaMineral* rocha, double Peso, int Valor, int id);

void ImprimeRocha(RochaMineral *Rocha);

void setPesoRocha(RochaMineral *Rocha, double Peso);
double getPesoRocha(RochaMineral *Rocha);

void setValor(RochaMineral *Rocha, int Valor);
int getValor(RochaMineral *Rocha);

void setId(RochaMineral *Rocha, int id);
int getId(RochaMineral *Rocha);


#endif // ROCHAMINERAL_H_INCLUDED