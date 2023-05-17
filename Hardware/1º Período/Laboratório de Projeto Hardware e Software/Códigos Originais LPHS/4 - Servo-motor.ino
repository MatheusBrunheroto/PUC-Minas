// Vídeo Disponível Em : https://youtu.be/RiPJOpUG0oo

#include <Servo.h>

Servo servo;

void setup(){
  servo.attach(9);
  pinMode(A5, INPUT);
}

void loop(){

  servo.write(map(analogRead(A5),0,1000,0,180));
  
}
    