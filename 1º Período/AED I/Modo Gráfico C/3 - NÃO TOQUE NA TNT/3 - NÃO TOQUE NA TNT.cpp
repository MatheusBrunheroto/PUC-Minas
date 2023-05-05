#include <graphics.h>
#include <stdio.h>
#include <time.h>

 main(){

    srand(time(NULL));

    initwindow(498,498,"NÃO TOQUE NA TNT",0,0);
    int i = 0;
    char gif[49][30];
    for(int i = 0; i <= 48; i++){
        sprintf(gif[i], "frame_%02d_delay-0.05s.gif", i);
    }

    // Loop que da o efeito do GIF enquanto o mouse não atravessar a área
    do{

        readimagefile(gif[i], 0, 0, 498, 498);
        i++;
        if(i > 49){
            i = 0;
        } else {}

    }while(!((mousex() >= 97 && mousex() <= 397) && (mousey() >= 87 && ((mousey()<=397) || mousey()<=402)))); // Definição de "área"
    closegraph();

    initwindow(734,538,"BOOOOOOOOOOM!",0,0);
     readimagefile("nuke.jpg", 0, 0, 734, 538);
    do{

        if(rand() % 55 == 0){
            putpixel(rand() % 734, rand() % 538, 12);
        }
        else{
            putpixel(rand() % 734, rand() % 538, 4);
        }

    }while(!kbhit());

}
