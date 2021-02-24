#include <stdio.h>
#include <stdlib.h>

void paresLuvas(int luvas[], int n);
void bubble_sort (int vetor[], int n);
void exibeVetor(int vetor[], int n);


int main(void) {
  int tamLuvas;
  printf("Informe a quantidade de luvas: ");
  scanf("%i", &tamLuvas);
  printf("------------------------------------\n");
  int luvas[tamLuvas];
  printf("Informe os tamanhos das luvas:\n");
  for(int i = 0; i < tamLuvas; i++) {
    scanf("%d", &luvas[i]);
  }
 
  bubble_sort(luvas, tamLuvas);
  return 0;
}


void exibeVetor(int vetor[], int n) {
  int *ptr;
  ptr = vetor;
  for(int i = 0; i < n; i++) {
    printf("%i \n", *ptr);
    ptr++;
  }  
}


void bubble_sort (int vetor[], int n) {
  int k, j, aux;
  for (k = 1; k < n; k++) {
    for (j = 0; j < n - 1; j++) {
      if (vetor[j] > vetor[j + 1]) {
        aux = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = aux;
      }
    }
  }
  
  paresLuvas(vetor, n); 
}


void paresLuvas(int luvas[], int n) {
  int *prim;
  int j = 0;
  int tam = 0;
  prim = luvas;
  for(int i = 0; i < n; i++) {
    if(*prim == *(prim + 1)) {
      tam++;
      prim++;
    }
    prim++;
  }
  int vetorPares[tam];
  prim = luvas;
  for(int i = 0; i < n; i++) {
    if(*prim == *(prim + 1)) {
      vetorPares[j] = *prim;
      j++;
      prim++;
    }
    prim++;
  }
  printf("------------------------------------\n");
  
  if(j == 0) {
    printf("Não ha pares. \n");
  } else if(j == 1) {
    printf("%i par. \n", j);
    printf("Tamanho: \n");
  } else {
    printf("%i pares. \n", j);
    printf("Tamanhos: \n");
  }
  exibeVetor(vetorPares, tam);
}