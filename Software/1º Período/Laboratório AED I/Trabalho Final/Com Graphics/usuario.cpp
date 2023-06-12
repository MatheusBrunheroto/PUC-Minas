#include "struct.h"
#include "sistema.h"

#include <stdio.h>

#include "usuario.h"


void Usuario(carro * Disponiveis){

    int opcao;
    float dinheiro;

    printf("Insira seu dinheiro -> ");
    scanf("%f",&dinheiro);
    LimpaTela();


    do{
        printf("Dinheiro -> R$ %0.2f\n\n", dinheiro);

        printf("[1] - Comprar Carros\n");
        printf("[2] - Visualizar Carros\n");
        printf("[3] - Voltar\n\n");
        printf("Opção -> ");
        scanf("%i",&opcao);

        switch(opcao){

            case 1: dinheiro = ComprarUsuario(Disponiveis, dinheiro);
            break;

            case 2: VisualizarUsuario(Disponiveis);
            break;

            case 3: LimpaTela(); Sistema(Disponiveis);
            break;

            default:  printf("\nOpção Inválida !! \n"); LimpaTela();
        }

    }while(opcao != 2);
}

void VisualizarUsuario(carro * Disponiveis){

    int opcao;
    int tamanho = Tamanho(Disponiveis);

    Exibe(Disponiveis, false, 0);
    printf("[S] - Sair \n\n\n",4);
    printf("Opção -> ");
    scanf("%i",&opcao);

    if(opcao != 83 || opcao != 115){

        if(opcao <= tamanho){
            // MOSTRAR CARRO
        }
        else
            printf("\nCarro Inexistente !!\n");

    }

    LimpaTela();
}


float ComprarUsuario(carro * Disponiveis, float dinheiro){

    int opcao;
    int tamanho = Tamanho(Disponiveis);

    Exibe(Disponiveis, true, dinheiro);
    printf("[S] - Sair \n\n\n",4);
    printf("Opção -> ");
    scanf("%i",&opcao);

    if(opcao != 83 || opcao != 115){

        if(opcao <= tamanho){

            if(Disponiveis[opcao - 1].vendido == true)
                printf("\nO Carro ja foi vendido !!\n");
            else if(dinheiro < Disponiveis[opcao-1].preco)
                printf("\nDinheiro Insuficiente !!\n");
            else{
                Disponiveis[opcao - 1].vendido = true;
                dinheiro = dinheiro - Disponiveis[opcao - 1].preco;
            }
        }
        else
            printf("\nCarro Inexistente !!\n");

    }

    LimpaTela();
    return dinheiro;
}
