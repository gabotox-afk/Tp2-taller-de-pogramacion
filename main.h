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

