#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

No *cria_no(){
    return NULL;
}

No *adicionarNoNodo(No *n,char *str, int linha){
    int i;
    No *novo = (No*)malloc(sizeof(No));
    strcpy(novo->palavra, str);
    for(i = 0; i < 500; i++){
        novo->indices[i] = 0;
    }
    novo->indices[linha] = 1;
    novo->prox = n;
    return novo;
}



