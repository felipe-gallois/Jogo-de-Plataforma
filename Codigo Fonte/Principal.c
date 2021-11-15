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

#include <stdlib.h>

#include "conio2.h"
#include "Menu.h"
#include "Entradas.h"
#include "Jogo.h"
#include "Constantes.h"

int main() {

    int encerrar = 0, estado = ESTADOINI;
    int mapa = 1;

    while(!encerrar)
    {
        switch(estado)
        {
            case MENU:
            textbackground(BLACK); /* PARA NÃO COLORIR A TELA ACIDENTALMENTE */
            system("cls");
            ExecutaMenu(&estado, &encerrar);
            break;
            case JOGO:
            textbackground(BLACK); /* PARA NÃO COLORIR A TELA ACIDENTALMENTE */
            system("cls");
            ExecutaJogo(&estado, &encerrar, &mapa);
            break;
            case RANKING:
            textbackground(BLACK); /* PARA NÃO COLORIR A TELA ACIDENTALMENTE */
            system("cls");
            /* ExecutaRanking(); -> TODO */
            break;
        }
    }

    return 0;
}