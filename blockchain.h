#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

typedef struct _NodoBlock {
  int dato;
  int id;
  char mensaje;
  struct _NodoBlock *sig;
  struct _NodoBlock *ant;
} NodoBlock;

typedef struct _BlockChain
{
    int dato;
    struct _NodoBlock *primero;
    struct _NodoBlock *ultimo;

}blockChain;

#endif