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

#include <windows.h>

#include "conio2.h"
#include "Entradas.h"
#include "Constantes.h"

int RecebeEntrada() {

    if(_kbhit())
    {
        int entrada = _getch();

        switch(entrada)
        {
            case 224:
                entrada = _getch();

                switch(entrada)
                {
                    case 72:
                        return CIMA;
                    case 75:
                        return ESQUERDA;
                    case 77:
                        return DIREITA;
                    case 80:
                        return BAIXO;
                    default:
                        return INVALIDO;
                }
            case 27:
                return ESC;
            case 83:
                return S;
            case 115:
                return S;
            case 78:
                return N;
            case 110:
                return N;
            case 32:
                return SPCBR;
            case 13:
                return ENTER;
            default:
                return INVALIDO;
        }
    }

    return -1;
}