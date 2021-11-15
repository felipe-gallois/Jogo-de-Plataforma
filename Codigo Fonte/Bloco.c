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

/**
* CONVERSÃO: 1 ELEMENTO DA MATRIZ (X, Y) CORRESPONDE A 2 ESPAÇOS NO CONSOLE
* LADO A LADO (POSX, POSY), LOGO POSX = 1 + 2X E POSY = 1 + Y. ATENÇÃO: A
* POSIÇÃO DO BLOCO É OBTIDA ATRAVÉS DA POSIÇÃO DA SUA METADE ESQUERDA.
*/

/* RETORNA CASO HAJA UM BLOCO NA POSIÇÃO ESPECIFICADA */

int TemBloco(int posx, int posy, char mapa[ALTMAX][LARGMAX]) {

    if(posx % 2 == 0) {
        posx--;
    }

    if(mapa[posy - 1][(posx - 1) / 2] == 'x') {
        return 1;
    }

    return 0;
}

/* DESENHA OS BLOCOS NO CONSOLE */

void DesenhaBlocos(char mapa[ALTMAX][LARGMAX]) {

    textbackground(RED);
    textcolor(BLACK);

    for(int y = 0; y < ALTMAX; y++) {

        for(int x = 0; x < LARGMAX; x++) {

            if(mapa[y][x] == 'x') {
                putchxy(1 + 2 * x, 1 + y, '#');
                putchxy(2 + 2 * x, 1 + y, '#');
            }
        }
    }
}