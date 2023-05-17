// Simulação Disponível Em : https://www.tinkercad.com/things/gznTIcpwHi6-placar-nba-com-display
// Esse projeto é uma continuação do Placar NBA que não foi dada durante as aulas de LPHS, portanto fiz sozinho como projeto separado.

int A = 6, B = 7, C = 8, D = 9, E = 10, F = 11, G = 12;
int PlacarTime1 = 0, PlacarTime2 = 0;

int time1_2 = A1, time1_3 = A2;
int time2_2 = A4, time2_3 = A5;

int buzzer = 13;

void numeros(int numero){
  
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  digitalWrite(E,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,LOW);
  
  if(numero == 1){
    digitalWrite(B,HIGH);
    digitalWrite(C,HIGH);
  }
  else if(numero == 2){
    digitalWrite(A,HIGH);
  	digitalWrite(B,HIGH);
    digitalWrite(D,HIGH);
    digitalWrite(E,HIGH);
    digitalWrite(G,HIGH);
  }
  else if(numero == 3){
    digitalWrite(A,HIGH);
  	digitalWrite(B,HIGH);
    digitalWrite(C,HIGH);
    digitalWrite(D,HIGH);
    digitalWrite(G,HIGH);
  }
  else if(numero == 4){
  	digitalWrite(B,HIGH);
	digitalWrite(C,HIGH);
    digitalWrite(F,HIGH);
    digitalWrite(G,HIGH);
  }
  else if(numero == 5){
  	digitalWrite(A,HIGH);
	digitalWrite(C,HIGH);
    digitalWrite(D,HIGH);
    digitalWrite(F,HIGH);
	digitalWrite(G,HIGH);
  }
  else if(numero == 6){
  	digitalWrite(A,HIGH);
	digitalWrite(C,HIGH);
    digitalWrite(D,HIGH);
    digitalWrite(E,HIGH);
    digitalWrite(F,HIGH);
	digitalWrite(G,HIGH);
  }
  else if(numero == 7){
  	digitalWrite(A,HIGH);
	digitalWrite(B,HIGH);
    digitalWrite(C,HIGH);
  }
  else if(numero == 8){
  	digitalWrite(A,HIGH);
	digitalWrite(B,HIGH);
    digitalWrite(C,HIGH);
    digitalWrite(D,HIGH);
    digitalWrite(E,HIGH);
	digitalWrite(F,HIGH);
    digitalWrite(G,HIGH);
  }
  else if(numero == 9){
  	digitalWrite(A,HIGH);
	digitalWrite(B,HIGH);
    digitalWrite(C,HIGH);
    digitalWrite(F,HIGH);
    digitalWrite(G,HIGH);
  }
  else{
  	digitalWrite(A,HIGH);
	digitalWrite(B,HIGH);
    digitalWrite(C,HIGH);
    digitalWrite(D,HIGH);
    digitalWrite(E,HIGH);
	digitalWrite(F,HIGH);
  }
  
}

void setup(){
  
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  digitalWrite(5,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(2,HIGH);
  
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  
  pinMode(buzzer,OUTPUT);
  
  pinMode(time1_2,INPUT);
  pinMode(time1_3,INPUT);
  pinMode(time2_2,INPUT);
  pinMode(time2_3,INPUT);
  
}


void loop(){
  
  if(digitalRead(time1_2) == 1){
    PlacarTime1 += 2;
    delay(1000);
  }
  else if(digitalRead(time1_3) == 1){
    PlacarTime1 += 3;
    tone(buzzer,440,1500);
    delay(1000);
  }
  else if(digitalRead(time2_2) == 1){
    PlacarTime2 += 2;
    delay(1000);
  }
  else if(digitalRead(time2_3) == 1){
    PlacarTime2 += 3;
    tone(buzzer,660,1500);
    delay(1000);
  } else {}
  
  /* Não consegui reduzir o código abaixo pois através de funções
     os números se sobrepõem por alguma razão misteriosa */
  
  digitalWrite(5,LOW);
  numeros(PlacarTime1/10);
  delay(20);
  digitalWrite(5,HIGH);
    
    
  digitalWrite(4,LOW);
  numeros(PlacarTime1%10);
  delay(20);
  digitalWrite(4,HIGH);
  
  digitalWrite(2,LOW);
  numeros(PlacarTime2%10);
  delay(20);
  digitalWrite(2,HIGH);
    
    
  digitalWrite(3,LOW);
  numeros(PlacarTime2/10);
  delay(20);
  digitalWrite(3,HIGH); 
  
  if(PlacarTime1 >= 100 || PlacarTime2 >= 100){
  	abort(); // Desliga o programa caso algum time exceda 99
  } else {}
  
}
