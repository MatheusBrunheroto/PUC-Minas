#include <locale.h>

#include "struct.h"
#include "entrada.h"


/* Projeto Final AED I Matheus Brunheroto
   Objetivo : criar um sistema de venda de carros utilizando
   laços condicionais e de repetição, estruturas de alocação estática,
   registros, funções e modo gráfico.
   No meu projeto será possível adicionar carros para o seu sistema, como
   administrador e como usuário comprar. Isso enquanto sua execução não for interrompida,
   pois o projeto não requer armazenamento em memória secundária. Terei que
   usar o básico dos ponteiros, pois nesse caso não faz sentido trabalhar
   sem eles.

   Conforme fui fazendo o código, notei a necessidade de dividir as funções em
   headers, pois estava difícil trabalhar em algo específico dentro de um ambiente
   com mais de 600 linhas de código.

   Headers ->
              struct.h
              entrada.h
              sistema.h
              usuario.h
              administrador.h
              exibicao.h

    Link da apresentação do projeto -> https://youtu.be/v0O3TVWdEzg
    Link da apresentação da alteração que realizei após a gravação do vídeo acima -> https://youtu.be/rkNue_pTLms

*/


int main(){

    setlocale(LC_ALL, "Portuguese");

    // Há 10 carros pré-alocados, tendo espaço para mais 10 serem adicionados pelo Administrador do sistema.

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

        {"Nulo", "Nulo", 0, 0, false},
        {"Nulo", "Nulo", 0, 0, false},
        {"Nulo", "Nulo", 0, 0, false},
        {"Nulo", "Nulo", 0, 0, false},
        {"Nulo", "Nulo", 0, 0, false},
        {"Nulo", "Nulo", 0, 0, false},
        {"Nulo", "Nulo", 0, 0, false},
        {"Nulo", "Nulo", 0, 0, false},
        {"Nulo", "Nulo", 0, 0, false},
        {"Nulo", "Nulo", 0, 0, false}
   
    };


    Entrada(ListaDeCarros);
    return 0;

}
