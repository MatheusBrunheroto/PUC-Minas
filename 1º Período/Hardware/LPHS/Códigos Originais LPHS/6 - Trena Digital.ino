// Vídeo Disponível Em : https://youtu.be/6ek_RHoklys

int trigger = 8;
int echo = 9;

void setup(){

  pinMode(trigger, OUTPUT);  
  pinMode(echo, INPUT); 
  Serial.begin(9600);

}
void loop() {

    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);

    Serial.print("Distance: ");
    Serial.print(pulseIn(echo,HIGH)/58);
    Serial.print("\n");
    delay(1000);

}
