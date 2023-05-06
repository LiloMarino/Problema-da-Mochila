#ifndef ARVORE_H
#define ARVORE_H

#include <stdbool.h>
#include <stdio.h>
#include "config.h"

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
 * */
void LerDados(char *fn, Elemento Itens[]);

/**
 *  @brief Resolve o problema pelo método da Heuristica Gulosa
 *  @note Recomendado apenas para a elaboração de outros métodos por conta da sua ineficiência.
 *  @param Itens Vetor de elementos contendo informações de tamanho, prioridade e quantidade máxima de cada item.
 *  @param Quantidades Vetor de Quantidades já inicializado.
 *  @param registro Ponteiro para o arquivo de log
 */
void HeuristicaGulosa(const Elemento Itens[], int Quantidades[], FILE *registro);

/**
 * @brief Resolve o problema pelo método da Heurística Míope com Ordenação de Prioridade/Tamanho
 * @param Itens Vetor de elementos contendo informações de tamanho, prioridade e quantidade máxima de cada item.
 * @param Quantidades Vetor de Quantidades já inicializado.
 * @param registro Ponteiro para o arquivo de log
 */
void HeuristicaMOPT(const Elemento Itens[], int Quantidades[], FILE *registro);

/**
 * @brief Resolve o problema pelo método da Heurística Míope com Ordenação de Prioridade
 * @param Itens Vetor de elementos contendo informações de tamanho, prioridade e quantidade máxima de cada item.
 * @param Quantidades Vetor de Quantidades já inicializado.
 * @param registro Ponteiro para o arquivo de log
 * @warning A função reordena a base de dados dos itens
 */
void HeuristicaMOP(Elemento Itens[], int Quantidades[], FILE *registro);

/**
 * @brief Resolve o problema pelo método da Heurística Míope com Ordenação de Tamanho
 * @param Itens Vetor de elementos contendo informações de tamanho, prioridade e quantidade máxima de cada item.
 * @param Quantidades Vetor de Quantidades já inicializado.
 * @param registro Ponteiro para o arquivo de log
 * @warning A função reordena a base de dados dos itens
 */
void HeuristicaMOT(Elemento Itens[], int Quantidades[], FILE *registro);

/**
 *  @brief Faz a primeira ramificação da árvore
 *  @param Itens Vetor de elementos contendo informações de tamanho, prioridade e quantidade máxima de cada item.
 *  @param Quantidades Vetor de Quantidades já inicializado.
 *  @param MelhorSolucao Vetor que conterá a sequência da melhor solução.
 *  @param MSolucao Endereço do variável que conterá a melhor solução atual do problema.
 *  @param registro Ponteiro para o arquivo de log
 *  @return Retorna a Capacidade Restante do Ramo
 * */
int PrimeiroRamo(const Elemento Itens[], int Quantidades[], int MelhorSolucao[], int *MSolucao, FILE *registro);

/**
 *  @brief Faz todas as próximas ramificações depois da primeira
 *  @param Itens Vetor de elementos contendo informações de tamanho, prioridade e quantidade máxima de cada item.
 *  @param Quantidades Vetor de Quantidades do Ramo Anterior.
 *  @param CapacRestante Capacidade Restante do Ramo Anterior.
 *  @param MelhorSolucao Vetor que conterá a sequência da melhor solução.
 *  @param MSolucao Endereço do variável que contém a melhor solução atual do problema.
 *  @param registro Ponteiro para o arquivo de log
 * */
void ProximosRamos(const Elemento Itens[], int Quantidades[], int *CapacRestante, int MelhorSolucao[], int *MSolucao, FILE *registro);

/**
 * @brief Verifica se a solução atual é melhor que a melhor solução e caso seja melhor substitui em MelhorSolucao
 * @param Itens Vetor contendo a base de dados dos itens
 * @param Quantidades Vetor contendo as quantidades dos itens do ramo atual
 * @param MelhorSolucao Vetor contendo a melhor solução
 * @param MSolucao Endereço do variável que contém a melhor solução atual do problema.
 */
void AnalisaSolucao(const Elemento Itens[], const int Quantidades[], int MelhorSolucao[], int *MSolucao);

/**
 * @brief Calcula a solução do ramo atual e a retorna
 * @param Itens Vetor contendo a base de dados dos itens
 * @param Quantidades Vetor contendo as quantidades dos itens do ramo atual
 * @return Retorna a solução do ramo atual baseado no vetor Quantidades.
 */
int CalculaSolucao(const Elemento Itens[], const int Quantidades[]);

/**
 * @brief Resolve o problema pelo método Branch Bound.
 * @param Itens Vetor contendo a base de dados dos itens.
 * @param Quantidades Vetor de Quantidades já inicializado.
 * @param registro Ponteiro para o arquivo de log
 */
void BranchBound(const Elemento Itens[], int Quantidades[], FILE *registro);

/**
 * @brief Realiza as ramificações pelo método Branch Bound.
 * @param Itens Vetor contendo a base de dados dos itens.
 * @param Quantidades Vetor de Quantidades do Ramo Anterior.
 * @param CapacRestante Capacidade Restante do Ramo Anterior.
 * @param MelhorSolucao Vetor que conterá a sequência da melhor solução.
 * @param MSolucao Endereço do variável que contém a melhor solução atual do problema.
 * @param Podado Vetor que indica se o elemento da árvore está podado ou não.
 * @param registro Ponteiro para o arquivo de log
 */
void RamificaBranchBound(const Elemento Itens[], int Quantidades[], int CapacRestante, int MelhorSolucao[], int *MSolucao, bool Podado[], FILE *registro);

/**
 * @brief Calcula o Limitante do Ramo Atual para a verificação de poda.
 * @param Itens Vetor contendo a base de dados dos itens.
 * @param Quantidades Vetor de Quantidades do Ramo Atual.
 * @param k índice do elemento a ser verificado a poda.
 * @return Retorna o Limitante.
 */
int CalculaLimitante(const Elemento Itens[], const int Quantidades[], const int k);

/**
 * @brief Verifica se é necessário ou não podar o ramo pelo cálculo do limitante
 * @param Itens Vetor contendo a base de dados dos itens.
 * @param Quantidades Vetor de Quantidades do Ramo Atual.
 * @param k índice do elemento a ser verificado a poda.
 * @param MSolucao Endereço do variável que contém a melhor solução atual do problema.
 * @param Podado Vetor que indica se o elemento da árvore está podado ou não.
 * @return Retorna verdadeiro se é necessário ramificar e falso caso seja necessário podar.
 */
bool VerificaRamificacao(const Elemento Itens[], const int Quantidades[], const int k, const int *MSolucao, bool Podado[]);

#endif