#include "struct.h"
#include "entrada.h"
#include "administrador.h"
#include "usuario.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "sistema.h"





/* A fun��o "Tamanho" recebe o vetor ListadeCarros, e atrav�s dele verifica
   os carros de (0 - 20). Eu defini como padr�o de carro inexistente
   o ano = 0. Ent�o todo carro cujo ano = 0 � invalido e o
   comando 'break' � executado. */ // ORT

int Tamanho(carro * Disponiveis){

    int i, tamanho;

    for(i = 0, tamanho = 0; i < 20; i++){

        if(Disponiveis[i].ano == 0)
            break;
        else
            tamanho++;

    }
    return tamanho;
}



void LimpaTela(bool visualizacao){

    /* Exibi��o = 0, Significa que o usu�rio est� comprando um carro,
     ou um administrador est� removendo um carro. Pois requisita
     a confirma��o extra. E nos casos de Visualiza��o de carros
     por exemplo, n�o � requisitado a confirma��o extra. */

    if(visualizacao == false){
        printf("Pressione ENTER para continuar ...");
        getchar();
        getchar();
        system("cls");                                // Talvez isso n�o funcione em todos os compiladores / sistemas operacionais
    }
    else{
        system("cls");
    }

}



/* A fun��o "Sistema" mostra as primeiras op��es ap�s a entrada no sistema, e executa
   as op��es determinadas pelos n�meros na tela. */ // ORT

void Sistema(carro * ListaDeCarros){
    int opcao;

    do{
        printf("Sistema de Venda de Carros\n\n");
        printf("[1] - Usu�rio\n");
        printf("[2] - Administrador\n");
        printf("[3] - Sair\n\n");
        printf("Op��o -> ");
        scanf("%i",&opcao);

        LimpaTela(false);

        switch(opcao){
            case 1: Usuario(ListaDeCarros);
            break;

            case 2: Administrador(ListaDeCarros);
            break;

            case 3: Entrada(ListaDeCarros);
            break;

            default: printf("\nOp��o Inv�lida !! \n"); LimpaTela(false);
        }

    }while(opcao != 3);
}



/* A fun��o "Exibe" mostra a tabela dos carros Dispon�veis. A partir de valores alimentados na fun��o
   � poss�vel determinar se a exibi��o � de um usu�rio ou de um administrador, com isso, � poss�vel configur�-la
   de formas diferentes. Al�m disso, com as vari�veis .vendido e .novo, � poss�vel afirmar se o carro
   � novo ou vendido, sendo que "vendido" sobrep�e "novo". */ // ORT

void Exibe(carro * Disponiveis, bool Usuario, float dinheiro){

    if(Usuario == true)
        printf("Dinheiro -> R$ %0.2f\n\n", dinheiro);

    printf("       Marca       |         Modelo       |  Ano  | Pre�o \n\n");

    int i;
    for(i = 0; i < 20; i++){

        if(Disponiveis[i].ano == 0)
            break;

        if(i >= 9){
            printf("[%i] - ",i + 1);
            printf(" %-11s| ", Disponiveis[i].marca);
            printf(" %-20s| ", Disponiveis[i].modelo);
            printf(" %-4i | ", Disponiveis[i].ano);
            printf("R$ %-6.02f ", Disponiveis[i].preco);
        }
        else{
            printf(" [%i] - ",i + 1);
            printf(" %-11s| ", Disponiveis[i].marca);
            printf(" %-20s| ", Disponiveis[i].modelo);
            printf(" %-4i | ", Disponiveis[i].ano);
            printf("R$ %-6.02f ", Disponiveis[i].preco);
        }


        if(Disponiveis[i].vendido == true)
            printf("%12s","(Vendido)");
        else if(Disponiveis[i].novo == true)
            printf("%12s", "(Novo)");

        printf("\n");


    }

    printf("\n\n");

}



