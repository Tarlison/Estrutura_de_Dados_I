#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

No *cria_no(void){
    return NULL;
}

No *insere_no(No *l, char *str, int linha){
    int i;
    No *novo = (No*)malloc(sizeof(No));
    strcpy(novo->palavra,str);
    for(i = 0 ; i < 30 ; i++){
        novo->indice[i] = 0;
    }
    novo->indice[linha] = 1;
    novo->prox = l;
    return novo;
}

No *conflito_no(No *l, char *str, int linha){
    No *aux;
    aux = l;
    while(strcmp(aux->palavra,str) != 0){
        aux = aux -> prox;
    }
    if(strcmp(aux->palavra,str) == 0)
        aux->indice[linha]++;
}

No *retira_no(Lista* l, char *str){
    No *ant = NULL;
    No *p = l;

    while(p != NULL && strcmp(p->prox,str) != 0){
        ant = p;
        p = p->prox;
    }

    if(p == NULL){
        return l;
    }

    if(ant == NULL){
        l = p->prox;
    }
    else{
        ant->prox = p->prox;
    }
    free(p);
    return l;
}

int no_vazio(No *l){
    return(l == NULL);
}

int no_busca(No *l, char *str){
    No *aux;
    aux = l;
    while(aux != NULL){
        if(strcmp(aux->palavra,str) == 0)
            return 1;
        aux = aux->prox;
    }
    return 0;
}

void imprimir_no(No *l, int linha){
    No *aux;
    aux = l;
    int i = 0;
    while(aux != NULL){
            printf("%s ",aux->palavra);
        while(i < linha){
            printf("%d|%d ",i,aux->indice[i]);
            i++;
        }
        printf("\n");
        aux = aux->prox;
        i = 0;
    }
}

void liberar_no(No *l){
    No *aux = l;
    while(aux != NULL){
        No *aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
}


