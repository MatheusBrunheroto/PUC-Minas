#include "struct.h"
#include "sistema.h" // Para redirecionar para SISTEMA

#include <stdio.h>
#include <stdbool.h>
#include <graphics.h>

#include "entrada.h"

void DesenhaBotao(int x1, int y1, int x2, int y2, char rotulo[30], bool inverte){

    int cor1 = 15;
    int cor2 = 8;

    if(inverte == true){
        int aux = cor1;
        cor1 = cor2;
        cor2 = aux;
    }

    bar(x1,y1,x2,y2);
    setlinestyle(0,0,2);


    setcolor(cor1);
    line(x1,y1,x2,y1);
    line(x1,y1,x1,y2);

    setcolor(cor2);
    line(x2,y1+2,x2,y2);
    line(x1+2,y2,x2,y2);

    setbkcolor(15);
    setcolor(0);
    outtextxy(x1 + ((x2-x1-(strlen(rotulo)*8))/2) + 2, y1+8, "rotulo");


}

int Entrada(carro * ListaDeCarros){
    bool entrada = false;

        initwindow(800,600,"Sistema",(getmaxwidth()-800)/2, (getmaxheight()-600)/2);        // Encontrar o centro da tela

    // Animação
    char gif[22];
    int i;
    for(i = 0; i <= 56; i++){

        sprintf(gif, "Venda_de_Carros-%d.gif", i); // Armazena em 'gif', 56 valores que contém 17 letras

    /* (160, 0) Coordenadas e tamanhos ajustados. X = 160 pois a animação tem 480 pixels de largura,
        e a janela 800. A coordenada central da janela é 400, e para encaixar o meio da animação no
        meio da janela, basta subtrair 400 pela metade de 480, que é 240. */

        readimagefile(gif, 160, 0, 480 + 160, 146);
        delay(50);

    }

    outtextxy(600,570,"© 2023 Matheus Brunheroto");                                     // (600,570) - Coordenadas para caber no canto inferior direito

    /*  Para criar uma barra que começe em 1/4 da animação e termine em 3/4 :
        A = (280, y1) x1 = 280 pois é necessário somar 120 à coordenada onde a animação se inicia, no caso 160.
        B = (520, y2) x2 = 520 pois é a ultima coordenada da animação, 480 + 160, subtraido por 1/4 da animação ou seja, por 120.
        y1 e y2 variam conforme a necessidade. */

       DesenhaBotao(280,240,520,280,"Entrar",false);
       DesenhaBotao(280,310,520,350,"Sair",false);


    do{

        if (ismouseclick(WM_LBUTTONDOWN)){
            if(mousex() >= 280 && mousex() <= 520){          // (x1 - x2)

                if(mousey() >= 240 && mousey() <= 280)  {     // Entrar
                    entrada = true;
                    DesenhaBotao(280,240,520,280,"Entrar",true);
                    delay(500);
                    DesenhaBotao(280,240,520,280,"Entrar",false);
                }
                else if(mousey() >= 310 && mousey() <= 350){  // Sair

                    printf("Volte Sempre ! \n");
                    DesenhaBotao(280,310,520,350,"Sair",true);
                    delay(500);
                    DesenhaBotao(280,310,520,350,"Sair",false);

                    return 0;
                }
            }

            clearmouseclick(WM_LBUTTONDOWN);
        }

    }while(entrada != true);
    closegraph();


    Sistema(ListaDeCarros);

}





