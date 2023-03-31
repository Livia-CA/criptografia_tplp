#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../main.h"

void recebe_mensagem_usuario(char mensagem_usuario[TMNH]) {
    printf("\n\nInforme a mensagem: ");
    fgets(mensagem_usuario, TMNH, stdin);
    mensagem_usuario[strcspn(mensagem_usuario, "\r\n")] = 0;
}

void tamanho_mensagem(int* tmnh_mensagem, char mensagem_usuario[TMNH]) {
    *tmnh_mensagem = strlen(mensagem_usuario);
}

void converte_minusculo(char mensagem_usuario[TMNH], int tmnh_mensagem) {
    int i;

    for (i = 0; i < tmnh_mensagem; i++){
        mensagem_usuario[i] = tolower(mensagem_usuario[i]);
    }
}

void quantidade_colunas(int* qtd_colunas, int tmnh_mensagem) {
    *qtd_colunas = (tmnh_mensagem % 2) == 0 ? (tmnh_mensagem / 2) : (tmnh_mensagem / 2) + 1;
}

void converte_mensagem_para_numero(char mensagem_usuario[TMNH], int mensagem_numerica[2][TMNH], int qtd_colunas) {
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

void decodifica_mensagem(int qtd_colunas, char mensagem_descriptografada[TMNH], int mensagem_numerica[2][TMNH]) {
    int i, j, x;

    x = 0;

    for (i = 0; i < 2; i++){
        for (j = 0; j < qtd_colunas; j++){
            if (mensagem_numerica[i][j] >= 1 && mensagem_numerica[i][j] <= 26){
                mensagem_descriptografada[x] = mensagem_numerica[i][j]+'a'-1;
            } else if (mensagem_numerica[i][j] == 27) {
                mensagem_descriptografada[x] = mensagem_numerica[i][j]+19;
            } else if (mensagem_numerica[i][j] == 28) {
                mensagem_descriptografada[x] = mensagem_numerica[i][j]+16;
            } else {
                mensagem_descriptografada[x] = 32;
            }
            x++;
        }
    }

    mensagem_descriptografada[x] = '\0';
}
