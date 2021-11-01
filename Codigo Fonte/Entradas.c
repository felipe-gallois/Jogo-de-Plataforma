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

//#include <ctype.h> //PARA TRABALHAR COM CARACTERES FORA DO PADRÃO ASCII
#include <windows.h>

#include "conio2.h" //_GETCH
#include "Entradas.h"
#include "Constantes.h"

int RecebeEntrada()
{
    if(_kbhit())
    {
        int entrada = _getch();

        switch(entrada)
        {
            case 224: //SETAS DO TECLADO
                entrada = _getch();

                switch(entrada)
                {
                    case 72: //PARA CIMA
                        return CIMA;
                    case 75: //PARA A ESQUERDA
                        return ESQUERDA;
                    case 77: //PARA A DIREITA
                        return DIREITA;
                    case 80: //PARA BAIXO
                        return BAIXO;
                    default:
                        return INVALIDO;
                }
            case 27: //ESC
                return ESC;
            case 83: //S MAIÚSCULO
                return S;
            case 115: //S MINÚSCULO
                return S;
            case 78: //N MAIÚSCULO
                return N;
            case 110: //N MINÚSCULO
                return N;
            case 32: //BARRA DE ESPAÇO
                return SPCBR;
            default:
                return INVALIDO;
        }
    }

    return -1;
}