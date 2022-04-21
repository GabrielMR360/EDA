#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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

void imprime(No *raiz)
{
    if (raiz != NULL)
    {
        imprime(raiz->esquerda);
        printf("%d ", raiz->chave);
        imprime(raiz->direita);
    }
}

No *geraABP()
{
    FILE *testeA;
    int numeros[50];

    No *raiz = inicializa();

    testeA = abreArquivoLeitura("Exemplo-TesteB.csv");

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

void libera(No *raiz)
{
    if (raiz != NULL)
    {
        libera(raiz->esquerda);
        libera(raiz->direita);
        free(raiz);
    }
}