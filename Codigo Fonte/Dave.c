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
#include "Constantes.h"
#include "Dave.h"
#include "Bloco.h"

int LocalizaDaveX(char mapa[ALTMAX][LARGMAX])
{
    for(int y = 0; y < ALTMAX; y++)
    {
        for(int x = 0; x < LARGMAX; x++)
        {
            if(mapa[y][x] == 'D')
            {
                return 1 + 2 * x;
            }
        }
    }

    return 0; //VALOR PADRÃO
}

int LocalizaDaveY(char mapa[ALTMAX][LARGMAX])
{
    for(int y = 0; y < ALTMAX; y++)
    {
        for(int x = 0; x < LARGMAX; x++)
        {
            if(mapa[y][x] == 'D')
            {
                return 1 + y;
            }
        }
    }

    return 0; //VALOR PADRÃO
}

void ApagaDave(Dave *dave)
{
    textbackground(BLACK);
    putchxy(dave->posX, dave->posY, ' ');
    putchxy(dave->posX, dave->posY - 1, ' ');
}

void DesenhaDave(Dave *dave, int posX, int posY)
{
    dave->posX = posX;
    dave->posY = posY;

    textbackground(WHITE);
    textcolor(BLACK);

    putchxy(posX, posY - 1, 1); //ROSTO

    textbackground(LIGHTBLUE);
    putchxy(posX, posY, 19); //PERNAS
}

/* APAGA A POSIÇÃO ANTIGA DE DAVE E DESENHA NA POSIÇÃO MAIS RECENTE */
void atualiza_posicao(Dave *dave, int posX, int posY) {
    ApagaDave(dave);
    DesenhaDave(dave, posX, posY);
}

/* RETORNA SE O DAVE PODE SE MOVIMENTAR PARA UMA DETERMINADA POSIÇÃO */
int pode_movimentar(int posX, int posY, char mapa[ALTMAX][LARGMAX]) {
    if(TemBloco(posX, posY, mapa) || TemBloco(posX, posY - 1, mapa)) {
        return 0;
    }

    return 1;
}

/* ATUALIZA A POSIÇÃO DE DAVE SE FOR POSSÍVEL */
int atualiza_se_puder(Dave *dave, int posX, int posY, char mapa[ALTMAX][LARGMAX]) {
    if(pode_movimentar(posX, posY, mapa)) {
        atualiza_posicao(dave, posX, posY);
        return 1;
    } else if((posY == dave->posY - 1 || posY == dave->posY + 1) &&
                (posX == dave->posX - 1 || posX == dave->posX + 1)) { /* CASO ESPECIAL: MOVIMENTO EM DIAGONAL */
        if(pode_movimentar(dave->posX, posY, mapa)) {
            atualiza_posicao(dave, dave->posX, posY);
            return 1;
        }
    }

    return 0;
}

/* INDICA SE O DAVE ESTÁ SENDO SUSTENTADO POR UM BLOCO */
int no_ar(int posX, int posY, char mapa[ALTMAX][LARGMAX]) {

    if(TemBloco(posX, posY + 1, mapa)) {
        return 0;
    }

    return 1;
}

/* MOVIMENTA O DAVE, QUANDO POSSÍVEL, DE ACORDO COM A ENTRADA DO USUÁRIO */
void movimenta_dave(int entrada, Dave *dave, char mapa[ALTMAX][LARGMAX]) {

    if(no_ar(dave->posX, dave->posY, mapa)) { /* CASO DAVE ESTEJA NO AR */

        if(dave->saltando) { /* CASO DAVE ESTEJA NO AR E SALTANDO */

            switch(entrada) {
                case DIREITA:
                dave->aceleracao = 1;
                break;
                case ESQUERDA:
                dave->aceleracao = -1;
                break;
            }

            if(atualiza_se_puder(dave, dave->posX + dave->aceleracao, dave->posY - 1, mapa)) {
                dave->saltando--;
            } else {
                dave->saltando = 0;
            }

        } else { /* CASO DAVE ESTEJA NO AR E CAINDO */

            switch(entrada) {
                case DIREITA:
                if(dave->aceleracao == -1) {
                    dave->aceleracao = 0;
                } else if(dave->aceleracao == 0) {
                    dave->aceleracao = 1;
                }
                break;
                case ESQUERDA:
                if(dave->aceleracao == 1) {
                    dave->aceleracao = 0;
                } else if(dave->aceleracao == 0) {
                    dave->aceleracao = -1;
                }
                break;
            }

            atualiza_se_puder(dave, dave->posX + dave->aceleracao, dave->posY + 1, mapa);

            if(!no_ar(dave->posX, dave->posY, mapa)) {
                dave->aceleracao = 0;
            }
        }

    } else { /* CASO DAVE ESTEJA SUSTENTADO POR UM BLOCO */

        if(dave->saltando) { /* CASO DAVE ESTEJA SUBINDO, MAS AINDA EM CONTATO COM O CHÃO */

            if(atualiza_se_puder(dave, dave->posX + dave->aceleracao, dave->posY - 1, mapa)) {
                dave->saltando--;
            } else {
                dave->saltando = 0;
            }

        } else { /* CASO DAVE ESTEJA NO CHÃO E NÃO SUBINDO*/

            switch(entrada) {
                case DIREITA:
                atualiza_se_puder(dave, dave->posX + 1, dave->posY, mapa);
                dave->aceleracao = 1;
                break;
                case ESQUERDA:
                atualiza_se_puder(dave, dave->posX - 1, dave->posY, mapa);
                dave->aceleracao = -1;
                break;
                case CIMA:
                if(atualiza_se_puder(dave, dave->posX + dave->aceleracao, dave->posY - 1, mapa)) {
                    dave->saltando = BLOCOS - 1;
                }
                break;
                default:
                dave->aceleracao = 0;
            }

        }
    }
}