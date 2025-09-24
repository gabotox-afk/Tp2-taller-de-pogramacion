#include "blockfederada.h"
#include <stdio.h>
#include <stdlib.h>

void modif_len(_blockFederada* red) {

    int nueva_capacidad = red->capacidad + 1;
    blockChain* nuevos_datos = realloc(red->datos, nueva_capacidad * sizeof(blockChain));
    red->datos = nuevos_datos;
    red->capacidad = nueva_capacidad;
}

_blockFederada* crear_red_federada(int largo_inicial){
    _blockFederada *nuevo = (_blockFederada*) malloc(sizeof(_blockFederada));
    nuevo -> capacidad = largo_inicial;
    nuevo -> datos = malloc (largo_inicial*sizeof(blockChain));
    nuevo -> cantidad_blocks = 0;
    return nuevo;
}

void liberar_red_federada(_blockFederada* red){
    if(!red) return;

    for (int i = 0; i < red->cantidad_blocks; i++) {    
        liberar_lista(&red->datos[i]);
    }

    free (red->datos);
    free(red);
}

blockChain* buscar_blockchain_por_id(_blockFederada* bf, int id){
    if (bf == NULL ){
        return NULL;
    }
    return &bf -> datos[id];
}

void agregar_blockchain( _blockFederada* bf, blockChain* bc){

    if (bf -> cantidad_blocks >= bf -> capacidad){
        modif_len(bf);
    }

    bf -> datos[bf->cantidad_blocks] = *bc;
    bf -> cantidad_blocks ++;
}

int* extraer_ids_hojas(_blockFederada* red) {
    int cantidad = red->cantidad_blocks;
    if (cantidad == 0) {
        printf("no hay hojas para rellenar el arbol");
        return NULL;
    }

    int* arreglo_hojas = malloc(cantidad * sizeof(int));

    for (int i = 0; i < cantidad; i++) {
        blockChain* cadena_actual = &red->datos[i];

        if (cadena_actual->ultimo != NULL) {
            arreglo_hojas[i] = cadena_actual->ultimo->id_actual;
        } else {
            arreglo_hojas[i] = 1;
        }
    }

    return arreglo_hojas;
}

