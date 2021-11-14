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

#ifndef RELIQUIAS_H
#define RELIQUIAS_H

enum coletaveis {AMETISTA = 1, SAFIRA, RUBI, ANEL, COROA, JETPACK, TROFEU};

struct Coletaveis {
    int tipo;
    int x;
    int y;
};

void DesenhaColetaveis(char mapa[ALTMAX][LARGMAX], struct Coletaveis itens[MAXCOLET]);

int coleta(Dave *dave, struct Coletaveis itens[MAXCOLET]);

#endif
