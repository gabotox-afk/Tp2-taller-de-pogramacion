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

//crea la blockchain
blockChain* crear_block_chain(int* c);

//crea un nodo con el mensaje, el id actual y el id del nodo anterior, si es el primer nodo creado, id_anterior guardara 0
NodoBlock* crear_nodo(char* m, int* c, int* p, int id_ant);

//agrega un nodoblock, al final de la blockchain
void agregar_bloque(blockChain* bc, NodoBlock* nuevo);

//libera la memoria de una blockchain
void liberar_lista(blockChain* bc);

//busca un nodo dentro de una blockchain con su id
NodoBlock* buscar_nodo_por_id(blockChain* bc, int id_buscado);

//imprimi los datos que guardan los nodos de la blockchain
void imprimir_lista(blockChain* bc);

//devuelve 1 o 0 para saber si la blockchain esta vacia o no, respectivamente
int esta_vacia(blockChain* bc);



#endif