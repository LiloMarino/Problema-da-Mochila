#ifndef ARVORE_H
#define ARVORE_H

#define CAPACIDADE_DA_MOCHILA 400
#define NUMERO_DE_ITEMS 4

struct StElemento
{
    int Prioridade;
    int Tamanho;
    int MaxQntde;
};

typedef struct StElemento Elemento;

/**
 * @brief Lê os dados do arquivo de entrada e inicializa as estruturas de itens e quantidades.
 * 
 * @param fn Nome do arquivo de entrada.
 * @param Itens Vetor de elementos contendo informações de tamanho, prioridade e quantidade máxima de cada item.
 * @param Quantidades Inicializa o Vetor Quantidades.
 * */
void LerDados(char *fn, Elemento Itens[], int Quantidades[]);

/**
 *  @brief Realiza os testes pelo método da Heuristica Gulosa
 * 
 *  @note Recomendado apenas para a elaboração de outros métodos por conta da sua ineficiência.
 *  @param Itens Vetor de elementos contendo informações de tamanho, prioridade e quantidade máxima de cada item.
 *  @param Quantidades Vetor de Quantidades já inicializado.
 * */
void HeuristicaGulosa(Elemento Itens[], int Quantidades[]);

/**
 *  @brief Faz a primeira ramificação da árvore
 * 
 *  @param Itens Vetor de elementos contendo informações de tamanho, prioridade e quantidade máxima de cada item.
 *  @param Quantidades Vetor de Quantidades já inicializado.
 *  @return 
 * */
int PrimeiroRamo(Elemento Itens[], int Quantidades[]);

/**
 *  @brief Faz todas as próximas ramificações depois da primeira
 * 
 *  @param Itens Vetor de elementos contendo informações de tamanho, prioridade e quantidade máxima de cada item.
 *  @param Quantidades Vetor de Quantidades do Ramo Anterior.
 *  @param CapacRestante Capacidade Restante do Ramo Anterior.
 * */
void ProximosRamos(Elemento Itens[], int Quantidades[], int CapacRestante);

#endif