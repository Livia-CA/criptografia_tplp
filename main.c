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

int main() {

    int i, j;
    int matriz_a[2][2];

    gera_matriz(matriz_a);

    printf("Matriz A:\n");

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("%d ", matriz_a[i][j]);
        }
        printf("\n");
    }

    return 0;

}