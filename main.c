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

#if GERAR == 0
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
        char nome_log[20] = "logs/";
        char nome_arquivo[20] = "dados.txt";
        strcat(nome_log, classe);
        FILE *registro;
        FILE *log = CriaLog(nome_log);
        fprintf(log, "Gulosa    BranchBound\n");
        /*Inicia os testes*/
        for (int i = 1; i <= NUMERO_DE_CASOS; i++)
        {
                /*Lê os dados do arquivo i*/
                LerDados(nome_arquivo, Itens);
#if METHOD_USE != 2
#if SHOW_ON_TERMINAL == 1
                printf("METODO HEURISTICA GULOSA:\n");
#endif
                /*Realiza pela Heuristica Gulosa*/
                registro = CriaLog("HeuristicaGulosa");
                iniciarTempo();
                HeuristicaGulosa(Itens, Quantidades, registro);
                segundos = finalizarTempo();
                fprintf(registro, "\nTempo total de execução: %lf segundos.\n", segundos);
                fprintf(log, "%lf ", segundos);
                fclose(registro);
#endif
#if METHOD_USE != 1
#if SHOW_ON_TERMINAL == 1
                printf("METODO BRANCH BOUND:\n");
#endif
                /*Realiza pelo Branch Bound*/
                registro = CriaLog("BranchBound");
                iniciarTempo();
                BranchBound(Itens, Quantidades, registro);
                segundos = finalizarTempo();
                fprintf(registro, "\nTempo total de execução: %lf segundos.\n", segundos);
                fprintf(log, "%lf ", segundos);
                fclose(registro);
#endif
#if SHOW_ON_TERMINAL == 0
                /*Mostra uma barra de progresso que avança conforme os casos vão sendo analisados*/
                BarraDeProgresso(i, NUMERO_DE_CASOS);
#endif
                sprintf(nome_arquivo, "dados-%d.txt", i + 1);
                fprintf(log, "\n");
        }
        printf("\n");
        fclose(log);
}
#elif GERAR == 1
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
