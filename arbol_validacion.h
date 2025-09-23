#ifndef ARBOL_VALIDACION_H
#define ARBOL_VALIDACION_H
  
typedef struct arbol_v {
int *datos;
int ultimo;
int len;
} arbol_v;

void modif_len( arbol_v* , int nueva_capacidad);

arbol_v crear_red_federada(int largo_inicial);

void liberar_red_federada(arbol_v* red);


#endif






