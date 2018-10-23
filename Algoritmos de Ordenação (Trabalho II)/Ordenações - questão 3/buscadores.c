int pesquisa_binaria ( int *entrada, int chave , int tamanho){
    int inf,sup,meio;
    inf=0;
    sup=tamanho-1;
    while (inf<=sup){
        meio=(inf+sup)/2;
        if (chave==entrada[meio])
            return meio;
        else if (chave<entrada[meio])
            sup=meio-1;
        else
            inf=meio+1;
    }
    return -1;
}

int buscaSequencial(int *vetor, int chave, int tamanho){
    int i = 0;
    for(i = 0; i < tamanho; i++){
        if(chave == vetor[i])
            return i;
    }
        return -1;
}
