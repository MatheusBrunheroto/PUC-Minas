#include <stdio.h>

// Vamos declarar um ser humano usando typedef
typedef struct{
    char * nome;
    int idade;
    int peso;
}humano; // Novo tipo de variável não primitiva, diferente de uma variável

// Agora vamos declarar um animal sem usar typedef
struct animais{
    char * raca;
    char idade;
    char peso;
}cachorro; /* Como não estamos usando typedef, cachorro não se torna um novo tipo, 
e sim uma variável de struct animais */

int main(){
    
    humano /* novo tipo */ Matheus; // similar a int x;
    // Agora a partir disso é possível declarar:
    
    Matheus.nome = "Matheus";
    Matheus.idade = 18;
    Matheus.peso = 100;
    
    /* Como humano é um tipo e não uma variável, não é possível declarar diretamente
       humano.nome
       humano.idade
       humano.peso 
       Diferente do que acontece quando não usamos typedef e damos um nome no fim da struct */
       
    // animais gato; não funciona, pois animais não é tipo, então usamos:
    struct animais gato;
    
    gato.raca = "Laranja";
    gato.idade = 1;
    gato.peso = 10;
    
    /* Foi necessário declarar gato usando "struct animais". Note que na declaração da struct
       há um "cachorro" antes do ";", isso não cria um novo tipo como no typedef, apenas cria
       uma variável sem precisar declarar no main como "struct animais cachorro", portando
       é possível utiliza-la diretamente da seguinte forma : */
      
    cachorro.raca = "Border Collie";
    cachorro.idade = 6;
    cachorro.peso = 15;
    
    // Vamos imprimir para confirmar
    
    printf("HUMANO :\n");
    printf("%s\n%i\n%i\n\n",Matheus.nome, Matheus.idade, Matheus.peso);
    
    printf("ANIMAIS :\n");
    printf("\nGATO\n%s\n%i\n%i\n",gato.raca, gato.idade, gato.peso);
    printf("\nCACHORRO\n%s\n%i\n%i\n\n",cachorro.raca, cachorro.idade, cachorro.peso);
    
}
