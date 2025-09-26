#ifndef arbol_validacion_H
#define arbol_validacion_H


typedef struct arbol_v {
    int raiz_valor;
    int* hojas;
    int cantidad_hojas;
    int capacidad_hojas;
} arbol_v;

//crea un arbol de validacion, no lo llena con las hojas correspondientes
arbol_v* crear_arbol_validacion(int capacidad_inicial);

// llena el arbol de validacion con las hojas que le correspondern
arbol_v* construir_arbol_validacion(int* ids_hojas, int cantidad_hojas);

//libera la memoria en el arbol de validacion
void liberar_arbol_validacion(arbol_v* arbol);

//actualiza las hojas en el arbol de validacion
void actualizar_hoja(arbol_v* arbol, int indice_hoja, int nuevo_valor);

//calcula el valor de un subconjunto en el rango {inicio, fin}
int calcular_valor_subconjunto(arbol_v* arbol, int inicio, int fin);

//recalcula el valor de la raiz
void recalcular_raiz(arbol_v* arbol);

//imprime el arbol de validacion
void imprimir_arbol_validacion(arbol_v* arbol);

//aumenta la capacidad del arbol de validacion
void aumentar_capacidad(arbol_v* arbol, int indice_requerido);




#endif 






