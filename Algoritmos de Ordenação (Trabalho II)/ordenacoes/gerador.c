#include <stdio.h>
#include <stdlib.h>
#include "gerador.h"

void gerador(FILE * arq, int quant){
    int cont;
    for(cont = 0; cont < quant; cont++){
        fprintf(arq, "%d\n", rand()%10000);
    }
}
