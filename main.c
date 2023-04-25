#include <stdio.h>
#include "arvore.h"
#include "learquivo.h"

struct StElemento
{
    int Prioridade;
    int Tamanho;
    int MaxCapac;
};

typedef struct StElemento Elemento;

int main()
{
    Elemento Itens[NUMERO_DE_ITEMS];
    ArqCmds Dados = abreArquivoCmd("dados.txt");
    char *str = NULL;
    int i;
    /*Atribuição dos Valores*/
    for (int i = 0; leLinha(Dados, &str); i++)
    {
        sscanf(str, "%d %d", &Itens[i].Tamanho, &Itens[i].Prioridade);
    }
    fechaArquivoCmd(Dados);
    /*Máx de cada item*/
    for (i = 0; i < NUMERO_DE_ITEMS; i++)
    {
        Itens[i].MaxCapac = CAPACIDADE_DA_MOCHILA / Itens[i].Tamanho;
    }
    /*Verificações*/
    for (int j = 0; j < NUMERO_DE_ITEMS; j++)
    {
        for (i = Itens[j].MaxCapac; i >= 0; i--)
        {
            printf("%d\n", i);
        }
    }
}