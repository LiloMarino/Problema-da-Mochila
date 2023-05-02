#include "config.h"
#if GERAR == 0
#include <stdio.h>
#include "arvore.h"
#include "Bibliotecas/efficiency.h"
int main()
{
    Elemento Itens[NUMERO_DE_ITEMS];
    int Quantidades[NUMERO_DE_ITEMS];
    LerDados("dados.txt", Itens, Quantidades);
    iniciarTempo();
    HeuristicaGulosa(Itens, Quantidades);
    finalizarTempo();
    printf("METODO BRANCH BOUND:\n");
    iniciarTempo();
    BranchBound(Itens, Quantidades);
    finalizarTempo();
}
#elif GERAR == 1
#include "Bibliotecas/geradores.h"
int main()
{
    
}
#endif
