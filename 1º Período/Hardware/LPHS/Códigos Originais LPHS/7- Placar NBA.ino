// Vídeo Disponível Em : https://youtu.be/S6aQ6ltVjrw

int time1_2 = 8, time1_3 = 9;
int time2_2 = 10, time2_3 = 11;

int PlacarTime1 = 0, PlacarTime2 = 0;

int buzzer = 7;

void setup(){

  pinMode(time1_2,INPUT);
  pinMode(time1_3,INPUT);
  pinMode(time2_2,INPUT);
  pinMode(time2_3,INPUT);
  pinMode(buzzer,OUTPUT);

  Serial.begin(9600);
  Serial.print("\nPlacar -> Time 1  |  Time 2");
}

void imprimeplacar(int ponto){
  if(ponto < 10){
    Serial.print("\n           ");
    Serial.print(PlacarTime1);
    Serial.print("      |      ");
    Serial.print(PlacarTime2);
  }
  else if(ponto < 100){
    Serial.print("\n           ");
    Serial.print(PlacarTime1);
    Serial.print("     |      ");
    Serial.print(PlacarTime2);  
  }
  else{
    Serial.print("\n           ");
    Serial.print(PlacarTime1);
    Serial.print("    |      ");
    Serial.print(PlacarTime2);  
  }
} 

void loop() {

  if(digitalRead(time1_2) == 1){
    PlacarTime1 += 2;
    imprimeplacar(PlacarTime1);
    delay(1000);
  }
  else if(digitalRead(time1_3) == 1){
    PlacarTime1 += 3;
    tone(buzzer,440,1500);
    imprimeplacar(PlacarTime1);
    delay(1000);
  }
  else if(digitalRead(time2_2) == 1){
    PlacarTime2 += 2;
    imprimeplacar(PlacarTime1);
    delay(1000);
  }
  else if(digitalRead(time2_3) == 1){
    PlacarTime2 += 3;
    tone(buzzer,660,1500);
    imprimeplacar(PlacarTime1);
    delay(1000);
  } else {}

}
