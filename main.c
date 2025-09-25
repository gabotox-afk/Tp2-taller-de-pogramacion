#include "main.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "generador_primos.h"
#include "arbol_validacion.h"


void alta(int id_bc, _blockFederada* red, arbol_v* arbol, char* mensaje, int* contador_primos, int* contador_bc, int* primos) {
  

  if(id_bc >= red ->cantidad_blocks){
    
    id_bc = red -> cantidad_blocks;
    NodoBlock* nuevo = crear_nodo(mensaje, contador_primos,primos, 0);

    blockChain* block= crear_block_chain(contador_bc);
    agregar_blockchain(red,block);
    agregar_bloque(block, nuevo);
  
    liberar_arbol_validacion(red ->arbol_validacion);
    
  
    
    int *ids_hojas = extraer_ids_hojas(red);
    red -> arbol_validacion = construir_arbol_validacion(ids_hojas, red -> cantidad_blocks);

    return;
  }

  blockChain* block = buscar_blockchain_por_id( red, id_bc);

  int id_ant;

  if(block -> ultimo != NULL){
    id_ant = block -> ultimo -> id_actual;
  }
  else{
    id_ant = 0;
  }

  NodoBlock* nuevo = crear_nodo(mensaje, contador_primos,primos, id_ant );

  agregar_bloque(block, nuevo);

  actualizar_hoja(arbol, id_bc, (block -> ultimo) -> id_actual);




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

int validacion(_blockFederada* bf, arbol_v* arbol){

  int prop_heap = 0;
  int prop_raiz = 0;

  for(int i = 0; arbol -> raiz_valor > arbol -> hojas[i] && i < bf -> cantidad_blocks; i++){
    if(i == bf -> cantidad_blocks -1) prop_heap += 1;
  }
  
  int multiplicacion = 1;
  
  for(int i = 0; i< bf -> cantidad_blocks; i ++)
    multiplicacion *= arbol ->hojas[i];

   return (multiplicacion == arbol -> raiz_valor && prop_heap);

}

int validacion_sub(int vp, int min, int max, arbol_v *arbol){
  
  int valor_subconjunto = calcular_valor_subconjunto(arbol,min,max );

  return (vp == valor_subconjunto);
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
 

  blockChain*bc1= crear_block_chain(&contadorbc);
  blockChain*bc2= crear_block_chain(&contadorbc);


  NodoBlock* n1 = crear_nodo("hola",&contadorp, p,0);
  NodoBlock* n2 = crear_nodo("como",&contadorp, p,2);
  NodoBlock* n3 = crear_nodo("adios",&contadorp, p,3);
  NodoBlock* n4 = crear_nodo("adioooooos",&contadorp, p,5);
  NodoBlock* n5 = crear_nodo("papotes",&contadorp,p,0 );
  agregar_bloque(bc1, n1);
  agregar_bloque(bc1, n2);
  agregar_bloque(bc1, n3);
  agregar_bloque(bc1, n4);

  imprimir_lista (bc1);
  

 

  _blockFederada* bf = crear_red_federada(2);
  agregar_blockchain(bf, bc1);
  agregar_blockchain(bf, bc2);

  agregar_bloque(bc2,n5 );

  imprimir_lista (bc2);
 
   
  bf -> arbol_validacion = crear_arbol_validacion(bf -> cantidad_blocks);

  int *prueba = extraer_ids_hojas(bf);

  for (int i = 0; i < bf -> cantidad_blocks; i++)printf("%d",prueba[i]);

  bf -> arbol_validacion = construir_arbol_desde_red(bf);

  imprimir_arbol_validacion(bf ->arbol_validacion);

  
  printf("\n\nJUSTO ANTES DE ALTA\n\n");

  alta(4 , bf, bf -> arbol_validacion,"gigachad" ,&contadorp, &contadorbc, p); 

  //VALIDACION VERIFICADO

  //VALIDACION SUBCONJUNTO VERIFICADO


  // actualizacion(bf, 0,3, "papota",&contadorp,p,bf ->arbol_validacion ); VERIFICADO


  imprimir_lista(bc1);

  imprimir_arbol_validacion(bf -> arbol_validacion);


  liberar_lista(bc1);

  free(p);



  return 0;
}