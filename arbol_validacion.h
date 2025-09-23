#ifndef ARBOL_VALIDACION_H
#define ARBOL_VALIDACION_H

typedef struct _ABNodo {
  int dato;
  struct _ABNodo *izq, *der;
} _ABNodo;


_ABNodo* construir_arbol_desde_hojas(int* ids_hojas, int cantidad_hojas);

_ABNodo crear_nodo_arbol(int valor);

void liberar_arbol(_ABNodo* raiz);



#endif






