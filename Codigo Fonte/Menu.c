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
#include <string.h>

#include "conio2.h"

#include "Constantes.h"
#include "Entradas.h"

#define NJ_LINHA ".-------------.\n"
#define NJ_TEXTO "|  Novo Jogo  |\n"

#define CAR_LINHA ".------------.\n"
#define CAR_TEXTO "|  Carregar  |\n"

#define RANK_LINHA ".-----------.\n"
#define RANK_TEXTO "|  Ranking  |\n"

#define SAIR_LINHA ".--------.\n"
#define SAIR_TEXTO "|  Sair  |\n"

#define MARGEM_TOPO 9
#define DISTANCIA 4

#define COR RED

int limita(int selecao) {
    if(selecao < NOVO) {
        return NOVO;
    }

    if(selecao > SAIR) {
        return SAIR;
    }

    return selecao;
}

void desenha_nj() {
    cputsxy(LARGMAX - (int) (strlen(NJ_LINHA) / 2), MARGEM_TOPO, NJ_LINHA);
    cputsxy(LARGMAX - (int) (strlen(NJ_TEXTO) / 2), MARGEM_TOPO + 1, NJ_TEXTO);
    cputsxy(LARGMAX - (int) (strlen(NJ_LINHA) / 2), MARGEM_TOPO + 2, NJ_LINHA);
}

void desenha_car() {
    cputsxy(LARGMAX - (int) (strlen(CAR_LINHA) / 2), MARGEM_TOPO + DISTANCIA, CAR_LINHA);
    cputsxy(LARGMAX - (int) (strlen(CAR_TEXTO) / 2), MARGEM_TOPO + DISTANCIA + 1, CAR_TEXTO);
    cputsxy(LARGMAX - (int) (strlen(CAR_LINHA) / 2), MARGEM_TOPO + DISTANCIA + 2, CAR_LINHA);
}

void desenha_rank() {
    cputsxy(LARGMAX - (int) (strlen(RANK_LINHA) / 2), MARGEM_TOPO + DISTANCIA * 2, RANK_LINHA);
    cputsxy(LARGMAX - (int) (strlen(RANK_TEXTO) / 2), MARGEM_TOPO + DISTANCIA * 2 + 1, RANK_TEXTO);
    cputsxy(LARGMAX - (int) (strlen(RANK_LINHA) / 2), MARGEM_TOPO + DISTANCIA * 2 + 2, RANK_LINHA);
}

void desenha_sair() {
    cputsxy(LARGMAX - (int) (strlen(SAIR_LINHA) / 2), MARGEM_TOPO + DISTANCIA * 3, SAIR_LINHA);
    cputsxy(LARGMAX - (int) (strlen(SAIR_TEXTO) / 2), MARGEM_TOPO + DISTANCIA * 3 + 1, SAIR_TEXTO);
    cputsxy(LARGMAX - (int) (strlen(SAIR_LINHA) / 2), MARGEM_TOPO + DISTANCIA * 3 + 2, SAIR_LINHA);
}

void desenha_menu(int *selecao) {

    textbackground(COR);
    textcolor(BLACK);

    desenha_nj();

    textbackground(BLACK);
    textcolor(WHITE);

    desenha_car();

    desenha_rank();

    desenha_sair();

    *selecao = NOVO;
}

void atualiza_menu(int *anterior, int posterior) {

    textbackground(BLACK);
    textcolor(WHITE);

    switch(*anterior) {
        case NOVO:
        desenha_nj();
        break;
        case CARREGAR:
        desenha_car();
        break;
        case RANK:
        desenha_rank();
        break;
        case SAIR:
        desenha_sair();
        break;
    }

    textbackground(COR);
    textcolor(BLACK);

    switch(posterior) {
        case NOVO:
        desenha_nj();
        break;
        case CARREGAR:
        desenha_car();
        break;
        case RANK:
        desenha_rank();
        break;
        case SAIR:
        desenha_sair();
        break;
    }

    *anterior = posterior;
}

void ExecutaMenu(int* estado, int* encerrar) {

    int selecao, entrada;
    int terminar = 0;

    desenha_menu(&selecao);

    while(!terminar) {
        entrada = RecebeEntrada();

        switch(entrada) {
            case ESC:
            *encerrar = 1;
            terminar = 1;
            break;
            case CIMA:
            atualiza_menu(&selecao, limita(selecao - 1));
            entrada = -1;
            break;
            case BAIXO:
            atualiza_menu(&selecao, limita(selecao + 1));
            entrada = -1;
            break;
            case ENTER:
                switch (selecao)
                {
                case NOVO:
                *estado = JOGO;
                terminar = 1;
                break;
                case CARREGAR:
                break;
                case RANK:
                break;
                case SAIR:
                *encerrar = 1;
                terminar = 1;
                break;
                }
            break;
        }
    }
}