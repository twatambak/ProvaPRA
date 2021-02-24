#include <stdio.h>
#include <stdlib.h>

#define N 15

void comparaString(char *p1, char *p2);

int main(void) {
  char *p1;
  char *p2;
  p1 = malloc(sizeof(char) * N);
  p2 = malloc(sizeof(char) * N);
  printf("Por favor nao adiciona espaco quando for escrever a string que o codigo buga e acha que sao duas strings aaaaaa \n");
  printf("---------------------------------\n");
  printf("Informe a primeira string: ");
  scanf("%s", p1);
  printf("Informe a segunda string: ");
  scanf("%s", p2);
  printf("---------------------------------\n");
  comparaString(p1, p2);
  return 0;
}

void comparaString(char *p1, char *p2) {
  int passos = 0; 
  char *pTrocas;
  pTrocas = malloc(sizeof(char) * N);
  pTrocas = p1;

  int i = 0;
  while(*p2 != NULL) {
    if(*p1 == *p2) {
      printf("Mantem %c:\n", *p1);
      pTrocas[i] = *p1;
      printf("%s\n", pTrocas);
      //passos++;
    } else if(*p1 == NULL) {
      printf("Adiciona %c: \n", *p2);
      printf("%s => ", pTrocas);
      pTrocas[i] = *p2;
      printf("%s\n", pTrocas);
      passos++;
    } else if(*p1 != *p2){
      printf("Substitui %c por %c: \n", *p1, *p2);
      printf("%s => ", pTrocas);
      pTrocas[i] = *p2;
      printf("%s\n", pTrocas);
      passos++;
    }
    printf("---------------------------------\n");
    i++;
    p1++;
    p2++;
  }

  while(*p1 != NULL) {
    printf("Deleta %c: \n", *p1);
    printf("%s => ", pTrocas);
    pTrocas[i] = ' ';
    printf("%s\n", pTrocas);
    passos++;
    i++;
    p1++;
    printf("---------------------------------\n");
  }
  if(passos == 0) {
    printf("As strings sao iguais.\n");
  } else if(passos == 1){
    printf("Eh necessario apenas %i passo.\n", passos);
  } else {
    printf("Sao necessarios %i passos.\n", passos);
  }
  free(*p1);
  free(*p2);
  //free(*pTrocas);
}