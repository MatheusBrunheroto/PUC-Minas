#include <stdio.h>

/* Escreva um programa na linguagem C para ler um número inteiro N
e depois apresente os N primeiros números naturais ímpares. */

int main(){
    int n;
    printf("Escreva um número inteiro : ");
    scanf("%i",&n);
    
    if(n >= 0){
        for(int i = 0; i <= n; i++){
            if(i % 2 != 0){
                printf("%i ",i);
            } else {}
        }
    } else {}
}
