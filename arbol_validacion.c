#include "arbol_validacion.h"
#include <stdlib.h>


void expandir_capacidad(arbol_v* arbol) {
    int nueva_capacidad = arbol->len * 2;

    int* nuevos_datos = realloc(arbol->datos, nueva_capacidad * sizeof(int));

    arbol->datos = nuevos_datos;
    arbol->len = nueva_capacidad;

}

arbol_v* crear_arbol_validacion(int largo_inicial){
    arbol_v *nuevo = (arbol_v*) malloc (sizeof(arbol_v));

    int capacidad_nueva = 1;
    while(capacidad_nueva < largo_inicial){
        capacidad_nueva *= 2;
    }
    
    capacidad_nueva *= 2;
    nuevo->len= capacidad_nueva;
    nuevo -> ultimo = 0;
    nuevo->datos= malloc (capacidad_nueva*sizeof(int));
    return nuevo;
}

void liberar_arbol_validacion(arbol_v* arbol) {



    free(arbol->datos);
    free(arbol);
}