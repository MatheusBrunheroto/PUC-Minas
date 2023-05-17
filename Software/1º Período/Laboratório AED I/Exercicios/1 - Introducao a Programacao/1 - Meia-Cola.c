#include <stdio.h>

/* 1. A fábrica de refrigerantes Meia-Cola vende seu produto em três formatos: lata
de 350 ml, garrafa de 600 ml e garrafa de 2 litros. Se um comerciante compra
uma determinada quantidade de cada formato, faça um algoritmo para calcular
quantos litros de refrigerante ele comprou. */

float total = 0;

float mult(char* recipiente_str, float recipiente_float){

     int qnt = 0;
     printf("Quantidade de %s : ",recipiente_str);
     scanf("%d",&qnt);

     while(qnt < 0){
        printf("Valor Invalido, insira novamente :");
        scanf("%d",&qnt);
     }

     return qnt * recipiente_float;
}

int main(){

    total += mult("lata",0.35);
    total += mult("garrafas (600ml)",0.6);
    total += mult("garrafas (2 litros)",2);

    printf("Quantidade Total em Litros = %0.2f",total);

    return 0;
}
