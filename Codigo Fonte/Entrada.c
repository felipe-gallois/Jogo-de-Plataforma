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

#include "conio2.h"
#include "Constantes.h"
#include "Entrada.h"

void desenha_entrada(struct Entrada *entrada, char mapa[ALTMAX][LARGMAX]) {

    textcolor(BLACK);

    for(int y = 0; y < ALTMAX; y++)
    {
        for(int x = 0; x < LARGMAX; x++)
        {
            if(mapa[y][x] == 'O')
            {
                textbackground(LIGHTGRAY);
                putchxy(1 + 2 * x, 1 + y, ' ');

                textbackground(DARKGRAY);
                putchxy(2 + 2 * x, 1 + y, 64);

                entrada->x = 1 + 2 * x;
                entrada->y = 1 + y;
            }
        }
    }
}

void atualiza_entrada(struct Entrada *entrada) {

    textcolor(BLACK);

    textbackground(LIGHTGRAY);
    putchxy(entrada->x, entrada->y, ' ');

    textbackground(DARKGRAY);
    putchxy(entrada->x + 1, entrada->y, 64);
}