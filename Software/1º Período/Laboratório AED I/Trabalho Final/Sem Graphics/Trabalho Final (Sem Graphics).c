#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>


/* Projeto Final AED I Matheus Brunheroto
   Objetivo : criar um sistema de venda de carros utilizando
   laços condicionais e de repetição, estruturas de alocação estática,
   registros e funções.
   No meu projeto será possível adicionar carros para o seu sistema, como
   administrador e como usuário comprar. Isso enquanto sua execução não for interrompida,
   pois o projeto não requer armazenamento em memória secundária. Terei que
   usar o básico dos ponteiros, pois nesse caso não faz sentido trabalhar
   sem eles. */


typedef struct{
    char marca[11], modelo[20];
    int ano;
    float preco;
    bool novo, vendido;
}carro;


void Sistema(carro * ListaDeCarros);
void Exibe(carro * Disponiveis, bool Usuario, float dinheiro);
void LimpaTela();
int Tamanho(carro * Disponiveis);


void Usuario(carro * Disponiveis); // talvez inserir sistema de dinheiro pro usuario
float ComprarUsuario(carro * Disponiveis, float dinheiro);


void Administrador(carro * CarroADM);
void RegistrarCarroADM(carro * NovoADM);
void RemoverCarroADM(carro * RemovidoADM);


int main(){

    setlocale(LC_ALL, "Portuguese");

    // Há 10 carros pré-alocados, tendo espaço para mais 10 serem adicionados pelo Administrador do sistema, caso deseje mais, basta mudar o valor do vetor.
    carro ListaDeCarros[20] = {
        {"Fiat", "Uno sem Escada", 1986, 10500, false, false},
        {"Fiat", "Uno com Escada", 1986, 13500, false, false},
        {"Chevrolet", "Camaro Amarelo", 2010, 516200, false, false},
        {"Chevrolet", "Opala Preto", 1982, 32050, false, false},
        {"Ford", "Maverick", 1974, 244890, false, false},
        {"Ford", "Mustang", 2020, 566300, false, false},
        {"Volkswagen", "Fusca", 1953, 22900, false, false},
        {"Volkswagen", "Gol", 1984, 78160, false, false},
        {"Honda", "Civic SI", 2009, 60500, false, false},
        {"Honda", "Accord", 2023, 148210, false, false},
    };

    Sistema(ListaDeCarros);

    return 0;

}


// - FUNÇÕES DE EXIBIÇÃO - PRONTO

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

            case 3: exit(0);
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




