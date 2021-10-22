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

#include "Entradas.h"
#include "Constantes.h"
#include "Bloco.h"

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
    strcpy(saida[20], "x   D          xxxxxxx          xxxxxxx                    x");
    strcpy(saida[21], "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
}

void DesenhaMapa(char mapa[ALTMAX][LARGMAX]) //DESENHA OS ELEMENTOS ESTÁTICOS DO MAPA
{
    /* ELEMENTOS PARA DESENHAR (ESTÁTICOS):
       - PAREDES
       - PORTA
       - ENTRADA
    */

    DesenhaBlocos(mapa);
}

void ProcessaEventos(int entrada) //EXECUTADO A CADA TICK DO JOGO. ATUALIZA OS EVENTOS.
{

}

void AtualizaDesenho() //EXECUTADO A CADA TICK DO JOGO. ATUALIZA O DESENHO.
{

}

void SalvaJogo()
{

}

void ExecutaJogo(int* estado, int* encerrar)
{
    //OBS: FALTA IMPLEMENTAR A POSSIBILIDADE DE CARREGAR PARTIDAS SALVAS

    char mapa[ALTMAX][LARGMAX] = { 0 };

    CarregaMapa(MAPA1, mapa); //EM DESENVOLVIMENTO

    DesenhaMapa(mapa); //DESENHA OS ELEMENTOS NA TELA

    int entrada, contador_delay = 0;

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
                *encerrar = 1;
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

    /* FIM DA FUNÇÃO */

    if(!novo)
        *estado = MENU; //SE NÃO FOR REINICIAR O JOGO, VOLTA PARA O MENU INICIAL
}