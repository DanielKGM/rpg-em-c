#define TAMANHO_MOCHILA 10
#define MAX_CARACTERES_ITEM 16
#define MENSAGEM_NOVO_ITEM "guardado(a) na sua mochila!"
#define MENSAGEM_ITEM_REMOVIDO "removido(a) da sua mochila!"

// "" para que não tenha mensagem de item removido ou guardado

typedef struct _mochila {
  char itens[TAMANHO_MOCHILA][MAX_CARACTERES_ITEM];
  int ultima_posicao_disponivel;
} Mochila;

Mochila * criar_mochila();
void liberar_mochila(Mochila *mochila);
int inserir_item(Mochila *mochila, char item[]);
int retirar_um_item(Mochila *mochila);
void consultar_mochila(Mochila *mochila); 