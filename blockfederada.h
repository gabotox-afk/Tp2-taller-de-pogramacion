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

//expande la capacidad de la blockfederada
void modif_len(_blockFederada* bF);

//crea la blockfederada
_blockFederada* crear_red_federada(int largo_inicial);

//libera la memoria de la blockfederada
void liberar_red_federada(_blockFederada* red);

//busca una blockchain de la blockfederada, con su id
blockChain* buscar_blockchain_por_id(_blockFederada* bf, int id);

//agrega una blockchain a la blockfederada
void agregar_blockchain( _blockFederada* bf, blockChain* bc);

//crea un arreglo con los numeros de las hojas
int* extraer_ids_hojas(_blockFederada* red);

//modifica y recalcula los nodos internos del arbol
void modificar_arbol(arbol_v* arbol, int id_blockchain, _blockFederada *bf);

#endif

