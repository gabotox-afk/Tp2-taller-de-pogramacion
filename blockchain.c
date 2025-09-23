#include "blockchain.h"


NodoBlock* crear_nodo(char* m, int* c, int* p, int id_ant){
    NodoBlock* nuevo = (NodoBlock*) malloc(sizeof (NodoBlock));
    nuevo ->id_actual= p[(*c)];
    if ((*c)== 0){
        nuevo -> id_anterior= 0;    
    }
    else{
        nuevo -> id_anterior= p[id_ant];
    }

    nuevo -> mensaje= m;
    nuevo -> sig= NULL;

    (*c)++;
    return nuevo;
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

    free(bc);

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

void agregar_bloque(blockChain* bc, NodoBlock* nuevo){
    if (bc == NULL || nuevo == NULL){
        return;
    }

    if (esta_vacia(bc)){
        bc -> primero= nuevo;
        bc ->ultimo = nuevo;
    }
    else{
        bc -> ultimo -> sig = nuevo;
        bc -> ultimo = nuevo;
    }
}

blockChain* crear_block_chain(int* c){
    blockChain* nuevo = (blockChain*) malloc(sizeof(blockChain));
    nuevo -> id_block = (*c);
    nuevo -> primero = NULL;
    nuevo -> ultimo = NULL;
    (*c)++;
    printf("aura\n%d\naura",*c);
    return nuevo;


}