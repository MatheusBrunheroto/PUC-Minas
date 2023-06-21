#include <locale.h>

#include "struct.h"
#include "entrada.h"


/* Projeto Final AED I Matheus Brunheroto
   Objetivo : criar um sistema de venda de carros utilizando
   la�os condicionais e de repeti��o, estruturas de aloca��o est�tica,
   registros, fun��es e modo gr�fico.
   No meu projeto ser� poss�vel adicionar carros para o seu sistema, como
   administrador e como usu�rio comprar. Isso enquanto sua execu��o n�o for interrompida,
   pois o projeto n�o requer armazenamento em mem�ria secund�ria. Terei que
   usar o b�sico dos ponteiros, pois nesse caso n�o faz sentido trabalhar
   sem eles.

   Conforme fui fazendo o c�digo, notei a necessidade de dividir as fun��es em
   headers, pois estava dif�cil trabalhar em algo espec�fico dentro de um ambiente
   com mais de 600 linhas de c�digo.

   Headers ->
              struct.h
              entrada.h
              sistema.h
              usuario.h
              administrador.h
              exibicao.h


- Botao de informacoes na tela inicial, com aquela imagem do photoshop
- Captcha
- Colocar a primeira letra em letra maiuscula no ADM REGISTRAR
   */

int main(){

    setlocale(LC_ALL, "Portuguese");

    // H� 10 carros pr�-alocados, tendo espa�o para mais 10 serem adicionados pelo Administrador do sistema.
    carro ListaDeCarros[20] = {
        {"Fiat", "Uno sem Escada", 1986, 10500, false, false},
        {"Fiat", "Uno com Escada", 1986, 13500, false, false},
        {"Chevrolet", "Camaro Amarelo", 2010, 516200, false, false},
        {"Chevrolet", "Opala Preto", 1982, 32050, false, false},
        {"Ford", "Maverick", 1974, 244890, false, false},
        {"Ford", "Mustang", 2020, 566300, false, false},
        {"Volkswagen", "Fusca", 1953, 22900, false, false},
        {"Volkswagen", "Gol", 1984, 78160, false, false},
        {"Honda", "Civic SI", 2009, 60500, false, false},
        {"Honda", "Accord", 2023, 148210, false, false},
    };


    Entrada(ListaDeCarros);
    return 0;

}
