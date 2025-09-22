#ifndef BLOCKFEDERADA_H
#define BLOCKFEDERADA_H
#include "blockchain.h"
#include "arbol_validacion.h"

typedef struct _BlockFederada {
blockChain *datos;
int capacidad;
int cantidad_blocks;
ABNodo* raiz_validacion;
}_blockFederada;

void modif_len(_blockFederada* bF, int nueva_capacidad);

_blockFederada* crear_red_federada(int capacidad_inicial);

void liberar_red_federada(_blockFederada* red);



#endif