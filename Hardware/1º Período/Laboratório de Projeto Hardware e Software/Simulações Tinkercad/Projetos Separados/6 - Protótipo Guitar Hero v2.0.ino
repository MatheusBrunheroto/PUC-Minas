// Simulação Disponível Em : https://www.tinkercad.com/things/0Sz4taXGE1e-prototipo-guitar-hero-20

/* Essa é a versão do protótipo 2.0 referente ao
   projeto final de LPHS "Guitar Hero". Nessa versão
   pretendo unir 3 notas simples, fazendo com que elas 
   sejam premeditáveis e tocadas no momento em que devem
   ser apertadas, assim como no jogo. */


/* Aqui estão os vetores que armazenam a ordem das luzes
   de cada segmento de cores, seus respectivos botões e
   a declaração do Buzzer. */
  
int VERMELHO[4] = {2,3,4,5}, BOTAO_VERMELHO = 10;
int VERDE[4] = {6,7,8,9}, BOTAO_VERDE = 11;
int AMARELO[4] = {A5,A4,A3,A2}, BOTAO_AMARELO = 12;
int BUZZER = A1;


/*	A struct abaixo, simula um processamento paralelo
	que não é permitido pelo arduino, ela mantém as cores
    descendo juntas, fazendo com que o problema onde as notas
    descem uma por uma seja resolvido. */

struct LEDS{
	int posicao;
  	bool permissao;
};
typedef struct LEDS Cor;
Cor Vermelho = {0, false};
Cor Verde = {0, false};
Cor Amarelo = {0, false};

struct LEDS verificacao(int x, int * y, bool z, int nota) {
  
  	int coluna = x;
	int * linha = y;
  
	if (x < 4 && z == true){
      
  		digitalWrite(coluna[linha],HIGH); 
  		digitalWrite(coluna[linha - 1],LOW); 
    	
      	if(x == 3)
        	tone(BUZZER, nota, 200);
      
    	return {x += 1,true};
      
  	}
  	else{
   		
  		digitalWrite(coluna[linha - 1],LOW);   
    	return {0, false};
  
    }
}


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

  
void loop() {
  
  	int x = (rand() % 3) + 1; // [1-3]
  	
  	// "Seletor Aleatório" de Cores
  	if(x == 1){
    	Vermelho.permissao = true;
    }
	else if(x == 2){
    	Verde.permissao = true;
  	}
    else{
      	Amarelo.permissao = true;
    }
    
	/* A cor ira descer, e quando ela estiver na ultima posição
       a nota designada a ela será tocada. */
	Vermelho = verificacao(Vermelho.posicao, VERMELHO, Vermelho.permissao, 294);
  	Verde = verificacao(Verde.posicao,VERDE,Verde.permissao, 330);
  	Amarelo = verificacao(Amarelo.posicao,AMARELO,Amarelo.permissao, 349);
 
  	delay(1000);  // Controla a velocidade

}








