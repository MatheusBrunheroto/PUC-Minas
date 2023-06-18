#include "struct.h"
#include "sistema.h"

#include <stdio.h>
#include <string.h>
#include <graphics.h>

#include "exibicao.h"


/* A função "FotosCarro" guarda as fotos dos carros pré-alocados e dos carros de
   demonstração, que são carros com fotos pré-definidas inseridos dentro da opção
   administrador para demonstrar sua funcionalidade.
   A função "VisualizarUsuario" só chama "FotosCarro" se a opção for menor ou igual ao tamanho
   da lista, portanto, quando essa função é acionada, terá a foto de um carro válido, ou inválido. */

void FotosCarros(carro * Disponiveis, int opcao){

    getchar();

    /* Não importa as informações de preço, vendido e novo. A comparação é somente
       entre marca, modelo e ano. que devem ser escritos corretamente pelo administrador */

    carro CarrosDemonstracao[20] = {

        // Carros Pré-definidos
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

        // Carros de Demonstração
        {"Fiat", "Punto", 2014, 0, false, false},
        {"Fiat", "Palio", 2013, 0, false, false},
        {"Chevrolet", "Onix", 2020, 0, false, false},
        {"Chevrolet", "Spin", 2013, 0, false, false},
        {"Ford", "Eco Sport", 2016, 0, false, false},
        {"Ford", "Focus", 2014, 0, false, false},
        {"Volkswagen", "Polo", 2018, 0, false, false},
        {"Volkswagen", "Golf", 2016, 0, false, false},
        {"Honda", "City", 2013, 0, false, false},
        {"Honda", "Fit", 2010, 0, false, false},

    };


    int tamanho = Tamanho(CarrosDemonstracao);
    bool carro_valido = false;
    char modelo[22];

    int i;
    for(i = 0; i < tamanho; i++){

        if(strcmp(CarrosDemonstracao[i].marca, Disponiveis[opcao - 1].marca) == 0){
            if(strcmp(CarrosDemonstracao[i].modelo, Disponiveis[opcao - 1].modelo) == 0){
                if(CarrosDemonstracao[i].ano == Disponiveis[opcao - 1].ano){

                    sprintf(modelo, "Veiculo %s.jpg", Disponiveis[opcao - 1].modelo);
                    carro_valido = true;
                    break;

                }
            }
        }
    }

    if(carro_valido == false)
        strcpy(modelo, "Invalido.jpg");

    initwindow(800, 600, Disponiveis[opcao - 1].modelo, (getmaxwidth()-800)/2, (getmaxheight()-600)/2);
    readimagefile(modelo, 0, 0, 800, 600);


    do{
    }while(getchar() != '\n' && !kbhit());

    closegraph();

}
