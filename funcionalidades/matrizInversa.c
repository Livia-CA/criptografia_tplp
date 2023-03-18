#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int matrizA[2][2] = {4,7,8,1};
    int matrizAdjunta[2][2];
    int determinante;

    double inversaDaMatrizA[2][2];
    
    float matrizIdentidade[2][2];

    int i, j, k, l;

    srand(time(0));

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            //matrizA[i][j] = rand()%10000;

            determinante = (matrizA[0][0] * matrizA[1][1]) - (matrizA[0][1] * matrizA[1][0]);

            if(determinante == 0) {
                i = 0;
                j = 0;
            }
        }
    }

    printf("Matriz A:\n");

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("%d ", matrizA[i][j]);
        }
        printf("\n");
    }

    printf("\ndeterminante: %d\n", determinante);

    k = 1;
    l = 1;

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            if(i != j) {
                matrizAdjunta[i][j] = -matrizA[k][l];
            } else {
                matrizAdjunta[i][j] = matrizA[k][l];
            }

            if(k == 1) {
                k--;
            }
        }
        k++;
        l--;
    }

    printf("\nMatriz adjunta:\n");

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("%d ", matrizAdjunta[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            inversaDaMatrizA[i][j] = (double)matrizAdjunta[i][j] / determinante;
        }
    }

    printf("\nInversa da matriz A: \n");

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("%f ", inversaDaMatrizA[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            matrizIdentidade[i][j] = 0;
            for(k = 0; k < 2; k++){
                matrizIdentidade[i][j] += matrizA[i][k]*inversaDaMatrizA[k][j];
            }
        }
    }

    printf("\n\nA^-1 * A: \n");

    for(i = 0; i < 2; i++){
        for(j = 0; j < 2; j++){
            printf("%f ", matrizIdentidade[i][j]);
        }
        printf("\n");
    }

    return 0;

}