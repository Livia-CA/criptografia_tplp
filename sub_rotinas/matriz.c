#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../main.h"

void gera_matriz(int matriz_a[2][2], int* determinante) {
    int i, j;

    srand(time(0));

    do {
        for(i = 0; i < 2; i++) {
            for(j = 0; j < 2; j++) {
                matriz_a[i][j] = rand()%99;
            }
        }

        *determinante = (matriz_a[0][0] * matriz_a[1][1]) - (matriz_a[0][1] * matriz_a[1][0]);
    } while(*determinante != 1 && *determinante != -1);
}

void gera_matriz_adjunta(int matriz_a[2][2], int matriz_adjunta[2][2]) {
    int i, j, k, l;

    k = 1;
    l = 1;

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            if(i != j) {
                matriz_adjunta[i][j] = -matriz_a[k][l];
            } else {
                matriz_adjunta[i][j] = matriz_a[k][l];
            }

            if(k == 1) {
                k--;
            }
        }
        k++;
        l--;
    }
}

void gera_matriz_inversa(int matriz_adjunta[2][2], int determinante, int inversa_matriz_a[2][2]) {
    int i, j;

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            inversa_matriz_a[i][j] = (int)matriz_adjunta[i][j] / determinante;
        }
    }
}

void imprime_matriz_quadrada(int matriz[2][2]) {
    int i, j;

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("%6d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void produto_matrizes(int qtd_colunas, int result[2][TMNH], int matriz_a[2][TMNH], int matriz_b[2][2]) {
    int i, j, k;

    for(i = 0; i < 2; i++){
        for(j = 0; j < qtd_colunas; j++){
            result[i][j] = 0;
            for(k = 0; k < 2; k++){
                result[i][j] += matriz_a[k][j] * matriz_b[i][k];
            }
        }
    }
}