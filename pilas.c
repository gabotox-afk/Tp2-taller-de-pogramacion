#include <stdio.h>
#include <stdlib.h>

typedef void (*FuncionVisitante) (void *dato);


typedef struct _Pila {
void **datos;
int ultimo;
int len;
} Pila;
//typedef struct _Pila{
//    int len;
//    int *datos;
//    int ultimo;
//}Pila;

void modif_len(Pila* p, int l){
    p->len =l;
    void **nuevosD= realloc ( p->datos, l *sizeof(void *));
    p->datos= nuevosD;
    if(p->ultimo >= l)
        p->ultimo = l-1;
}

Pila *pila_crear(int l){
    Pila *nuevo = malloc (sizeof(Pila));
    nuevo->len = l;
    nuevo->datos=malloc (l*sizeof(int));
    nuevo -> ultimo=-1;
    return nuevo;
}
int pila_es_vacia(Pila* pila){
    if( pila -> ultimo == -1)
        return 1;
    return 0;
    }
void* pila_tope(Pila* p){
    if (pila_es_vacia(p))
        return NULL;
    return p->datos[p->ultimo];
}
void pila_apilar(Pila* p, void *dato){
    if(p->ultimo +1 == p->len){
        modif_len(p,p->len +1);
    }

    if (p->ultimo == -1){
        p->ultimo = 0;
        p->datos[p->ultimo]= dato;   
        return;   
    }
    p->ultimo = p->ultimo +1;
    p->datos[p->ultimo] = dato;
}
void pila_desapilar(Pila* p){
    if(p->ultimo == -1){
        printf("la pila esta vacia");
        return;
    }
    p->ultimo = p->ultimo -1;

}
void pila_imprimir(Pila* p, FuncionVisitante f){
    for(int i = 0; i <= p-> ultimo; i++){
        f (p->datos[i]);
    }
}
void pila_destruir(Pila* p){
    if(!p) return;
    free (p->datos);
    free(p);
}

void imprimir_entero(void *d){
    printf("\n%d\n", *(int *)d);
}

int main(){
    Pila *pila = pila_crear(10);
    int *dato= malloc (sizeof(int));
    *dato=3;
    pila_apilar(pila, dato);
    pila_apilar(pila, dato);
    pila_apilar(pila, dato);
    pila_apilar(pila, dato);
    pila_apilar(pila, dato);
    pila_apilar(pila, dato);
    pila_apilar(pila, dato);
    pila_apilar(pila, dato);
    pila_apilar(pila, dato);
    pila_apilar(pila, dato);
    pila_apilar(pila, dato);
    pila_imprimir(pila,imprimir_entero);

    pila_destruir(pila);

    return 0;
}