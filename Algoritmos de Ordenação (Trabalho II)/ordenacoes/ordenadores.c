#include "ordenadores.h"
#include <stdio.h>
#include <stdlib.h>

void imprimir_ordenacao(char * texto, int *saida, int tamanho){
    int contador;
    printf("%s - %d elementos: \n", texto, tamanho);
    for (contador = 0; contador < tamanho; contador++){
        printf("[%d]", saida[contador]);
    }printf("\n");
}

void transf_entrada_to_saida(int * entrada, int * saida, int tamanho){
    int cont;
    for(cont = 0; cont < tamanho; cont++){
        saida[cont] = entrada[cont];
    }
}

void bubble_sort(int * entrada, int * saida, int tamanho){
    int contador, aux, i;
    transf_entrada_to_saida(entrada, saida, tamanho);
    for (contador = 1; contador < tamanho; contador++) {
        for (i = 0; i < tamanho - 1; i++) {
            if (saida[i] > saida[i + 1]) {
                aux = saida[i];
                saida[i] = saida[i + 1];
                saida[i + 1] = aux;
            }
        }
    }
    imprimir_ordenacao("Bubble Sort", saida, tamanho);
}

void selection_sort (int * entrada, int * saida, int tamanho) {
    int i, j, min, aux;
    transf_entrada_to_saida(entrada, saida, tamanho);
    for (i = 0; i < (tamanho - 1); i++) {
        min = i;
        for (j = i+1; j < tamanho; j++) {
            if (saida[j] < saida[min]) {
                min = j;
            }
        }
        if (i != min) {
            aux = saida[i];
            saida[i] = saida[min];
            saida[min] = aux;
        }
    }
    imprimir_ordenacao("Selection Sort", saida, tamanho);
}

void insertion_sort(int * entrada, int * saida, int tamanho){
	int i = 0, j = 0, valor;
	transf_entrada_to_saida(entrada, saida, tamanho);
	for(i = 1; i < tamanho; i++){
	    valor = saida[i];
	    j = -1 + i;
	    while (saida[j] > valor && 0 <= j){
	    	saida[j+1] = saida[j];
            --j;
	    }
	    saida[j+1] = valor;
	}
	imprimir_ordenacao("Insertion Sort", saida, tamanho);
}

void radix_sort(int * entrada, int * saida, int tamanho) {
    int i, *b, exp = 1;
    transf_entrada_to_saida(entrada, saida, tamanho);
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
    imprimir_ordenacao("Radix Sort", saida, tamanho);
}

int partition_( int *vetorDesordenado, int posicaoInicio, int posicaoFim ){
   int x,i,j,auxiliar;
   x = vetorDesordenado[posicaoInicio];
   i = posicaoInicio - 1;
   j = posicaoFim + 1;
   for(;;){
      do { j--; } while( vetorDesordenado[j] > x );
      do { i++; } while( vetorDesordenado[i] < x );

      if (i < j){
         auxiliar = vetorDesordenado[i];
         vetorDesordenado[i] = vetorDesordenado[j];
         vetorDesordenado[j] = auxiliar;
      } else {
         return j;
      }
   }
}
void quickSort( int *vetorDesordenado, int posicaoInicio, int posicaoFim ){
   int pivot;
   if (posicaoInicio < posicaoFim){
      pivot = partition_( vetorDesordenado, posicaoInicio, posicaoFim);
      quickSort( vetorDesordenado, posicaoInicio, pivot);
      quickSort(vetorDesordenado, pivot+1, posicaoFim);
   }
}

void merge_sort( int *vetorDesorndeado, int posicaoInicio, int posicaoFim ) {
   int i,j,k,metadeTamanho,*vetorTemp;
   if ( posicaoInicio == posicaoFim ) return;
   metadeTamanho = ( posicaoInicio+posicaoFim )/2;
   merge_sort( vetorDesorndeado, posicaoInicio, metadeTamanho);
   merge_sort( vetorDesorndeado, metadeTamanho+1,posicaoFim );
   i = posicaoInicio;
   j = metadeTamanho+1;
   k = 0;
   vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim-posicaoInicio+1));

   while( i < metadeTamanho+1 || j  < posicaoFim+1 ){
      if ( i == metadeTamanho+1 ){
 	vetorTemp[k] = vetorDesorndeado[j];
         j++;
         k++;
      }
      else{
         if (j==posicaoFim+1) {
            vetorTemp[k] = vetorDesorndeado[i];
            i++;
            k++;
         }
         else {
            if (vetorDesorndeado[i] < vetorDesorndeado[j]) {
               vetorTemp[k] = vetorDesorndeado[i];
               i++;
               k++;
            }
            else{
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
}
