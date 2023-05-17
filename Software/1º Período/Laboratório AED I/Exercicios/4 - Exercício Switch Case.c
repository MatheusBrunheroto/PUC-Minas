#include <stdio.h>
#include <stdbool.h>

/* Implemente um programa em linguagem C que realize, de forma não sequencial (menu de opções, utilizando a
   estrutura de seleção múltipla switch-case), as seguintes operações:

     1. Realizar, utilizando a função scanf, a leitura do preço de venda de um produto qualquer;
     2. Calcular o preço de venda do produto, aplicando-se um desconto de 10% (dez porcento);
     3. Calcular o preço de venda do produto, aplicando-se um desconto de 20% (vinte porcento);
     4. Sair do programa. */

int main(){
    
    system("clear");
    
    int opcao;
    float preco = -1;
    bool preco_inserido = false;
    
    do{
        
        printf("Menu: ");
        if(preco_inserido == true){
            printf("   (Preço = R$ %0.2f)",preco);
        } else {}
        printf("\n\n");
        printf("[1] - Inserção de preço de venda do produto \n");
        printf("[2] - Preço de venda do produto com desconto de 10% \n");
        printf("[3] - Preço de venda do produto com desconto de 20% \n");
        printf("[4] - Sair \n\n");
        printf("Digite sua opção -> ");
        scanf("%i",&opcao);
    
        switch(opcao){
            
            case 1:
                printf("Insira o preço de venda -> ");
                scanf("%f",&preco);
                while(preco < 0){
                    printf("Valor inválido, insira novamente -> ");
                    scanf("%f",&preco);
                }
                if(preco == 0){
                    preco_inserido = false;
                }
                else{
                    preco_inserido = true;
                }
                
            break;
            
            case 2:
                if(preco_inserido == true){
                    printf("O preço de venda do produto com desconto de 10% é R$ %0.2f\n",preco - (10*preco)/100);
                }
                else{
                    printf("O preço de venda do produto nao foi inserido\n");
                }
            break;
        
            case 3:
                if(preco_inserido == true){
                    printf("O preço de venda do produto com desconto de 20% é R$ %0.2f\n",preco - (20*preco)/100);
                }
                else{
                    printf("O preço de venda do produto nao foi inserido\n");
                }
            break;
        
            case 4:
            break;
            
            default:
                printf("A opcao inserida é inválida\n");
        }
        getchar();
        printf("Pressione ENTER para continuar ...");
        getchar();
        system("clear");
    }while(opcao != 4);
}
