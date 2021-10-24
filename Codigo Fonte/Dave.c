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
#include "Dave.h"

int LocalizaDaveX(char mapa[ALTMAX][LARGMAX])
{
    for(int y = 0; y < ALTMAX; y++)
    {
        for(int x = 0; x < LARGMAX; x++)
        {
            if(mapa[y][x] == 'D')
            {
                return 1 + 2 * x;
            }
        }
    }

    return 0; //VALOR PADRÃO
}

int LocalizaDaveY(char mapa[ALTMAX][LARGMAX])
{
    for(int y = 0; y < ALTMAX; y++)
    {
        for(int x = 0; x < LARGMAX; x++)
        {
            if(mapa[y][x] == 'D')
            {
                return 1 + y;
            }
        }
    }

    return 0; //VALOR PADRÃO
}

void ApagaDave(Dave *dave)
{
    textbackground(BLACK);
    putchxy(dave->posX, dave->posY, ' ');
    putchxy(dave->posX, dave->posY - 1, ' ');
}

void DesenhaDave(Dave *dave, int posX, int posY)
{
    dave->posX = posX;
    dave->posY = posY;

    textbackground(WHITE);
    textcolor(BLACK);

    putchxy(posX, posY - 1, 1); //ROSTO

    textbackground(LIGHTBLUE);
    putchxy(posX, posY, 19); //PERNAS
}