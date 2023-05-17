#include <graphics.h>
#include <stdio.h>

 main(){

    initwindow(400,300);
    do{
        printf("X : %i   ",mousex());
        printf("Y : %i\n",mousey());
        delay(500);
    }while(!kbhit());
    closegraph();

}
