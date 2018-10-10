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
    for(i = 0;)

}

void imprimir(Palavra *p, No *l, int x, int y){ //minha cabeça bugou com tanto ponteiro nessa função
                                                //Então acho que ta errada kkkkk
                                                //Sorry, luigi :c
    Palavra *aux;
    aux = p;
    for(aux->prox->prox; aux->prox != NULL; aux->prox = aux->prox->prox){
        printf("(%d,%d)",aux->prox->linha,aux->prox->quant);
    }

}
