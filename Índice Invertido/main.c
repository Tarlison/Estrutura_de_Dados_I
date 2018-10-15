#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


int main(){
    FILE *f;
    f = fopen("teste.txt","r");

    No *l;
    No *inv;
    l = cria_no();
    inv = cria_no();



    int i = 0, j = 0;
    int li, co;
    char s[100],s1[30][150];
    while(fscanf(f," %[^\n]s",s) != EOF){

        li = 0, co = 0;
        for(j = 0 ; j <= (strlen(s)) ; j++){
            if(s[j]==' ' || s[j]=='\0'){
                s1[li][co]='\0';
                li++;
                co=0;
            }
            else{
                s1[li][co]=s[j];
                co++;
            }

        }
        for(j = 0 ; j < li ; j++){

            if(no_busca(l,s1[j])==0){
                l = insere_no(l, s1[j], i);
            }
            else
                 conflito_no(l,s1[j],i);
        }

        i++;
    }

    imprimir_no(l,i);
    fclose(f);
    liberar_no(l);
    return 0;

}
