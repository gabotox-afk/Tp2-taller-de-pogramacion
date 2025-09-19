#ifndef BLOCKFEDERADA_H
#define BLOCKFEDERADA_H
#include "blockchain.h"

typedef struct _BlockFederada {
blockChain *datos;
int ultimo;
int len;
}_blockFederada;

void modif_len(_blockFederada* bF, int l);



#endif