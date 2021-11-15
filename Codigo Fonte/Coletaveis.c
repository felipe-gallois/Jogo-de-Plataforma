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
#include "Dave.h"
#include "Coletaveis.h"

/* DESENHA AMETISTA NA POSIÇÃO ESPECIFICADA */

void desenha_ametista(int posX, int posY) {

    textbackground(BLACK);
    textcolor(MAGENTA);

    putchxy(posX, posY, 6);
}

/* DESENHA SAFIRA NA POSIÇÃO ESPECIFICADA */

void desenha_safira(int posX, int posY) {

    textbackground(BLACK);
    textcolor(LIGHTCYAN);

    putchxy(posX, posY, 4);
}

/* DESENHA RUBI NA POSIÇÃO ESPECIFICADA */

void desenha_rubi(int posX, int posY) {

    textbackground(BLACK);
    textcolor(LIGHTRED);

    putchxy(posX, posY, 4);
}

/* DESENHA ANEL NA POSIÇÃO ESPECIFICADA */

void desenha_anel(int posX, int posY) {

    textbackground(BLACK);
    textcolor(YELLOW);

    putchxy(posX, posY, 'o');
}

/* DESENHA COROA NA POSIÇÃO ESPECIFICADA */

void desenha_coroa(int posX, int posY) {

    textbackground(BLACK);
    textcolor(YELLOW);

    putchxy(posX, posY, 14);
}

/* DESENHA JETPACK NA POSIÇÃO ESPECIFICADA */

void desenha_jetpack(int posX, int posY) {

    textbackground(GREEN);
    textcolor(BLACK);

    putchxy(posX, posY, '"');
}

/* DESENHA TROFEU NA POSIÇÃO ESPECIFICADA */

void desenha_trofeu(int posX, int posY) {

    textbackground(BLACK);
    textcolor(YELLOW);

    putchxy(posX, posY, 'T');
}

/* DESENHA TODOS OS COLETÁVEIS DO MAPA */

void DesenhaColetaveis(char mapa[ALTMAX][LARGMAX], struct Coletaveis itens[MAXCOLET]) {

    textbackground(BROWN);
    textcolor(BLACK);

    int n = 0;

    for(int y = 0; y < ALTMAX; y++)
    {
        for(int x = 0; x < LARGMAX; x++)
        {
            switch(mapa[y][x])
            {
                case '!':
                if(n < MAXCOLET) {
                    itens[n].tipo = AMETISTA;
                    itens[n].x = 1 + 2 * x;
                    itens[n].y = 1 + y;
                    desenha_ametista(1 + 2 * x, 1 + y);
                    n++;
                }
                break;
                case '@':
                if(n < MAXCOLET) {
                    itens[n].tipo = SAFIRA;
                    itens[n].x = 1 + 2 * x;
                    itens[n].y = 1 + y;
                    desenha_safira(1 + 2 * x, 1 + y);
                    n++;
                }
                break;
                case '#':
                if(n < MAXCOLET) {
                    itens[n].tipo = RUBI;
                    itens[n].x = 1 + 2 * x;
                    itens[n].y = 1 + y;
                    desenha_rubi(1 + 2 * x, 1 + y);
                    n++;
                }
                break;
                case '$':
                if(n < MAXCOLET) {
                    itens[n].tipo = ANEL;
                    itens[n].x = 1 + 2 * x;
                    itens[n].y = 1 + y;
                    desenha_anel(1 + 2 * x, 1 + y);
                    n++;
                }
                break;
                case '%':
                if(n < MAXCOLET) {
                    itens[n].tipo = COROA;
                    itens[n].x = 1 + 2 * x;
                    itens[n].y = 1 + y;
                    desenha_coroa(1 + 2 * x, 1 + y);
                    n++;
                }
                break;
                case 'J':
                if(n < MAXCOLET) {
                    itens[n].tipo = JETPACK;
                    itens[n].x = 1 + 2 * x;
                    itens[n].y = 1 + y;
                    desenha_jetpack(1 + 2 * x, 1 + y);
                    n++;
                }
                break;
                case 'T':
                if(n < MAXCOLET) {
                    itens[n].tipo = TROFEU;
                    itens[n].x = 1 + 2 * x;
                    itens[n].y = 1 + y;
                    desenha_trofeu(1 + 2 * x, 1 + y);
                    n++;
                }
                break;
            }
        }
    }
}

/* RETORNA O ITEM COLETADO, SE HOUVER */

int coleta(Dave *dave, struct Coletaveis itens[MAXCOLET]) {

    int retorno;

    for(int n = 0; n < MAXCOLET; n++) {

        if(itens[n].tipo != '\0') {

            if(itens[n].x == dave->posX) {

                if(itens[n].y == dave->posY || itens[n].y == dave->posY - 1) {

                    retorno = itens[n].tipo;
                    itens[n].tipo = '\0';
                    return retorno;
                }
            }
        }
    }

    return 0;
}