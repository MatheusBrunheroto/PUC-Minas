#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include <graphics.h>

#include "struct.h"

int Tamanho(carro * Disponiveis);


void Usuario(carro * Disponiveis);
float ComprarUsuario(carro * Disponiveis, float dinheiro);


void Administrador(carro * CarroADM);
void RegistrarCarroADM(carro * NovoADM);
void RemoverCarroADM(carro * RemovidoADM);



void Sistema(carro * ListaDeCarros);
void Exibe(carro * Disponiveis, bool Usuario, float dinheiro);
void LimpaTela();



