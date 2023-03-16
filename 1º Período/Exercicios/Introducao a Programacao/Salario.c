#include <stdio.h>

/* 3. Faça um algoritmo para ler o salário de um funcionário e aumentá-lo em 15%.
Após o aumento, desconte 8% de impostos. Imprima o salário inicial, o salário
com o aumento e o salário final. */

float s;

int main(){

    printf("Insira o salario : ");
    scanf("%f",&s);
    while (s < 0){
        printf("Valor Invalido, insira novamente : ");
        scanf("%f",&s);
    }

    printf("\nSalario : %0.3f\n",s);

    s += 15*(s/100);
    printf("Salario com aumento : %0.3f\n",s);

    s -= 8*(s/100);
    printf("Salario final : %0.3f\n",s);
}
