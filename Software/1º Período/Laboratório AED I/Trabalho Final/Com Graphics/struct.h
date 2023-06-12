#include <stdbool.h>

#ifndef STRUCT_H
#define STRUCT_H

typedef struct{
    char marca[11], modelo[20];
    int ano;
    float preco;
    bool novo, vendido;
}carro;

#endif
