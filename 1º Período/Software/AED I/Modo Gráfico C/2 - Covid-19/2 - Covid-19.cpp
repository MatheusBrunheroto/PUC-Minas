#include <graphics.h>
#include <time.h>

/* Esse programa abre novas janelas diversas vezes, não deixe ele rodando enquanto
   estiver fora do computador, não se assuste pois ao fechar uma janela todas serão fechadas. */

void covid(){

    srand(time(NULL));

    int i = 0;
    int x1 = rand() % 600, y1 = rand() % 600;
    int x2 = rand() % 600, y2 = rand() % 600;
    int x3 = rand() % 600, y3 = rand() % 600;

    int wid1 = initwindow(x1, y1, "Covid-19",rand() % getmaxwidth(), rand() % getmaxheight());
    int wid2 = initwindow(x2, y2, "Covid-19",rand() % getmaxwidth(), rand() % getmaxheight());
    int wid3 = initwindow(x3, y3, "Covid-19",rand() % getmaxwidth(), rand() % getmaxheight());

    do{

        if(i % 2 == 0){
            setcurrentwindow(wid1);
            putpixel(rand() % x1, rand() % y1 ,2);
            putpixel(rand() % x1, rand() % y1, 10);
        }
        else if(i % 3 == 0){
            setcurrentwindow(wid2);
            putpixel(rand() % x2, rand() % y2 ,2);
            putpixel(rand() % x2, rand() % y2, 10);
        }
        else{
            setcurrentwindow(wid3);
            putpixel(rand() % x3, rand() % y3 ,2);
            putpixel(rand() % x3, rand() % y3, 10);
        }

        if(i > 50000){
                covid(); // Função recursiva sem condição de parada
        } else {}

        i++;

    }while(!kbhit());

    closegraph();
}

 main(){
    covid();
}
