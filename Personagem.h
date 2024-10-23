#define TAMANHO_MAX_NOME 20

enum enum_atributos{forca=0, inteligencia=1, sabedoria=2, destreza=3, constituicao=4, carisma=5,numero_de_atributos};

typedef struct _personagem{
  char nome[TAMANHO_MAX_NOME];
  char classe[TAMANHO_MAX_NOME];
  double dinheiro;
  int nivel;
  int posicao[2]; //posição[2]={linha,coluna(y,x)};
  int atributos[6]; //fiz uma struct para os atributos antes, mas achei assim melhor assim
} Personagem;

Personagem * criar_personagem();
void liberar_personagem(Personagem *personagem);
int aumentar_nivel(Personagem *personagem, int atributo);
void movimentar_personagem(Personagem *personagem, int linha, int coluna);
void definir_dinheiro(Personagem *personagem, double valor);
void consultar_atributos(Personagem *personagem);
void consultar_todos_atributos(Personagem *personagem);