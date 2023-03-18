#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

void gera_matriz(int matriz_a[2][2]) {
    int i, j;
    int determinante;

    srand(time(0));

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            matriz_a[i][j] = rand()%1000;

            determinante = (matriz_a[0][0] * matriz_a[1][1]) - (matriz_a[0][1] * matriz_a[1][0]);
        }
        
        if(determinante == 0) {
            i = 0;
            j = 0;
        }
    }
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

int main() {

    int i, j;
    int matriz_a[2][2];
    int matriz_adjunta[2][2];

    gera_matriz(matriz_a);

    printf("Matriz A:\n");

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("%d ", matriz_a[i][j]);
        }
        printf("\n");
    }

    gera_matriz_adjunta(matriz_a, matriz_adjunta);
    
    return 0;

}