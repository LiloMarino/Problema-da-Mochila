#include <stdio.h>
#include "arvore.h"
#include "learquivo.h"

int main()
{
    Elemento Itens[NUMERO_DE_ITEMS];
    int Quantidades[NUMERO_DE_ITEMS];
    ArqCmds Dados = abreArquivoCmd("dados.txt");
    char *str = NULL;
    /*Atribuição dos Valores*/
    for (int i = 0; leLinha(Dados, &str); i++)
    {
        sscanf(str, "%d %d", &Itens[i].Tamanho, &Itens[i].Prioridade);
    }
    fechaArquivoCmd(Dados);
    /*Máx de cada item*/
    for (int i = 0; i < NUMERO_DE_ITEMS; i++)
    {
        Itens[i].MaxQntde = CAPACIDADE_DA_MOCHILA / Itens[i].Tamanho;
        Quantidades[i] = 0;
    }
    HeuristicaGulosa(Itens,Quantidades);
}