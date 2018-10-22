#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gerador.h"
#include "ordenadores.h"

int main(){
    int opcao = 1, cont;
    long long int comparacoes = 0;
    int * entrada = (int*) malloc(sizeof(int)*100010);
    int * saida = (int*) malloc(sizeof(int)*100010);
    FILE * arqEnt = NULL;
    FILE * arqSai = NULL;
    clock_t tempo;
    srand(time(NULL));
    while(opcao != 0){
        printf("======PROJETO ORDENACAO======\n");
        printf("1 - Gerar Arquivos\n");
        printf("2 - Ordenar Arquivos\n");
        printf("3 - buscar elementos\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            arqEnt = fopen("original_100.txt","w");
            if(arqEnt != NULL){
                printf("O arquivo de 100 elementos foi gerado\n");
                gerador(arqEnt, 100);
                fclose(arqEnt);
            } else {
                printf("O arquivo de 100 elementos nao foi gerado\n");
            }

            arqEnt = fopen("original_1000.txt","w");
            if(arqEnt != NULL){
                printf("O arquivo de 1000 elementos foi gerado\n");
                gerador(arqEnt, 1000);
                fclose(arqEnt);
            } else {
                printf("O arquivo de 1000 elementos nao foi gerado\n");
            }

            arqEnt = fopen("original_10000.txt","w");
            if(arqEnt != NULL){
                printf("O arquivo de 10000 elementos foi gerado\n");
                gerador(arqEnt, 10000);
                fclose(arqEnt);
            } else {
                printf("O arquivo de 10000 elementos nao foi gerado\n");
            }

            arqEnt = fopen("original_100000.txt","w");
            if(arqEnt != NULL){
                printf("O arquivo de 100000 elementos foi gerado\n");
                gerador(arqEnt, 100000);
                fclose(arqEnt);
            } else {
                printf("O arquivo de 100000 elementos nao foi gerado\n");
            }

            break;
        case 2:
            arqEnt = fopen("original_100.txt", "r");
            if(arqEnt != NULL){//ve se o arquivo original de 100 elementos foi lido
                printf("\nLendo o arquivo de 100 elementos\n\n");
                preenche_vetor(arqEnt, entrada);// os arquivos são inseridos no vetor
                fclose(arqEnt);

                bubble_sort(entrada, saida, 100);
                arqSai = fopen("saida_100_bubble.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 100);
                    printf("Arquivo ordenado bubble de 100 elem. gerado\n\n");
                    fclose(arqSai);//preenche u arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado bubble de 100 elem. nao foi gerado\n");
                }

                selection_sort(entrada, saida, 100);
                arqSai = fopen("saida_100_selection.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 100);
                    printf("Arquivo ordenado selection de 100 elem. gerado\n\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado selection de 100 elem. nao foi gerado\n");
                }

                insertion_sort(entrada, saida, 100);
                arqSai = fopen("saida_100_insertion.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 100);
                    printf("Arquivo ordenado insertion de 100 elem. gerado\n\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado insertion de 100 elem. nao foi gerado\n");
                }

                radix_sort(entrada, saida, 100);
                arqSai = fopen("saida_100_radix.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 100);
                    printf("Arquivo ordenado radix de 100 elem. gerado\n\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado radix de 100 elem. nao foi gerado\n");
                }

                transf_entrada_to_saida(entrada, saida, 100);
                tempo = clock();
                comparacoes = 0;
                quickSort(saida, 0, 99, &comparacoes);
                tempo = clock() - tempo;
                imprimir_dados("Quick Sort", 100, ((double) tempo)/CLOCKS_PER_SEC, comparacoes);
                arqSai = fopen("saida_100_quick.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 100);
                    printf("Arquivo ordenado quick de 100 elem. gerado\n\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado quick de 100 elem. nao foi gerado\n");
                }

                transf_entrada_to_saida(entrada, saida, 100);
                tempo = clock();
                comparacoes = merge_sort(saida, 0, 99);
                tempo = clock() - tempo;
                imprimir_dados("Merge Sort", 100, ((double) tempo)/CLOCKS_PER_SEC, comparacoes);
                arqSai = fopen("saida_100_merge.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 100);
                    printf("Arquivo ordenado merge de 100 elem. gerado\n\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado merge de 100 elem. nao foi gerado\n");
                }
                /*for(cont = 0; cont < 100; cont++){//apagar essas linhas depois
                    printf("[%d] ", saida[cont]);
                } printf("\n");*/
            } else {
                printf("Arquivo de 100 nao foi lido\n");
            }

            //INICIANDO A DE 1000 ELEMENTOS
            arqEnt = fopen("original_1000.txt", "r");
            if(arqEnt != NULL){//ve se o arquivo original de 1000 elementos foi lido
                printf("\nLendo o arquivo de 1000 elementos\n\n");
                preenche_vetor(arqEnt, entrada);// os arquivos são inseridos no vetor
                fclose(arqEnt);

                bubble_sort(entrada, saida, 1000);
                arqSai = fopen("saida_1000_bubble.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 1000);
                    printf("Arquivo ordenado bubble de 1000 elem. gerado\n\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado bubble de 1000 elem. nao foi gerado\n");
                }

                selection_sort(entrada, saida, 1000);
                arqSai = fopen("saida_1000_selection.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 1000);
                    printf("Arquivo ordenado selection de 1000 elem. gerado\n\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado selection de 1000 elem. nao foi gerado\n");
                }

                insertion_sort(entrada, saida, 1000);
                arqSai = fopen("saida_1000_insertion.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 1000);
                    printf("Arquivo ordenado insertion de 1000 elem. gerado\n\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado insertion de 1000 elem. nao foi gerado\n");
                }

                transf_entrada_to_saida(entrada, saida, 1000);
                tempo = clock();
                comparacoes = 0;
                quickSort(saida, 0, 999, &comparacoes);
                tempo = clock() - tempo;
                imprimir_dados("Quick Sort", 1000, ((double) tempo)/CLOCKS_PER_SEC, comparacoes);
                arqSai = fopen("saida_1000_quick.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 1000);
                    printf("Arquivo ordenado quick de 1000 elem. gerado\n\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado quick de 1000 elem. nao foi gerado\n");
                }

                transf_entrada_to_saida(entrada, saida, 1000);
                tempo = clock();
                comparacoes = merge_sort(saida, 0, 999);
                tempo = clock() - tempo;
                imprimir_dados("Merge Sort", 1000, ((double) tempo)/CLOCKS_PER_SEC, comparacoes);
                arqSai = fopen("saida_1000_merge.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 1000);
                    printf("Arquivo ordenado merge de 1000 elem. gerado\n\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado merge de 1000 elem. nao foi gerado\n");
                }

            } else {
                printf("Arquivo de 1000 nao foi lido\n");
            }

            arqEnt = fopen("original_10000.txt", "r");
            if(arqEnt != NULL){//ve se o arquivo original de 10000 elementos foi lido
                printf("\nLendo o arquivo de 10000 elementos\n\n");
                preenche_vetor(arqEnt, entrada);// os arquivos são inseridos no vetor
                fclose(arqEnt);

                bubble_sort(entrada, saida, 10000);
                arqSai = fopen("saida_10000_bubble.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 10000);
                    printf("Arquivo ordenado bubble de 10000 elem. gerado\n\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado bubble de 10000 elem. nao foi gerado\n");
                }

                selection_sort(entrada, saida, 10000);
                arqSai = fopen("saida_10000_selection.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 10000);
                    printf("Arquivo ordenado selection de 10000 elem. gerado\n\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado selection de 10000 elem. nao foi gerado\n");
                }

                insertion_sort(entrada, saida, 10000);
                arqSai = fopen("saida_100_insertion.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 10000);
                    printf("Arquivo ordenado insertion de 10000 elem. gerado\n\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado insertion de 10000 elem. nao foi gerado\n");
                }

                radix_sort(entrada, saida, 10000);
                arqSai = fopen("saida_10000_radix.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 10000);
                    printf("Arquivo ordenado radix de 10000 elem. gerado\n\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado radix de 10000 elem. nao foi gerado\n");
                }

                transf_entrada_to_saida(entrada, saida, 10000);
                tempo = clock();
                comparacoes = 0;
                quickSort(saida, 0, 9999, &comparacoes);
                tempo = clock() - tempo;
                imprimir_dados("Quick Sort", 10000, ((double) tempo)/CLOCKS_PER_SEC, comparacoes);
                arqSai = fopen("saida_100_quick.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 10000);
                    printf("Arquivo ordenado quick de 10000 elem. gerado\n\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado quick de 10000 elem. nao foi gerado\n");
                }

                transf_entrada_to_saida(entrada, saida, 10000);
                tempo = clock();
                comparacoes = merge_sort(saida, 0, 9999);
                tempo = clock() - tempo;
                imprimir_dados("Merge Sort", 10000, ((double) tempo)/CLOCKS_PER_SEC, comparacoes);
                arqSai = fopen("saida_10000_merge.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 10000);
                    printf("Arquivo ordenado merge de 10000 elem. gerado\n\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado merge de 10000 elem. nao foi gerado\n");
                }
            } else {
                printf("Arquivo de 10000 nao foi lido\n");
            }

            //INICIANDO A DE 100000 ELEMENTOS
            arqEnt = fopen("original_100000.txt", "r");
            if(arqEnt != NULL){//ve se o arquivo original de 100000 elementos foi lido
                printf("\nLendo o arquivo de 100000 elementos\n\n");
                preenche_vetor(arqEnt, entrada);// os arquivos são inseridos no vetor
                fclose(arqEnt);

                bubble_sort(entrada, saida, 100000);
                arqSai = fopen("saida_100000_bubble.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 100000);
                    printf("Arquivo ordenado bubble de 100000 elem. gerado\n\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado bubble de 100000 elem. nao foi gerado\n");
                }

                selection_sort(entrada, saida, 100000);
                arqSai = fopen("saida_100000_selection.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 100000);
                    printf("Arquivo ordenado selection de 100000 elem. gerado\n\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado selection de 100000 elem. nao foi gerado\n");
                }

                insertion_sort(entrada, saida, 100000);
                arqSai = fopen("saida_100000_insertion.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 100000);
                    printf("Arquivo ordenado insertion de 100000 elem. gerado\n\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado insertion de 100000 elem. nao foi gerado\n");
                }

                transf_entrada_to_saida(entrada, saida, 100000);
                tempo = clock();
                comparacoes = 0;
                quickSort(saida, 0, 99999, &comparacoes);
                tempo = clock() - tempo;
                imprimir_dados("Quick Sort", 100000, ((double) tempo)/CLOCKS_PER_SEC, comparacoes);
                arqSai = fopen("saida_100000_quick.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 100000);
                    printf("Arquivo ordenado quick de 100000 elem. gerado\n\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado quick de 100000 elem. nao foi gerado\n");
                }

                transf_entrada_to_saida(entrada, saida, 100000);
                tempo = clock();
                comparacoes = merge_sort(saida, 0, 99999);
                tempo = clock() - tempo;
                imprimir_dados("Merge Sort", 100000, ((double) tempo)/CLOCKS_PER_SEC, comparacoes);
                arqSai = fopen("saida_100000_merge.txt","w");
                if(arqSai != NULL){
                    preenche_arq_saida(arqSai, saida, 100000);
                    printf("Arquivo ordenado merge de 100000 elem. gerado\n\n");
                    fclose(arqSai);//preenche o arquivo para essa ordenação
                } else {
                    printf("Arquivo ordenado merge de 100000 elem. nao foi gerado\n");
                }

            } else {
                printf("Arquivo de 100000 nao foi lido\n");
            }
            break;
        case 3:
            for(cont = 0; cont < 10000;cont++){
                entrada[cont] = rand()%10000;
            }
            arqEnt = fopen("saida_100000_selection.txt", "r");
            if(arqEnt != NULL){
                printf("Arquivo foi aberto para pesquisa binaria\n");
                for(cont = 0; cont < 100000;cont++){
                    fscanf(arqEnt,"%d", &saida[cont]);
                }
                fclose(arqEnt);
                tempo = clock();
                for(cont = 0; cont < 10000; cont++){
                    pesquisa_binaria(entrada, saida[cont], 100000);
                }
                tempo = clock() - tempo;
                printf("Tempo na pesquisa binaria no vetor de 100.000 elementos: %lf seg\n", ((double)tempo)/CLOCKS_PER_SEC);
            } else {
                printf("Arquivo nao pode ser aberto para pesquisa binaria\n");
            }
            arqEnt = fopen("original_100000.txt", "r");
            if(arqEnt != NULL){
                printf("Arquivo foi aberto para busca sequencial\n");
                for(cont = 0; cont < 100000;cont++){
                    fscanf(arqEnt,"%d", &saida[cont]);
                }
                fclose(arqEnt);
                tempo = clock();
                for(cont = 0; cont < 10000; cont++){
                    buscaSequencial(entrada, saida[cont], 100000);
                }
                tempo = clock() - tempo;
                printf("Tempo na busca sequecial no vetor de 100.000 elementos: %lf seg\n", ((double)tempo)/CLOCKS_PER_SEC);
            } else {
                printf("Arquivo nao pode ser aberto para busca sequencial\n");
            }
        }
    }
    return 0;
}
