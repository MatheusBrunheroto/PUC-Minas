#include "struct.h"
#include "sistema.h"

#include <stdio.h>
#include <graphics.h>

#include "entrada.h"


/* A fun��o "Entrada", serve para criar o menu interativo inicial, com as op��es de entrada e sa�da.
   Atrav�s do 'sprintf' � poss�vel ler o nome das imagens + n�mero que devem estar na mesma pasta que o
   c�digo-fonte e exibi-las, gerando um efeito de anima��o. */

int Entrada(carro * ListaDeCarros){
    bool entrada = false;

    initwindow(800, 600, "Sistema", (getmaxwidth()-800)/2, (getmaxheight()-600)/2);        // Encontrar o centro da tela

    char gif[22];
    int i;
    for(i = 0; i <= 56; i++){

        sprintf(gif, "Venda_de_Carros-%d.gif", i);

        /* (160, 0) Coordenadas e tamanhos ajustados. X = 160, pois a anima��o tem 480 p�xeis de largura,
� � � �    e a janela 800. A coordenada central da janela � 400, e para encaixar o meio da anima��o no
� � � �    meio da janela, basta subtrair 400 pela metade de 480, que � 240. */

        readimagefile(gif, 160, 0, 480 + 160, 146);
        delay(10);

    }

    readimagefile("Info.jpg", 15, 565, 20 + 15, 20 + 565);
    outtextxy(600, 570, "� 2023 Matheus Brunheroto");                                     // (600,570) - Coordenadas para caber no canto inferior direito


    /*  Para criar uma barra que comece em 1/4 da anima��o e termine em 3/4 :
� � � � A = (280, y1) x1 = 280, pois � necess�rio somar 120 � coordenada onde a anima��o se inicia, no caso 160.
� � � � B = (520, y2) x2 = 520 pois � a �ltima coordenada da anima��o, 480 + 160, subtra�do por 1/4 da anima��o, ou seja, por 120.
� � � � y1 e y2 variam conforme a necessidade. */

    DesenhaBotao(280, 240, 520, 280, "Entrar", false);
    DesenhaBotao(280, 310, 520, 350, "Sair", false);


    /* O loop abaixo � iniciado apenas quando um clique ocorre, ap�s isso � verificado inicialmente as
       coordenadas no eixo x, se as coordenadas no eixo x corresponderem �s coordenadas dos bot�es de entrada e sa�da,
       � verificado o eixo y para confirmar se de fato o mouse est� em cima de um bot�o, se estiver, o prop�sito do bot�o ser� executado. */

    do{

        if (ismouseclick(WM_LBUTTONDOWN)){

            if(mousex() >= 280 && mousex() <= 520){                 // (x1 - x2)
                if(mousey() >= 240 && mousey() <= 280)  {           // Entrar (y1 - y2)

                    entrada = true;
                    DesenhaBotao(280, 240, 520, 280, "Entrar", true);           // Efeito Invers�o
                    delay(200);
                    DesenhaBotao(280, 240, 520, 280, "Entrar", false);

                }
                else if(mousey() >= 310 && mousey() <= 350){        // Sair (y1 - y2)

                    printf("\nVolte Sempre ! \n");
                    DesenhaBotao(280, 310, 520, 350, "Sair", true);             // Efeito Invers�o
                    delay(200);
                    DesenhaBotao(280, 310, 520, 350, "Sair", false);

                    exit(0);                                       // Encerra o programa

                }
            }
            else if(mousex() >= 15 && mousex() <= 35 && mousey() >= 565 && mousey() <= 585){     // Bot�o (i)

                readimagefile("Tabela.jpg", 0, 0, 800, 600);

                 do{
                }while(!kbhit());

                closegraph();
                Entrada(ListaDeCarros); // Retorna para o in�cio

            }

            clearmouseclick(WM_LBUTTONDOWN);

        }

    }while(entrada != true);
    closegraph();


    Sistema(ListaDeCarros);

}



/* A fun��o "DesenhaBotao" recebe coordenadas (x1, y1) e (x2, y1) para formar um ret�ngulo.
   Tamb�m recebe o nome que deve ser escrito dentro do ret�ngulo e se a invers�o deve ocorrer.
   A invers�o acontece quando um ret�ngulo � pressionado, invertendo as linhas que est�o em suas
   laterais, dando um efeito de profundidade. */

void DesenhaBotao(int x1, int y1, int x2, int y2, char palavra[7], bool inverte){

    int cor1 = 15;
    int cor2 = 8;

    if(inverte == true){
        int aux = cor1;
        cor1 = cor2;
        cor2 = aux;
    }

    bar(x1, y1, x2, y2);
    setlinestyle(0, 0, 2);

    setcolor(cor1);
    line(x1, y1, x2, y1);
    line(x1, y1, x1, y2);

    setcolor(cor2);
    line(x2, y1 + 2, x2, y2);
    line(x1 + 2, y2, x2, y2);

    setbkcolor(15);
    setcolor(0);

    /* O comando abaixo escreve um texto dentro do ret�ngulo gerado na posi��o 400 - 3 * (tamanho da palavra),
       pois em m�dia cada letra ocupa 6 p�xeis cada, contando com pequenos espa�os entre elas (olh�metro),
       ent�o tirando 3 vezes o tamanho � encontrado a metade do caminho. Mesma ideia usada no in�cio dessa fun��o.
       Obs : Isso muda se tiverem mais letras mai�sculas. */

    outtextxy(400 - strlen(palavra)*3, y1 + 10, palavra);
}
