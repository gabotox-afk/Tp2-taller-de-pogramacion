#include "arbol_validacion.h"



void expandir_capacidad(arbol_v* arbol) {
    int nueva_capacidad = arbol->capacidad * 2;

    int* nuevos_datos = realloc(arbol->datos, nueva_capacidad * sizeof(int));

    arbol->datos = nuevos_datos;
    arbol->capacidad = nueva_capacidad;

}

arbol_v* crear_arbol_federada(int largo_inicial){
    arbol_v *nuevo = (arbol_v*) malloc (sizeof(arbol_v));

    int cont = 1;
    while(cont < largo_inicial){
        cont *= 2;
    }

    nuevo->capacidad = largo_inicial;
    nuevo->datos= malloc (largo_inicial*sizeof(int));
    nuevo -> cantidad_nodos= 0;
    return nuevo;
}

void liberar_arbol_validacion(arbol_v* arbol) {

    free(arbol->datos);
    free(arbol);
}