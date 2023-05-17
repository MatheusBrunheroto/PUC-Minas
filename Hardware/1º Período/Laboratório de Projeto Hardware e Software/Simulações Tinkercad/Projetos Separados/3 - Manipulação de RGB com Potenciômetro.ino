// Simulação Disponível Em : https://www.tinkercad.com/things/7E53Lti7YlK-manipulacao-de-rgb-com-potenciometro

int R = 5, G = 6, B = 7;

void setup(){
  
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  
}

void loop(){
    
    analogWrite(R,map(analogRead(A0),1024,0,0,255));
  	if(analogRead(A0) >= 1000){
      digitalWrite(1,HIGH);
  	}
  	else{
      digitalWrite(1,LOW);
    }
  
    analogWrite(G,map(analogRead(A1),1024,0,0,255));
    if(analogRead(A1) >= 1000){
      digitalWrite(2,HIGH);
  	}
  	else{
      digitalWrite(2,LOW);
    }
  
    analogWrite(B,map(analogRead(A2),1024,0,0,255));
    if(analogRead(A2) >= 1000){
      digitalWrite(3,HIGH);
  	}
  	else{
      digitalWrite(3,LOW);
    }

}
