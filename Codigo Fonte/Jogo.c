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
#include <stdio.h> //FILE
#include <string.h> //STRCPY
#include <stdlib.h> //MALLOC

#include <windows.h>

#include "Entradas.h"
#include "Constantes.h"
#include "Placar.h"
#include "Bloco.h"
#include "Porta.h"
#include "Dave.h"
#include "Coletaveis.h"

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

void DesenhaElementos(Dave *dave, char mapa[ALTMAX][LARGMAX], placar_t *placar, struct Porta *porta, struct Coletaveis itens[MAXCOLET]) //DESENHA OS ELEMENTOS ESTÁTICOS DO MAPA
{
    /* PLACAR */

    desenha_placar(placar);

    /* BLOCOS */

    DesenhaBlocos(mapa);

    /* PORTA */

    DesenhaPorta(mapa, porta);

    /* DAVE */

    DesenhaDave(dave, dave->posX, dave->posY);

    /* COLETAVEIS */

    DesenhaColetaveis(mapa, itens);
}

void ProcessaEventos(int *fim, int entrada, char mapa[ALTMAX][LARGMAX], Dave *dave, placar_t *placar, struct Porta *porta, struct Coletaveis itens[MAXCOLET]) //EXECUTADO A CADA TICK DO JOGO. ATUALIZA OS EVENTOS.
{
    /* PLACAR */
    
    if(!(placar->atualizado)) {
        atualiza_placar(placar);
    }

    /* PORTA */

    AtualizaPorta(porta);

    /* DAVE */

    movimenta_dave(entrada, dave, mapa);

    /* COLETÁVEIS */

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
        default: /* COROA */
        placar->pontos += 300;
        placar->atualizado = 0;
    }

    /* TESTA FIM */

    if(TemPorta(dave->posX, dave->posY, porta)) {
        *fim = 1;
    }
    
}

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

void ExecutaJogo(int* estado, int* encerrar)
{
    //OBS: FALTA IMPLEMENTAR A POSSIBILIDADE DE CARREGAR PARTIDAS SALVAS

    char mapa[ALTMAX][LARGMAX] = { 0 };

    CarregaMapa(MAPA1, mapa); //EM DESENVOLVIMENTO

    placar_t placar = {0, 0, 0, 1, 5}; //CRIA O PLACAR

    struct Porta porta;

    Dave dave = {LocalizaDaveX(mapa), LocalizaDaveY(mapa)}; //CRIA O DAVE

    struct Coletaveis itens[MAXCOLET];

    for(int i = 0; i < MAXCOLET; i++) {
        itens[i].tipo = 0;
    }

    DesenhaElementos(&dave, mapa, &placar, &porta, itens); //DESENHA OS ELEMENTOS NA TELA

    int entrada;

    int terminar = 0, novo = 0, salvar = 0; //VARIÁVEIS DE CONTROLE

    while(!terminar)
    {

        entrada = RecebeEntrada();

        switch(entrada) //TRATA AS TECLAS ESPECIAIS
        {
            case ESC:
                terminar = 1;
                novo = 0;
                salvar = 0;
                *estado = MENU;
                break;
            case N:
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


        //TODO
        ProcessaEventos(&terminar, entrada, mapa, &dave, &placar, &porta, itens); //CALCULA E ALTERA AS POSIÇÕES DOS ELEMENTOS

        if(salvar)
        {
            SalvaJogo(&dave, &placar); //TODO
            salvar = 0;
        }

        Sleep(DELAY);
    }

    if(!novo) {
        *estado = MENU; //SE NÃO FOR REINICIAR O JOGO, VOLTA PARA O MENU INICIAL
    }
}