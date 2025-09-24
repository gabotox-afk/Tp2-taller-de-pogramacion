#ifndef arbol_validacion_H
#define arbol_validacion_H
#include "blockfederada.h"
// La estructura que define el nuevo modelo de árbol.
typedef struct arbol_v {
    int raiz_valor;
    int* hojas;
    int cantidad_hojas;
    int capacidad_hojas;
} arbol_v;


/**
 * Crea un contenedor vacío para el árbol simplificado.
 */
arbol_v* crear_arbol_validacion(int capacidad_inicial);

/**
 * Libera toda la memoria del árbol simplificado.
 */
void liberar_arbol_validacion(arbol_v* arbol);

/**
 * Función principal para actualizar o agregar una hoja.
 * Después de cambiar el valor de una hoja, recalcula la raíz.
 */
void actualizar_hoja(arbol_v* arbol, int indice_hoja, int nuevo_valor);

/**
 * (Para validacion_total) Devuelve el valor cacheado de la raíz.
 */
int obtener_valor_raiz(arbol_v* arbol);

/**
 * (Para validacion_subconjunto) Calcula el valor para un rango de hojas.
 */
int calcular_valor_subconjunto(arbol_v* arbol, int inicio, int fin);


void imprimir_arbol_validacion(arbol_v* arbol);


#endif 






