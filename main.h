#ifndef MAIN_H
#define MAIN_H
#include "blockchain.h"
#include "blockfederada.h"
#include "arbol_validacion.h"

void alta(int id_b , _blockFederada* bf ,char* mensaje);

void actualizacion(_blockFederada* bf, int id_b, int id_n, char* nm);

int validacion(_blockFederada* bf);

int validacion_sub(int vp, int min, int max, _blockFederada bf);


#endif