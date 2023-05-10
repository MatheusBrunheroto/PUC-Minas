#include <graphics.h>
#include <stdio.h>

// Imprime a Paleta de Cores e Formatos
void cores (int janela, int seta){
    setcurrentwindow(janela);

    // Tampa o fundo anterior, para não acumular setas
    readimagefile("FundoPreto.jpg", 0, 0, 1025, 500);

    // - CORES :
    for(int color = 0, coordx = 60; color < 16; color++){ // BGI COLORS 0 - 15
        setfillstyle(1,color);
        fillellipse (coordx, 100, 25, 25);
        coordx += 60;
    }

    // Não ajusta o tamanho da imagem caso esteja na primeira casa
    if(seta == 49){
        readimagefile("SetaPreta.jpg", seta, 49, 30, 30);
    }
    else{
        /* Não entendo o por que disso acontecer, a cada incremento, seta aumenta 60
        e é necessário reduzir 20 de seta para manter a proporção, o mesmo ocorre no decremento. */

        readimagefile("SetaPreta.jpg", seta, 49, seta - 20 , 30);
    }

}

 main(){

    const int esquerda = 75, cima = 72, direita = 77 , baixo = 80;
    int seta = 49;

    int cor = 0, tamanho = 5;
    int tecla_0, tecla = esquerda /* Valor Inicial */, x, y;

    printf("Pressione as setas para cima ou baixo para selecionar entre cores e formatos.\n");
    printf("Pressione as setas para a esquerda ou direita para alternar entre os possíveis valores da opção selecionada\n");
    printf("(Qualquer tecla que não seja as setas irão fechar o programa!)\n");
    printf("\nPressione ENTER para continuar ...");
    getchar();

    int w1 = initwindow(1025,230,"Paleta de Cores e Formatos", 0 , 590);
    int w2 = initwindow(600,600,"Quadro");

    cores(w1, seta);

    while(tecla == esquerda || tecla == cima || tecla == direita || tecla == baixo){

        setcurrentwindow(w2);

        // CORES :
        if(kbhit()){

            tecla_0 = getch();
            if(tecla_0 != 0){
                break;
            } else {}
            tecla = getch();

            // Mover a seta para a ESQUERDA e mudar as cores
            if(tecla == esquerda){

                seta -= 60;
                cor--;
                if(seta < 49){  // "Ciclo"
                    seta = 49 + (60 * 15); // Esse resultado implica no "cor = 15"
                    cor = 15;
                } else {}
                cores(w1, seta);

            }

            // Mover a seta para a DIREITA e mudar as cores
            else if(tecla == direita){

                seta += 60;
                cor++;
                if(seta > 49 + (60 * 15)){  // "Ciclo"
                    seta = 49; // Esse resultado implica no "cor = 0"
                    cor = 0;
                } else {}
                cores(w1, seta);

            }

            // Aumenta o tamanho do formato
            else if(tecla == cima){
                if(tamanho >= 5 && tamanho <= 100){
                    tamanho++;
                }
                else if(tamanho < 5){
                    tamanho = 5;
                }
                else{
                    tamanho = 100;
                }
            }

            // Diminui o tamanho do formato
            else if(tecla == baixo){
                if(tamanho >= 5 && tamanho <= 100){
                    tamanho--;
                }
                else if(tamanho < 5){
                    tamanho = 5;
                }
                else{
                    tamanho = 100;
                }
            }

            else{
                break;
            }

        }

        // FORMATOS :
        else{

            // Para não poluir o código
            x = mousex();
            y = mousey();
            setfillstyle(1,cor);

            // Circulo
            if(ismouseclick(WM_LBUTTONDOWN)){
               // setfillstyle(1,cor);
                fillellipse(x, y , tamanho / 2, tamanho / 2);
                clearmouseclick(WM_LBUTTONDOWN);
            }

            // Quadrado
            else if(ismouseclick(WM_RBUTTONDOWN)){
              //  setfillstyle(1,cor);
                bar(x,y , x+tamanho, y+tamanho);
                rectangle(x-1, y-1 , x+tamanho, y+tamanho);
                clearmouseclick(WM_RBUTTONDOWN);
            } else {}
        }

    }

}
