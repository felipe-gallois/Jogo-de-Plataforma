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

#include "conio2.h"
#include "Constantes.h"
#include "Placar.h"

/* DESENHA O PLACAR NO CONSOLE */

void desenha_placar(placar_t *placar) {

    textbackground(BLACK);
    textcolor(LIGHTGREEN);

    cputsxy(15, 3, "PONTUACAO");

    char pontos[6];
    sprintf(pontos, "%05d", placar->pontos);
    cputsxy(17, 4, pontos);

    cputsxy((int) (LARGMAX - 2), 3, "NIVEL");

    char nivel[2];
    sprintf(nivel, "%d", placar->nivel);
    cputsxy(((int) (LARGMAX - 2)) + 2, 4, nivel);

    cputsxy((int) (LARGMAX * 2 - 18), 3, "DAVES");

    char vidas[2];
    sprintf(vidas, "%d", placar->vidas);
    cputsxy(((int) (LARGMAX * 2 - 18)) + 2, 4, vidas);

    placar->atualizado = 1;
}

/* ATUALIZA O PLACAR */

void atualiza_placar(placar_t *placar) {

    textbackground(BLACK);
    textcolor(LIGHTGREEN);

    char pontos[6];
    sprintf(pontos, "%05d", placar->pontos);
    cputsxy(17, 4, pontos);

    char nivel[2];
    sprintf(nivel, "%d", placar->nivel);
    cputsxy(((int) (LARGMAX - 2)) + 2, 4, nivel);

    char vidas[2];
    sprintf(vidas, "%d", placar->vidas);
    cputsxy(((int) (LARGMAX * 2 - 18)) + 2, 4, vidas);

    placar->atualizado = 1;
}