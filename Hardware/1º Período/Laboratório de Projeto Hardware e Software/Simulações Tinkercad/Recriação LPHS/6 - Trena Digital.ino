// Simulação Disponível Em : https://www.tinkercad.com/things/c8LUgdXpHFv-sensor-ultrassonico

/* Obviamente o HC-SR04 não funciona aqui pois o espaço é 2D
   e ilimitado, para testar, basta copiar a minha simulação e colocar
   algum objeto na frente do sensor. */

int trigger = 8;
int echo = 9;

void setup(){

  pinMode(trigger, OUTPUT);  
  pinMode(echo, INPUT); 
  Serial.begin(9600);

}

void loop() {

    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger,LOW);

    Serial.print("Distance: ");
    Serial.print(pulseIn(echo,HIGH)/58);
    Serial.print("\n");
    delay(1000);

}
