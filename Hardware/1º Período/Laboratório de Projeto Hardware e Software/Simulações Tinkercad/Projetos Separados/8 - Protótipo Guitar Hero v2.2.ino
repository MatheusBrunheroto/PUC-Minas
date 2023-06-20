// Simulação Disponível Em : https://www.tinkercad.com/things/cZiBi6ydY6S-gerador-de-notas-guitar-hero

/* Essa é a versão do protótipo 2.2 referente ao
   projeto final de LPHS "Guitar Hero". Nessa versão
   foi acrescentado um sistema que consegue gerar
   notas para qualquer música desde que seja escrita
   da mesma forma que a atual está escrita, as notas +
   as pausas ('0'). */

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

int musica[] = {
 
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_AS4, NOTE_AS4, NOTE_AS4, NOTE_AS4,
  NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5,
  NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, 
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5, 
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5,
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, 
  NOTE_G5, NOTE_G5, NOTE_G5, NOTE_G5, 
  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_F4,
  NOTE_G4, 0, NOTE_G4, NOTE_D5,
  NOTE_C5, 0, NOTE_AS4, 0,
  NOTE_A4, 0, NOTE_A4, NOTE_A4,
  NOTE_C5, 0, NOTE_AS4, NOTE_A4, 
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4, 0, NOTE_G4, NOTE_D5,
  NOTE_C5, 0, NOTE_AS4, 0,
  NOTE_A4, 0, NOTE_A4, NOTE_A4,
  NOTE_C5, 0, NOTE_AS4, NOTE_A4, 
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5,
  NOTE_G4,0, NOTE_G4, NOTE_AS5,
  NOTE_A5, NOTE_AS5, NOTE_A5, NOTE_AS5

 };


int Coluna_Vermelha[4] = {2,3,4,5};
int Coluna_Verde[4] = {6,7,8,9};
int Coluna_Amarela[4] = {A5,A4,A3,A2};
int BUZZER = A1;


struct LEDS{
    int posicao;
    bool permissao;
};

/* Os registros de cores foram divididos entre quatro para
   aumentar a quantidade de notas que descerão. Eu as dividi dessa forma
   para conseguir usar em loops e não causar -> https://prnt.sc/AzTIHjfy9cru */

typedef struct LEDS Cor;

/* Cada cor corresponde a uma coluna, o 4 corresponde ao número de notas que
   cada coluna consegue representar ao mesmo tempo.
   Por exemplo : um número aleatório X é gerado, então uma nota Cor[i] vai passar
   a existir, e ela vai ser um peão das colunas e da função "verificacao".
   Então a cada vez que a nota desce, essa nota Cor[i] vai ter sua posição/linha alterada, porém
   permanecendo na mesma coluna. Isso não impede que outra Cor[i] também seja gerada e movimentada
   na mesma coluna. */

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
  
  	int x = rand() % 12;
  
    for (int nota = 0; nota < 111; nota++) {

        if(musica[nota] != 0){ // Evita gerar nota para Pausas

            /* O while abaixo faz com que uma determinada Cor[i] que já tem a permissão como true, receba true novamente,
               sem isso a música pode ficar dessincronizada, pois pode gerar uma nota que ainda está em uso. */      

            while(Vermelho[x].permissao == true || Verde[x - 4].permissao == true || Amarelo[x - 8].permissao == true)
                x = rand() % 12; // [0 - 11]
              
            if(x >= 0 && x <= 3){
              Vermelho[x].permissao = true;
            }
  
            else if(x >= 4 && x <= 7){
                x -= 4; // Ajustar x para [0 - 3]
                Verde[x].permissao = true;
            }
  
            else {
                x -= 8; // Ajustar x para [0 - 3]
                Amarelo[x].permissao = true;
            }

            /*  O loop abaixo simula um processamento paralelo que não é permitido pelo
                arduino, ele mantém as cores descendo juntas, fazendo com que o 
                problema onde as notas descem uma por uma seja resolvido.
                No caso, a função verificacao é chamada com os parâmetros

                Coluna_Cor → Endereço da coluna.
                Cor[i].posicao → Posição da nota [i] de determinada cor gerada [0 - 3].
                Cor[i].permissao → Permissão da nota [i] de determinada cor gerada.
                
                Na função "verificacao", se Cor[i].posicao == 3, a nota de determinada cor
                terá sua nova posição como 0, e permissão false, voltando ao seu estado inicial,
                portanto, eliminada. */

            for(int i = 0; i < 4; i++){
                Vermelho[i] = verificacao(Coluna_Vermelha, Vermelho[i].posicao, Vermelho[i].permissao,  musica[nota]);
                Verde[i] = verificacao(Coluna_Verde, Verde[i].posicao, Verde[i].permissao,  musica[nota]);
                Amarelo[i] = verificacao(Coluna_Amarela, Amarelo[i].posicao, Amarelo[i].permissao,  musica[nota]);    
            }

        }

    delay(262);  
  }

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

struct LEDS verificacao(int Coluna[], int Linha, bool Permissao, int  musica){
  
  
  if (Linha <= 3 && Permissao == true){
      
      digitalWrite(Coluna[Linha], HIGH);     // Acende a atual
      digitalWrite(Coluna[Linha - 1], LOW);  // Apaga a anterior, efeito de movimento.
      
        if(Linha == 3)
          tone(BUZZER, musica, 175);
      
      return {Linha += 1, true}; // Retorna a próxima linha e mantém a permissão.
    
      /*O return acima funciona pois no próximo loop Linha vai ser == 4, portanto
      	cai no else abaixo. */
      
    }
    else{
      
      digitalWrite(Coluna[Linha - 1], LOW);   
      return {0, false};
  
    }
}
