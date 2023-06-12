#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include <graphics.h>

#include "exibicao.h"

#include "struct.h"

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


// - FUNÇÕES DO MODO ADMINISTRADOR


void Administrador(carro * CarroADM){

    int tamanho = Tamanho(CarroADM);
    int opcao;                                  // A variável 'opcao' será inicialmente utilizada para inserir a senha, valor que logo após será reciclado.

    printf("Senha : ");
    if(scanf("%i", &opcao) != 0000)
        while(opcao != 0000){
            LimpaTela();
            printf("Senha Incorreta !!\n");
            printf("Senha : ");
            scanf("%i", &opcao);
        }
    LimpaTela();

    do{
        printf("[1] - Registrar Carro\n");
        printf("[2] - Remover Carro\n");
        printf("[3] - Voltar\n\n");
        printf("Opção -> ");
        scanf("%i",&opcao);

        switch(opcao){

            case 1: RegistrarCarroADM(CarroADM);
            break;

            case 2: RemoverCarroADM(CarroADM);
            break;

            case 3: LimpaTela(); Sistema(CarroADM);
            break;

            default:  printf("\nOpção Inválida !! \n"); LimpaTela();
        }

    }while(opcao != 3);
}

void RegistrarCarroADM(carro * NovoADM){

    int tamanho = Tamanho(NovoADM);

    char marca[11], modelo[20];
    int ano;
    float preco;


    LimpaTela();

    printf("Marca -> ");
    gets(NovoADM[tamanho].marca);

    printf("Modelo -> ");
    gets(NovoADM[tamanho].modelo);

    printf("Ano -> ");
    scanf("%i", &NovoADM[tamanho].ano);

    printf("Preço -> ");
    scanf("%f", &NovoADM[tamanho].preco);

    LimpaTela();

    NovoADM[tamanho].novo = true;

}

void RemoverCarroADM(carro * RemovidoADM){

    int tamanho = Tamanho(RemovidoADM);
    int i, opcao;
    bool Processo = false;

    Exibe(RemovidoADM, false, 0);
    printf("[S] - Sair \n\n\n",4);
    printf("Opção -> ");
    scanf("%i",&opcao);

    if(opcao != 83 || opcao != 115){

        for(i = opcao; i <= tamanho; i++){      // Sobrepõe todos os carros de cima para baixo a partir do selecionado
            RemovidoADM[i - 1] = RemovidoADM[i];
            Processo = true;
        }
        if(Processo == true)                    // Ao remover '20' sem a presença do mesmo, o último carro era removido
            RemovidoADM[tamanho - 1].ano = 0;

    }

    LimpaTela();
}


// - FUNÇÕES DO MODO USUÁRIO - EM ANDAMENTO


void Usuario(carro * Disponiveis){

    int opcao;
    float dinheiro;

    printf("Insira seu dinheiro -> ");
    scanf("%f",&dinheiro);
    LimpaTela();


    do{
        printf("Dinheiro -> R$ %0.2f\n\n", dinheiro);

        printf("[1] - Comprar Carros\n");
        printf("[2] - Voltar\n\n");
        printf("Opção -> ");
        scanf("%i",&opcao);

        switch(opcao){

            case 1: dinheiro = ComprarUsuario(Disponiveis, dinheiro);
            break;

            case 2: LimpaTela(); Sistema(Disponiveis);
            break;

            default:  printf("\nOpção Inválida !! \n"); LimpaTela();
        }

    }while(opcao != 2);
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











// - FUNÇÕES DE EXIBIÇÃO


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

void LimpaTela(){
    printf("Pressione ENTER para continuar ...");
    getchar();
    getchar();
    system("cls");                                // Talvez isso não funcione em todos os compiladores / sistemas operacionais
}







