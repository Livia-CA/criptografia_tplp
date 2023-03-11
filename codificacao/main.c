#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TMNH 10000

int main()
{
    char texto[TMNH];
    int texto_num[2][TMNH], colunas, i, j, tmnh_texto, x;

    printf("entre com o texto que gostaria de criptografar: ");
    fgets( texto, TMNH, stdin );

    tmnh_texto = strlen(texto)-1;

    colunas = tmnh_texto%2 == 0 ? tmnh_texto/2 : tmnh_texto/2 + 1;

    x = 0;

    for (i = 0; i < 2; i++){
        for (j = 0; j < colunas; j++){
            texto_num[i][j] = (double)texto[x];
            x++;
        }
    }

    texto_num[1][colunas-1] = texto_num[1][colunas-1] == 10 ? 32 : texto_num[1][colunas-1];

    for (i = 0; i < 2; i++){
        for (j = 0; j < colunas; j++){
            printf("%d ", texto_num[i][j]);
        }
        printf("\n");
    }

    return 0;
}
