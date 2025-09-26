#ifndef MAIN_H
#define MAIN_H
#include "blockchain.h"
#include "blockfederada.h"
#include "arbol_validacion.h"

//agrega un nuevo valor a una blockchain o crea una blockchain nueva si se pide ingresar un valor en una inexistente. Refleja los cambios en el arbol de validacion
void alta(int id_bc, _blockFederada* red, arbol_v* arbol, char* mensaje, int* contador_primos, int* contador_bc, int* primos);

//cambia el valor y mensaje de un nodo en especifico, tambien actualiza el valor de los nodods siguientes, refleja los cambios en el arbol de validacion
void actualizacion(_blockFederada* bf, int id_block, int id_nodo, char* nuevo_mensaje, int* contador_primos,  int* primos, arbol_v* arbol);

//revisa si el arbol cumple con las caracteristicas de un heap y si cumple con la caracteristica de que raiz = multiplicacion de las hojas
int validacion(_blockFederada* bf, arbol_v* arbol);

//compara un valor con el resultado de la multiplicacion de las hojas correspondientes a las blockchains en el intervalo {min-max}
int validacion_sub(int vp, int min, int max, arbol_v *arbol);

#endif