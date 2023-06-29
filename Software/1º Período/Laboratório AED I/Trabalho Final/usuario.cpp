#include "struct.h"
#include "sistema.h"
#include "exibicao.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "usuario.h"


/* A função "Usuario" mostra as primeiras opções após a entrada como usuário, e executa
   as opções determinadas pelos números na tela. Além disso, conta com um sistema de
   dinheiro, que é resetado toda vez que o usuário volta para o menu principal. */

void Usuario(carro * Disponiveis){

    int opcao;
    float dinheiro;

    printf("Insira seu dinheiro -> ");
    scanf("%f", &dinheiro);
    LimpaTela(false);


    do{
        printf("Dinheiro -> R$ %0.2f\n\n", dinheiro);

        printf("[1] - Comprar Carros\n");
        printf("[2] - Visualizar Carros\n");
        printf("[3] - Voltar\n\n");
        printf("Opção -> ");
        scanf("%i", &opcao);

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



/* A função "VisualizarUsuario" exibe os carros disponíveis, e depende diretamente da função
   "LoopOpcoes", que retorna 0, causando a saída da função "VisualizarUsuario",
   ou retorna o valor da opção selecionada, se for maior que o tamanho de ListaDeCarros, o carro não existe. */

void VisualizarUsuario(carro * Disponiveis){

    int tamanho = Tamanho(Disponiveis);
    int opcao;
    opcao = LoopOpcoes(Disponiveis, 0, true);

    if(opcao != 0){
        while(opcao != 0){

            if(opcao <= tamanho){
                FotosCarros(Disponiveis, opcao);
            }
            else{
                getchar();
                printf("\nCarro Inexistente !!\n");
                printf("Pressione ENTER para continuar ...");
                getchar();
            }

            opcao = LoopOpcoes(Disponiveis, 0, true);

        }
    }

    system("cls");

}



/* A função "ComprarUsuario" exibe os carros disponíveis, e depende diretamente da função
   "LoopOpcoes", que retorna 0, causando a saída da função "ComprarUsuario",
   ou retorna o valor da opção selecionada, se for maior que o tamanho de ListaDeCarros, o carro não existe.
   Caso o carro exista, o dinheiro entra em ação, permitindo ou não a compra de um carro. */

 float ComprarUsuario(carro * Disponiveis, float Dinheiro){

    int tamanho = Tamanho(Disponiveis);
    int opcao;
    opcao = LoopOpcoes(Disponiveis, Dinheiro, false);

    while(opcao != 0){

        if(opcao <= tamanho){

            if(Disponiveis[opcao - 1].vendido == true)
                printf("\nO Carro ja foi vendido !!\n");
            else if(Dinheiro < Disponiveis[opcao-1].preco)
                printf("\nDinheiro Insuficiente !!\n");
            else{
                Disponiveis[opcao - 1].vendido = true;
                Dinheiro = Dinheiro - Disponiveis[opcao - 1].preco;
            }

        }
        else
            printf("\nCarro Inexistente !!\n");

        opcao = LoopOpcoes(Disponiveis, Dinheiro, false);

    }

    LimpaTela(false);
    return Dinheiro;

}
