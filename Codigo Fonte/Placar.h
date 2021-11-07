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

#ifndef PLACAR_H
#define PLACAR_H

typedef struct
{
    int atualizado;
    int pontos;
    int pontuacao_agregada;
    int nivel;
    int vidas;
} placar_t;

void desenha_placar(placar_t *placar);

void atualiza_placar(placar_t *placar);

#endif