#ifndef LISTA_H_
#define LISTA_H_
typedef struct nodo{
    char palavra[3000];
    int indice[300];
    struct nodo *prox;
}No;

No *cria_no(void);
No *insere_no(No *l, char *str, int linha);
No *conflito_no(No *l, char *str, int linha);
No *retira_no(No *l, char *str);
int no_vazio(No *l);
int no_busca(No *l, char *str);
void imprimir_no(No *l, int linha);
void liberar_no(No *l);

#endif // LISTA_H_
