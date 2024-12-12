#include "Central.h"
#include "ListaSondas.h"
#include <stdio.h>

int EntradaPorArquivo(TSondas *ListaSondas){
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

    fscanf(entrada,"%d", &numrochas);
    RochaMineral elementos[numrochas];// Vetor que guarda os valores de cada rocha
    int tamanho = numrochas;

    for(int j=0; j<numrochas; j++){
        fscanf(entrada, "%d""%d", &peso, &valor);
        RochaMineral novarocha;
        InicializaRocha(&novarocha, peso, valor);
        Celula novarochaa;
        novarochaa.rocha = novarocha;
        InsereRocha(&temporaria.CompartmentoS, &novarochaa);//insere todas as rochas na sonda temporária para depois redistribuir
        
        elementos[j] = novarocha;
    }
    Redistribuicao(ListaSondas, &temporaria, elementos, tamanho);
}
void Redistribuicao(TSondas *Sondas, Sonda *temporaria, RochaMineral elementosparacombinacao[], int tamanhodoselementos){
    gerarTodasCombinacoes(elementosparacombinacao, tamanhodoselementos);
}


void gerarCombinacoes(RochaMineral elementosparacombinacao[], int tamanhodoselementos, int r, int indicedoauxiliar, RochaMineral auxiliar[], int i){
    if (indicedoauxiliar == r) {
        for (int j = 0; j < r; j++) {
            printf("%d ", auxiliar[j].Valor);
        }
        printf("\n");
    return;
    }

    if (i >= tamanhodoselementos) {
        return;
    }

    auxiliar[indicedoauxiliar] = elementosparacombinacao[i];
    gerarCombinacoes(elementosparacombinacao, tamanhodoselementos, r, indicedoauxiliar + 1, auxiliar, i + 1);

    gerarCombinacoes(elementosparacombinacao, tamanhodoselementos, r, indicedoauxiliar, auxiliar, i + 1);
}

void gerarTodasCombinacoes(RochaMineral elementosparacombinacao[], int tamanhodoselementos){
    for (int r = 1; r <= tamanhodoselementos; r++) {
        RochaMineral auxiliar[r]; 
        gerarCombinacoes(elementosparacombinacao, tamanhodoselementos, r, 0, auxiliar, 0);
    }
}
