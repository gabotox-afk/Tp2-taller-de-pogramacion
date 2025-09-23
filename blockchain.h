#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include <stdlib.h>
#include <stdio.h>

typedef struct _NodoBlock {
  int id_actual;
  char *mensaje;
  int id_anterior;
  struct _NodoBlock *sig;
} NodoBlock;

typedef struct _BlockChain
{
    int id_block;
    struct _NodoBlock *primero;
    struct _NodoBlock *ultimo;

}blockChain;

blockChain* crear_block_chain(int* c);

NodoBlock* crear_nodo(char* m, int id_act, int id_ant);

void agregar_bloque(blockChain* bc, NodoBlock* nuevo, int* c);

void liberar_lista(blockChain* bc);

NodoBlock* buscar_nodo_por_id(blockChain* bc, int id_buscado);

void imprimir_lista(blockChain* bc);

int esta_vacia(blockChain* bc);



#endif