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
            matriz_a[i][j] = rand()%10000;

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

void imprime_matriz_quadrada(double matriz[2][2]) {
    int i, j;

    for(i = 0; i < 2; i++) {
        for(j = 0; j < 2; j++) {
            printf("%f\t ", matriz[i][j]);
        }
        printf("\n");
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

void decodifica_mensagem(int qtd_colunas, char mensagem_descriptografada[TMNH], double mensagem_numerica[2][TMNH]) {
    int i, j, x;

    x = 0;

    for (i = 0; i < 2; i++){
        for (j = 0; j < qtd_colunas; j++){
            if ((int)mensagem_numerica[i][j] >= 1 && (int)mensagem_numerica[i][j] <= 26){
                mensagem_descriptografada[x] = (int)mensagem_numerica[i][j]+'a'-1;
            } else if ((int)mensagem_numerica[i][j] == 27) {
                mensagem_descriptografada[x] = (int)mensagem_numerica[i][j]+19;
            } else if ((int)mensagem_numerica[i][j] == 28) {
                mensagem_descriptografada[x] = (int)mensagem_numerica[i][j]+16;
            } else {
                mensagem_descriptografada[x] = 32;
            }
            x++;
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
    int tmnh_mensagem;
    int qtd_colunas;

    double mensagem_numerica_codificada[2][TMNH];
    double mensagem_numerica_decodificada[2][TMNH];
    char mensagem_descriptografada[TMNH];

    int opcao_menu;

    do {
        scanf("%d%*c", &opcao_menu);

        switch(opcao_menu) {
            case 1:
                gera_matriz(matriz_a, &determinante);
                
                printf("\nMatriz A:\n");

                imprime_matriz_quadrada(matriz_a);

                gera_matriz_adjunta(matriz_a, matriz_adjunta);

                gera_matriz_inversa(matriz_adjunta, determinante, inversa_matriz_a);

                printf("\nInversa da Matriz A:\n");

                imprime_matriz_quadrada(inversa_matriz_a);
            break;

            case 2:
                recebe_mensagem_usuario(mensagem_usuario);

                tmnh_mensagem = strlen(mensagem_usuario) - 1;

                converte_minusculo(mensagem_usuario, tmnh_mensagem);

                qtd_colunas = (tmnh_mensagem % 2) == 0 ? (tmnh_mensagem / 2) : (tmnh_mensagem / 2) + 1;

                converte_mensagem_para_numero(mensagem_usuario, mensagem_numerica, qtd_colunas);

                produto_matrizes(qtd_colunas, mensagem_numerica_codificada, mensagem_numerica, matriz_a);

                printf("Mensagem codificada com sucesso!");
            break;

            case 3:
                printf("\n\nMensagem codificada: \n");

                for(i = 0; i < 2; i++){
                    for(j = 0; j < qtd_colunas; j++){
                        printf("%.f\t ", mensagem_numerica_codificada[i][j]);
                    }
                    printf("\n");
                }
            break;

            case 4:
                produto_matrizes(qtd_colunas, mensagem_numerica_decodificada, mensagem_numerica_codificada, inversa_matriz_a);

                printf("\n\nMensagem decodificada:\n\n");

                for(i = 0; i < 2; i++){
                    for(j = 0; j < qtd_colunas; j++){
                        printf("%.f ", mensagem_numerica_decodificada[i][j]);
                    }
                }

                decodifica_mensagem(qtd_colunas, mensagem_descriptografada, mensagem_numerica);

                printf("\n");

                for (i = 0; i < tmnh_mensagem; i++){
                    printf("%c", mensagem_descriptografada[i]);
                }

                exit(0);
            break;

            case 9:
                printf("Programa encerrado");
                exit(0);
            break;
        
            default:
                printf("Programa encerrado");
                exit(0);
            break;
        }
    } while (1);

    return 0;
}