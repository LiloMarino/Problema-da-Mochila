#include "config.h"

/*Define a classe da mochila*/
#if CLASSE_DA_MOCHILA == 1
const char classe[] = "Classe P1";
#define CAPACIDADE_DA_MOCHILA 500
#define NUMERO_DE_ITEMS 100
#define TAMANHO_MIN 10
#define TAMANHO_MAX 200
#define PRIORIDADE_MIN 10
#define PRIORIDADE_MAX 100
#elif CLASSE_DA_MOCHILA == 2
const char classe[] = "Classe P2";
#define CAPACIDADE_DA_MOCHILA 500
#define NUMERO_DE_ITEMS 100
#define TAMANHO_MIN 200
#define TAMANHO_MAX 500
#define PRIORIDADE_MIN 10
#define PRIORIDADE_MAX 100
#elif CLASSE_DA_MOCHILA == 3
const char classe[] = "Classe M1";
#define CAPACIDADE_DA_MOCHILA 500
#define NUMERO_DE_ITEMS 1000
#define TAMANHO_MIN 10
#define TAMANHO_MAX 200
#define PRIORIDADE_MIN 10
#define PRIORIDADE_MAX 100
#elif CLASSE_DA_MOCHILA == 4
const char classe[] = "Classe M2";
#define CAPACIDADE_DA_MOCHILA 500
#define NUMERO_DE_ITEMS 1000
#define TAMANHO_MIN 200
#define TAMANHO_MAX 500
#define PRIORIDADE_MIN 10
#define PRIORIDADE_MAX 100
#elif CLASSE_DA_MOCHILA == 5
const char classe[] = "Classe G1";
#define CAPACIDADE_DA_MOCHILA 500
#define NUMERO_DE_ITEMS 10000
#define TAMANHO_MIN 10
#define TAMANHO_MAX 200
#define PRIORIDADE_MIN 10
#define PRIORIDADE_MAX 100
#elif CLASSE_DA_MOCHILA == 6
const char classe[] = "Classe G2";
#define CAPACIDADE_DA_MOCHILA 500
#define NUMERO_DE_ITEMS 10000
#define TAMANHO_MIN 200
#define TAMANHO_MAX 500
#define PRIORIDADE_MIN 10
#define PRIORIDADE_MAX 100
#else
const char classe[] = "Classe Custom";
#endif

#if GERAR == 0 && COMPILA_REGISTRO_GERAL != 1
#include <stdio.h>
#include <string.h>
#include "arvore.h"
#include "Bibliotecas/efficiency.h"
#include "Bibliotecas/geradores.h"
int main()
{
        /*Inicializa as variáveis*/
        Elemento Itens[NUMERO_DE_ITEMS];
        int Quantidades[NUMERO_DE_ITEMS] = {0};
        double segundos;
        char nome_log[40] = "../logs/";
        char nome_arquivo[20] = "dados.txt";
        strcat(nome_log, classe);
        FILE *registro;
        FILE *log = CriaLog(nome_log);
#if METHOD_USE == 0
        fprintf(log, "MOPT      BranchBound     MOP     MOT\n");
#endif
        /*Inicia os testes*/
        for (int i = 1; i <= NUMERO_DE_CASOS; i++)
        {
#if UNICO_REGISTRO_POR_MOCHILA == 1
                registro = CriaLog("RegistroGeral");
#endif
                /*Lê os dados do arquivo i*/
                LerDados(nome_arquivo, Itens);
#if METHOD_USE == 1 || METHOD_USE == 0
#if SHOW_ON_TERMINAL == 1
                printf("METODO HEURISTICA MOPT:\n");
#endif
                /*Realiza pela Heurística Míope com Ordenação de Prioridade/Tamanho*/
#if UNICO_REGISTRO_POR_MOCHILA != 1
                registro = CriaLog("HeuristicaMOPT");
#else
                fprintf(registro, "METODO HEURISTICA MOPT:\n");
#endif
                iniciarTempo();
                HeuristicaMOPT(Itens, Quantidades, registro);
                segundos = finalizarTempo();
                fprintf(registro, "\nTempo total de execução: %lf segundos.\n", segundos);
                fprintf(log, "%lf ", segundos);
#if UNICO_REGISTRO_POR_MOCHILA != 1
                fclose(registro);
#endif
#endif
#if METHOD_USE == 2 || METHOD_USE == 0
#if SHOW_ON_TERMINAL == 1
                printf("METODO BRANCH BOUND:\n");
#endif
                /*Realiza pelo Branch Bound*/
#if UNICO_REGISTRO_POR_MOCHILA != 1
                registro = CriaLog("BranchBound");
#else
                fprintf(registro, "METODO BRANCH BOUND:\n");
#endif
                iniciarTempo();
                BranchBound(Itens, Quantidades, registro);
                segundos = finalizarTempo();
                fprintf(registro, "\nTempo total de execução: %lf segundos.\n", segundos);
                fprintf(log, "%lf ", segundos);
#if UNICO_REGISTRO_POR_MOCHILA != 1
                fclose(registro);
#endif
#endif
#if METHOD_USE == 3 || METHOD_USE == 0
#if SHOW_ON_TERMINAL == 1
                printf("METODO HEURISTICA MOP:\n");
#endif
                /*Realiza pela Heurística Míope com Ordenação de Prioridade*/
#if UNICO_REGISTRO_POR_MOCHILA != 1
                registro = CriaLog("HeuristicaMOP");
#else
                fprintf(registro, "METODO HEURISTICA MOP:\n");
#endif
                iniciarTempo();
                HeuristicaMOP(Itens, Quantidades, registro);
                segundos = finalizarTempo();
                fprintf(registro, "\nTempo total de execução: %lf segundos.\n", segundos);
                fprintf(log, "%lf ", segundos);
#if UNICO_REGISTRO_POR_MOCHILA != 1
                fclose(registro);
#endif
#endif
#if METHOD_USE == 4 || METHOD_USE == 0
#if SHOW_ON_TERMINAL == 1
                printf("METODO HEURISTICA MOT:\n");
#endif
                /*Realiza pela Heurística Míope com Ordenação de Tamanho*/
#if UNICO_REGISTRO_POR_MOCHILA != 1
                registro = CriaLog("HeuristicaMOT");
#else
                fprintf(registro, "METODO HEURISTICA MOT:\n");
#endif
                iniciarTempo();
                HeuristicaMOT(Itens, Quantidades, registro);
                segundos = finalizarTempo();
                fprintf(registro, "\nTempo total de execução: %lf segundos.\n", segundos);
                fprintf(log, "%lf ", segundos);
#if UNICO_REGISTRO_POR_MOCHILA != 1
                fclose(registro);
#endif
#endif
#if METHOD_USE == 5
#if SHOW_ON_TERMINAL == 1
                printf("METODO HEURISTICA GULOSA:\n");
#endif
                /*Realiza pela Heuristica Gulosa*/
#if UNICO_REGISTRO_POR_MOCHILA != 1
                registro = CriaLog("HeuristicaGulosa");
#else
                fprintf(registro, "METODO HEURISTICA GULOSA:\n");
#endif
                iniciarTempo();
                HeuristicaGulosa(Itens, Quantidades, registro);
                segundos = finalizarTempo();
                fprintf(registro, "\nTempo total de execução: %lf segundos.\n", segundos);
                fprintf(log, "%lf ", segundos);
#if UNICO_REGISTRO_POR_MOCHILA != 1
                fclose(registro);
#endif
#endif
#if SHOW_ON_TERMINAL == 0
                /*Mostra uma barra de progresso que avança conforme os casos vão sendo analisados*/
                BarraDeProgresso(i, NUMERO_DE_CASOS);
#endif
                /*Altera para a leitura para o próximo arquivo*/
                sprintf(nome_arquivo, "dados-%d.txt", i + 1);
                fprintf(log, "\n");
#if UNICO_REGISTRO_POR_MOCHILA == 1
                fclose(registro);
#endif
        }
        printf("\n");
        fclose(log);
}
#elif GERAR == 1 && COMPILA_REGISTRO_GERAL != 1
#include "Bibliotecas/geradores.h"
int main()
{
        FILE *dados;
        for (int i = 0; i < NUMERO_DE_CASOS; i++)
        {
                dados = CriaLog("dados");
                for (int j = 0; j < NUMERO_DE_ITEMS; j++)
                {
                        fprintf(dados, "%d ", GerarNumeroInt(TAMANHO_MIN, TAMANHO_MAX));         // Gera Tamanho
                        fprintf(dados, "%d \n", GerarNumeroInt(PRIORIDADE_MIN, PRIORIDADE_MAX)); // Gera Prioridade
                }
                fclose(dados);
        }
}
#endif
#if COMPILA_REGISTRO_GERAL == 1
#include <stdio.h>
#include "Bibliotecas/geradores.h"
int main()
{
        /*Compila os valores dos registros em um único arquivo e deleta todos os registros gerais*/
        FILE *compilado = CriaLog("../logs/Compilado");
        FILE *registro;
        char nome_arquivo[20] = "RegistroGeral.txt";
        for (int i = 1; i <= NUMERO_DE_CASOS; i++)
        {
                
        }
        sprintf(nome_arquivo, "RegistroGeral-%d.txt", i + 1);
}
#endif
