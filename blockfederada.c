#include "blockfederada.h"
#include <stdio.h>
#include <stdlib.h>

void modif_len(_blockFederada* bF, int nueva_capacidad){
    nueva_capacidad++;
    bF->capacidad = nueva_capacidad;
    _blockFederada **nuevosD= realloc ( bF->datos, nueva_capacidad *sizeof(void*));
    bF ->datos= nuevosD;
}