#include "arbol_validacion.h"
#include <stdlib.h>


void expandir_capacidad(arbol_v* arbol) {
    int nueva_capacidad = arbol->len * 2;

    int* nuevos_datos = realloc(arbol->datos, nueva_capacidad * sizeof(int));

    arbol->datos = nuevos_datos;
    arbol->len = nueva_capacidad;

}

arbol_v* crear_arbol_validacion(int numero_de_blocks){
    arbol_v *nuevo = (arbol_v*) malloc (sizeof(arbol_v));


    int capacidad_nueva = calcular_capacidad_hojas(numero_de_blocks);

    nuevo->len= capacidad_nueva;
    nuevo -> ultimo = 0;
    nuevo->datos= malloc (capacidad_nueva*sizeof(int));
    return nuevo;
}

void liberar_arbol_validacion(arbol_v* arbol) {

    if(!arbol) return;
    free(arbol->datos);
    free(arbol);
}

int calcular_capacidad_hojas(int numero_de_blocks){
    int capacidad_nueva = 1;
    while(capacidad_nueva < numero_de_blocks){
        capacidad_nueva *= 2;
    }

    capacidad_nueva *= 2;
    return capacidad_nueva;

}

int obtener_indice_hoja(int capacidad_hojas, int indice_blockchain){

    return capacidad_hojas + indice_blockchain;

}

int obtener_indice_padre(int indice_hijo){

    return indice_hijo / 2;

}
