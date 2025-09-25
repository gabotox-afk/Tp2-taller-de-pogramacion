#include "arbol_validacion.h"
#include "blockfederada.h"
#include <stdio.h>
#include <stdlib.h>


arbol_v* crear_arbol_validacion(int capacidad_inicial) {
    arbol_v* arbol = malloc(sizeof(arbol_v));
    if (arbol == NULL) return NULL;

    arbol->raiz_valor = 1;
    arbol->cantidad_hojas = 0;
    arbol->capacidad_hojas = capacidad_inicial;
    
    if (capacidad_inicial > 0) {
        arbol->hojas = malloc(capacidad_inicial * sizeof(int));
        if (arbol->hojas == NULL) {
            free(arbol);
            return NULL;
        }
    } else {
        arbol->hojas = NULL;
    }
    return arbol;
}

arbol_v* construir_arbol_validacion(int* ids_hojas, int cantidad_hojas) {
    if (ids_hojas == NULL || cantidad_hojas <= 0) {
        return NULL;
    }

    arbol_v* arbol = crear_arbol_validacion(cantidad_hojas);
    if (arbol == NULL) {
        return NULL;
    }

    for (int i = 0; i < cantidad_hojas; i++) {
        arbol->hojas[i] = ids_hojas[i];
    }
    arbol->cantidad_hojas = cantidad_hojas;
    recalcular_raiz(arbol);
    return arbol;
}




void liberar_arbol_validacion(arbol_v* arbol) {
    if (arbol == NULL) return;
    free(arbol->hojas);
    free(arbol);
}


void recalcular_raiz(arbol_v* arbol) {
    arbol->raiz_valor = 1;
    for (int i = 0; i < arbol->cantidad_hojas; i++) {
        arbol->raiz_valor *= arbol->hojas[i];
    }
}

void aumentar_capacidad(arbol_v* arbol, int indice_requerido) {   

    int nueva_capacidad = arbol -> capacidad_hojas + 1;
    if (nueva_capacidad <= indice_requerido) {
        nueva_capacidad = indice_requerido + 1;
    }

    int* temp = realloc(arbol->hojas, nueva_capacidad * sizeof(int));


    arbol->hojas = temp;
    arbol->capacidad_hojas = nueva_capacidad;

}


void actualizar_hoja(arbol_v* arbol, int indice_hoja, int nuevo_valor) {
    if (arbol == NULL || indice_hoja < 0) {
        return;
    }
    if(indice_hoja >= arbol -> capacidad_hojas) aumentar_capacidad( arbol, indice_hoja);
    
    arbol->hojas[indice_hoja] = nuevo_valor;

    if (indice_hoja >= arbol->cantidad_hojas) {
        arbol->cantidad_hojas = indice_hoja + 1;
    }

 
    recalcular_raiz(arbol);
}



int calcular_valor_subconjunto(arbol_v* arbol, int inicio, int fin) {
    int resultado = 1;

    for (int i = inicio; i <= fin; i++) {
        resultado *= arbol->hojas[i];
    }
    return resultado;
}



void imprimir_arbol_validacion(arbol_v* arbol) {
    if (arbol == NULL) return;
    printf("\n--- Arbol validacion ---\n");
    printf("valor de la Raiz: %d\n", arbol->raiz_valor);
    printf("Hojas (%d/%d): [ ", arbol->cantidad_hojas, arbol->capacidad_hojas);
    for (int i = 0; i < arbol->cantidad_hojas; i++) {
        printf("%d ", arbol->hojas[i]);
    }
    printf("]\n--------------------------\n");
}