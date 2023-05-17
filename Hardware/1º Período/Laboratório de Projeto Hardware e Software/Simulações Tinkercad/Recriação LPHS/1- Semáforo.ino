// Simulação Disponível Em: https://www.tinkercad.com/things/ewy2KyRXeLg-semaforo

int VERMELHO = 2;
int AMARELO = 5;
int VERDE = 8;

void setup()
{
  pinMode(VERMELHO, OUTPUT);
  pinMode(AMARELO, OUTPUT);
  pinMode(VERDE, OUTPUT);
}

void loop()
{
  digitalWrite(VERMELHO, HIGH);
  delay(5000); 
  digitalWrite(VERMELHO, LOW);
  
  digitalWrite(AMARELO, HIGH);
  delay(2000); 
  digitalWrite(AMARELO, LOW);
  
  
  digitalWrite(VERDE, HIGH);
  delay(5000);
  digitalWrite(VERDE, LOW);
}