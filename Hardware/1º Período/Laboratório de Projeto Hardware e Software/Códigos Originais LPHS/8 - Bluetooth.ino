// Vídeo Disponível Em : https://www.youtube.com/watch?v=aiwNGhDU0tg

char RX;
int TX = 1;
int LED_VERDE = 8;
int LED_VERMELHO = 9;

void setup(){
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(RX, INPUT);
  pinMode(TX, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  if(Serial.available()){
    Serial.print("\n");
    RX = Serial.read();
    Serial.print("Arduino Recebido : (RX) : ");
    Serial.print(RX);
    Serial.print("\n");

    if(RX == 'S'){
      Serial.print("Stop");
      digitalWrite(LED_VERDE,LOW);
      digitalWrite(LED_VERMELHO,HIGH);
    }
    else{
      digitalWrite(LED_VERMELHO,LOW);
      digitalWrite(LED_VERDE,HIGH);
      if(RX == 'F'){
        Serial.print("Forward");
      }
      else if(RX == 'L'){ 
        Serial.print("Left");
      }
      else if(RX == 'B'){
        Serial.print("Backwards");
      }
      else if(RX = 'R'){
        Serial.print("Right");
      } else {}
    }
    Serial.print("\n");
  }
  // Serial.print("Arduino Enviado : (TX) : ");
  // Serial.print(TX);
  // Serial.print("\n");
  // delay(1000);
}