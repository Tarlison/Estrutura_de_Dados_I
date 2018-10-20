#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void radixsort(int vetor[], int tamanho) {
    int i, *b, exp = 1;
    int maior = vetor[0];
    b = (int *)calloc(tamanho, sizeof(int));
    for (i = 0; i < tamanho; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }
    while (maior/exp > 0) {
        int bucket[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vetor[i] / exp) % 10]++;/*guarda a quantidade de vezes que o dígito de uma ordem especifica
    	    (unidade, dezena, etc)*/
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];/*ele faz uma coisa doida aqui*/
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    	for()
    }
    free(b);
}


int main(){
    int cont, tamanho;
    srand(time(NULL));
    return 0;
}
