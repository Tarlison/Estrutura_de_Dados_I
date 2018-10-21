#ifndef GERADOR_H
#define GERADOR_H

void gerador(FILE * arq, int quant);
void preenche_vetor(FILE * arq, int * vet);
void preenche_arq_saida(FILE * saida, int * vetor, int tamanho);

#endif // GERADOR_H
