#include "config.h"
#if GERAR == 0
#include <stdio.h>
#include "arvore.h"
#include "Bibliotecas/efficiency.h"
#include "Bibliotecas/geradores.h"
int main()
{
    Elemento Itens[NUMERO_DE_ITEMS];
    int Quantidades[NUMERO_DE_ITEMS] = {0};
    FILE *registro;
    LerDados("dados.txt", Itens);
#if METHOD_USE != 2
    printf("METODO HEURISTICA GULOSA:\n");
    registro = CriaLog("HeuristicaGulosa");
    iniciarTempo();
    HeuristicaGulosa(Itens, Quantidades, registro);
    fprintf(registro, "\nTempo total de execução: %lf segundos.\n", finalizarTempo());
    fclose(registro);
#endif
#if METHOD_USE != 1
    printf("METODO BRANCH BOUND:\n");
    registro = CriaLog("BranchBound");
    iniciarTempo();
    BranchBound(Itens, Quantidades, registro);
    fprintf(registro, "\nTempo total de execução: %lf segundos.\n", finalizarTempo());
    fclose(registro);
#endif
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
            fprintf(dados, "%d ", GerarNumeroInt(TAMANHO_MIN,TAMANHO_MAX)); // Gera Tamanho
            fprintf(dados, "%d \n", GerarNumeroInt(PRIORIDADE_MIN,PRIORIDADE_MAX)); // Gera Prioridade
        }
        fclose(dados);
    }
}
#endif
