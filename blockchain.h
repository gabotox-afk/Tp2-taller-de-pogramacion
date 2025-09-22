#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

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

NodoBlock* crear_nodo(char* mensaje, int id_actual, int id_anterior);

void liberar_lista(blockChain* bc);

NodoBlock* buscar_nodo_por_id(blockChain* bc, int id_buscado);

void imprimir_lista(blockChain* bc);

int esta_vacia(blockChain* bc);



#endif