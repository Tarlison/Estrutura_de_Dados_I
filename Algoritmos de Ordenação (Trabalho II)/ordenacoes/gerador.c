#include <stdio.h>
#include <stdlib.h>
#include "gerador.h"

void gerador(FILE * arq, int quant){
    int cont;
    if(arq != NULL){
        for(cont = 0; cont < quant; cont++){
            fprintf(arq, "%d\n", rand()%10000);
        }
    } else {
        printf("O arquivo de %d elementos não foi criado\n", quant);
    }

}

void preenche_vetor(FILE * arq, int * vet){
    int cont = 0;
    if(arq != NULL){
        while(fscanf(arq, "%d", &vet[cont]) != EOF){
            cont++;
        }
    } else {
        printf("O arquivo nao pode ser lido\n");
    }
}
