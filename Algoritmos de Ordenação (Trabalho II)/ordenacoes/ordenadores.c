#include "ordenadores.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimir_dados(char* texto, int tamanho, double time, long long int comparacoes){
    printf("Algoritmo: %s\n", texto);
    printf("Tamanho: %d elementos\n", tamanho);
    if (comparacoes != 0) printf("Comparacoes: %lld\n", comparacoes);
    printf("Tempo: %lf seg\n", time);
}

void transf_entrada_to_saida(int * entrada, int * saida, int tamanho){
    int cont;
    for(cont = 0; cont < tamanho; cont++){
        saida[cont] = entrada[cont];
    }
}

void bubble_sort(int * entrada, int * saida, int tamanho){
    clock_t tempo;
    int contador, aux, i;
    long long int comparacoes = 0;
    transf_entrada_to_saida(entrada, saida, tamanho);
    tempo = clock();
    for (contador = 1; contador < tamanho; contador++) {
        for (i = 0; i < tamanho - 1; i++) {
            if (saida[i] > saida[i + 1]) {
                comparacoes++;
                aux = saida[i];
                saida[i] = saida[i + 1];
                saida[i + 1] = aux;
            }
        }
    }
    tempo = clock() - tempo;
    imprimir_dados("Bubble Sort", tamanho, ((double) tempo)/CLOCKS_PER_SEC, comparacoes);
}

void selection_sort (int * entrada, int * saida, int tamanho) {
    int i, j, min, aux;
    long long int comparacoes = 0;
    clock_t tempo;
    transf_entrada_to_saida(entrada, saida, tamanho);
    tempo = clock();
    for (i = 0; i < (tamanho - 1); i++) {
        min = i;
        for (j = i+1; j < tamanho; j++) {
            if (saida[j] < saida[min]) {
                comparacoes++;
                min = j;
            }
        }
        if (i != min) {
            comparacoes++;
            aux = saida[i];
            saida[i] = saida[min];
            saida[min] = aux;
        }
    }
    tempo = clock() - tempo;
    imprimir_dados("Selection Sort", tamanho, ((double) tempo)/CLOCKS_PER_SEC, comparacoes);
}

void insertion_sort(int * entrada, int * saida, int tamanho){
	int i = 0, j = 0, valor;
	long long int comparacoes = 0;
	clock_t tempo;
	transf_entrada_to_saida(entrada, saida, tamanho);
	tempo = clock();
	for(i = 1; i < tamanho; i++){
	    valor = saida[i];
	    j = -1 + i;
	    while (saida[j] > valor && 0 <= j){
            comparacoes++;
	    	saida[j+1] = saida[j];
            --j;
	    }
	    saida[j+1] = valor;
	}
	tempo = clock() - tempo;
	imprimir_dados("Insertion Sort", tamanho, ((double) tempo)/CLOCKS_PER_SEC, comparacoes);
}

void radix_sort(int * entrada, int * saida, int tamanho) {
    int i, *b, exp = 1;
    clock_t tempo;
    transf_entrada_to_saida(entrada, saida, tamanho);
    tempo = clock();
    int maior = saida[0];
    b = (int *)calloc(tamanho, sizeof(int));
    for (i = 0; i < tamanho; i++) {
        saida[i] = entrada[i];//insere no vetor saida
        if (entrada[i] > maior)
    	    maior = entrada[i];
    }
    while (maior/exp > 0) {
        int bucket[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    	for (i = 0; i < tamanho; i++)
    	    bucket[(saida[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(saida[i] / exp) % 10]] = saida[i];
    	for (i = 0; i < tamanho; i++)
    	    saida[i] = b[i];
    	exp *= 10;
    }
    free(b);
    tempo = clock() - tempo;
    imprimir_dados("Radix Sort", tamanho, ((double) tempo)/CLOCKS_PER_SEC, 0);
}

int partition_( int *vetorDesordenado, int posicaoInicio, int posicaoFim, long long int * comparacoes){
    int x,i,j,auxiliar;
    x = vetorDesordenado[posicaoInicio];
    i = posicaoInicio - 1;
    j = posicaoFim + 1;
    for(;;){
        do { j--; (*comparacoes)++;} while( vetorDesordenado[j] > x );
        do { i++; (*comparacoes)++;} while( vetorDesordenado[i] < x );

        if (i < j){
            (*comparacoes)++;
            auxiliar = vetorDesordenado[i];
            vetorDesordenado[i] = vetorDesordenado[j];
            vetorDesordenado[j] = auxiliar;
        } else {
            return j;
        }
    }
}
void quickSort( int *vetorDesordenado, int posicaoInicio, int posicaoFim, long long int * comparacoes){
    int pivot;
    if (posicaoInicio < posicaoFim){
        (*comparacoes)++;
        pivot = partition_( vetorDesordenado, posicaoInicio, posicaoFim, comparacoes);
        quickSort(vetorDesordenado, posicaoInicio, pivot, comparacoes);
        quickSort(vetorDesordenado, pivot+1, posicaoFim, comparacoes);
    }
}

long long int merge_sort( int *vetorDesorndeado, int posicaoInicio, int posicaoFim ) {
    int i,j,k,metadeTamanho,*vetorTemp, comparacoes = 0;
    if ( posicaoInicio == posicaoFim ) {
        comparacoes++;
        return comparacoes;
    }
    metadeTamanho = ( posicaoInicio+posicaoFim )/2;
    comparacoes += merge_sort( vetorDesorndeado, posicaoInicio, metadeTamanho);
    comparacoes += merge_sort( vetorDesorndeado, metadeTamanho+1,posicaoFim );
    i = posicaoInicio;
    j = metadeTamanho+1;
    k = 0;
    vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim-posicaoInicio+1));

    while( i < metadeTamanho+1 || j  < posicaoFim+1 ){
        comparacoes++;
        if ( i == metadeTamanho+1 ){
            vetorTemp[k] = vetorDesorndeado[j];
            j++;
            k++;
        } else {
            comparacoes++;
            if (j==posicaoFim+1) {
                vetorTemp[k] = vetorDesorndeado[i];
                i++;
                k++;
            } else {
            comparacoes++;
            if (vetorDesorndeado[i] < vetorDesorndeado[j]) {
                vetorTemp[k] = vetorDesorndeado[i];
                i++;
                k++;
            } else {
                vetorTemp[k] = vetorDesorndeado[j];
                j++;
                k++;
            }
         }
      }
   }
   for( i = posicaoInicio; i <= posicaoFim; i++ ){
      vetorDesorndeado[i] = vetorTemp[i-posicaoInicio];
   }
   free(vetorTemp);
   return comparacoes;
}
