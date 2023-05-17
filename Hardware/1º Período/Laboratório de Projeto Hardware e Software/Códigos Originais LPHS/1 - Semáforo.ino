// Vídeo Disponível Em : https://youtu.be/KoGwIgPdZPA

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  digitalWrite(8, HIGH);
  delay(4500); 
  digitalWrite(8, LOW);
  
  digitalWrite(5, HIGH);
  delay(3000); 
  digitalWrite(5, LOW);
  
  
  digitalWrite(2, HIGH);
  delay(7500);
  digitalWrite(2, LOW);
}
