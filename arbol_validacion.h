#ifndef arbol_validacion_H
#define arbol_validacion_H


typedef struct arbol_v {
    int raiz_valor;
    int* hojas;
    int cantidad_hojas;
    int capacidad_hojas;
} arbol_v;


arbol_v* crear_arbol_validacion(int capacidad_inicial);

arbol_v* construir_arbol_validacion(int* ids_hojas, int cantidad_hojas);


void liberar_arbol_validacion(arbol_v* arbol);


void actualizar_hoja(arbol_v* arbol, int indice_hoja, int nuevo_valor);


int calcular_valor_subconjunto(arbol_v* arbol, int inicio, int fin);

void recalcular_raiz(arbol_v* arbol);

void imprimir_arbol_validacion(arbol_v* arbol);




void aumentar_capacidad(arbol_v* arbol, int indice_requerido);




#endif 






