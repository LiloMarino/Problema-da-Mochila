#include "arvore.h"
#include "learquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    AnalisaSolucao(Itens, Quantidades, MelhorSolucao, MSolucao);
    ImprimeVetorInt(Quantidades, NUMERO_DE_ITEMS);
    return CapacRestante;
}

void ProximosRamos(const Elemento Itens[], int Quantidades[], int CapacRestante, int MelhorSolucao[], int *MSolucao)
{
    /*Acha o primeiro elemento diferente de 0 e subtrai 1 dele*/
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
    AnalisaSolucao(Itens, Quantidades, MelhorSolucao, MSolucao);
    ImprimeVetorInt(Quantidades, NUMERO_DE_ITEMS);

    /*Ramifica Novamente*/
    ProximosRamos(Itens, Quantidades, CapacRestante, MelhorSolucao, MSolucao);
}

void AnalisaSolucao(const Elemento Itens[], const int Quantidades[], int MelhorSolucao[], int *MSolucao)
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

void ReiniciaPoda(bool Podado[])
{
    /*Reinicia o vetor de poda*/
    for (int i = 0; i < NUMERO_DE_ITEMS; i++)
    {
        Podado[i] = false;
    }
}

void BranchBound(const Elemento Itens[], int Quantidades[])
{
    int MelhorSolucao[NUMERO_DE_ITEMS];
    int MSolucao = 0;
    int CapacRestante = PrimeiroRamo(Itens, Quantidades, MelhorSolucao, &MSolucao);

    /*Inicializa o vetor de poda*/
    bool Podado[NUMERO_DE_ITEMS];
    ReiniciaPoda(Podado);

    /*Realiza as ramificações pelo método BranchBound*/
    RamificaBranchBound(Itens, Quantidades, CapacRestante, MelhorSolucao, &MSolucao, Podado);
    printf("Solucao:\n");
    ImprimeVetorInt(MelhorSolucao, NUMERO_DE_ITEMS);
    printf("Valor: %d\n", MSolucao);
}

void RamificaBranchBound(const Elemento Itens[], int Quantidades[], int CapacRestante, int MelhorSolucao[], int *MSolucao, bool Podado[])
{
    /*Acha o primeiro elemento diferente de 0 que não esteja podado*/
    int k = -1;
    for (int i = NUMERO_DE_ITEMS - 1; i >= 0; i--)
    {
        if (Quantidades[i] != 0 && Podado[i] == false)
        {
            k = i;
            break;
        }
    }

    if (k == -1)
    {
        /*Não foi encontrado um elemento diferente de 0 ou não podado*/
        return;
    }

    /*Verifica se é necessário ramificar*/
    if (VerificaRamificacao(Itens, Quantidades, k, MSolucao, Podado))
    {
        /*Subtrai 1 do k-ésimo item*/
        Quantidades[k] -= 1;
        CapacRestante += Itens[k].Tamanho;

        /*Verifica se cabe mais dos próximos itens*/
        for (int i = k + 1; i < NUMERO_DE_ITEMS; i++)
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
        AnalisaSolucao(Itens, Quantidades, MelhorSolucao, MSolucao);
        ImprimeVetorInt(Quantidades, NUMERO_DE_ITEMS);
    }
    /*Continua...*/
    RamificaBranchBound(Itens, Quantidades, CapacRestante, MelhorSolucao, MSolucao, Podado);
}

int CalculaLimitante(const Elemento Itens[], const int Quantidades[], const int k)
{
    double Limitante = 0;
    for (int i = 0; i < k; i++)
    {
        Limitante += Itens[i].Prioridade * Quantidades[i];
    }

    Limitante += Itens[k].Prioridade * (Quantidades[k] - 1);

    int Somatorio = 0;
    for (int i = 0; i < k; i++)
    {
        Somatorio += Itens[i].Tamanho * Quantidades[i];
    }

    Limitante += Itens[k + 1].Fator * (CAPACIDADE_DA_MOCHILA - Somatorio - Itens[k].Tamanho * (Quantidades[k] - 1));

    /*Arredonda para cima usando ceil*/
    Limitante = ceil(Limitante);
    return (int)Limitante;
}

bool VerificaRamificacao(const Elemento Itens[], const int Quantidades[], const int k, const int *MSolucao, bool Podado[])
{
    /*Calcula o Limitante*/
    int Limitante = CalculaLimitante(Itens, Quantidades, k);

    if (k == 0)
    {
        /*Compara com a melhor solução*/
        if (Limitante > *MSolucao)
        {
            /*Ramifica*/
            ReiniciaPoda(Podado);
            return true;
        }
        else
        {
            /*Poda*/
            Podado[k] = true;
            return false;
        }
    }
    else
    {
        /*Compara com a solução ótima*/
        int OtimaSolucao = CalculaSolucao(Itens, Quantidades);
        if (Limitante > OtimaSolucao)
        {
            /*Ramifica*/
            ReiniciaPoda(Podado);
            return true;
        }
        else
        {
            /*Poda*/
            Podado[k] = true;
            return false;
        }
    }
}

