#ifndef MAIN_H
#define MAIN_H
#include "blockchain.h"
#include "blockfederada.h"
#include "arbol_validacion.h"

void alta(int id_bc, _blockFederada* red, arbol_v* arbol, char* mensaje, int* contador_primos, int* contador_bc, int* primos);


void actualizacion(_blockFederada* bf, int id_block, int id_nodo, char* nuevo_mensaje, int* contador_primos,  int* primos, arbol_v* arbol);

int validacion(_blockFederada* bf, arbol_v* arbol);

int validacion_sub(int vp, int min, int max, arbol_v *arbol);

#endif