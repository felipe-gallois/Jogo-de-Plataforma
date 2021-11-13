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

void CarregaMapa(const char* diretorio, char saida[ALTMAX][LARGMAX])
{
    /* DEFINIÇÃO TEMPORÁRIA PARA FINS DE TESTE.
       AGUARDAR AULA DE STREAMING DE ARQUIVOS PARA FAZER A VERDADEIRA DEFINIÇÃO DA FUNÇÃO */
    
    strcpy(saida[10], "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
    strcpy(saida[11], "x                                                          x");
    strcpy(saida[12], "x                                                          x");
    strcpy(saida[13], "x                                                          x");
    strcpy(saida[14], "x                                                          x");
    strcpy(saida[15], "x                                                          x");
    strcpy(saida[16], "x                                                          x");
    strcpy(saida[17], "x                                 xxxxxxx                  x");
    strcpy(saida[18], "x                                                          x");
    strcpy(saida[19], "x   O                   xxxxxxx                            x");
    strcpy(saida[20], "x   D          xxxxxxx          xxxxxxx          P         x");
    strcpy(saida[21], "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
}

void DesenhaElementos(Dave *dave, char mapa[ALTMAX][LARGMAX], placar_t *placar, struct Porta *porta) //DESENHA OS ELEMENTOS ESTÁTICOS DO MAPA
{
    /* PLACAR */

    desenha_placar(placar);

    /* BLOCOS */

    DesenhaBlocos(mapa);

    /* PORTA */

    DesenhaPorta(mapa, porta);

    /* DAVE */

    DesenhaDave(dave, dave->posX, dave->posY);
}

void ProcessaEventos(int *fim, int entrada, char mapa[ALTMAX][LARGMAX], Dave *dave, placar_t *placar, struct Porta *porta) //EXECUTADO A CADA TICK DO JOGO. ATUALIZA OS EVENTOS.
{
    /* PLACAR */
    
    if(!(placar->atualizado)) {
        atualiza_placar(placar);
    }

    /* PORTA */

    AtualizaPorta(porta);

    /* DAVE */

    movimenta_dave(entrada, dave, mapa);

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

    DesenhaElementos(&dave, mapa, &placar, &porta); //DESENHA OS ELEMENTOS NA TELA

    int entrada;

    int terminar = 0, novo = 0, salvar = 0; //VARIÁVEIS DE CONTROLE

    while(!terminar)
    {
        /* RECEBE ENTRADA - TEMPO INTEIRO */

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

        /* ATUALIZA JOGO - APENAS NOS MOMENTOS OPORTUNOS */

        //TODO
        ProcessaEventos(&terminar, entrada, mapa, &dave, &placar, &porta); //CALCULA E ALTERA AS POSIÇÕES DOS ELEMENTOS

        if(salvar)
        {
            SalvaJogo(&dave, &placar); //TODO
            salvar = 0;
        }

        Sleep(DELAY);
    }

    /* FIM DA FUNÇÃO */

    if(!novo)
        *estado = MENU; //SE NÃO FOR REINICIAR O JOGO, VOLTA PARA O MENU INICIAL
}