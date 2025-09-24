#ifndef ARBOL_VALIDACION_H
#define ARBOL_VALIDACION_H
#include "blockfederada.h"
  
typedef struct arbol_v {
int *datos;
int cantidad_nodos;
int capacidad;
} arbol_v;

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

//modifica y recalcula los nodos internos del arbol
void modificar_arbol(arbol_v* arbol, int id_blockchain, _blockFederada* bf)


#endif






