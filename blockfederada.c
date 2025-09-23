#include "blockfederada.h"
#include <stdio.h>
#include <stdlib.h>

void expandir_capacidad(_blockFederada* red) {

    int nueva_capacidad = red->capacidad + 1;
    blockChain* nuevos_datos = realloc(red->datos, nueva_capacidad * sizeof(blockChain));
    red->datos = nuevos_datos;
    red->capacidad = nueva_capacidad;
}

_blockFederada* crear_red_federada(int largo_inicial){
    _blockFederada *nuevo = malloc (sizeof(_blockFederada));
    nuevo->capacidad = largo_inicial;
    nuevo->datos=malloc (largo_inicial*sizeof(blockChain));
    nuevo -> cantidad_blocks= 0;
    nuevo -> raiz_validacion = NULL;
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