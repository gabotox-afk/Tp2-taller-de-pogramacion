#include "arbol_validacion.h"
#include <stdlib.h>
#include <stdio.h>


void expandir_capacidad(arbol_v* arbol) {
    int nueva_capacidad = arbol->capacidad * 2;

    int* nuevos_datos = realloc(arbol->datos, nueva_capacidad * sizeof(int));

    arbol->datos = nuevos_datos;
    arbol->capacidad = nueva_capacidad;

}

arbol_v* crear_arbol_validacion(int numero_de_blocks){
    arbol_v *nuevo = (arbol_v*) malloc (sizeof(arbol_v));


    int capacidad_nueva = calcular_capacidad_hojas(numero_de_blocks);
    capacidad_nueva *= 2;

    nuevo->capacidad= capacidad_nueva;
    nuevo -> cantidad_nodos = 0;
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
    return capacidad_nueva;

}

int obtener_indice_hoja(int capacidad_hojas, int indice_blockchain){

    return capacidad_hojas + indice_blockchain;

}

int obtener_indice_padre(int indice_hijo){

    return indice_hijo / 2;

}

arbol_v* construir_arbol(int* ids_hojas, int cantidad_hojas) {
    if (ids_hojas == NULL || cantidad_hojas <= 0) {
        printf("no se puede llenar un arbol vacio");
        return NULL;
    }

    int capacidad_hojas = calcular_capacidad_hojas(cantidad_hojas);
    int capacidad_total = capacidad_hojas * 2;
    arbol_v* arbol = crear_arbol_validacion(capacidad_total);
    if (arbol == NULL) return NULL;


 
    for (int i = 0; i < capacidad_hojas; i++) {
        int indice_actual = obtener_indice_hoja(capacidad_hojas, i);
        if (i < cantidad_hojas) {
            arbol->datos[indice_actual] = ids_hojas[i];
        } else {
            arbol->datos[indice_actual] = 1;
        }
    }

    for (int i = capacidad_hojas - 1; i > 0; i--) {
        int hijo_izq = arbol->datos[2 * i];
        int hijo_der = arbol->datos[2 * i + 1];
        arbol->datos[i] = hijo_izq * hijo_der;
    }
    
    arbol->cantidad_nodos = capacidad_total - 1;
    return arbol;
}


void modificar_arbol(arbol_v* arbol, int id_blockchain, _blockFederada* bf) {

    blockChain* temp = (&bf ->datos[id_blockchain]);
    int nuevo_dato = (temp -> ultimo) -> id_actual;

    int capacidad_hojas = calcular_capacidad_hojas(bf -> cantidad_blocks);

    int indice_hoja = capacidad_hojas + id_blockchain;
    arbol->datos[indice_hoja] = nuevo_dato;



    int indice_actual = indice_hoja / 2;

    while (indice_actual > 0) {
        int hijo_izq = arbol->datos[2 * indice_actual];
        int hijo_der = arbol->datos[2 * indice_actual + 1];
        arbol->datos[indice_actual] = hijo_izq * hijo_der;


        indice_actual = indice_actual / 2;
    }
}

