#include "blockchain.h"


NodoBlock* crear_nodo(char* m, int id_act, int id_ant){
    NodoBlock* nuevo = (NodoBlock*) malloc(sizeof (NodoBlock));
    nuevo ->id_actual= id_act;
    nuevo -> id_anterior= id_ant;
    nuevo -> mensaje= m;
}

void liberar_lista(blockChain* bc){


}
NodoBlock* buscar_nodo_por_id(blockChain* bc, int id_buscado){


}
void imprimir_lista(blockChain* bc){


}
int esta_vacia(blockChain* bc){


}