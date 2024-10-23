
#include "Personagem.h"
#define NIVEL_INICIAL 6

void atributos_iniciais(Personagem *personagem, int _forca, int _inteligencia, int _sabedoria, int _destreza, int _constituicao, int _carisma){
  personagem->atributos[forca]=_forca;
  personagem->atributos[inteligencia]=_inteligencia;
  personagem->atributos[sabedoria]=_sabedoria;
  personagem->atributos[destreza]=_destreza;
  personagem->atributos[constituicao]=_constituicao;
  personagem->atributos[carisma]=_carisma;
}

Personagem * criar_personagem(){
  Personagem *personagem;
  personagem=malloc(sizeof(Personagem));
  printf("Escolha o seu nome: \n> ");
  scanf("%s",personagem->nome);
  printf("Escolha sua classe: Bárbaro, Cavaleiro\n");
  while(1){
    printf("> ");
    scanf("%s",personagem->classe);
    if(strcmp(personagem->classe, "Bárbaro") == 0){ 
      atributos_iniciais(personagem,3,0,0,1,2,0);
      break;
    } else if (strcmp(personagem->classe, "Cavaleiro") == 0) {
      atributos_iniciais(personagem,2,0,0,2,1,1);
      break;
    } else {
      continue;
    }
  }
  personagem->nivel=NIVEL_INICIAL;
  return personagem;
}

void liberar_personagem(Personagem *personagem){
  free(personagem);
}

int aumentar_nivel(Personagem *personagem, int atributo){
  personagem->atributos[atributo]+=1;
  personagem->nivel+=1;
  return personagem->nivel;
}

void movimentar_personagem(Personagem *personagem, int linha, int coluna){
  if((linha<0)||(linha>4)){
    return;
  } else if ((coluna<0)||(coluna>4)) {
    return;
  } else {
  personagem->posicao[0]=linha;
  personagem->posicao[1]=coluna;
  }
}

void definir_dinheiro(Personagem *personagem, double valor){
  personagem->dinheiro+=valor;
}

void consultar_atributos(Personagem *personagem){
  printf("Atributos:\n\t[1] Força: %i\n\t[2] Inteligência: %i\n\t[3] Sabedoria: %i\n\t[4] Destreza: %i\n\t[5] Constituição: %i\n\t[6] Carisma: %i\n",
  personagem->atributos[forca],
  personagem->atributos[inteligencia],
  personagem->atributos[sabedoria],
  personagem->atributos[destreza],
  personagem->atributos[constituicao],
  personagem->atributos[carisma]
  );
}

void consultar_todos_atributos(Personagem *personagem){
  printf("Personagem:\n\tNome: %s\n\tClasse: %s\n\tNível: %i\n\tDinheiro: %.2f BTC\n\tPosição(linha,coluna): %i, %i\n",
  personagem->nome,
  personagem->classe,
  personagem->nivel,
  personagem->dinheiro,
  personagem->posicao[0],
  personagem->posicao[1]
  );
  consultar_atributos(personagem);
}