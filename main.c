#include "Mochila.h"
#include "Personagem.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// DANIEL CAMPOS GALDEZ MONTEIRO
// PROGRAMA DE TESTE QUE USA OS TADS PERSONAGEM E MOCHILA:

void apagar_tela() {
  printf(
      "\033[0;0H\033[2J"); // isso serve para apagar a tela do console do replit
}

void santuario(Personagem *personagem) {
  unsigned short int i = numero_de_atributos + 1;
  printf("[*] Bem-vindo ao santuário! Escolha que atributo quer subir.\n");
  consultar_atributos(personagem);
  while (i > numero_de_atributos) {
    printf("> ");
    if (scanf("%hu", &i) != 1) {
      i = numero_de_atributos + 1;
    }
  }
  //apagar_tela();
  return aumentar_nivel(personagem, i - 1);
}

void poco_desejos(Mochila *mochila) {
  char item[MAX_CARACTERES_ITEM];
  printf("[*] Bem-vindo ao poço dos desejos! Coloque uma string na sua "
         "mochila.\n> ");
  scanf("%s", item);
  //apagar_tela();
  inserir_item(mochila, item);
}

void imprimir_mapa(int linha_player, int coluna_player, char mapa[4][4][6]) {
  int i = 0, j = 0;
  printf("Mapa:\n");
  for (i = 0; i < 4; i++) {
    printf("\t");
    for (j = 0; j < 4; j++) {
      if ((i == linha_player - 1) && (j == coluna_player - 1)) {
        printf("[ X ]");
      } else {
        printf("%s", mapa[i][j]);
      }
    }
    printf("\n");
  }
}

void eventos(Personagem *personagem, Mochila *mochila, int linha, int coluna) {
  if ((linha == 1) && (coluna == 3)) {
    printf("[*] Um dos seus itens foi roubado!\n");
    retirar_um_item(mochila);
  } else if ((linha == 1) && (coluna == 4)) {
    poco_desejos(mochila);
  } else if ((linha == 3) && (coluna == 3)) {
    santuario(personagem);
  } else if ((linha == 2) && (coluna == 1)) {
    printf("[*] Você trabalha por 1hr e ganha 5BTC.\n");
    definir_dinheiro(personagem, 5);
  } else if ((linha == 3) && (coluna == 1)) {
    printf("[*] Você doa 1BTC para alguns moradores de rua.\n");
    definir_dinheiro(personagem, -1);
  } else {
    printf("[*] Nada aqui.\n");
  }
}

int andar(Personagem *personagem, Mochila *mochila, char mapa[4][4][6]) {
  int linha = 0, coluna = 0;
  printf("\nEscolha uma linha e uma coluna para visitar (999 para sair).\n> "
         "Linha: ");
  scanf("%i", &linha);
  if (linha == 999) {
    //apagar_tela();
    printf("Obrigado por jogar!\n");
    liberar_mochila(mochila);
    liberar_personagem(personagem);
    return 0;
  }
  printf("> Coluna: ");
  scanf("%i", &coluna);
  //apagar_tela();
  movimentar_personagem(personagem, linha, coluna);
  eventos(personagem, mochila, linha, coluna);
  imprimir_mapa(linha, coluna, mapa);
  return 1;
}

int main(void) {
  Personagem *personagem1;
  Mochila *mochila1;
  int continuarjogo = 1;
  char mapa[4][4][6] = {
      {"(   )", "(   )", "( ! )", "( P )"},
      {"( T )", "(   )", "(   )", "(   )"},
      {"( C )", "(   )", "( S )", "(   )"},
      {"(   )", "(   )", "(   )", "(   )"},
  };
  printf("Bem-vindo ao Bárbaros Indestrutíveis e Cavaleiros Triunfantes!\n");
  personagem1 = criar_personagem();
  mochila1 = criar_mochila();
  //apagar_tela();
  imprimir_mapa(1, 1, mapa);
  while (continuarjogo) {
    consultar_todos_atributos(personagem1);
    consultar_mochila(mochila1);
    continuarjogo = andar(personagem1, mochila1, mapa);
  }
  return 0;
}