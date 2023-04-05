#include <stdio.h>

/* 2. Para doar sangue é necessário ter entre 18 e 67 anos. Faça um programa que
pergunte a idade de uma pessoa e diga se ela pode doar sangue ou não. */

// Não foi especificado mas por senso comum vou considerar que "entre" representa >= e <=

int main(){

    int idade;
    printf("Qual a sua idade ? : ");
    scanf("%i",&idade);
    while(idade < 0 || idade > 116){
        printf("Valor Invalido, insira novamente : ");
        scanf("%d",&idade);
    }

    (idade >= 18 && idade <= 67)? printf("Pode ") : printf("Não pode ");
    printf("doar sangue.");

    return 0;
}