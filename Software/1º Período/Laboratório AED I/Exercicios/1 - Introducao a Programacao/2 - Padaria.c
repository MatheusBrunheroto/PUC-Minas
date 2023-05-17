#include <stdio.h>

/* 2. A padaria HotPão vende uma certa quantidade de pães franceses e uma
quantidade de broas a cada dia. Cada pãozinho custa R$ 0,12 e a broa custa R$
1,50. Ao final do dia, o dono quer saber quanto arrecadou com a venda dos pães
e broas (juntos), e quanto deve guardar numa conta de poupança (10% do total
arrecadado). Você foi contratado para fazer os cálculos para o dono. Com base
nestes fatos, faça um algoritmo para ler as quantidades de pães e de broas, e
depois calcular os dados solicitados. */

float pao_frances = 0.12, broas = 1.5;
float total = 0;

float mult(char* tipo_str, float tipo_float){

     int qnt = 0;
     printf("Quantidade de %s : ",tipo_str);
     scanf("%d",&qnt);

     while(qnt < 0){
        printf("Valor Invalido, insira novamente : ");
        scanf("%d",&qnt);
     }

     return qnt * tipo_float;
}


int main(){

    total += mult("Pao Frances",0.12);
    total += mult("Broas",1.5);

    printf("\nRenda Total = %0.2f\n",total);
    printf("Valor para Poupanca = %0.3f",total/10);

    return 0;
}
