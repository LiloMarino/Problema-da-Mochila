#include "arvore.h"
#include "learquivo.h"
#include <stdio.h>
#include <stdlib.h>

/*Função para imprimir um vetor de inteiros*/
void ImprimeVetorInt(const int vetor_int[], const int ni)
{
    // Imprime o vetor int
    for (int i = 0; i < ni; i++)
    {
        printf("%d ", vetor_int[i]);
    }
    printf("\n");
}

/*Função usada para o qsort ordenar o vetor de Elementos*/
int ComparaElementos(const void *a, const void *b)
{
    const Elemento *elem1 = (const Elemento *)a;
    const Elemento *elem2 = (const Elemento *)b;

    if (elem1->Fator > elem2->Fator)
    {
        return -1;
    }
    else if (elem1->Fator < elem2->Fator)
    {
        return 1;
    }
    else
    {
        return 0;
    }
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

    /*Máx de cada item e Fator Priodade/Tamanho*/
    for (int i = 0; i < NUMERO_DE_ITEMS; i++)
    {
        Itens[i].MaxQntde = CAPACIDADE_DA_MOCHILA / Itens[i].Tamanho;
        Itens[i].Fator = (double)Itens[i].Prioridade / Itens[i].Tamanho;
        Quantidades[i] = 0;
    }

    /*Ordena os Itens do maior Fator para o menor utilizando a função qsort*/
    qsort(Itens, NUMERO_DE_ITEMS, sizeof(Elemento), ComparaElementos);
}

void HeuristicaGulosa(const Elemento Itens[], int Quantidades[])
{
    int MelhorSolucao[NUMERO_DE_ITEMS];
    int MSolucao = 0;
    int CapacRestante = PrimeiroRamo(Itens, Quantidades, MelhorSolucao, &MSolucao);
    ProximosRamos(Itens, Quantidades, CapacRestante, MelhorSolucao, &MSolucao);
    printf("Solucao:\n");
    ImprimeVetorInt(MelhorSolucao, NUMERO_DE_ITEMS);
    printf("Valor: %d\n", MSolucao);
}

int PrimeiroRamo(const Elemento Itens[], int Quantidades[], int MelhorSolucao[], int *MSolucao)
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
    /*Verifica a primeira Solução*/
    *MSolucao = 0;
    VerificaSolucao(Itens, Quantidades, MelhorSolucao, MSolucao);
    ImprimeVetorInt(Quantidades, NUMERO_DE_ITEMS);
    return CapacRestante;
}

void ProximosRamos(const Elemento Itens[], int Quantidades[], int CapacRestante, int MelhorSolucao[], int *MSolucao)
{
    /*Achar o primeiro elemento diferente de 0*/
    int j = -1;
    for (int i = NUMERO_DE_ITEMS - 1; i >= 0; i--)
    {
        if (Quantidades[i] != 0)
        {
            Quantidades[i] -= 1;
            CapacRestante += Itens[i].Tamanho;
            j = i + 1;
            break;
        }
    }

    if (j == -1)
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
    VerificaSolucao(Itens, Quantidades, MelhorSolucao, MSolucao);
    ImprimeVetorInt(Quantidades, NUMERO_DE_ITEMS);

    /*Ramifica Novamente*/
    ProximosRamos(Itens, Quantidades, CapacRestante, MelhorSolucao, MSolucao);
}

void VerificaSolucao(const Elemento Itens[], const int Quantidades[], int MelhorSolucao[], int *MSolucao)
{
    int Solucao = CalculaSolucao(Itens, Quantidades);
    /*Verifica se a solução atual é a nova melhor solução*/
    if (Solucao > *MSolucao)
    {
        for (int i = 0; i < NUMERO_DE_ITEMS; i++)
        {
            MelhorSolucao[i] = Quantidades[i];
        }
        *MSolucao = Solucao;
        return;
    }
    else
    {
        return;
    }
}

int CalculaSolucao(const Elemento Itens[], const int Quantidades[])
{
    int Solucao = 0;
    for (int i = 0; i < NUMERO_DE_ITEMS; i++)
    {
        Solucao += Quantidades[i] * Itens[i].Prioridade;
    }
    return Solucao;
}

void BranchBound()
{
}
