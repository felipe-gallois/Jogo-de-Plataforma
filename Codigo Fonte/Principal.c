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

/* INCLUDES */
#include <stdlib.h> //MALLOC

/* ENUMS */
enum estados {MENU, JOGO, RANKING}; //ENUMERA OS POSSÍVEIS ESTADOS DO PROGRAMA

/* MAIN */
int main()
{
    /* INÍCIO DO PROGRAMA */

    int *encerrar = (int*) malloc(sizeof(int));

    *encerrar = 0;

    int *estado = (int*) malloc(sizeof(int));

    *estado = MENU;

    /* LOOP PRINCIPAL */

    while(!(*encerrar))
    {
        switch(*estado)
        {
            case MENU:
                ExecutaMenu(); //TODO
                break;
            case JOGO:
                ExecutaJogo(); //TODO
                break;
            case RANKING:
                ExecutaRanking(); //TODO
                break;
        }
    }

    /* FIM DO PROGRAMA */

    free(encerrar);
    free(estado);

    return 0;
}
