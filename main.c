#include <stdio.h>
#include <math.h>
#include "arvore.h"

int main()
{
    Elemento Itens[NUMERO_DE_ITEMS];
    int Quantidades[NUMERO_DE_ITEMS];
    LerDados("dados.txt",Itens,Quantidades);
    HeuristicaGulosa(Itens,Quantidades);
}