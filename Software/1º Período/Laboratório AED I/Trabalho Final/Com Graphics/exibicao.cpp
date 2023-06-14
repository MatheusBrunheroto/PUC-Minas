#include "struct.h"
#include "sistema.h"

#include <stdio.h>
#include <string.h>
#include <graphics.h>

#include "exibicao.h"

/* A função "FotosCarro" guarda as fotos dos carros pré-alocados e dos carros de
   demonstração, que são carros com fotos pré-definidas inseridos dentro da opção
   administrador para demonstrar sua funcionalidade. */  // ORT

void FotosCarros(carro * Disponiveis, int opcao){

    getchar();

    /* Não importa as informações de preço, vendido e novo. A comparação é somente
       entre marca, modelo e ano. que devem ser escritos corretamente pelo administrador */ // ORT

    carro CarrosDemonstracao[20] = {
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


    int tamanho = Tamanho(Disponiveis);
    char modelo[22];


    int i;
    for(i = 0; i < tamanho - 1; i++){

        if(strcmp(Disponiveis[i].marca, Disponiveis[opcao - 1].marca) == 0){
            if(strcmp(Disponiveis[i].modelo, Disponiveis[opcao - 1].modelo) == 0){
                if(Disponiveis[i].ano == Disponiveis[opcao - 1].ano){

                    initwindow(800, 600, Disponiveis[opcao - 1].modelo, (getmaxwidth()-800)/2, (getmaxheight()-600)/2);
                    sprintf(modelo, "Veiculo %s.jpg", Disponiveis[opcao - 1].modelo);
                    readimagefile(modelo, 0, 0, 800, 600);
                    break;

                }
                else
                    strcmp(modelo, "Invalido.jpg");
                    readimagefile(modelo, 0, 0, 800, 600);
            }
        }
      /*  else{

            if(Disponiveis[i].marca == CarrosDemonstracao[opcao - 1].marca){
                if(Disponiveis[i].modelo == CarrosDemonstracao[opcao - 1].modelo){
                    if(Disponiveis[i].ano == CarrosDemonstracao[opcao - 1].ano){

                        initwindow(800, 600, Disponiveis[opcao - 1].modelo, (getmaxwidth()-800)/2, (getmaxheight()-600)/2);
                        sprintf(modelo, "Veiculo %s.jpg", Disponiveis[opcao - 1].modelo);
                        readimagefile(modelo, 0, 0, 800, 600); // pegar fotos dos modelos
                        break;

                    }
                }
            }
        } */

    }

    do{
    }while(getchar() != '\n' && !kbhit());
    closegraph();

}
