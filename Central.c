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
    int elementos[numrochas];// Vetor que guarda os ids de cada rocha
    int tamanho = numrochas;

    for(int j=0; j<numrochas; j++){
        fscanf(entrada, "%d""%d", &peso, &valor);
        RochaMineral novarocha;
        int id2 = j;
        InicializaRocha(&novarocha, peso, valor, id2);
        Celula novarochaa;
        novarochaa.rocha = novarocha;
        InsereRocha(&temporaria.CompartmentoS, &novarochaa);//insere todas as rochas na sonda temporária para depois redistribuir
        
        elementos[j] = novarocha.id;
    }
    Redistribuicao(ListaSondas, &temporaria, tamanho, elementos);
}
void Redistribuicao(TSondas *Sondas, Sonda *temporaria, int tamanho, int elementos[]){
    printf("oi");
    int linhas = 0, *x;
    x = malloc((tamanho+1) * sizeof(int));
    linhas = CalculaNumCombinacoes(tamanho);
    printf("%d", linhas);
    
    int** matind = (int**) malloc(sizeof(int*) * linhas);
    for(int i=0; i <= tamanho; i++){
        matind[i] = (int*) malloc(sizeof(int) * tamanho+1);
    }
    memset(matind, -1, sizeof(matind));
    for(int j=0; j<linhas; j++){
        for(int k=0;k<tamanho; k++){
            printf("%d", *matind[k]);
        }
        printf("\n");
    }
}
/*
    for (int k = 0; k <= tamanho; k++){
        combinacao_simples(tamanho, k, x, 0, 0, matind);
    }
}

int pos = 0;
void combinacao_simples(int tamanho, int r, int x[], int next, int k, int **matind){
    int i;
    if (k == r){
        for (i = 0; i < r; i++){
            matind[pos][i] = x[i];
            printf("%d", matind[pos][i]);
        }
        pos++;
    }
    else{
        for (i = next; i < tamanho; i++){
            x[k] = i;
            combinacao_simples(tamanho, r, x, i + 1, k + 1, matind);
        }
    }
}
*/
int Fatorial(int tamanho){
    int res = 1;
    for (int i = 1; i <= tamanho; i++){
        res *= i;
    }
    return res;
}
int Combinacao(int tamanho, int k){
    if (k > tamanho)
        return 0;
    return (int)(Fatorial(tamanho) / (Fatorial(k) * Fatorial(tamanho - k)));
}

int CalculaNumCombinacoes(int tamanho){
    int sum = 0;
    for (int k = 1; k <= tamanho; k++)
    {
        sum += Combinacao(tamanho, k);
    }
    return sum;
}



/* int usados[] = [0,0,0,0,0,0,0];
for(int i=0; i<3; i++){
}
    melhor_comb = []
    melhor_valor = -1
    for comb in  [[0,7], [5,8]]:
        for rocha in comb:
            if usados[rocha] :
                comb_invalida = True 
        
        valor = val(comb)
        peso = peso(comb)

        if peso < capa and valor > melhor_valor and not comb_invalida:
            melhor_valor = valor
            melhor_comb = comb
    
    for rocha in melhor_comb:
        usados[rocha] = 1*/

