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
#include <stdlib.h>
#include <windows.h>

#include "Entradas.h"
#include "Constantes.h"
#include "Placar.h"
#include "Bloco.h"
#include "Porta.h"
#include "Entrada.h"
#include "Dave.h"
#include "Coletaveis.h"
#include "Fogo.h"
#include "Agua.h"

/* CARREGA O MAPA DO ARQUIVO PARA UMA MATRIZ */

void CarregaMapa(const char* diretorio, char saida[ALTMAX][LARGMAX])
{
    FILE *arquivo;
    arquivo = fopen(diretorio, "r");

    if(arquivo != NULL) {

        int x = 0, y = 0, nova_linha = 0, fim = 0;
        char temp[LARGMAX + 2];

        while(!fim) {
            fgets(temp, LARGMAX + 2, arquivo);

            while(x < LARGMAX && !nova_linha) {
                switch(temp[x]) {
                    case '\n':
                    nova_linha = 1;
                    break;
                    case '\0':
                    fim = 1;
                    nova_linha = 1;
                    break;
                    default:
                    saida[y][x] = temp[x];
                }
                x++;
            }

            if(y < ALTMAX - 1 && !fim) {
                x = 0;
                y++;
                nova_linha = 0;
            } else {
                fim = 1;
            }
        }

    }

    fclose(arquivo);
}

/* DESENHA TODOS OS ELEMENTOS NA TELA */

void DesenhaElementos(Dave *dave, char mapa[ALTMAX][LARGMAX], placar_t *placar, struct Porta *porta, struct Coletaveis itens[MAXCOLET], struct Entrada *origem) //DESENHA OS ELEMENTOS ESTÁTICOS DO MAPA
{
    desenha_placar(placar);

    DesenhaBlocos(mapa);

    DesenhaPorta(mapa, porta);

    desenha_entrada(origem, mapa);

    DesenhaDave(dave, dave->posX, dave->posY);

    DesenhaColetaveis(mapa, itens);

    DesenhaFogo(mapa);

    DesenhaAgua(mapa);
}

/* PROCESSA OS EVENTOS E ATUALIZA AS INFORMAÇÕES NO CONSOLE */

int ProcessaEventos(int *fim, int entrada, char mapa[ALTMAX][LARGMAX], Dave *dave, placar_t *placar, struct Porta *porta, struct Coletaveis itens[MAXCOLET], struct Entrada *origem, int *vidas, int *novo) //EXECUTADO A CADA TICK DO JOGO. ATUALIZA OS EVENTOS.
{
    if(!(placar->atualizado)) {
        atualiza_placar(placar);
    }

    AtualizaPorta(porta);

    atualiza_entrada(origem);

    movimenta_dave(entrada, dave, mapa);

    int coletado = coleta(dave, itens);

    switch(coletado) {
        case 0:
        break;
        case AMETISTA:
        placar->pontos += 50;
        placar->atualizado = 0;
        break;
        case SAFIRA:
        placar->pontos += 100;
        placar->atualizado = 0;
        break;
        case RUBI:
        placar->pontos += 150;
        placar->atualizado = 0;
        break;
        case ANEL:
        placar->pontos += 200;
        placar->atualizado = 0;
        break;
        case COROA:
        placar->pontos += 300;
        placar->atualizado = 0;
        break;
        case TROFEU:
        placar->pontos += 1000;
        placar->atualizado = 0;
        dave->trofeu = 1;
        break;
        case JETPACK:
        placar->atualizado = 0;
        dave->jetpack = 1;
        break;
    }

    if(TemAgua(dave->posX, dave->posY, mapa) || TemAgua(dave->posX, dave->posY - 1, mapa) ||
         TemFogo(dave->posX, dave->posY, mapa) || TemFogo(dave->posX, dave->posY - 1, mapa)) {

        (*vidas)--;
        placar->atualizado = 0;
        *novo = 1;
        *fim = 1;
    }

    if(TemPorta(dave->posX, dave->posY, porta) && dave->trofeu == 1) {
        *fim = 1;
        return 1;
    }

    return 0;

}

/* SALVA OS DADOS EM UM ARQUIVO */

void SalvaJogo(Dave *dave, placar_t *placar)
{
    FILE *arquivo;
    arquivo = fopen(DIR_SAVE, "wb+");

    if(arquivo != NULL) {
        fwrite(dave, sizeof(Dave), 1, arquivo);
        fwrite(placar, sizeof(placar_t), 1, arquivo);
    }

    fclose(arquivo);
}

/* LOOP DE EXECUÇÃO DA PARTIDA */

void ExecutaJogo(int *estado, int *encerrar, int *n_mapa, int *vidas)
{
    char mapa[ALTMAX][LARGMAX] = { 0 };

    switch(*n_mapa) {
        case 1:
        CarregaMapa(MAPA1, mapa);
        break;
        case 2:
        CarregaMapa(MAPA2, mapa);
        break;
        case 3:
        CarregaMapa(MAPA3, mapa);
        break;
    }

    placar_t placar = {0, 0, 0, 1, *vidas};

    struct Porta porta;

    struct Entrada origem;

    Dave dave = {LocalizaDaveX(mapa), LocalizaDaveY(mapa)};

    struct Coletaveis itens[MAXCOLET];

    for(int i = 0; i < MAXCOLET; i++) {
        itens[i].tipo = 0;
    }

    DesenhaElementos(&dave, mapa, &placar, &porta, itens, &origem);

    int entrada;

    int terminar = 0, novo = 0, salvar = 0, proxima_fase = 0;

    while(!terminar)
    {
        entrada = RecebeEntrada();

        switch(entrada)
        {
            case ESC:
                *n_mapa = 1;
                terminar = 1;
                novo = 0;
                salvar = 0;
                *estado = MENU;
                break;
            case N:
                *n_mapa = 1;
                *vidas = VIDAS;
                terminar = 1;
                novo = 1;
                salvar = 0;
                *encerrar = 0;
                break;
            case S:
                terminar = 0;
                novo = 0;
                salvar = 1;
                *encerrar = 0;
                break;
        }

        proxima_fase = ProcessaEventos(&terminar, entrada, mapa, &dave, &placar, &porta, itens, &origem, vidas, &novo);

        if(salvar)
        {
            SalvaJogo(&dave, &placar);
            salvar = 0;
        }

        Sleep(DELAY);
    }

    if(*vidas == 0) {
        *n_mapa = 1;
        *estado = MENU;
    }

    if(proxima_fase) {
        if(*n_mapa + 1 > NUM_FASES) {
            *n_mapa = 1;
            *estado = MENU;
        } else {
            (*n_mapa)++;
        }
    } else if(!novo) {
        *estado = MENU;
    }
}