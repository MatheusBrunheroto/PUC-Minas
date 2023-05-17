#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  srand((unsigned)time(NULL));

  int n;
  printf("Insira o tamanho do Captcha que deseja gerar : ");
  scanf("%i", &n);
  char captcha[n];
  char solucao[n];
  system("clear");
  
  do {
    printf("Captcha -> ");
    for (int i = 0, aux; i < n; i++) {
      aux = rand() % (122 - 48 + 1) + 48;
      while ((aux >= 58 && aux <= 64) || (aux >= 91 && aux <= 96)) {
        aux = rand() % (122 - 48 + 1) + 48;
      }

      captcha[i] = aux;
      printf("%c", captcha[i]);
    }
    captcha[n] = '\0';

    printf("\nSolução : ");
    scanf("%s", solucao);

    if (strcmp(captcha, solucao) == 0) {
      getchar();
      printf("\nVocê acertou o Captcha, pressione ENTER para continuar ...");
    } else {
      getchar();
      printf("\nVocê errou o Captcha, pressione ENTER para continuar ...");
      getchar();
    }
    system("clear");
    
  } while ((strcmp(captcha, solucao) != 0));
}