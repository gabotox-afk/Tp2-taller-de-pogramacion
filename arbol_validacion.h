#ifndef ARBOL_VALIDACION_H
#define ARBOL_VALIDACION_H
#include "blockchain.h"

typedef struct Arbol_v {
    int* datos;
    int cantidad_nodos;
    int capacidad;
} arbol_v;



void imprimir_arbol(arbol_v* arbol);

//expande la capacidad del arbol
void expandir_capacidad( arbol_v* arbol);

//crea el arbol de validacion
arbol_v* crear_arbol_validacion(int largo_inicial);

//libera la memoria del arbol de validacion
void liberar_arbol_validacion(arbol_v* red);

//calcula la capacidad de hojas necesaria, con la cantidad de hojas
int calcular_capacidad_hojas(int numero_de_blocks);

//obtiene el indice de la hoja de la blockchain, con su indice y la capacida de hojas
int obtener_indice_hoja(int capacidad_hojas, int indice_blockchain);

//
int obtener_indice_padre(int indice_hijo);

//construye el arbol
arbol_v* construir_arbol(int* ids_hojas, int cantidad_hojas);

void calcular_padres(arbol_v* arbol, int indice);









#endif






