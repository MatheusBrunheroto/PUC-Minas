#include <stdio.h>

/* Escreva um programa na linguagem C para ler um número inteiro
positivo par N e apresente todos os números pares de 0 até N, em
ordem decrescente. */

int main(){
  
    int n = 1;
    printf("Escreva um número inteiro positivo par N : ");
    while(n % 2 != 0){
        scanf("%i",&n); 
    }
    printf("Números inteiros pares de 0 até N em ordem decrescente -> ");
    for(int i = n; i >= 0; i-=2){
        printf("%i ",i);
    }
}
