#ifndef LISTA_H_
#define LISTA_H_

typedef struct nodo{
    int linha;
    int quant;
    struct nodo *prox;
}No;

typedef struct palavra{
    struct nodo *prox;
}Palavra;

No *cria_no();
No *add(Palavra *p, No *l, int x, int y);
Palavra *cria_palavra();
void imprimir(Palavra *p, No *l, int x, int y);

#endif // LISTA_H_
