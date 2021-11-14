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
#include "Bloco.h"
#include "Dave.h"

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

void DesenhaElementos(Dave *dave, char mapa[ALTMAX][LARGMAX]) //DESENHA OS ELEMENTOS ESTÁTICOS DO MAPA
{
    /* BLOCOS */

    DesenhaBlocos(mapa);

    /* DAVE */

    DesenhaDave(dave, dave->posX, dave->posY);
}

void ProcessaEventos(int entrada, char mapa[ALTMAX][LARGMAX], Dave *dave) //EXECUTADO A CADA TICK DO JOGO. ATUALIZA OS EVENTOS.
{
    /* DAVE */
    movimenta_dave(entrada, dave, mapa);
    
}

void SalvaJogo()
{

}

void ExecutaJogo(int* estado, int* encerrar)
{
    //OBS: FALTA IMPLEMENTAR A POSSIBILIDADE DE CARREGAR PARTIDAS SALVAS

    char mapa[ALTMAX][LARGMAX] = { 0 };

    CarregaMapa(MAPA1, mapa); //EM DESENVOLVIMENTO
    
    Dave dave = {LocalizaDaveX(mapa), LocalizaDaveY(mapa)}; //CRIA O DAVE

    DesenhaElementos(&dave, mapa); //DESENHA OS ELEMENTOS NA TELA

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
        ProcessaEventos(entrada, mapa, &dave); //CALCULA E ALTERA AS POSIÇÕES DOS ELEMENTOS

        if(salvar)
        {
            SalvaJogo(); //TODO
            salvar = 0;
        }

        Sleep(DELAY);
    }

    if(!novo) {
        *estado = MENU; //SE NÃO FOR REINICIAR O JOGO, VOLTA PARA O MENU INICIAL
    }
}