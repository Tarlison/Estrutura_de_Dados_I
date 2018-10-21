#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gerador.h"

int main(){
    int opcao = 1,cont;
    int * entrada = (int*) malloc(sizeof(int)*100010);
    int * saida = (int*) malloc(sizeof(int)*100010);
    FILE * arqEnt = NULL;
    srand(time(NULL));
    while(opcao != 0){
        printf("======PROJETO ORDENACAO======\n");
        printf("1 - Gerar Arquivos\n");
        printf("2 - Ordenar Arquivos\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            arqEnt = fopen("original_100.txt","w");
            gerador(arqEnt, 100);
            fclose(arqEnt);
            arqEnt = fopen("original_1000.txt","w");
            gerador(arqEnt, 1000);
            fclose(arqEnt);
            arqEnt = fopen("original_10000.txt","w");
            gerador(arqEnt, 10000);
            fclose(arqEnt);
            arqEnt = fopen("original_100000.txt","w");
            gerador(arqEnt, 100000);
            fclose(arqEnt);
            break;
        case 2:
            arqEnt = fopen("original_100.txt", "r");
            printf("Lendo o arquivo de 100 elementos\n");
            preenche_vetor(arqEnt, entrada);
            for(cont = 0; cont < 100; cont++){//apagar essas linhas depois
                printf("[%d] ", entrada[cont]);
            } printf("\n");
            fclose(arqEnt);
            break;
        }
    }
    return 0;
}
