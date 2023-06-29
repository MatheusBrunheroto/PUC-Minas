#include "struct.h"
#include "sistema.h"

#include <stdio.h>

#include "administrador.h"


/* A fun��o "Administrador" mostra as primeiras op��es ap�s a entrada como administrador,
   caso a senha seja escrita corretamente, e executa as op��es determinadas pelos n�meros na tela. */

void Administrador(carro * CarroADM){

    int tamanho = Tamanho(CarroADM);
    int opcao, i = 0;                                  // A vari�vel 'opcao' ser� inicialmente utilizada para inserir a senha, que ser� reciclada logo ap�s.

    printf("Senha : ");
    if(scanf("%i", &opcao) != 1234)

        while(opcao != 1234){

            i++;
            if(i == 3){
                LimpaTela(false);
                Sistema(CarroADM);
            }

            LimpaTela(false);
            printf("Senha Incorreta !!\n");
            printf("Senha : ");
            scanf("%i", &opcao);

        }

    LimpaTela(false);


    do{

        printf("[1] - Registrar Carro\n");
        printf("[2] - Remover Carro\n");
        printf("[3] - Voltar\n\n");
        printf("Op��o -> ");
        scanf("%i", &opcao);

        switch(opcao){

            case 1: RegistrarCarroADM(CarroADM);
            break;

            case 2: RemoverCarroADM(CarroADM);
            break;

            case 3: LimpaTela(false); Sistema(CarroADM);
            break;

            default:  printf("\nOp��o Inv�lida !! \n"); LimpaTela(false);
        }

    }while(opcao != 3);
}



/* A fun��o "RegistrarCarroADM" requisita do administrador informa��es sobre o carro que est� sendo inserido.
   O carro inserido est� ocupando a posi��o 'tamanho', que � um valor retornado da fun��o 'Tamanho'. Essa fun��o
   retorna o tamanho literal da lista de carros e n�o seus "endere�os" em mem�ria est�tica, portanto � usada
   dentro do [] do vetor como um "novo endere�o", que, na verdade, � o tamanho da lista de carros. E isso s�
   � poss�vel pois, o vetor NovoADM, na verdade, � o endere�o da lista de carros. */

void RegistrarCarroADM(carro * NovoADM){

    int tamanho = Tamanho(NovoADM);

    char marca[11], modelo[20];
    int ano;
    float preco;


    LimpaTela(false);

    printf("Marca -> ");
    gets(NovoADM[tamanho].marca);

    printf("Modelo -> ");
    gets(NovoADM[tamanho].modelo);

    printf("Ano -> ");
    scanf("%i", &NovoADM[tamanho].ano);

    printf("Pre�o -> ");
    scanf("%f", &NovoADM[tamanho].preco);

    LimpaTela(false);

    NovoADM[tamanho].novo = true;
    NovoADM[tamanho].vendido = false;

}



 /* A fun��o "RemoverCarroADM" exibe os carros dispon�veis, e depende diretamente da fun��o
   "LoopOpcoes", que retorna 0, causando a sa�da da fun��o "RemoverCarroADM",
   ou retorna o valor da op��o selecionada, se for maior que o tamanho de ListaDeCarros, o carro n�o existe.
   Caso o carro exista ele ser� removido. */

void RemoverCarroADM(carro * RemovidoADM){

    int tamanho;
    int opcao, i;

    opcao = LoopOpcoes(RemovidoADM, 0, false);

    while(opcao != 0){

        tamanho = Tamanho(RemovidoADM);

        if(opcao <= tamanho){

            for(i = opcao; i <= tamanho; i++){       // Sobrep�e todos os carros de cima para baixo a partir do selecionado
                RemovidoADM[i - 1] = RemovidoADM[i];
            }

            RemovidoADM[tamanho - 1].ano = 0;

        }
        else
            printf("\nCarro Inexistente !!\n");

        opcao = LoopOpcoes(RemovidoADM, 0, false);

    }
    LimpaTela(false);
}
