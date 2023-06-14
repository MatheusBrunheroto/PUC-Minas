#include "struct.h"
#include "sistema.h"
#include "exibicao.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "usuario.h"


/* A função "Usuario" mostra as primeiras opções após a entrada como usuário, e executa
   as opções determinadas pelos números na tela. Além disso, conta com um sistema de
   dinheiro, que é resetado toda vez que o usuário volta para o menu principal */

void Usuario(carro * Disponiveis){

    int opcao;
    float dinheiro;

    printf("Insira seu dinheiro -> ");
    scanf("%f",&dinheiro);
    LimpaTela(false);


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

            case 3: LimpaTela(false); Sistema(Disponiveis);
            break;

            default:  printf("\nOpção Inválida !! \n"); LimpaTela(false);
        }

    }while(opcao != 3);
}

// PENDENTE

void VisualizarUsuario(carro * Disponiveis){

    char opcaoCHAR[2];
    int  opcaoINT;
    int tamanho = Tamanho(Disponiveis);

    while(strcmp(opcaoCHAR,"s") != 0){

        LimpaTela(true);
        Exibe(Disponiveis, false, 0);
        printf("[S] - Sair \n\n\n",4);

        printf("Opção -> ");
        scanf("%s", opcaoCHAR);
        opcaoCHAR[0] = tolower(opcaoCHAR[0]);


        if(strcmp(opcaoCHAR,"s") != 0)
            opcaoINT = atoi(opcaoCHAR);    // Converter número em String para Int
        else
            break;


        if(opcaoINT <= tamanho){
            FotosCarros(Disponiveis,opcaoINT);
        }
        else{
            getchar();
            printf("\nCarro Inexistente !!\n");
            printf("Pressione ENTER para continuar ...");
            getchar();
        }

    }

    system("cls");

}


// PENDENTE

float ComprarUsuario(carro * Disponiveis, float dinheiro){

    char opcaoCHAR[2];
    int  opcaoINT;
    int tamanho = Tamanho(Disponiveis);

    while(strcmp(opcaoCHAR,"s") != 0){

        LimpaTela(false);
        Exibe(Disponiveis, true, dinheiro);
        printf("[S] - Sair \n\n\n",4);

        printf("Opção -> ");
        scanf("%s", opcaoCHAR);
        opcaoCHAR[0] = tolower(opcaoCHAR[0]);

        if(strcmp(opcaoCHAR,"s") != 0)
            opcaoINT = atoi(opcaoCHAR);    // Converter número em String para Int
        else
            break; // Da pra botar isso tudo em outra função?

        if(opcaoINT <= tamanho){

            if(Disponiveis[opcaoINT - 1].vendido == true)
                printf("\nO Carro ja foi vendido !!\n");
            else if(dinheiro < Disponiveis[opcaoINT-1].preco)
                printf("\nDinheiro Insuficiente !!\n");
            else{
                Disponiveis[opcaoINT - 1].vendido = true;
                dinheiro = dinheiro - Disponiveis[opcaoINT - 1].preco;
            }

        }
        else
            printf("\nCarro Inexistente !!\n");

    }

    LimpaTela(false);
    return dinheiro;

}
