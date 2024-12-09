#include "Central.h"
#include "ListaSondas.h"
#include <stdio.h>

void EntradaPorArquivo(TSondas *ListaSondas){
    printf("Digite o nome do arquivo: ");
    char nome[STRING];
    scanf("%s", nome);

    FILE* entrada;
    entrada = fopen(nome, "r");
    if(entrada==NULL){
        printf("Erro ao ler o arquivo.");
        return 0;
    }
     
    int identificador = 0;
    double PesoMax = 40; // Capacidade de armazenamento
    FazListaVazia(ListaSondas);
    for(int m = 0; m<MaxTam;m++){
        Sonda NovaSonda;
        identificador = m+1;
        NovaSonda.CompartmentoS.PesoTotal = 0;
        InicializaSonda(&NovaSonda, identificador, PesoMax);
        InsereSonda(ListaSondas, &NovaSonda);
    }
    
    int numrochas;
    int peso, valor;
    Sonda temporaria;
    int id = 10;// identificador diferente para diferenciar das sondas definitivas
    PesoMax = 1000;
    InicializaSonda(&temporaria, id, PesoMax);

    fscanf(entrada, "%d", numrochas);
    for(int j=0; j<numrochas; j++){
        fscanf(entrada, "%d""%d", &peso, &valor);
        RochaMineral novarocha;
        InicializaRocha(&novarocha, peso, valor);
        InsereRocha(&temporaria.CompartmentoS, &novarocha);//insere todas as rochas na sonda temporária para depois redistribuir
    }

    Redistribucao(ListaSondas);
}
/*void Redistribucao(TSondas *Sondas){

}*/
void Imprimi(TSondas Sondas){
    
}
