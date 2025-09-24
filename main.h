#ifndef MAIN_H
#define MAIN_H
#include "blockchain.h"
#include "blockfederada.h"
#include "arbol_validacion.h"

void alta(int id_b ,arbol_v* arbol, _blockFederada* bf ,char* mensaje, int* contador_primos,int* contador_blocks,  int* primos);

void actualizacion(_blockFederada* bf, int id_block, int id_nodo, char* nuevo_mensaje, int* contador_primos,  int* primos);

int validacion(_blockFederada* bf);

int validacion_sub(int validacion_esperada, int min, int max, _blockFederada bf);


#endif