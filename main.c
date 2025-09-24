#include "stdlib.h"
#include "stdio.h"
#include "generador_primos.h"
#include "main.h"

void alta(int id_b , _blockFederada* bf ,char* mensaje,  int* c,  int* p){
  
  NodoBlock* nuevo = crear_nodo(mensaje, c, p, (*c)-1);

  blockChain* bc = buscar_blockchain_por_id(bf, id_b);

  

}

void actualizacion(_blockFederada* bc, int id_b, int id_n, char* nm,  int* c,  int* p){
  
}

int validacion(_blockFederada* bc){
  
}

int validacion_sub(int vp, int min, int max, _blockFederada bc){
  
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

  NodoBlock* n1 = crear_nodo("hola",&contadorp, p,contadorp-1);
  NodoBlock* n2 = crear_nodo("como",&contadorp, p,contadorp-1);
  NodoBlock* n3 = crear_nodo("adios",&contadorp, p,contadorp-1);
  
  agregar_bloque(bc1, n1);
  agregar_bloque(bc1, n2);
  agregar_bloque(bc1, n3);

  imprimir_lista (bc1);

  if(buscar_nodo_por_id(bc1, 1)== NULL){
    printf("no existe");
    return 0;
  }
  printf("existe");



  liberar_lista(bc1);


  return 0;
}
