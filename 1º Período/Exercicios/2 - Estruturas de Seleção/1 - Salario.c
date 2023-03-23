#include <stdio.h>

/* 1. Uma empresa decidiu dar um aumento escalonado a seus funcionários de acordo
com a seguinte regra:
- 13% para os salários inferiores ou iguais a R$200,00;
- 11% para os salários situados entre R$ 200,00 e R$400,00 (inclusive);
- 9% para os salários entre R$400,00 e R$800,00(inclusive) e
- 7% para os demais salários.
Escreva um programa que receba o salário atual de um funcionário e forneça o
valor do seu novo salário. */

int main(){

    float salario;
    printf("Insira o salário atual de um funcionário : ");
    scanf("%f",&salario);
    while(salario < 1){
        printf("Valor Invalido, insira novamente : ");
        scanf("%d",&salario);
     }
    
    if(salario <= 200){
        salario += (13*salario)/100;
    }
    else if(salario > 200 && salario <= 400){
        salario += (11*salario)/100;
    }
    else if(salario > 400 && salario <= 800){
        salario += (9*salario)/100;    
    }
    else{
        salario += (7*salario)/100;
    }

    printf("O novo salário será de : %0.2f",salario);

    return 0;
}