#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int pos = 0;
void combinacao_simples(int n, int r, int x[], int next, int k, int **matind)
{
    int i;
    if (k == r)
    {
        for (i = 0; i < r; i++)
        {
            matind[pos][i] = x[i];
         
        }
       
        pos++;
    }
    else
    {
        for (i = next; i < n; i++)
        {
            x[k] = i;
            combinacao_simples(n, r, x, i + 1, k + 1, matind);
        }
    }
}

int fat(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
    {
        res *= i;
    }
    return res;
}

// Função para calcular a combinação C(n, k) usando tgamma
int combination(int n, int k)
{
    if (k > n)
        return 0;
    return (int)(fat(n) / (fat(k) * fat(n - k)));
}

int comb;
// Função para calcular a soma de todas as combinações de 1 a n
int sum_combinations(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; k++)
    {
        sum += combination(n, k);
    }
    return sum;
}
int main()
{

    int n, r, *x;
    printf("Entre com o valor de n: ");
    scanf("%d", &n);

    x = malloc((n+1) * sizeof(int));
    int linhas = sum_combinations(n);
    


    int** matind = (int**) malloc(sizeof(int*) * linhas);
    for(int i=0; i <= n; i++){
        matind[i] = (int*) malloc(sizeof(int) * n+1);
    }


    memset(matind, -1, sizeof(matind));

    for (int k = 0; k <= n; k++)
    {
        combinacao_simples(n, k, x, 0, 0, matind);
    }

    printf("%d\n", matind[0][0]);
    for (int i = 0; i < linhas; i++)
    {
        for (int k = 0; k < n + 1; k++)
        {
            if (matind[i][k] == -1)
            {
                break;
            }
            printf("%d ", matind[i][k]);
        }
        printf("\n");
    }
    free(x);
    return 0;
}