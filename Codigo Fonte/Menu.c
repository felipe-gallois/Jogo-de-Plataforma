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

#include "Entradas.h"

void desenha_menu() {
    textbackground(BLACK);
    textcolor(WHITE);

    cputsxy(1, 1, " _____                   __             \n");
    cputsxy(1, 2, "|   | |___ _ _ ___    __|  |___ ___ ___ \n");
    cputsxy(1, 3, "| | | | . | | | . |  |  |  | . | . | . |\n");
    cputsxy(1, 4, "|_|___|___|\\_/|___|  |_____|___|_  |___|\n");
    cputsxy(1, 5, "                               |___|    \n");
}

void atualiza_menu() {

}

void ExecutaMenu(int* estado, int* encerrar) {
    int terminar = 0;

    desenha_menu();

    while(!terminar) {
        atualiza_menu();
    }
}