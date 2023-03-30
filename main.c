#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main() {
    int i, j;
    int matriz_a[2][2];
    int determinante;
    int matriz_adjunta[2][2];
    int inversa_matriz_a[2][2];

    char mensagem_usuario[TMNH];
    int mensagem_numerica[2][TMNH];
    int tmnh_mensagem;
    int qtd_colunas;

    int mensagem_numerica_codificada[2][TMNH];
    int mensagem_numerica_decodificada[2][TMNH];
    char mensagem_descriptografada[TMNH];

    int opcao_menu;

    printf("------------------------------------------------------\n");
    printf("|             Trabalho pratico - LabProg1            |\n");
    printf("------------------------------------------------------\n\n");

    printf("------------------------------------------------------\n");
    printf("| Menu:                                              |\n");
    printf("|                                                    |\n");
    printf("| [1] - Gerar A e sua inversa                        |\n");
    printf("| [2] - Ler mensagem e codificar                     |\n");
    printf("| [3] - Imprimir mensagem codificada                 |\n");
    printf("| [4] - Decodificar e imprimir mensagem decodificada |\n");
    printf("| [9] - Sair                                         |\n");
    printf("------------------------------------------------------\n");

    do {
        printf("\n* Opcao: ");
        scanf("%d%*c", &opcao_menu);

        switch(opcao_menu) {
            case 1:
                gera_matriz(matriz_a, &determinante);

                printf("\nMatriz A:\n\n");

                imprime_matriz_quadrada(matriz_a);

                gera_matriz_adjunta(matriz_a, matriz_adjunta);

                gera_matriz_inversa(matriz_adjunta, determinante, inversa_matriz_a);

                printf("\n\nInversa da Matriz A:\n\n");

                imprime_matriz_quadrada(inversa_matriz_a);

                printf("\n------------------------------------------------------\n");
            break;

            case 2:
                recebe_mensagem_usuario(mensagem_usuario);

                tamanho_mensagem(&tmnh_mensagem, mensagem_usuario);

                converte_minusculo(mensagem_usuario, tmnh_mensagem);

                quantidade_colunas(&qtd_colunas, tmnh_mensagem);

                converte_mensagem_para_numero(mensagem_usuario, mensagem_numerica, qtd_colunas);

                produto_matrizes(qtd_colunas, mensagem_numerica_codificada, mensagem_numerica, matriz_a);

                printf("\n[#] Mensagem codificada com sucesso!\n");

                printf("\n------------------------------------------------------\n");
            break;

            case 3:
                printf("\n\nMensagem codificada:\n\n");

                for(i = 0; i < 2; i++){
                    for(j = 0; j < qtd_colunas; j++){
                        printf("%d\t ", mensagem_numerica_codificada[i][j]);
                    }
                    printf("\n");
                }

                printf("\n------------------------------------------------------\n");
            break;

            case 4:
                produto_matrizes(qtd_colunas, mensagem_numerica_decodificada, mensagem_numerica_codificada, inversa_matriz_a);

                printf("\n\nMensagem decodificada:\n\n");

                for(i = 0; i < 2; i++){
                    for(j = 0; j < qtd_colunas; j++){
                        printf("%3d ", mensagem_numerica_decodificada[i][j]);
                    }
                }

                decodifica_mensagem(qtd_colunas, mensagem_descriptografada, mensagem_numerica);

                printf("\n\n");

                printf("%s", mensagem_descriptografada);

                printf("\n\n------------------------------------------------------\n\n");
            break;

            case 9:
                printf("\n----------------------\n");
                printf("| Programa encerrado |\n");
                printf("----------------------\n");
                exit(0);
            break;

            default:
                printf("\n------------------\n");
                printf("| Opcao invalida |\n");
                printf("------------------\n");
            break;
        }
    } while (1);

    return 0;
}
