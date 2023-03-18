#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "main.h"

void gera_matriz(double matriz_a[2][2], int* determinante) {
    int i, j;

    srand(time(0));

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            matriz_a[i][j] = rand()%1000;

            *determinante = (matriz_a[0][0] * matriz_a[1][1]) - (matriz_a[0][1] * matriz_a[1][0]);
        }
        
        if(*determinante == 0) {
            i = 0;
            j = 0;
        }
    }
}

void gera_matriz_adjunta(double matriz_a[2][2], int matriz_adjunta[2][2]) {
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

void gera_matriz_inversa(int matriz_adjunta[2][2], int determinante, double inversa_matriz_a[2][2]) {
    int i, j;

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            inversa_matriz_a[i][j] = (double)matriz_adjunta[i][j] / determinante;
        }
    }
}

void recebe_mensagem_usuario(char mensagem_usuario[TMNH]) {
    printf("Entre com o texto que gostaria de criptografar: ");
    fgets(mensagem_usuario, TMNH, stdin);
}

void converte_minusculo(char mensagem_usuario[TMNH], int tmnh_mensagem) {
    int i, j;

    for (i = 0; i < tmnh_mensagem; i++){
        mensagem_usuario[i] = tolower(mensagem_usuario[i]);
    }
}

void converte_mensagem_para_numero(char mensagem_usuario[TMNH], double mensagem_numerica[2][TMNH], int qtd_colunas) {
    int i, j, k;

    k = 0;

    for (i = 0; i < 2; i++){
        for (j = 0; j < qtd_colunas; j++){
            if (mensagem_usuario[k] >= 'a' && mensagem_usuario[k] <= 'z'){
                mensagem_numerica[i][j] = mensagem_usuario[k]-'a'+1;
            } else if (mensagem_usuario[k] == '.') {
                mensagem_numerica[i][j] = mensagem_usuario[k]-19;
            } else if (mensagem_usuario[k] == ',') {
                mensagem_numerica[i][j] = mensagem_usuario[k]-16;
            } else {
                mensagem_numerica[i][j] = 29;
            }
            k++;
        }
    }
}

void produto_matrizes(int qtd_colunas, double result[2][TMNH], double matriz_a[2][TMNH], double matriz_b[2][2]) {
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

int main() {
    int i, j;
    double matriz_a[2][2];
    int determinante;
    int matriz_adjunta[2][2];
    double inversa_matriz_a[2][2];

    char mensagem_usuario[TMNH];
    double mensagem_numerica[2][TMNH];
    int qtd_colunas;
    int tmnh_mensagem;

    double mensagem_codificada[2][TMNH];
    double mensagem_decodificada[2][TMNH];

    gera_matriz(matriz_a, &determinante);

    printf("Matriz A:\n");

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("%f ", matriz_a[i][j]);
        }
        printf("\n");
    }

    gera_matriz_adjunta(matriz_a, matriz_adjunta);

    gera_matriz_inversa(matriz_adjunta, determinante, inversa_matriz_a);

    printf("\nInversa da matriz A: \n");

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("%f ", inversa_matriz_a[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    recebe_mensagem_usuario(mensagem_usuario);

    tmnh_mensagem = strlen(mensagem_usuario) - 1;

    converte_minusculo(mensagem_usuario, tmnh_mensagem);

    qtd_colunas = (tmnh_mensagem % 2) == 0 ? (tmnh_mensagem / 2) : (tmnh_mensagem / 2) + 1;

    converte_mensagem_para_numero(mensagem_usuario, mensagem_numerica, qtd_colunas);

    printf("\nMensagem convertida para numeros: \n");

    for (i = 0; i < 2; i++){
        for (j = 0; j < qtd_colunas; j++){
            printf("%f ", mensagem_numerica[i][j]);
        }
        printf("\n");
    }

    produto_matrizes(qtd_colunas, mensagem_codificada, mensagem_numerica, matriz_a);

    printf("\n\nMensagem codificada: \n");

    for(i = 0; i < 2; i++){
        for(j = 0; j < qtd_colunas; j++){
            printf("%f ", mensagem_codificada[i][j]);
        }
        printf("\n");
    }

    produto_matrizes(qtd_colunas, mensagem_decodificada, mensagem_codificada, inversa_matriz_a);

    printf("\n\nMensagem decodificada: \n");

    for(i = 0; i < 2; i++){
        for(j = 0; j < qtd_colunas; j++){
            printf("%f ", mensagem_decodificada[i][j]);
        }
        printf("\n");
    }

    return 0;
}