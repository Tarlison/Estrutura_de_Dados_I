#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
int main(){
    FILE *arquivo;
    int c,auxC = 0;
    arquivo = fopen("teste.txt.txt","r");
    if (arquivo == NULL){
        printf("Houve um erro ao tentar abrir o arquivo.\n");
    }
    while((c = fgetc(arquivo)) != EOF){
        printf("Caractere lido: %c\n", c);
        if(c != ' '){
            auxC++;
        }
    }
    printf("QUANTIDADE DE CARACTERES: %d", auxC);


    if((c == EOF) && (feof(arquivo) == 0) && (ferror(arquivo) != 0))
        perror("Erro: fgetc");


    fclose(arquivo);


}
