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

    int vet[numrochas];

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
    
    Redistribuicao(ListaSondas, &temporaria, numrochas);
}

void Redistribuicao(TSondas *Sondas, Sonda *temporaria, int tamanho){
    int ** auxmatrizes= TodasCombinacoes(tamanho);

    int RochasUtilizadas[tamanho];

    int melhorcombinacao = -1;
    int combtual;

    int melhorvalor = 0, valoratual;

    double pesoatual, melhorpeso;

    int total_matrizindices = (1 << tamanho) - 1;


    Celula* pAux = temporaria->CompartmentoS.primeiro->pProx;
    


    for(int i=0; i<tamanho; i++){
        RochasUtilizadas[i] = 1;
    }

    for(int atual = 0; atual < MaxTam; atual++){

        melhorcombinacao = -1; combtual = -1; melhorvalor = -1;

        for(int j=0;j<total_matrizindices;j++){


            valoratual = 0; pesoatual = 0;

            combtual = j;

            for(int k=0; k<tamanho; k++){

                if(auxmatrizes[j][k] == -1){
                    break;
                } if(!RochasUtilizadas[auxmatrizes[j][k]]){
                        break;
                }

                pAux = temporaria->CompartmentoS.primeiro->pProx;

                for(int h = 0; h <= auxmatrizes[j][k]; h++) {
                    if(pAux == NULL){
                        break;
                    }

                    if(pAux->rocha.id == auxmatrizes[j][k] && RochasUtilizadas[auxmatrizes[j][k]]){

                        valoratual += pAux->rocha.Valor;
                        pesoatual += pAux->rocha.Peso;

                    }
                    pAux = pAux->pProx;
                }

                pAux = temporaria->CompartmentoS.primeiro->pProx;

                
                
            }
            
            pAux = temporaria->CompartmentoS.primeiro->pProx;
            

            if(valoratual >= melhorvalor){
                if (pesoatual > 40){
                    for(int m=0; m<tamanho; m++){
                        auxmatrizes[j][m] = -1;
                    }
                } else {
                    melhorvalor = valoratual;
                    melhorcombinacao = combtual;
                    melhorpeso = pesoatual;
                }
            }
            
        }

        int a = 0;


        printf("Sonda %d: Peso %0.lf, Valor %d, Solucao [", atual+1, melhorpeso, melhorvalor);
        while (auxmatrizes[melhorcombinacao][a] != -1){
            if(auxmatrizes[melhorcombinacao][a+1] == -1){
                printf("%d]\n", auxmatrizes[melhorcombinacao][a]);
            } else {
            printf("%d ", auxmatrizes[melhorcombinacao][a]);
            }
            a++;
        }

        for(int d = 0; d < tamanho; d ++){
            if(auxmatrizes[melhorcombinacao][d]==-1){
                break;
            }
            RochasUtilizadas[auxmatrizes[melhorcombinacao][d]] = 0;
        }

        int g = 0;

        Celula *RochaRemovida;


        if(!VerificaListaVazia(&temporaria->CompartmentoS)){

            while (auxmatrizes[melhorcombinacao][g]!= -1){

                pAux = temporaria->CompartmentoS.primeiro->pProx;

                while(pAux!= NULL){
                    if(auxmatrizes[melhorcombinacao][g] == pAux->rocha.id){

                        RochaRemovida = RemoveRocha(&temporaria->CompartmentoS, pAux);
                        InsereRocha(&Sondas->sonda[atual].CompartmentoS, RochaRemovida);
                        auxmatrizes[melhorcombinacao][g] = -1;

                    }
                    pAux = pAux->pProx;
                }
                g++;
            }    
        }
    }

    /*for(int g = 0; g < MaxTam; g++){
        printf("sonda %d:\n", g);
        ImprimiLista(&Sondas->sonda[g].CompartmentoS);
    }/**/
    

    
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

    /*for (int i = 0; i < total_matrizindices; i++) {
        for (int j = 0; j < n; j++) {
        if (matrizindices[i][j] == -1) {
            break;
        }
        }
    }*/


    return matrizindices;
}
