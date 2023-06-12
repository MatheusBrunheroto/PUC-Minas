#include "entrada.h" // Para voltar para a entrada se o usuario desejar
#include "struct.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "sistema.h"

#include "usuario.h"
#include "administrador.h"

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


void LimpaTela(){
    printf("Pressione ENTER para continuar ...");
    getchar();
    getchar();
    system("cls");                                // Talvez isso não funcione em todos os compiladores / sistemas operacionais
}

void Sistema(carro * ListaDeCarros){
    int opcao;

    do{
        printf("Sistema de Venda de Carros\n\n");
        printf("[1] - Usuário\n");
        printf("[2] - Administrador\n");
        printf("[3] - Sair\n\n");
        printf("Opção -> ");
        scanf("%i",&opcao);

        LimpaTela();

        switch(opcao){
            case 1: Usuario(ListaDeCarros);
            break;

            case 2: Administrador(ListaDeCarros);
            break;

            case 3: Entrada(ListaDeCarros);
            break;

            default: printf("\nOpção Inválida !! \n"); LimpaTela();
        }

    }while(opcao != 3);
}

void Exibe(carro * Disponiveis, bool Usuario, float dinheiro){

    carro AUX;
    int tamanho = Tamanho(Disponiveis);
    int i, j;

    // Organizando em Ordem Alfabética, utilizei o princípio do 'Bubble Sort' pois nesse caso são poucos valores

    for (i = 0; i < tamanho; i++) {
        for (j = 0; j < tamanho - 1; j++) {

            if (strcmp(Disponiveis[j].marca, Disponiveis[j + 1].marca) > 0) {        //   (z) > (a), portanto é necessário subir Palavra2, e descer Palavra1

                AUX = Disponiveis[j];
                Disponiveis[j] = Disponiveis[j + 1];
                Disponiveis[j + 1] = AUX;

            }
            else if (strcmp(Disponiveis[j].marca, Disponiveis[j + 1].marca) == 0) {  //   (z) == (a), portanto é necessário avaliar o modelo

                if(strcmp(Disponiveis[j].modelo, Disponiveis[j + 1].modelo) > 0){

                    AUX = Disponiveis[j];
                    Disponiveis[j] = Disponiveis[j + 1];
                    Disponiveis[j + 1] = AUX;

                }
            }

        }
    }

    LimpaTela();

    if(Usuario == true)
        printf("Dinheiro -> R$ %0.2f\n\n", dinheiro);

    printf("       Marca       |         Modelo       |  Ano  | Preço \n\n");

    for(i = 0; i < 20; i++){

        if(Disponiveis[i].ano == 0)                    // Não imprimir Carros não registrados acima do valor 10
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
            printf("%10s","(Vendido)");
        else if(Disponiveis[i].novo == true)
            printf("%10s", "(Novo)");

        printf("\n");


    }

    printf("\n\n");

}



