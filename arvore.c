#include "arvore.h"
#include <stdio.h>

void ImprimeVetorInt(int vetor_int[], int ni)
{
    // Imprime o vetor int
    for (int i = 0; i < ni; i++)
    {
        printf("%d ", vetor_int[i]);
    }
    printf("\n");
}

void HeuristicaGulosa(Elemento Itens[], int Quantidades[])
{
    /*Heuristica Gulosa*/
    int i;
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
            ImprimeVetorInt(Quantidades, NUMERO_DE_ITEMS);
        }
    }
}
