#define TMNH 10000

void gera_matriz(int matriz_a[2][2], int* determinante);
void gera_matriz_adjunta(int matriz_a[2][2], int matriz_adjunta[2][2]);
void gera_matriz_inversa(int matriz_adjunta[2][2], int determinante, double inversa_matriz_a[2][2]);

void recebe_mensagem_usuario(char mensagem_usuario[TMNH]);
void converte_minusculo(char mensagem_usuario[TMNH], int tmnh_mensagem);
void converte_mensagem_para_numero(char mensagem_usuario[TMNH], int mensagem_numerica[2][TMNH], int qtd_colunas);