// Simulação Disponível Em : https://www.tinkercad.com/things/7APqLHjyvSN-prototipo-guitar-hero

int VERMELHO[4] = {2,3,4,5}, BOTAO_VERMELHO = 12;
int VERDE[4] = {6,7,8,9}, BOTAO_VERDE = 11;
int AMARELO[4] = {A5,A4,A3,A2}, BOTAO_AMARELO = 10;

int BUZZER = A1;
int pressionado;

void setup(){
  
	for(int i = 0; i < 4; i++){
    	pinMode(VERMELHO[i], OUTPUT);
    	pinMode(VERDE[i], OUTPUT);
    	pinMode(AMARELO[i], OUTPUT);
  	}
  
  	pinMode(BUZZER, OUTPUT);
  
 	pinMode(BOTAO_VERMELHO, INPUT);
  	pinMode(BOTAO_VERDE, INPUT);
  	pinMode(BOTAO_AMARELO, INPUT);
  
}

int BOTAO_PRESSIONADO(int botao, int num){
	
	// Intervalo entre "num" para pressionar o botão
  	for(int i = 30; i > 0; i--){
    	delay(i);
    
  		if(digitalRead(botao) == HIGH && num == 3){    
  			tone(BUZZER,500,1000); // Acertou
  		}
    	else if(digitalRead(botao) == HIGH){
      		tone(BUZZER,123,1000); // Errou
      		delay(1000);
    		return 1;
    	}

  	}

}

void loop(){
  
    // Vermelho
	for(int i = 0; i < 5; i++){ 
    
    	if(i == 0){
      		digitalWrite(VERMELHO[i],HIGH);
  		}
    	else{
      		digitalWrite(VERMELHO[i - 1],LOW);
	  		digitalWrite(VERMELHO[i],HIGH);
    	}
   		
     // Em caso de erro, a função retornou 1, e cancela o loop atual
    	if(BOTAO_PRESSIONADO(BOTAO_VERMELHO,i) == 1){
      		digitalWrite(VERMELHO[i],LOW);
      		break; 
        } else {}
    }
  	
  	// Verde
	for(int i = 0; i < 5; i++){ 

    	if(i == 0){
      		digitalWrite(VERDE[i],HIGH);
  		}
    	else{
      		digitalWrite(VERDE[i - 1],LOW);
	  		digitalWrite(VERDE[i],HIGH);
    	}
   		if(BOTAO_PRESSIONADO(BOTAO_VERDE,i) == 1){
      		digitalWrite(VERDE[i],LOW);
      	break; 
    	}
    
  	}
  
  	// Amarelo
  	for(int i = 0; i < 5; i++){ 
    
    	if(i == 0){
      		digitalWrite(AMARELO[i],HIGH);
  		}
    	else{
      		digitalWrite(AMARELO[i - 1],LOW);
	  		digitalWrite(AMARELO[i],HIGH);
    	}
   		if(BOTAO_PRESSIONADO(BOTAO_AMARELO,i) == 1){
      		digitalWrite(AMARELO[i],LOW);
      	break; 
    	}
    
  	}
  
}
