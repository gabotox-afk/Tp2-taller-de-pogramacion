#include "blockfederada.h"
#include <stdio.h>
#include <stdlib.h>

void modif_len(_blockFederada* bF, int l){
    l++;
    bF->len = l;
    _blockFederada **nuevosD= realloc ( bF->datos, l *sizeof(void*));
    bF ->datos= nuevosD;
}