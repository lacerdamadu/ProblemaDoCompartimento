#include "Central.h"
#include "ListaSondas.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

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
    int tamanho = numrochas;

    for(int j=0; j<numrochas; j++){
        fscanf(entrada, "%d""%d", &peso, &valor);
        RochaMineral novarocha;
        int id2 = j;
        InicializaRocha(&novarocha, peso, valor, id2);
        Celula novarochaa;
        novarochaa.rocha = novarocha;
        InsereRocha(&temporaria.CompartmentoS, &novarochaa);//insere todas as rochas na sonda temporária para depois redistribuir
    }
    TodasCombinacoes(tamanho);
}

void Redistribuicao(TSondas *Sondas, Sonda *temporaria, int tamanho){
    int ** aux = TodasCombinacoes(tamanho);
    int RochasUtilizadas[tamanho];
    int melhorcombinacao[tamanho];
    int combtual[tamanho];

    int melhorvalor = 0, valoratual = 0;
    int total_matrizindices = (1 << tamanho) - 1;
    RochaMineral Aux;

    for(int i=0; i<tamanho; i++){
        RochasUtilizadas[i] = -1;
        melhorcombinacao[i] = -1;
        combtual[i] = -1;
    }
    for(int j=0;j<total_matrizindices;j++){
        for(int k=0; k<tamanho; k++){
            Aux.id = total_matrizindices[j][k];
            combtual[j] = total_matrizindices[j][k];
            valoratual += Aux.Valor;
        }
        if(valoratual >= melhorvalor){
            if (valoratual > 40){
                
                break;
            }
            melhorvalor = valoratual;
            for(int l=0; l<tamanho;l++){
                melhorcombinacao[l] = total_matrizindices[l][j];
            }
        }
    }

}

void CombinacaoSimples(int n, int r, int x[], int next, int k, int **matrizindices, int *index){
    if (k == r) {
        for (int i = 0; i < r; i++) {
            matrizindices[*index][i] = x[i];
        }
        matrizindices[*index][r] = -1;
        (*index)++;
    } 
    else {
        for (int i = next; i < n; i++) {
        x[k] = i;
        CombinacaoSimples(n, r, x, i + 1, k + 1, matrizindices, index);
        }
    }
 }


int** TodasCombinacoes(int n){
    int total_matrizindices = (1 << n) - 1;
    int **matrizindices = (int **)malloc(total_matrizindices * sizeof(int *));

    for (int i = 0; i < total_matrizindices; i++) {
        matrizindices[i] = (int *)malloc((n + 1) * sizeof(int));
    }

    int *x = (int *)malloc(n * sizeof(int));
    int index = 0;

    for (int r = 1; r <= n; r++) {
        CombinacaoSimples(n, r, x, 0, 0, matrizindices, &index);
    }

    for (int i = 0; i < total_matrizindices; i++) {
        for (int j = 0; j < n; j++) {
        if (matrizindices[i][j] == -1) {
            break;
        }
        printf("%d ", matrizindices[i][j]);
        }
        printf("\n");
    }
    return matrizindices;
}