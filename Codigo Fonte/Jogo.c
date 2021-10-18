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
#include <stdlib.h> //MALLOC
#include "Entradas.h"

/* DEFINES */
#define LARGMAX 120 //LARGURA MÁXIMA DE UM MAPA
#define ALTMAX 30 //ALTURA MÁXIMA DE UM MAPA

#define MAPA1 "fase_1.txt"

#define DELAY 60 //DEMORA ARTIFICIAL DA ATUALIZAÇÃO DO JOGO, EM MS

void CarregaMapa(const char* diretorio, char* saida) //NÃO FUNCIONA, CONSERTAR
{
    FILE *arquivo = fopen(diretorio, "r");

    if(arquivo == NULL)
    {
        printf("Erro ao abrir o mapa especificado.");
        return 1;
    }

    int caractere, numero = 0;

    do
    {
        caractere = fgetc(arquivo);
        *(saida + numero) = (char) caractere;
        numero++;
    }
    while (caractere != EOF);

    *(saida + numero) = '\0';
    
    fclose(arquivo);
}

int ExecutaJogo()
{
    //OBS: FALTA IMPLEMENTAR A POSSIBILIDADE DE CARREGAR PARTIDAS SALVAS

    char *mapa = (char*) malloc(((LARGMAX + 1) * ALTMAX + 1) * sizeof(char)); //TALVEZ DECLARAR ESTATICAMENTE (SUGESTÃO DO PROFESSOR)

    CarregaMapa(MAPA1, mapa); //EM DESENVOLVIMENTO

    //TODO
    DesenhaMapa(mapa); //DESENHA OS ELEMENTOS NA TELA

    int entrada, contador_delay = 0, terminar = 0, novo = 0, salvar = 0;

    while(!terminar)
    {
        /* RECEBE ENTRADA - TEMPO INTEIRO */

        entrada = RecebeEntrada();

        switch(entrada) //TRATA AS TECLAS ESPECIAIS
        {
            case ESC:
                terminar = 1;
                break;
            case N:
                terminar = 1;
                novo = 1;
                break;
            case S:
                salvar = 1;
                break;
        }

        /* ATUALIZA JOGO - APENAS NOS INTERVALOS */

        if(contador_delay >= DELAY)
        {
            contador_delay = 1;

            //TODO
            ProcessaEventos(entrada); //CALCULA E ALTERA AS POSIÇÕES DOS ELEMENTOS
            //TODO
            AtualizaDesenho(); //DESENHA OS ELEMENTOS ALTERADOS
        }
        else
            contador_delay++;

        if(salvar)
        {
            SalvaJogo(); //TODO
            salvar = 0;
        }
    }

    free(mapa);

    if(novo)
        return 1; //NOVO JOGO

    return 0; //SEM NOVO JOGO
}