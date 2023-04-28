#include "arvore.h"
#include "learquivo.h"
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

void LerDados(char *fn, Elemento Itens[], int Quantidades[])
{
    ArqCmds Dados = abreArquivoCmd(fn);
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
}

void HeuristicaGulosa(Elemento Itens[], int Quantidades[])
{
    int CapacRestante = PrimeiroRamo(Itens,Quantidades);
    ProximosRamos(Itens,Quantidades,CapacRestante);
}

int PrimeiroRamo(Elemento Itens[], int Quantidades[])
{
    /* Máximo do primeiro item*/
    int CapacRestante = CAPACIDADE_DA_MOCHILA;
    CapacRestante -= Itens[0].MaxQntde * Itens[0].Tamanho;
    Quantidades[0] = Itens[0].MaxQntde;
    /* Verifica se cabe mais dos próximos itens*/
    for (int i = 1; i < NUMERO_DE_ITEMS; i++)
    {
        int qntde = 1;
        while (CapacRestante - Itens[i].Tamanho * qntde >= 0)
        {
            qntde++;
        }
        qntde--;
        CapacRestante -= qntde * Itens[i].Tamanho;
        Quantidades[i] = qntde;
    }
    ImprimeVetorInt(Quantidades, NUMERO_DE_ITEMS);
    return CapacRestante;
}

void ProximosRamos(Elemento Itens[], int Quantidades[], int CapacRestante)
{
    /*Achar o primeiro elemento diferente de 0*/
    int j = -1;
    for (int i = NUMERO_DE_ITEMS - 1; i >= 0; i--)
    {
        if (Quantidades[i] != 0)
        {
            Quantidades[i] -= 1;
            CapacRestante += Itens[i].Tamanho;
            j = i+1;
            break;
        }  
    }

    
    if(j == -1)
    {
        /*Não foi encontrado um elemento diferente de 0*/
        return;
    }

    /*Verifica se cabe mais dos próximos itens*/
    for (int i = j; i < NUMERO_DE_ITEMS; i++)
    {
        int qntde = 1;
        while (CapacRestante - Itens[i].Tamanho * qntde >= 0)
        {
            qntde++;
        }
        qntde--;
        CapacRestante -= qntde * Itens[i].Tamanho;
        Quantidades[i] = qntde;
    }
    ImprimeVetorInt(Quantidades, NUMERO_DE_ITEMS);

    /*Ramifica Novamente*/
    ProximosRamos(Itens, Quantidades, CapacRestante);
}