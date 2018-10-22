#ifndef ORDENADORES_H
#define ORDENADORES_H

void imprimir_ordenacao(char * texto, int *saida, int tamanho);
void transf_entrada_to_saida(int * entrada, int * saida, int tamanho);
void bubble_sort(int * entrada, int * saida, int tamanho);
void selection_sort (int * entrada, int * saida, int tamanho);
void insertion_sort(int * entrada, int * saida, int tamanho);
void radix_sort(int * entrada, int * saida, int tamanho);
int partition_( int *vetorDesordenado, int posicaoInicio, int posicaoFim );
void quickSort( int *vetorDesordenado, int posicaoInicio, int posicaoFim );
void merge_sort( int *vetorDesorndeado, int posicaoInicio, int posicaoFim );

#endif // ORDENADORES_H
