/* #ifdef == If Defined, if(VALOR), supondo que VALOR = verdadeiro.

   #ifndef == If Not Defined, supondo que VALOR = falso,
   portanto, não definido, o ifndef se comporta como um
   if(!VALOR).

   Nesse caso, isso é aplicado para a struct 'carro' para evitar que
   durante o código ele se redefina. Se STRUCT_H ainda não foi definido,
   defina STRUCT_H. A partir desse ponto STRUCT_H já foi definido e essa
   parte do código não rodará novamente. */

#ifndef STRUCT_H

    #define STRUCT_H

    typedef struct{
        char marca[11], modelo[20];
        int ano;
        float preco;
        bool novo, vendido;
    }carro;

#endif                             // #endif representa o fecha chaves do IF-ELSE


