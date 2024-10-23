
#include "Mochila.h"

Mochila *criar_mochila() {
  Mochila *mochila = malloc(sizeof(Mochila));
  mochila->ultima_posicao_disponivel = 0;
  return mochila;
}

void liberar_mochila(Mochila *mochila) { free(mochila); }

int inserir_item(Mochila *mochila, char item[]) {
  if (mochila->ultima_posicao_disponivel < TAMANHO_MOCHILA) {
    strcpy(mochila->itens[mochila->ultima_posicao_disponivel], item);
    mochila->ultima_posicao_disponivel += 1;
    if (sizeof(MENSAGEM_NOVO_ITEM) > sizeof("")) {
      printf("[*] '%s' %s\n", item, MENSAGEM_NOVO_ITEM);
    }
    return mochila->ultima_posicao_disponivel;
  } else {
    printf("[*] Mochila cheia!\n");
    return -1;
  }
}

int retirar_um_item(Mochila *mochila) {
  char nome_do_removido[MAX_CARACTERES_ITEM];
  if (mochila->ultima_posicao_disponivel > 0) {
    mochila->ultima_posicao_disponivel -= 1;
    strcpy(nome_do_removido,
           mochila->itens[mochila->ultima_posicao_disponivel]);
    strcpy(mochila->itens[mochila->ultima_posicao_disponivel], "");
    if (sizeof(MENSAGEM_ITEM_REMOVIDO) > sizeof("")) {
      printf("[*] '%s' %s\n", nome_do_removido, MENSAGEM_ITEM_REMOVIDO);
    }
    return mochila->ultima_posicao_disponivel;
  } else {
    return 0;
  }
}

void consultar_mochila(Mochila *mochila) {
  int i = 0;
  if (mochila->ultima_posicao_disponivel > 0) {
    printf("Mochila:\n\tItens: %i\n", mochila->ultima_posicao_disponivel);
    for (i = 0; i < mochila->ultima_posicao_disponivel; i++) {
      printf("\t*%s\n", mochila->itens[i]);
    }
  } else {
    printf("Mochila vazia!\n");
  }
}