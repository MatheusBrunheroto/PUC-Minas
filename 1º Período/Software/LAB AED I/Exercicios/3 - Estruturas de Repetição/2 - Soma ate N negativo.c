#include <stdio.h>

/* 2. Construa um programa que imprime a soma de todos os valores
positivos digitados pelo usuário até que ele digite um número
negativo. */

int main(){
    
    int soma = 0;
    int i;
    
    while(i >= 0){
        scanf("%i",&i);
        if(i >= 0){
            soma += i;
        } else {}
    }
    printf("Soma de todos os valores positivos = %i",soma);
    
}