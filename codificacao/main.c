#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define TMNH 10000

int main()
{
    char texto[TMNH], texto2[TMNH];
    int texto_num[2][TMNH], colunas, i, j, tmnh_texto, x;

    printf("entre com o texto que gostaria de criptografar: ");
    fgets( texto, TMNH, stdin );

    tmnh_texto = strlen(texto)-1;

    for (i = 0; i < tmnh_texto; i++){
        texto[i] = tolower(texto[i]);
    }

    colunas = tmnh_texto%2 == 0 ? tmnh_texto/2 : tmnh_texto/2 + 1;

    x = 0;

    for (i = 0; i < 2; i++){
        for (j = 0; j < colunas; j++){
            if (texto[x] >= 'a' && texto[x] <= 'z'){
                texto_num[i][j] = texto[x]-'a'+1;
            } else if (texto[x] == '.') {
                texto_num[i][j] = texto[x]-19;
            } else if (texto[x] == ',') {
                texto_num[i][j] = texto[x]-16;
            } else {
                texto_num[i][j] = 29;
            }
            x++;
        }
    }

    x = 0;

    for (i = 0; i < 2; i++){
        for (j = 0; j < colunas; j++){
            if (texto_num[i][j] >= 1 && texto_num[i][j] <= 26){
                texto2[x] = texto_num[i][j]+'a'-1;
            } else if (texto_num[i][j] == 27) {
                texto2[x] = texto_num[i][j]+19;
            } else if (texto_num[i][j] == 28) {
                texto2[x] = texto_num[i][j]+16;
            } else {
                texto2[x] = 32;
            }
            x++;
        }
    }

    //texto_num[1][colunas-1] = texto_num[1][colunas-1] == 10 ? 29 : texto_num[1][colunas-1];

    for (i = 0; i < 2; i++){
        for (j = 0; j < colunas; j++){
            printf("%d ", texto_num[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < x; i++){
        printf("%c ", texto2[i]);
    }

    return 0;
}
