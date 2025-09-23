#include "stdlib.h"
#include "stdio.h"
#include "generador_primos.h"
#include "main.h"

void alta(int id_b , _blockFederada* bf ,char* mensaje){
  
}

void actualizacion(_blockFederada* bf, int id_b, int id_n, char* nm){
  
}

int validacion(_blockFederada* bf){
  
}

int validacion_sub(int vp, int min, int max, _blockFederada bf){
  
}




int main() {
    int contadorp = 0 ;
    int contadorbf = 0;
  // Genero y muestro los primeros 100 números primos
  int *p = primos(100);
  for(int i = 0; i < 100; i++)
    printf("%d\n ",p[i]);


  // Uso los números primos

  // IMPORTANTE: libero la memoria pedida para el arreglo de números primos
  free(p);

  blockChain* bc1 = crear_block_chain(&contadorbf);
  blockChain* bc2 = crear_block_chain(&contadorbf);
  blockChain* bc3 = crear_block_chain(&contadorbf);
  


  return 0;
}
