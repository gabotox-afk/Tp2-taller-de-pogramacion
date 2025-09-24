#ifndef ARBOL_VALIDACION_H
#define ARBOL_VALIDACION_H
  
typedef struct arbol_v {
int *datos;
int ultimo;
int len;
} arbol_v;

void expandir_capacidad( arbol_v* arbol);

arbol_v* crear_arbol_validacion(int largo_inicial);

void liberar_arbol_validacion(arbol_v* red);

int calcular_capacidad_hojas(int numero_de_hojas);

int obtener_indice_hoja(int capacidad_hojas, int indice_blockchain);

int obtener_indice_padre(int indice_hijo);


#endif






