/*
    UNIVERSIDADE FEDERAL DO RIO GRANDE DO SUL
    INF01202 - ALGORITMOS E PROGRAMAÇÃO

    ATIVIDADE PRÁTICA
    TRABALHO FINAL DA DISCIPLINA

    ALUNOS: FELIPE GALLOIS E HENRIQUE CARNIEL DA SILVA
    MATRÍCULAS: 333713 E 335626

    ESTE PROGRAMA É UM JOGO INSPIRADO NO CLÁSSICO DOS ANOS 1980, DANGEROUS
    DAVE, E É PARTE DO TRABALHO FINAL DE AVALIAÇÃO DA DISCIPLINA DE ALGORITMOS
    E PROGRAMAÇÃO DO SEGUNDO SEMESTRE DE 2021.
*/

#include <stdio.h>

#include "Constantes.h"

/* ALGORITMO BUBBLESORT */

void BubbleSort(int *vet, int tamanho) {

    int fim = tamanho - 1, i, continua, aux;

    do {
        continua = 0;

        for (i = 0; i < fim; i++) {

            if(vet[i] < vet[i + 1]) {
                aux = vet[i];
                vet[i] = vet[i + 1];
                vet[i + 1] = aux;
                continua = 1;
            }
        }

        fim--;

    } while (continua);
}

/* ATUALIZA O RANKING NO ARQUIVO */

void AtualizaRanking(int pontuacao) {

    int ranking[TAM_RANKING] = { 0 }, i;

    FILE *arquivo = fopen(FRANKING ,"r");

    if(arquivo) {

        for (i = 0; i < TAM_RANKING; i++) {
            fscanf(arquivo, "%d", &ranking[i]);
        }

        fclose(arquivo);

    }

    if (pontuacao > ranking[TAM_RANKING - 1]) {

        ranking[TAM_RANKING - 1] = pontuacao;
        BubbleSort(ranking, TAM_RANKING);
    }

    arquivo = fopen(FRANKING ,"w");

    if (arquivo) { //GUARDA NO ARQUIVO RANKING OS DADOS

        for (i = 0; i < TAM_RANKING; i++) {
            fprintf(arquivo, "%d\n", ranking[i]);
        }

        fclose(arquivo);

    }
}