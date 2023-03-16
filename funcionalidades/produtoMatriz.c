#include <stdio.h>
#include <stdlib.h>

int main()
{
    float matriz1[100][100], matriz2[100][100], produto[100][100];
    int l, c, i, j, p, q;

    printf("Entre com o numero de linhas e colunas da primeira matriz respectivamente: ");
    scanf("%d%d", &l,&c);

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            printf("Entre com o numero da posicao (%d,%d) da primeira matriz: ", i,j);
            scanf("%f", &matriz1[i][j]);
        }
    }

    printf("Entre com o numero de colunas da segunda matriz: ");
    scanf("%d", &p);

    for(i = 0; i < c; i++){
        for(j = 0; j < p; j++){
            printf("Entre com o numero da posicao (%d,%d) da segunda matriz: ", i,j);
            scanf("%f", &matriz2[i][j]);
        }
    }

     for(i = 0; i < l; i++){
        for(j = 0; j < p; j++){
            produto[i][j] = 0;
            for(q = 0; q < c; q++){
                produto[i][j] += matriz1[i][q]*matriz2[q][j];
            }
        }
    }

    printf("\n\nA matriz 1: \n");

    for(i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            printf("%.1f ", matriz1[i][j]);
        }
        printf("\n");
    }

    printf("\n\nA matriz 2: \n");

    for(i = 0; i < c; i++){
        for(j = 0; j < p; j++){
            printf("%.1f ", matriz2[i][j]);
        }
        printf("\n");
    }

    printf("\n\nO produto das matrizes: \n");

    for(i = 0; i < l; i++){
        for(j = 0; j < p; j++){
            printf("%.1f ", produto[i][j]);
        }
        printf("\n");
    }


}
