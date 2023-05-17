// Simulação Disponível Em : https://www.tinkercad.com/things/7pYYSJvplKg-botao-epilepsia

int Button = 11;
int VERMELHO = 2, LARANJA = 3, AMARELO = 4, VERDE = 5, AZUL = 6;

void setup(){
  pinMode(Button, INPUT);
  
  pinMode(VERMELHO, OUTPUT);
  pinMode(LARANJA, OUTPUT);
  pinMode(AMARELO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(AZUL, OUTPUT);
}

void luzes(int LUZ){
    digitalWrite(LUZ, HIGH);
    delay(75);
    digitalWrite(LUZ, LOW);
}

void loop(){
  while(digitalRead(Button) == HIGH){ 
   luzes(VERMELHO);
   luzes(LARANJA);
   luzes(AMARELO);
   luzes(VERDE);
   luzes(AZUL);
  }
}