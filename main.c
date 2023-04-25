#include <stdio.h>
#include "arvore.h"
#include "learquivo.h"

struct StElemento
{
    int Prioridade;
    int Tamanho;
    int MaxQntde;
};

typedef struct StElemento Elemento;

void ImprimeVetorInt(int vetor_int[], int ni)
{
    // Imprime o vetor int
    for (int i = 0; i < ni; i++)
    {
        printf("%d ", vetor_int[i]);
    }
    printf("\n");
}

int main()
{
    Elemento Itens[NUMERO_DE_ITEMS];
    int Quantidades[NUMERO_DE_ITEMS];
    int ni = sizeof(Quantidades) / sizeof(int);
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
        Itens[i].MaxQntde = CAPACIDADE_DA_MOCHILA / Itens[i].Tamanho;
        Quantidades[i] = 0;
    }
    /*Verificações baseados na capacidade*/
    for (int j = 0; j < NUMERO_DE_ITEMS; j++)
    {
        for (i = Itens[j].MaxQntde; i >= 0; i--)
        {
            int CapacRestante = CAPACIDADE_DA_MOCHILA;
            /* Variações a partir do item i */
            if (CapacRestante - Itens[j].Tamanho * i >= 0)
            {
                CapacRestante -= Itens[j].Tamanho * i;
                Quantidades[j] = i;
            }
            /*Verificar os próximos*/
            for (int k = j + 1; k < NUMERO_DE_ITEMS; k++)
            {
                for (int qntde = Itens[k].MaxQntde; qntde >= 0; qntde--)
                {
                    if (CapacRestante - Itens[k].Tamanho * qntde >= 0)
                    {
                        CapacRestante -= Itens[k].Tamanho * qntde;
                        Quantidades[k] = qntde;
                        break;
                    }
                }
            }
            ImprimeVetorInt(Quantidades, ni);
        }
    }
}