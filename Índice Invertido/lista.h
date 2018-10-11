#ifndef LISTA_H_
#define LISTA_H_

typedef struct nodo{
    char palavra[500]; //uma palavra fica aqui
    int indices[500]; //aqui fica as linhas e o numero de vezes que se repetiu em cada linha
    struct nodo *prox;
}No;



No *cria_no();
No *adicionarNoNodo(No *n,char *ch, int linha);



#endif // LISTA_H_
