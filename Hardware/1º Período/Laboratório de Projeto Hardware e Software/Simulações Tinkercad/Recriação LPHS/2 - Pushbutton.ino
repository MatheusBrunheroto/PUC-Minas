// Simulação Disponível Em : https://www.tinkercad.com/things/1pDYpISGDlk-botao-ledbuiltin

int Button = 7;
void setup(){
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(Button, INPUT);
}

void loop(){
  if(digitalRead(Button) == LOW){
    digitalWrite(LED_BUILTIN,LOW);
  }else{
    digitalWrite(LED_BUILTIN,HIGH);
  }
}
    