#ifndef ARVORE_H
#define ARVORE_H

#define CAPACIDADE_DA_MOCHILA 400
#define NUMERO_DE_ITEMS 4

struct StElemento
{
    double Fator;
    int Prioridade;
    int Tamanho;
    int MaxQntde;
};

typedef struct StElemento Elemento;

/**
 * @brief Lê os dados do arquivo de entrada e inicializa as estruturas de itens e quantidades.
 * @param fn Nome do arquivo de entrada.
 * @param Itens Vetor de elementos contendo informações de tamanho, prioridade, fator prioridade/tamanho, quantidade máxima de cada item.
 * @param Quantidades Inicializa o Vetor Quantidades.
 * */
void LerDados(char *fn, Elemento Itens[], int Quantidades[]);

/**
 *  @brief Realiza os testes pelo método da Heuristica Gulosa
 *  @note Recomendado apenas para a elaboração de outros métodos por conta da sua ineficiência.
 *  @param Itens Vetor de elementos contendo informações de tamanho, prioridade e quantidade máxima de cada item.
 *  @param Quantidades Vetor de Quantidades já inicializado.
 * */
void HeuristicaGulosa(const Elemento Itens[], int Quantidades[]);

/**
 *  @brief Faz a primeira ramificação da árvore
 *  @param Itens Vetor de elementos contendo informações de tamanho, prioridade e quantidade máxima de cada item.
 *  @param Quantidades Vetor de Quantidades já inicializado.
 *  @param MelhorSolucao Vetor que conterá a sequência da melhor solução.
 *  @param MSolucao Endereço do variável que conterá a melhor solução atual do problema.
 *  @return Retorna a Capacidade Restante do Ramo
 * */
int PrimeiroRamo(const Elemento Itens[], int Quantidades[], int MelhorSolucao[], int *MSolucao);

/**
 *  @brief Faz todas as próximas ramificações depois da primeira
 *  @param Itens Vetor de elementos contendo informações de tamanho, prioridade e quantidade máxima de cada item.
 *  @param Quantidades Vetor de Quantidades do Ramo Anterior.
 *  @param CapacRestante Capacidade Restante do Ramo Anterior.
 *  @param MelhorSolucao Vetor que conterá a sequência da melhor solução.
 *  @param MSolucao Endereço do variável que contém a melhor solução atual do problema.
 * */
void ProximosRamos(const Elemento Itens[], int Quantidades[], int CapacRestante, int MelhorSolucao[], int *MSolucao);

/**
 * @brief Verifica se a solução atual é melhor que a melhor solução e caso seja melhor substitui em MelhorSolucao
 * @param Itens Vetor contendo a base de dados dos itens
 * @param Quantidades Vetor contendo as quantidades dos itens do ramo atual
 * @param MelhorSolucao Vetor contendo a melhor solução
 * @param MSolucao Endereço do variável que contém a melhor solução atual do problema.
 */
void VerificaSolucao(const Elemento Itens[], const int Quantidades[], int MelhorSolucao[], int *MSolucao);

/**
 * @brief Calcula a solução do ramo atual e a retorna
 * @param Itens Vetor contendo a base de dados dos itens
 * @param Quantidades Vetor contendo as quantidades dos itens do ramo atual
 * @return Retorna a solução do ramo atual baseado no vetor Quantidades.
 */
int CalculaSolucao(const Elemento Itens[], const int Quantidades[]);

void BranchBound();

#endif