// Simulação Disponível Em : https://www.tinkercad.com/things/3uHPScMbNzJ-potenciometro-buzzer-do-si

int buzzer = 7;
int potenciometro = A0;
int POT, i;

int NOTAS [] = {262,294 ,330,349,392,440,494};

void setup() {
	pinMode(buzzer, OUTPUT);
	pinMode(potenciometro, INPUT);
}

void loop() {
  
  POT = analogRead(potenciometro);
  
  /* Com esse código tento dividir as 7 notas igualmente entre
     1000 possíveis valores do potenciometro */
  
  for(int menor = 0, maior = 142, n = 0; n < 7 ;n++){

    if(POT >= menor && POT <= maior){
       i = n;
      break;
    }
    else if(maior + 142 <= 1000){
    	menor += 142;
    	maior += 142;
    }
    else{
      menor = 852;
      maior = 1000;
    }
  }

tone(buzzer, NOTAS[i], 2000);
  
}
