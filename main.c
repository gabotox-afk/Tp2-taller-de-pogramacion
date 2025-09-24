#include "main.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "generador_primos.h"
#include "arbol_validacion.h"



/**
 * Agrega un nodo a la red. Si el índice 'id_bc' es válido, se usa.
 * Si está fuera de rango, se crea una única blockchain nueva al final
 * y se agrega el nodo ahí.
 */
void alta(int id_bc, _blockFederada* red, arbol_v* arbol, char* mensaje, int* contador_primos, int primos[]) {


}



void actualizacion(_blockFederada* bf, int id_bc, int id_n, char* nm,  int* c,  int* p, arbol_v* arbol){

    blockChain* hola = buscar_blockchain_por_id(bf, id_bc);

    NodoBlock* temp = buscar_nodo_por_id(hola, id_n);

    temp->id_actual = p[(*c)];
    
    free(temp->mensaje);
    temp->mensaje = (char*)malloc(strlen(nm) + 1); 
    strcpy(temp->mensaje, nm);
    temp->mensaje = nm;

    (*c)++;
    temp = temp->sig;

    while(temp){
      temp->id_actual = p[(*c)];
      temp-> id_anterior = p [ (*c)-1];
      temp->mensaje = nm;
      (*c)++;
      temp = temp -> sig;
    }

    actualizar_hoja(arbol, id_bc, (hola -> ultimo) -> id_actual);
  
}

int validacion(_blockFederada* bf){
  
}

int validacion_sub(int vp, int min, int max, _blockFederada bf){
  
}




int main() {
    int contadorp = 0 ;
    int contadorbc = 0;
  // Genero y muestro los primeros 100 números primos
  int *p = primos(100);
  for(int i = 0; i < 100; i++)
    printf("%d\n ",p[i]);


  // Uso los números primos

  // IMPORTANTE: libero la memoria pedida para el arreglo de números primos
  free(p);

  blockChain*bc1= crear_block_chain(&contadorbc);
  blockChain*bc2= crear_block_chain(&contadorbc);


  NodoBlock* n1 = crear_nodo("hola",&contadorp, p,contadorp-1);
  NodoBlock* n2 = crear_nodo("como",&contadorp, p,contadorp-1);
  NodoBlock* n3 = crear_nodo("adios",&contadorp, p,contadorp-1);
  NodoBlock* n4 = crear_nodo("adioooooos",&contadorp, p,contadorp-1);
  
  agregar_bloque(bc1, n1);
  agregar_bloque(bc1, n2);
  agregar_bloque(bc1, n3);
  agregar_bloque(bc1, n4);

  imprimir_lista (bc1);

 

  _blockFederada* bf = crear_red_federada(2);
  agregar_blockchain(bf, bc1);
  agregar_blockchain(bf, bc2);
  imprimir_lista (bc2);
   
  bf -> arbol_validacion = crear_arbol_validacion(bf -> cantidad_blocks);

  int *prueba = extraer_ids_hojas(bf);

  for (int i = 0; i < bf -> cantidad_blocks; i++)printf("%d",prueba[i]);

  bf -> arbol_validacion = construir_arbol(extraer_ids_hojas(bf),calcular_capacidad_hojas(bf -> cantidad_blocks) );

  alta(2 , bf, bf -> arbol_validacion,"gigachad" ,&contadorp, p);

  imprimir_lista(&(bf->datos[2]));

  imprimir_arbol(bf -> arbol_validacion);

  

  liberar_lista(bc1);


  return 0;
}