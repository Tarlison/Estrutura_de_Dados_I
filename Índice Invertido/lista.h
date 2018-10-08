#ifndef LISTA_H_
#define LISTA_H_

typedef struct nodo{
    int linha;
    int pos_linha;
    struct nodo *prox;
}No;

No *cria_no();


#endif // LISTA_H_
