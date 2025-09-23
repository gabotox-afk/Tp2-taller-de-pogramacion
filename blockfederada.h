#ifndef BLOCKFEDERADA_H
#define BLOCKFEDERADA_H
#include "blockchain.h"
#include "arbol_validacion.h"

typedef struct _BlockFederada {
blockChain *datos;
int capacidad;
int cantidad_blocks;
arbol_v* arbol_validacion;
}_blockFederada;

void modif_len(_blockFederada* bF);

_blockFederada* crear_red_federada(int largo_inicial);

void liberar_red_federada(_blockFederada* red);



#endif

