#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

Palavra *cria_palavra(){
    return NULL;
}

No *cria_no(){
    return NULL;
}

No *add(Palavra *p,No* l, int x, int y){ //ponteiro da palavra que aponta para a lista,Lista que está a palavra, inteiro informando qual a linha que foi encontrado, int informando quantidade naquela linha;
    No *novo = (No*)malloc(sizeof(No)); //cria o NO para guardar a linha e a quantidade da palavra na linha;
    novo->linha = x; // coloca o int do numero em que a linha se encontra;
    novo->quant = y; //coloca  o int que informa a quantidade que a palavra apareceu na linha;
    novo->prox = l; //o ponteiro para o prox aponta para L pois o NO será colocado na primeira posição;
    if(l == NULL){
        novo->prox = NULL;
        l = novo;
    } else{
        l->prox = novo;
    }
    p->prox = l;
    return l;
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
