#define TMNH 10000

void gera_matriz(int matriz_a[2][2], int* determinante);
void imprime_matriz_quadrada(int matriz[2][2]);
void gera_matriz_adjunta(int matriz_a[2][2], int matriz_adjunta[2][2]);
void gera_matriz_inversa(int matriz_adjunta[2][2], int determinante, int inversa_matriz_a[2][2]);

void recebe_mensagem_usuario(char mensagem_usuario[TMNH]);
void tamanho_mensagem(int* tmnh_mensagem, char mensagem_usuario[TMNH]);
void converte_minusculo(char mensagem_usuario[TMNH], int tmnh_mensagem);
void quantidade_colunas(int* qtd_colunas, int tmnh_mensagem);
void converte_mensagem_para_numero(char mensagem_usuario[TMNH], int mensagem_numerica[2][TMNH], int qtd_colunas);

void produto_matrizes(int qtd_colunas, int result[2][TMNH], int matriz_a[2][TMNH], int matriz_b[2][2]);
void decodifica_mensagem(int qtd_colunas, char mensagem_descriptografada[TMNH], int mensagem_numerica[2][TMNH]);