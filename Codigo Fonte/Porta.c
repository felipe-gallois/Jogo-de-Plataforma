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
#include "Porta.h"

/* RETORNA SE A PORTA ESTÁ NA POSIÇÃO ESPECIFICADA */

int TemPorta(int posx, int posy, struct Porta *porta)
{
    if(posy == porta->y) {
        if(posx == porta->x || posx == porta->x + 1) {
            return 1;
        }
    }

    return 0;
}

/* DESENHA A PORTA */

void DesenhaPorta(char mapa[ALTMAX][LARGMAX], struct Porta *porta)
{
    textbackground(BROWN);
    textcolor(BLACK);

    for(int y = 0; y < ALTMAX; y++)
    {
        for(int x = 0; x < LARGMAX; x++)
        {
            if(mapa[y][x] == 'P')
            {
                putchxy(1 + 2 * x, 1 + y, ' ');
                putchxy(2 + 2 * x, 1 + y, 26);
                putchxy(1 + 2 * x, y, ' ');
                putchxy(2 + 2 * x, y, 26);

                porta->x = 1 + 2 * x;
                porta->y = 1 + y;
            }
        }
    }
}

/* ATUALIZA O DESENHO DA PORTA */

void AtualizaPorta(struct Porta *porta) {
    
    textbackground(BROWN);
    textcolor(BLACK);

    putchxy(porta->x, porta->y, ' ');
    putchxy(porta->x + 1, porta->y, 26);
    putchxy(porta->x, porta->y - 1, ' ');
    putchxy(porta->x + 1, porta->y - 1, 26);
}