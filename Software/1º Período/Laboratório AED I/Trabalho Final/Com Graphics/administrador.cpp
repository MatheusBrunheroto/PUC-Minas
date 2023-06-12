#include "struct.h"
#include "sistema.h"

#include <stdio.h>

#include "administrador.h"


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




