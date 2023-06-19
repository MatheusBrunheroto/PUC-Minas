// Simulação Disponível Em : https://www.tinkercad.com/things/bZaQESKTTYz-prototipo-guitar-hero-21

/* Essa é a versão do protótipo 2.1 referente ao
   projeto final de LPHS "Guitar Hero". Nessa versão
   pretendo duplicar a quantidade de processamento. */


/* Aqui estão os vetores que armazenam a ordem das luzes
   de cada segmento de cores, seus respectivos botões e
   a declaração do Buzzer. */
  
int Coluna_Vermelha[4] = {2,3,4,5};
int Coluna_Verde[4] = {6,7,8,9};
int Coluna_Amarela[4] = {A5,A4,A3,A2};
int BUZZER = A1;


/*	A struct abaixo, simula um processamento paralelo
	que não é permitido pelo arduino, ela mantém as cores
    descendo juntas, fazendo com que o problema onde as notas
    descem uma por uma seja resolvido. */

struct LEDS{
	int posicao;
  	bool permissao;
};

/* Os registros de cores foram divididos entre quatro para
   aumentar a quantidade de notas que descerão. Eu as dividi dessa forma
   para conseguir usar em loops e não causar -> https://prnt.sc/AzTIHjfy9cru */

typedef struct LEDS Cor;

Cor Vermelho[4] = {
    {0, false}, {0, false},
    {0, false}, {0, false}
};

Cor Verde[4] = {
    {0, false}, {0, false},
    {0, false}, {0, false}
};

Cor Amarelo[4] = {
    {0, false}, {0, false},
    {0, false}, {0, false}
};


struct LEDS verificacao(int Coluna[], int Linha, bool Permissao, int Nota);

void setup(){ 	
  
	for(int i = 0; i < 4; i++){
    	pinMode(Coluna_Vermelha[i], OUTPUT);
    	pinMode(Coluna_Verde[i], OUTPUT);
    	pinMode(Coluna_Amarela[i], OUTPUT);
  	}
  
  	pinMode(BUZZER, OUTPUT);
  
}

  
void loop() {
    
    // "Seletor Aleatório" de Cores
    
  	int x = rand() % 12; // [0 - 11]
  
  	if(x >= 0 && x <= 3){
    	Vermelho[x].permissao = true;
    }
  
  	else if(x >= 4 && x <= 7){
      	x -= 4;	// Ajustar x
        Verde[x].permissao = true;
    }
  
    else{
    	x -= 8;	// Ajustar x
        Amarelo[x].permissao = true;
    }
      
	/* A cor ira descer, e quando ela estiver na ultima posição
       a nota designada a ela será tocada. */

    for(int i = 0; i < 4; i++){
        Vermelho[i] = verificacao(Coluna_Vermelha, Vermelho[i].posicao, Vermelho[i].permissao, 294);
        Verde[i] = verificacao(Coluna_Verde, Verde[i].posicao, Verde[i].permissao, 330);
        Amarelo[i] = verificacao(Coluna_Amarela, Amarelo[i].posicao, Amarelo[i].permissao, 349);    
    }

  	delay(500);  // Controla a velocidade

}

     
/*            Coluna            Coluna           Coluna
                ↓                 ↓                ↓
             Vermelho    |     Amarelo     |     Verde

Linha 1 →       1                 1                1
Linha 2 →       2                 2                2
Linha 3 →       3                 3                3
Linha 4 →       4                 4                4 

*/

/* Aqui embaixo, cada Linha na verdade representa uma 'Nota'
   Cor[i] que vai descendo. E graças a struct LEDS, a nova posição
   sempre é mantida até que chegue em [4]. */

struct LEDS verificacao(int Coluna[], int Linha, bool Permissao, int Nota){
  
  
	if (Linha <= 3 && Permissao == true){
      
  		digitalWrite(Coluna[Linha], HIGH);     // Acende a atual
  		digitalWrite(Coluna[Linha - 1], LOW);  // Apaga a anterior, efeito de movimento.
    	
      	if(Linha == 3)
        	tone(BUZZER, Nota, 200);
      
    	return {Linha += 1, true}; // Retorna a próxima linha e mantém a permissão.
      
  	}
  	else{

    // Ou linha == 3, ou essa Nota está sem permissão.
   		
  		digitalWrite(Coluna[Linha - 1], LOW);   
    	return {0, false};
  
    }
}
