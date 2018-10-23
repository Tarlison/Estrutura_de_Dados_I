#ifndef ORDENADORES_H
#define ORDENADORES_H

void imprimir_dados(char* texto, int tamanho, double time, long long int comparacoes);
void transf_entrada_to_saida(int * entrada, int * saida, int tamanho);
void bubble_sort(int * entrada, int * saida, int tamanho);
void selection_sort (int * entrada, int * saida, int tamanho);
void insertion_sort(int * entrada, int * saida, int tamanho);
void radix_sort(int * entrada, int * saida, int tamanho);
int partition_( int *vetorDesordenado, int posicaoInicio, int posicaoFim, long long int * comparacoes);
void quickSort( int *vetorDesordenado, int posicaoInicio, int posicaoFim, long long int * comparacoes);
long long int merge_sort( int *vetorDesorndeado, int posicaoInicio, int posicaoFim );

#endif // ORDENADORES_H
