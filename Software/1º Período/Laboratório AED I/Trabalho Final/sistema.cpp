#include "struct.h"
#include "entrada.h"
#include "administrador.h"
#include "usuario.h"
#include "exibicao.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "sistema.h"


/* A função "Tamanho" recebe o vetor ListadeCarros, e através dele verifica
   os carros de (0 - 20). Eu defini como padrão de carro inexistente
   o ano = 0. Então todo carro cujo ano = 0 é invalido e o
   comando 'break' é executado. */

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



/* A função "LimpaTela", utiliza do comando system("cls"), que não necessariamente funcionará
   em todos os sistemas operacionais ou compiladores, outra alternativa caso não funcione é
   o comando system("clear"). */

void LimpaTela(bool visualizacao){

    /* Visualizacao = false significa que o usuário está comprando um carro,
       ou um administrador está removendo um carro. Pois requisita
       a confirmação extra. E nos casos de Visualização de carros
       por exemplo, não é requisitado a confirmação extra. */

    if(visualizacao == false){
        printf("Pressione ENTER para continuar ...");
        getchar();
        getchar();
        system("cls");
    }
    else{
        system("cls");
    }

}



/* A função "Sistema" mostra as primeiras opções após a entrada no sistema, e executa
   as opções determinadas pelos números na tela. */

void Sistema(carro * ListaDeCarros){
    int opcao;

    do{
        printf("Sistema de Venda de Carros\n\n");
        printf("[1] - Usuário\n");
        printf("[2] - Administrador\n");
        printf("[3] - Sair\n\n");
        printf("Opção -> ");
        scanf("%i", &opcao);

        LimpaTela(false);

        switch(opcao){
            case 1: Usuario(ListaDeCarros);
            break;

            case 2: Administrador(ListaDeCarros);
            break;

            case 3: Entrada(ListaDeCarros);
            break;

            default: printf("\nOpção Inválida !! \n"); LimpaTela(false);
        }

    }while(opcao != 3);
}



/* A função "Exibe" mostra a tabela dos carros Disponíveis. A partir de valores alimentados na função
   é possível determinar se a exibição é de um usuário ou de um administrador, com isso, é possível configurá-la
   de formas diferentes. Além disso, com as variáveis  .vendido e  .novo, é possível afirmar se o carro
   é novo ou vendido, sendo que 'vendido' sobrepõe 'novo'.
   Anteriormente a função "LimpaTela" estava implementada dentro de "Exibe", porém foi conveniente tirá-la devido as diferentes formas
   de limpar a tela que determinei, então a cada chamada de "Exibe" é necessário chamar "LimpaTela" antes. */

void Exibe(carro * Disponiveis, bool Usuario, float dinheiro){

    if(Usuario == true)
        printf("Dinheiro -> R$ %0.2f\n\n", dinheiro);

    printf("       Marca       |         Modelo       |  Ano  | Preço \n\n");

    int i;
    for(i = 0; i < 20; i++){

        if(Disponiveis[i].ano == 0)
            break;

        if(i >= 9){
            printf("[%i] - ", i + 1);
            printf(" %-11s| ", Disponiveis[i].marca);
            printf(" %-20s| ", Disponiveis[i].modelo);
            printf(" %-4i | ", Disponiveis[i].ano);
            printf("R$ %-6.02f ", Disponiveis[i].preco);
        }
        else{
            printf(" [%i] - ", i + 1);
            printf(" %-11s| ", Disponiveis[i].marca);
            printf(" %-20s| ", Disponiveis[i].modelo);
            printf(" %-4i | ", Disponiveis[i].ano);
            printf("R$ %-6.02f ", Disponiveis[i].preco);
        }


        if(Disponiveis[i].vendido == true)
            printf("%13s", "(Vendido)");
        else if(Disponiveis[i].novo == true)
            printf("%13s", "(Novo)");

        printf("\n");


    }

    printf("\n\n");

}



/* A função "LoopOpcoes" serve para intermediar os processos de execução entre "Exibe" e a função
   que a chamou, atuando como o seletor de opções.
   Ela lê uma string de 2 caracteres, pois caso contrário não seria possível ler um eventual
   número 10. Se a string lida for == "s" ou "S", a função retorna 0, caso contrário, retorna a
   opção em inteiro para que as funções que chamaram "LoopOpcoes" executem o que foram designadas
   a fazer. */

int LoopOpcoes(carro * Disponiveis, bool Usuario, float dinheiro, bool visualizacao){

    char opcaoCHAR[3];
    int  opcaoINT;

    while(strcmp(opcaoCHAR,"s") != 0){

        LimpaTela(visualizacao);
        Exibe(Disponiveis, Usuario, dinheiro);  // Buscar um nome melhor para usuario e visualizacao nessa funcao e em exibe
        printf("[S] - Sair \n\n\n",4);

        printf("Opção -> ");
        scanf("%s", opcaoCHAR);
        opcaoCHAR[0] = tolower(opcaoCHAR[0]);

        if(strcmp(opcaoCHAR,"s") != 0){
            opcaoINT = atoi(opcaoCHAR);
            return opcaoINT;
        }
        else
            break;

    }

    return 0;

}

