#include "blockchain.h"


NodoBlock* crear_nodo(char* m, int id_act, int id_ant){
    NodoBlock* nuevo = (NodoBlock*) malloc(sizeof (NodoBlock));
    nuevo ->id_actual= id_act;
    nuevo -> id_anterior= id_ant;
    nuevo -> mensaje= m;
}

void liberar_lista(blockChain* bc){
    NodoBlock* borrar= bc -> primero;
    while (borrar){
        NodoBlock* temp = borrar;
        borrar = borrar -> sig;
        free(temp -> mensaje);
        free(temp);
    }
    bc -> primero = NULL; 
    bc -> ultimo = NULL;   

}

NodoBlock* buscar_nodo_por_id(blockChain* bc, int id_buscado){
    NodoBlock* busqueda = bc -> primero;
    while( busqueda){
        if ( busqueda -> id_actual == id_buscado)
            return busqueda;
        busqueda = busqueda -> sig;
    }
    return NULL;
}

void imprimir_lista(blockChain* bc){
    NodoBlock* impresion = bc -> primero;
    while(impresion){
        printf("\nid actual: %d, mensaje: %s, id anterior: %d\n", impresion -> id_actual, impresion -> mensaje, impresion -> id_anterior);
        impresion = impresion -> sig;    
    }
    

}

int esta_vacia(blockChain* bc){
    return bc -> primero == NULL;
}