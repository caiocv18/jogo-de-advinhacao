#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STRING 255

int main() {
  printf("***************************************\n");
  printf("* BEM VINDO AO PROGRAMA DE ADVINHACAO *\n");
  printf("***************************************\n");

  srand(time(NULL));

  int numeroSecreto = rand() % 101;
  int tentativa;
  int numeroDeTentativas = 1;
  int acertou = 0;
  char nome[STRING];

  printf("INFORME SEU NOME: \n");
  fflush(stdin);
  scanf("%[^\n]s", nome);
  fflush(stdin);
  while (acertou == 0) {
    // printf("%d\n", numeroSecreto);
    printf("TENTATIVA NUMERO %d\n", numeroDeTentativas);
    printf("INFORME UM NUMERO PARA TENTATIVA (NUMERO ENTRE 0 E 100)\n");
    scanf("%d", &tentativa);

    acertou = numeroSecreto == tentativa;

    if (acertou) {
      printf("VOCE ADIVINHOU O NUMERO!\n");
      break;
    }

    else if (tentativa > numeroSecreto) {
      printf("O NUMERO E MENOR QUE %d, TENTE NOVAMENTE COM OUTRO NUMERO!\n",
             tentativa);
    }

    else if (tentativa < numeroSecreto) {
      printf("O NUMERO E MAIOR QUE %d, TENTE NOVAMENTE COM OUTRO NUMERO!\n",
             tentativa);
    }

    numeroDeTentativas++;
  }
  printf("FIM DE JOGO!\n");
  printf("VOCE ACERTOU DEPOIS DE %d TENTATIVAS!\n", numeroDeTentativas);
  printf("PLACAR\n");
  printf("%s - %d", nome, numeroDeTentativas);
}