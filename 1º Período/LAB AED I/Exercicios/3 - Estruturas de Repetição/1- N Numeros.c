#include <stdio.h>

/* 1. Desenvolva um programa que faça a captura de N números com
ponto flutuante. O programa deverá calcular o somatório e a média
desses números. */

int main(){
    
    int n, somatorio = 0;
    printf("Insira quantos números deseja escrever : ");
    scanf("%i",&n);
    
    for(int i = 1, valor = 0; i <= n ; i++){
        printf("Valor %i -> ",i);
        scanf("%i",&valor);
        somatorio += valor;
        valor = 0;
    }
    printf("Somatório : %i\n",somatorio);
    printf("Média : %i\n",somatorio/n);

}