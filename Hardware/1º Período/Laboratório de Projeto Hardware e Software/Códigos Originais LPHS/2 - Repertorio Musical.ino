// Vídeo Disponível Em : https://youtu.be/Bcm5Kmg0Mzc

int buzzer = 3;
int potenciometro = A3;
int POT;
int DO = 262;
int MI = 330;
int SOL = 392;
int SI = 494;

void setup() {
	Serial.begin(9600);
	pinMode(buzzer, OUTPUT);
	pinMode(potenciometro, INPUT);
}

void loop() {
	POT = analogRead(potenciometro);
	Serial.print(POT);

	if(POT >= 0 && POT <= 250){
  		tone(buzzer, DO, 2000);
	} 
	else if(POT > 250 && POT <= 500){
  		tone(buzzer, MI, 2000);
	}
	else if(POT > 500 && POT <= 750){
  		tone(buzzer, SOL, 2000);
	}
	else{
  		tone(buzzer, SI, 2000);
	}
}
