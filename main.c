#include "main.h"
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "generador_primos.h"
#include "arbol_validacion.h"


void alta(int id_bc, _blockFederada* red, arbol_v* arbol, char* mensaje, int* contadorp, int* contadorbc, int* primos) {
  

  if(id_bc >= red ->cantidad_blocks){
    
    id_bc = red -> cantidad_blocks;
    NodoBlock* nuevo = crear_nodo(mensaje, contadorp,primos, 0);

    blockChain* block= crear_block_chain(contadorbc);
    agregar_blockchain(red,block);
    agregar_bloque(block, nuevo);
  
    liberar_arbol_validacion(red ->arbol_validacion);
    
  
    int *ids_hojas = extraer_ids_hojas(red);
    red -> arbol_validacion = construir_arbol_validacion(ids_hojas, red -> cantidad_blocks);

    free(ids_hojas);

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

  NodoBlock* nuevo = crear_nodo(mensaje, contadorp,primos, id_ant );

  agregar_bloque(block, nuevo);

  actualizar_hoja(arbol, id_bc, (block -> ultimo) -> id_actual);




}



void actualizacion(_blockFederada* bf, int id_bc, int id_n, char* nm,  int* c,  int* p, arbol_v* arbol){

  blockChain* hola = buscar_blockchain_por_id(bf, id_bc);

  NodoBlock* temp = buscar_nodo_por_id(hola, id_n);

  temp->id_actual = p[(*c)];

 printf("\n\n\n%s\n\n\n",temp -> mensaje );
    
  free(temp->mensaje);
  temp->mensaje = (char*)malloc(strlen(nm) + 1); 
  strcpy(temp->mensaje, nm);

  (*c)++;
  temp = temp->sig;

  while(temp){
    temp->id_actual = p[(*c)];
    temp-> id_anterior = p [ (*c)-1];
    free(temp ->mensaje);
    temp ->mensaje = malloc(strlen(nm) + 1);
    strcpy(temp -> mensaje, nm);
    (*c)++;
    temp = temp -> sig;
  }

 

  actualizar_hoja(arbol, id_bc, (hola -> ultimo) -> id_actual);
  
}

int validacion(_blockFederada* bf, arbol_v* arbol){

  int prop_heap = 0;
  int prop_raiz = 0;

  for(int i = 0;i < bf -> cantidad_blocks &&  arbol -> raiz_valor > arbol -> hojas[i]; i++){
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

 

 _blockFederada* bf = crear_red_federada(2);
  bf->arbol_validacion = crear_arbol_validacion(2);
  printf("Sistema listo.\n\n");

  
  printf("\n================ ALTA ================\n");
  printf("\n Agrego nodo a blockchain 0 (nueva)\n");
  alta(0, bf, bf -> arbol_validacion, "profe", &contadorp, &contadorbc, p);
  imprimir_arbol_validacion(bf->arbol_validacion);
  printf("\n Agrego nodo a blockchain 1 (nueva)\n");
  alta(1, bf,bf ->arbol_validacion, "perdiste", &contadorp, &contadorbc, p);
  imprimir_arbol_validacion(bf->arbol_validacion);
  printf("\n Agrego otro nodo a la blockchain 0\n");
  alta(0, bf, bf -> arbol_validacion, "el", &contadorp, &contadorbc, p);
  printf("\n Agrego blockchain 3(fuera de la capacidad inicial)");
  alta(3, bf, bf -> arbol_validacion, "juego", &contadorp, &contadorbc, p);
  imprimir_arbol_validacion(bf->arbol_validacion);

  printf("\n================ ACTUALIZACIÓN ================\n");
  printf("\n Imprimo blockchain 0 antes de la actualización:\n");
  imprimir_lista(bf->datos[0]);
  
  printf("\n Actualizo nodo con ID 2 en blockchain 0\n");
  actualizacion(bf, 0, 2, "mensaje modificado", &contadorp, p, bf -> arbol_validacion);
  
  printf("\n Estado de la blockchain 0 despues de la actualización:\n");
  imprimir_lista(bf->datos[0]);
  printf("\n Árbol DESPUÉS de la actualización:\n");
  imprimir_arbol_validacion(bf->arbol_validacion);

  printf("\n================ VALIDACIÓN ================\n");
  printf(" Realizando validación total de la red ");
  printf("Resultado: %s\n", validacion(bf, bf ->arbol_validacion) ? "VÁLIDA" : "INVÁLIDA");
  printf("\n Validando subconjunto {0, 1} con valor esperado 39 (13*3) ");
  printf("Resultado: %s\n", validacion_sub(39, 0, 1, bf -> arbol_validacion) ? "CORRECTO" : "INCORRECTO");

  printf("\n Valido subconjunto {0, 1} con valor esperado 99, ");
  printf("Resultado: %s\n", validacion_sub(99, 0, 1, bf -> arbol_validacion) ? "CORRECTO" : "INCORRECTO");

  printf("\nCambio manualmente el valor de la raiz a una incorrecta (0)");
  bf -> arbol_validacion -> raiz_valor = 0;
  printf("\nValido la red, ");
  printf("Resultado: %s\n", validacion(bf, bf ->arbol_validacion) ? "VÁLIDA" : "INVÁLIDA");
  
  printf("\n================ Libero toda la memoria ================\n");

  liberar_red_federada(bf);
  free(p);
  printf("Toda la memoria ha sido liberada.\n");
  // IMPORTANTE: libero la memoria pedida para el arreglo de números primos

  return 0;
}