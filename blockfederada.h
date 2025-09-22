#ifndef BLOCKFEDERADA_H
#define BLOCKFEDERADA_H
#include "blockchain.h"
#include "arbol_validacion.h"

typedef struct _BlockFederada {
blockChain *datos;
int ultimo;
int len;
NodoArbol* raiz_validacion;
}_blockFederada;

void modif_len(_blockFederada* bF, int l);



#endif