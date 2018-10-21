#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gerador.h"
#include "ordenadores.h"

int main(){
    int opcao = 1,cont;
    int * entrada = (int*) malloc(sizeof(int)*100010);
    int * saida = (int*) malloc(sizeof(int)*100010);
    FILE * arqEnt = NULL;
    FILE * arqSai = NULL;
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
            if(arqEnt != NULL){//ve se o arquivo original de 100 elementos foi lido
                printf("Lendo o arquivo de 100 elementos\n");
                preenche_vetor(arqEnt, entrada);// os arquivos são inseridos no vetor
                fclose(arqEnt);

                bubble_sort(entrada, saida, 100);
                arqSai = fopen("saida_100_bubble.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 100);
                    printf("Arquivo ordenado bubble de 100 elem. gerado\n");
                    fclose(arqSai);//preenche u arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado bubble de 100 elem. nao foi gerado\n");
                }

                selection_sort(entrada, saida, 100);
                arqSai = fopen("saida_100_selection.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 100);
                    printf("Arquivo ordenado selection de 100 elem. gerado\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado selection de 100 elem. nao foi gerado\n");
                }

                insertion_sort(entrada, saida, 100);
                arqSai = fopen("saida_100_insertion.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 100);
                    printf("Arquivo ordenado insertion de 100 elem. gerado\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado insertion de 100 elem. nao foi gerado\n");
                }
                /*for(cont = 0; cont < 100; cont++){//apagar essas linhas depois
                    printf("[%d] ", saida[cont]);
                } printf("\n");*/

            } else {
                printf("Arquivo de 100 nao foi lido\n");
            }

            break;
        }
    }
    return 0;
}
