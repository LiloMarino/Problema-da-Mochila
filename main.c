#include "config.h"

/*Define a classe da mochila*/
#if CLASSE_DA_MOCHILA == 1
const char classe[] = "Classe P1";
#elif CLASSE_DA_MOCHILA == 2
const char classe[] = "Classe P2";
#elif CLASSE_DA_MOCHILA == 3
const char classe[] = "Classe M1";
#elif CLASSE_DA_MOCHILA == 4
const char classe[] = "Classe M2";
#elif CLASSE_DA_MOCHILA == 5
const char classe[] = "Classe G1";
#elif CLASSE_DA_MOCHILA == 6
const char classe[] = "Classe G2";
#else
const char classe[] = "Classe Custom";
#endif

#if MODO == 1
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
        FILE *log = CriaLog(nome_log, "csv");
#if METHOD_USE == 0
        fprintf(log, "MOPT,BranchBound,MOP,MOT,\n");
#endif
        /*Inicia os testes*/
        for (int i = 1; i <= NUMERO_DE_CASOS; i++)
        {
#if UNICO_REGISTRO_POR_MOCHILA == 1
                registro = CriaLog("RegistroGeral", "txt");
#endif
                /*Lê os dados do arquivo i*/
                LerDados(nome_arquivo, Itens);
#if METHOD_USE == 1 || METHOD_USE == 0
#if SHOW_ON_TERMINAL == 1
                printf("METODO HEURISTICA MOPT:\n");
#endif
                /*Realiza pela Heurística Míope com Ordenação de Prioridade/Tamanho*/
#if UNICO_REGISTRO_POR_MOCHILA != 1
                registro = CriaLog("HeuristicaMOPT", "txt");
#else
                fprintf(registro, "METODO HEURISTICA MOPT:\n");
#endif
                iniciarTempo();
                HeuristicaMOPT(Itens, Quantidades, registro);
                segundos = finalizarTempo();
                fprintf(registro, "\nTempo total de execução: %lf segundos.\n", segundos);
                fprintf(log, "%lf,", segundos);
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
                registro = CriaLog("BranchBound", "txt");
#else
                fprintf(registro, "METODO BRANCH BOUND:\n");
#endif
                iniciarTempo();
                BranchBound(Itens, Quantidades, registro);
                segundos = finalizarTempo();
                fprintf(registro, "\nTempo total de execução: %lf segundos.\n", segundos);
                fprintf(log, "%lf,", segundos);
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
                registro = CriaLog("HeuristicaMOP", "txt");
#else
                fprintf(registro, "METODO HEURISTICA MOP:\n");
#endif
                iniciarTempo();
                HeuristicaMOP(Itens, Quantidades, registro);
                segundos = finalizarTempo();
                fprintf(registro, "\nTempo total de execução: %lf segundos.\n", segundos);
                fprintf(log, "%lf,", segundos);
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
                registro = CriaLog("HeuristicaMOT", "txt");
#else
                fprintf(registro, "METODO HEURISTICA MOT:\n");
#endif
                iniciarTempo();
                HeuristicaMOT(Itens, Quantidades, registro);
                segundos = finalizarTempo();
                fprintf(registro, "\nTempo total de execução: %lf segundos.\n", segundos);
                fprintf(log, "%lf,", segundos);
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
                registro = CriaLog("HeuristicaGulosa", "txt");
#else
                fprintf(registro, "METODO HEURISTICA GULOSA:\n");
#endif
                iniciarTempo();
                HeuristicaGulosa(Itens, Quantidades, registro);
                segundos = finalizarTempo();
                fprintf(registro, "\nTempo total de execução: %lf segundos.\n", segundos);
                fprintf(log, "%lf,", segundos);
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

#elif MODO == 0
#include "Bibliotecas/geradores.h"
int main()
{
        FILE *dados;
        for (int i = 0; i < NUMERO_DE_CASOS; i++)
        {
                dados = CriaLog("dados", "txt");
                for (int j = 0; j < NUMERO_DE_ITEMS; j++)
                {
                        fprintf(dados, "%d ", GerarNumeroInt(TAMANHO_MIN, TAMANHO_MAX));         // Gera Tamanho
                        fprintf(dados, "%d \n", GerarNumeroInt(PRIORIDADE_MIN, PRIORIDADE_MAX)); // Gera Prioridade
                }
                fclose(dados);
        }
}

#elif MODO == 2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Bibliotecas/geradores.h"
#include "Bibliotecas/learquivo.h"
int main()
{
        /*Compila os valores dos registros em um único arquivo e deleta todos os registros gerais*/
        char nome_log[40] = "../logs/Compilado-";
        strcat(nome_log, classe);
        FILE *compilado = CriaLog(nome_log, "csv");
        ArqCmds *registro;
#if DELETE_DADOS == 1
        char nome_dados[30] = "dados.txt";
#endif
        char nome_arquivo[30] = "RegistroGeral.txt";
        registro = abreArquivoCmd(nome_arquivo);
        char *str = NULL;
        char *param = NULL;
        int Valor;
        fprintf(compilado, "MOPT,BranchBound,MOP,MOT,\n");
        for (int i = 1; registro != NULL; i++)
        {
                /*Atribuição dos Valores*/
                while (leLinha(registro, &str))
                {
                        param = getParametroI(str, 0);
                        if (strcmp(param, "Valor:") == 0)
                        {
                                sscanf(str, "Valor: %d", &Valor);
                                fprintf(compilado, "%d,", Valor);
                        }
                        free(param);
                }
                fprintf(compilado, "\n");
                fechaArquivoCmd(registro);
                remove(nome_arquivo); // Deleta o arquivo
                sprintf(nome_arquivo, "RegistroGeral-%d.txt", i + 1);
#if DELETE_DADOS == 1
                remove(nome_dados);
                sprintf(nome_dados, "dados-%d.txt", i + 1);
#endif
                registro = abreArquivoCmd(nome_arquivo);
                BarraDeProgresso(i, NUMERO_DE_CASOS);
        }
        printf("\n");
        fclose(compilado);
}
#elif MODO == 3
#include <stdio.h>
#include <string.h>
#include "Bibliotecas/geradores.h"
#include "Bibliotecas/learquivo.h"
int main()
{
        FILE *Final = CriaLog("../logs/Final", "csv");
        FILE *Tempo[6];
        FILE *Valor[6];
        char Tipo[] = "PMG";
        char nome_tempo[] = "../logs/Classe ";
        char nome_valor[] = "../logs/Compilado-Classe ";
        char aux[50] = "\0";
        fprintf(Final, "Tempo Classe P1,,,,Valor Classe P1,,,,Tempo Classe P2,,,,Valor Classe P2,,,,Tempo Classe M1,,,,Valor Classe M1,,,,Tempo Classe M2,,,,Valor Classe M2,,,,Tempo Classe G1,,,,Valor Classe G1,,,,Tempo Classe G2,,,,Valor Classe G2,,,\n");

        int i = 0;
        for (int j = 0; j < 6; j++)
        {
                int k = j % 2 + 1;
                sprintf(aux, "%s%c%d.csv", nome_tempo, Tipo[i], k);
                Tempo[j] = fopen(aux, "r");
                sprintf(aux, "%s%c%d.csv", nome_valor, Tipo[i], k);
                Valor[j] = fopen(aux, "r");
                if (k == 2)
                {
                        i++;
                }
        }
        char *str = NULL;

        for (int k = 0; k < NUMERO_DE_CASOS + 1; k++)
        {
                for (int i = 0; i < 3; i++)
                {
                        for (int j = 0; j < 2; j++)
                        {
                                // Lê uma linha do arquivo de tempo correspondente
                                if (leLinha(Tempo[i * 2 + j], &str))
                                {
                                        // Encontra o comprimento da string até o caractere de nova linha
                                        int len = strcspn(str, "\n");
                                        len--;
                                        // Imprime apenas a parte da string até o caractere de nova linha
                                        fprintf(Final, "%.*s,", len, str);
                                }
                                else
                                {
                                        break;
                                }

                                // Lê uma linha do arquivo de valor correspondente
                                if (leLinha(Valor[i * 2 + j], &str))
                                {
                                        // Encontra o comprimento da string até o caractere de nova linha
                                        int len = strcspn(str, "\n");
                                        len--;
                                        // Imprime apenas a parte da string até o caractere de nova linha
                                        fprintf(Final, "%.*s", len, str);
                                }
                                else
                                {
                                        break;
                                }

                                // Imprime uma vírgula entre as colunas, exceto na última coluna da linha
                                if (j != 1)
                                {
                                        fprintf(Final, ",");
                                }
                        }

                        // Imprime uma vírgula entre as classes, exceto na última classe
                        if (i != 2)
                        {
                                fprintf(Final, ",");
                        }
                }
                BarraDeProgresso(k,NUMERO_DE_CASOS);
                fprintf(Final, "\n");
        }
        printf("\n");
        for (int j = 0; j < 6; j++)
        {
                fclose(Tempo[j]);
                fclose(Valor[j]);
        }
        fclose(Final);
}
#endif
