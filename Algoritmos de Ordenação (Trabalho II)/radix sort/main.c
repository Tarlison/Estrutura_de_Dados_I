#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 20

void radixsort(int vetor[], int tamanho) {
    int i, *b, exp = 1, cont;
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
    	    bucket[i] += bucket[i - 1];/*ele faz uma coisa doida aqui, o vetor guarda agora a posição que começa
    	    um dígito, tipo: 0, 10, 11, 1, 2, 32, 12, 3, 4, 44, 35, 25, 5, 76, 57, 17, 7, 89, 9. o vetor guarda
    	    [2,2,3,1,2,3,1,3,0,2]*/
    	for (i = tamanho - 1; i >= 0; i--){
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];/**/
    	    /*for(cont = 0; cont < tamanho; cont++){
                printf("[%03d] ", b[cont]);}
                printf("<>\n");*/}
    	for (i = 0; i < tamanho; i++)
    	    vetor[i] = b[i];
        for(cont = 0; cont < tamanho; cont++)
            b[cont] = 0;
    	exp *= 10;
    	printf("\n");
    }
    free(b);
}


int main(){
    int cont, vetor[TAMANHO];
    srand(time(NULL));
    clock_t tempo = clock();
    for(cont = 0; cont < TAMANHO; cont++)
        vetor[cont] = rand()%1000;

    /*for(cont = 0; cont < TAMANHO; cont++)
        printf("[%03d] ", vetor[cont]);
    printf("\n");*/
    radixsort(vetor, TAMANHO);
    tempo = clock() - tempo;
    /*for(cont = 0; cont < TAMANHO; cont++)
        printf("[%03d] ", vetor[cont]);
    printf("\n");*/
    printf("Tempo decorrido: %lf\n", ((double)tempo)/CLOCKS_PER_SEC);
    return 0;
}
