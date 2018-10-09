#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
int main(){
    FILE *arquivo;
    arquivo = open("teste.txt","r");
    if (arquivo == NULL){
        printf("Houve um erro ao tentar abrir o arquivo.\n");
    }



}
