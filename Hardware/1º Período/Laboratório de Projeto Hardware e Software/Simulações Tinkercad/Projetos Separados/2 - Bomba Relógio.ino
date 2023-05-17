// Simulação Disponível Em : https://www.tinkercad.com/things/l9aLm66q1Ju-bomba-relogio

int A = 6, B = 7, C = 8, D = 9, E = 10, F = 11, G = 12;

void setup(){
  
  pinMode(A5, INPUT);
  pinMode(4, OUTPUT);
  
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
}

// A formação dos números eu mesmo descobri fuçando.
void numeros(int numero){
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

void loop(){
  
  delay(5000); // Tempo para escolher o número

  for(int i = map(analogRead(A5),1024,0,1,9); i >= 0; i--){
    
  	numeros(i);
    delay(1000);
    
  	digitalWrite(A,LOW);
  	digitalWrite(B,LOW);
  	digitalWrite(C,LOW);
  	digitalWrite(D,LOW);
  	digitalWrite(E,LOW);
  	digitalWrite(F,LOW);
  	digitalWrite(G,LOW);
    
    if(i == 0){
      tone(4,294,5000);
    }else{}
  }
  delay(2000);
  
}