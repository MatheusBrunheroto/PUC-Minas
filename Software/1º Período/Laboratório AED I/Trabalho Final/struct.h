/* #ifdef == If Defined, if(VALOR), supondo que VALOR = verdadeiro.

   #ifndef == If Not Defined, supondo que VALOR = falso,
   portanto, n�o definido, o ifndef se comporta como um
   if(!VALOR).

   Nesse caso, isso � aplicado para a struct 'carro' para evitar que
   durante o c�digo ele se redefina. Se STRUCT_H ainda n�o foi definido,
   defina STRUCT_H. A partir desse ponto STRUCT_H j� foi definido e essa
   parte do c�digo n�o rodar� novamente. */

#ifndef STRUCT_H

    #define STRUCT_H

    typedef struct{
        char marca[11], modelo[20];
        int ano;
        float preco;
        bool novo, vendido;
    }carro;

#endif                             // #endif representa o fecha chaves do IF-ELSE


