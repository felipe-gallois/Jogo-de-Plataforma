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

#ifndef DAVE_H
#define DAVE_H

#include "Constantes.h"

typedef struct Dave
{
    int posX, posY;
    int saltando; /* NÚMERO DE BLOCOS QUE DAVE PRECISA SALTAR */
    int aceleracao; /* -1 PARA ESQUERDA, 0 PARA SEM ACELERAÇÃO, 1 PARA DIREITA */
    int trofeu; // SE DAVE COLETOU O TROFEU
    int jetpack; // SE DAVE COLETOU A JETPACK
} Dave;

int LocalizaDaveX(char mapa[ALTMAX][LARGMAX]);

int LocalizaDaveY(char mapa[ALTMAX][LARGMAX]);

void DesenhaDave(Dave *dave, int posX, int posY);

void movimenta_dave(int entrada, Dave *dave, char mapa[ALTMAX][LARGMAX]);

#endif
