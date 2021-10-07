# Documentação do Código

Esta é a documentação do código do jogo.

## Arquivos Fonte

O programa foi organizado seguindo a estrutura de arquivos detalhada abaixo:


|       Conjunto       | Arquivos                                                                                                                                                                        | Descrição                                                                                                                          |
| :--------------------: | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | :------------------------------------------------------------------------------------------------------------------------------------- |
|      Principal      | `Principal.c`                                                                                                                                                                   | Apenas a função`main`, e as funções que desenham o menu principal pela primeira vez e que executam o loop de entradas e saídas. |
|       Entradas       | `Entradas.c`, `Entradas.h`                                                                                                                                                      | Agrupa funções relacionadas às entradas do teclado do jogador.                                                                    |
|         Menu         | `Menu.c`, `Menu.h`                                                                                                                                                              | Funções próprias do menu principal da aplicação.                                                                                |
|      Interface      | `Interface.c`, `Interface.h`                                                                                                                                                    | Funções genéricas para desenhar os quadros no console.                                                                            |
|         Jogo         | `Jogo.c`,<br />`Jogo.h`, `Carregar.c`, `Carregar.h`                                                                                                                             | Funções que controlam aspectos genéricos da execução do jogo propriamente dito e que lidam com o carregamento de jogos salvos.  |
|       Ranking       | `Ranking.c`, `Ranking.h`                                                                                                                                                        | Funções que operam sobre o streaming de arquivos que gravam as pontuações récorde.                                              |
|      Entidades      | `Agua.c`, `Agua.h`,`Bloco.c`, `Bloco.h`, `Dave.c`, `Dave.h`, `Entrada.c`, `Entrada.h`, `Fogo.c`, `Fogo.h`, `Mochila.c`, `Mochila.h`, `Porta.c`, `Porta.h`, `Chave.c`, `Chave.h` | Funções específicas de cada entidade do jogo.                                                                                     |
|        Placar        | `Placar.c`, `Placar.h`                                                                                                                                                          | Funções relacionadas às informações do placar.                                                                                  |
| Tela de Encerramento | `FimDeJogo.c`, `FimDeJogo.h`                                                                                                                                                    | Funções relacionadas à tela de fim de jogo.                                                                                       |
|     Coletáveis     | `Coletaveis.c`, `Coletaveis.h`                                                                                                                                                  | Funções gerais para os ítens coletáveis no jogo.                                                                                 |

## Funções

As seguintes funções foram utilizadas durante a criação do programa:


| Nome        | Assinatura           | Parâmetros | Retorno | Descrição                                                |
| ------------- | ---------------------- | :-----------: | :-------: | ------------------------------------------------------------ |
| CarregaMenu | `void CarregaMenu()` |      -      |    -    | Inicializa e exibe para o usuário o menu inicial do jogo. |
|             |                      |             |         |                                                            |
