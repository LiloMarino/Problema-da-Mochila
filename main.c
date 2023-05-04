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
    /*Gera 20 Elementos com Tamanhos e Prioridades com o intervalo de 1 a 200*/
    GerarMatrizInt(CAPACIDADE_DA_MOCHILA / 4, CAPACIDADE_DA_MOCHILA, NUMERO_DE_ITEMS, 2, "../dados.txt");
}
#endif
