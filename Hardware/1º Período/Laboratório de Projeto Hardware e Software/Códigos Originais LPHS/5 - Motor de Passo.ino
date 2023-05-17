// Vídeo Disponível Em : https://youtu.be/LnC5BlVDyKw

#include <Stepper.h>

int stepsPerRevolution = 500;

int led_verde = 2;
int led_vermelho = 3;

int botao_verde = 5;
int botao_vermelho = 6;

Stepper myStepper(stepsPerRevolution, 8,10,9,11);
void setup() {

  myStepper.setSpeed(50);

  pinMode(led_verde, OUTPUT);
  pinMode(led_vermelho, OUTPUT);

  pinMode(botao_verde, INPUT);
  pinMode(botao_vermelho, INPUT);

}

void loop() {
  
  if(digitalRead(botao_vermelho) == 1){

    digitalWrite(led_vermelho,HIGH);
    myStepper.step(-1024); // Horário

  }
  else if(digitalRead(botao_verde) == 1){

    digitalWrite(led_verde,HIGH);
    myStepper.step(1024); // Anti-Horário

  }
  else{

   }
   digitalWrite(led_verde,LOW);
   digitalWrite(led_vermelho,LOW); 
}