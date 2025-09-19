typedef struct _NodoBlock {
  int dato;
  int id;
  char mensaje;
  struct _NodoBlock *sig;
  struct _NodoBlock *ant;
} NodoBlock;

typedef struct _BlockFederada
{
    int dato;
    struct _BlockFederada *sig;
    struct _NodoBlock *primero;
    struct _NodoBlock *ultimo;
};
typedef struct _ABNodo {
  int dato;
  struct _ABNodo *izq, *der;
} ABNodo;


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
