#include <stdlib.h>
#include <stdio.h>
#include "bibliotecaABP.h"

FILE *abreArquivoLeitura(char *nomeArquivo)
{
    return fopen(nomeArquivo, "r");
}

No *inicializa()
{
    return NULL;
}

No *inserir(No *raiz, int valor)
{
    if (raiz == NULL)
    {
        No *novo = (No *)malloc(sizeof(No));
        novo->chave = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;

        return novo;
    }
    else
    {
        if (valor > raiz->chave)
        {
            raiz->direita = inserir(raiz->direita, valor); // Sobrescrever o endereço da direita com o endereço que a função retornou;
        }
        else if (valor < raiz->chave)
        {
            raiz->esquerda = inserir(raiz->esquerda, valor); // Sobrescrever o endereço da esquerda com o endereço que a função retornou;
        }
    }
    return raiz;
}

No *geraABP()
{
    FILE *testeA;
    int numeros[50];
    char *nomeArq;

    No *raiz = inicializa();

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArq);

    testeA = abreArquivoLeitura(nomeArq);

    if (testeA == NULL)
    {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }

    while (fscanf(testeA, "%d", numeros) != EOF)
    {
        raiz = inserir(raiz, *numeros);
    }
    fclose(testeA);
    return raiz;
}

int max(int num1, int num2)
{
    if (num1 > num2)
    {
        return num1;
    }
    else
    {
        return num2;
    }
}

int altura(No *raiz)
{
    // caso a arvore seja nula
    if (raiz == NULL)
    {
        return 0;
    }

    // recursão que retorna a altura da direita e esquerda
    return 1 + max(altura(raiz->esquerda), altura(raiz->direita));
}

// percorre a árvore gerando o fator de balanceamento
void percorreArvore(No *raiz)
{
    if (raiz == NULL)
        return;
    raiz->fatorDeBalanceamento = geraFatorBalanceamento(raiz);
    percorreArvore(raiz->esquerda);
    percorreArvore(raiz->direita);
}

// gera fator de balanceamento do nó
int geraFatorBalanceamento(No *raiz)
{
    if (raiz == NULL)
        return 0;
    return abs(altura(raiz->esquerda) - altura(raiz->direita));
}

void imprime(No *raiz)
{
    if (raiz != NULL)
    {
        imprime(raiz->esquerda);
        printf("Chave %d ", raiz->chave);
        printf("Fator de Balanceamte do nó %d \n", raiz->fatorDeBalanceamento);
        imprime(raiz->direita);
    }
}

void libera(No *raiz)
{
    if (raiz != NULL)
    {
        libera(raiz->esquerda);
        libera(raiz->direita);
        free(raiz);
    }
}