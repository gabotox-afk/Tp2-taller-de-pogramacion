#ifndef MAIN_H
#define MAIN_H
#include "blockchain.h"
#include "blockfederada.h"
#include "arbol_validacion.h"

void alta(int id_bc ,arbol_v* arbol, _blockFederada* bf ,char* mensaje, int* contador_primos,int* contador_block,  int* primos);

void actualizacion(_blockFederada* bf, int id_b, int id_n, char* nm, int* contador_primos,  int* primos);

int validacion(_blockFederada* bf);

int validacion_sub(int validacion_espedara, int min, int max, _blockFederada bf);


#endif