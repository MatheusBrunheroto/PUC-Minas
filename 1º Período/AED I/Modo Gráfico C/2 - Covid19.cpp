#include <graphics.h>
#include <time.h>

/* Esse programa abre novas janelas diversas vezes, não deixe ele rodando enquanto
   estiver fora do computador, não se assuste pois ao fechar uma janela todas serão fechadas. */

void covid(){

    srand(time(NULL));
    int x, y;
    int i = 0;

    int wid1 = initwindow(600, 300);
    int wid2 = initwindow(300, 400);
    int wid3 = initwindow(200, 600);

    do{

        x = rand() % 600;
        y = rand() % 600;
        if(i % 2 == 0){
            putpixel(x,y,2);
            putpixel(x,y,10);
            setcurrentwindow(wid1);
        }
        else if(i % 3 == 0){
            putpixel(x,y,2);
            putpixel(x,y,10);
            setcurrentwindow(wid2);
        }
        else{
            putpixel(x,y,2);
            putpixel(x,y,10);
            setcurrentwindow(wid3);
        }

        if(i > 100000){
                covid(); // Função recursiva sem condição de parada
        } else {}

        i++;

    }while(!kbhit());
    closegraph();
}

 main(){
    covid();
}
