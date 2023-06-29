#include "struct.h"
#include "sistema.h"

#include <stdio.h>

#include "administrador.h"


/* A função "Administrador" mostra as primeiras opções após a entrada como administrador,
   caso a senha seja escrita corretamente, e executa as opções determinadas pelos números na tela. */

void Administrador(carro * CarroADM){

    int tamanho = Tamanho(CarroADM);
    int opcao, i = 0;                                  // A variável 'opcao' será inicialmente utilizada para inserir a senha, que será reciclada logo após.

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
        printf("Opção -> ");
        scanf("%i", &opcao);

        switch(opcao){

            case 1: RegistrarCarroADM(CarroADM);
            break;

            case 2: RemoverCarroADM(CarroADM);
            break;

            case 3: LimpaTela(false); Sistema(CarroADM);
            break;

            default:  printf("\nOpção Inválida !! \n"); LimpaTela(false);
        }

    }while(opcao != 3);
}



/* A função "RegistrarCarroADM" requisita do administrador informações sobre o carro que está sendo inserido.
   O carro inserido está ocupando a posição 'tamanho', que é um valor retornado da função 'Tamanho'. Essa função
   retorna o tamanho literal da lista de carros e não seus "endereços" em memória estática, portanto é usada
   dentro do [] do vetor como um "novo endereço", que, na verdade, é o tamanho da lista de carros. E isso só
   é possível pois, o vetor NovoADM, na verdade, é o endereço da lista de carros. */

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

    printf("Preço -> ");
    scanf("%f", &NovoADM[tamanho].preco);

    LimpaTela(false);

    NovoADM[tamanho].novo = true;
    NovoADM[tamanho].vendido = false;

}



 /* A função "RemoverCarroADM" exibe os carros disponíveis, e depende diretamente da função
   "LoopOpcoes", que retorna 0, causando a saída da função "RemoverCarroADM",
   ou retorna o valor da opção selecionada, se for maior que o tamanho de ListaDeCarros, o carro não existe.
   Caso o carro exista ele será removido. */

void RemoverCarroADM(carro * RemovidoADM){

    int tamanho;
    int opcao, i;

    opcao = LoopOpcoes(RemovidoADM, 0, false);

    while(opcao != 0){

        tamanho = Tamanho(RemovidoADM);

        if(opcao <= tamanho){

            for(i = opcao; i <= tamanho; i++){       // Sobrepõe todos os carros de cima para baixo a partir do selecionado
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
