#include "BibArquivo.h"
#include <stdio.h>
#include <string.h> // necessário para strlen;
#include <stdlib.h>
#include <ctype.h> // necessário para ispunct e isdigit;

#define TAMLINHA 9000
#define SIZE 256

struct palavras
{
    char *palavra;
    unsigned int cont;
};

FILE *abreArquivoLeitura(char *nomeArquivo)
{
    return fopen(nomeArquivo, "r");
}

void separarArquivosPorNota(FILE *parq)
{
    FILE *notas1, *notas2, *notas3, *notas4, *notas5;
    char line[TAMLINHA];

    notas1 = fopen("notas1.txt", "w");
    notas2 = fopen("notas2.txt", "w");
    notas3 = fopen("notas3.txt", "w");
    notas4 = fopen("notas4.txt", "w");
    notas5 = fopen("notas5.txt", "w");

    if (notas1 == NULL || notas2 == NULL || notas3 == NULL || notas4 == NULL || notas5 == NULL)
    {
        printf("Erro na gravação do arquivo\n");
    }

    while (fgets(line, TAMLINHA, parq) != NULL) // Enquanto não for o fim do arquivo, lê até o \n
    {
        int tamanhoLinha = 0;

        tamanhoLinha = strlen(line); // tamanho da linha

        for (int i = 0; i < tamanhoLinha; i++) // Percorrer cada posição da linha;
        {
            if (line[i - 1] == '"' && line[i] == ',' && line[i + 1] == '1') // Compara se é igual a nota 1;
            {
                fprintf(notas1, "%s", line); // Separa no arquivo notas1;
            }
            else if (line[i - 1] == '"' && line[i] == ',' && line[i + 1] == '2')
            {
                fprintf(notas2, "%s", line);
            }
            else if (line[i - 1] == '"' && line[i] == ',' && line[i + 1] == '3')
            {
                fprintf(notas3, "%s", line);
            }
            else if (line[i - 1] == '"' && line[i] == ',' && line[i + 1] == '4')
            {
                fprintf(notas4, "%s", line);
            }
            else if (line[i - 1] == '"' && line[i] == ',' && line[i + 1] == '5')
            {
                fprintf(notas5, "%s", line);
            }
        }
    }

    fclose(notas1);
    fclose(notas2);
    fclose(notas3);
    fclose(notas4);
    fclose(notas5);
}

void salvarPalavraNoArquivo(char *palavra, FILE *arquivoPalavras)
{
    char *palavra2;
    char *out = palavra, *put = palavra;

    if (arquivoPalavras == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    // Remove os espaços antes de salvar as palavras no arquivo;
    palavra2 = palavra;
    while (*palavra2 == ' ')
        palavra2++;

    if (palavra2 != palavra)
        memmove(palavra, palavra2, strlen(palavra2) + 1);

    for (; *palavra != '\0'; ++palavra)
    {
        if (*palavra != ' ')
            *put++ = *palavra;
    }
    *put = '\0';

    // printf("%s\n", out);
    fprintf(arquivoPalavras, "%s\n", out);
}

void separarPalavrasPorDocumento(char *nomeArquivoNota, char *nomeArquivoPalavras)
{

    FILE *arquivoAberto = abreArquivoLeitura(nomeArquivoNota);
    FILE *arquivoPalavras = fopen(nomeArquivoPalavras, "w");
    char palavra[TAMLINHA];
    int totalPalavras = 0;

    if (arquivoAberto == NULL)
        printf("Nao foi possivel abrir %s para leitura.\n", nomeArquivoNota);
    else
    {
        while (fscanf(arquivoAberto, "%s", palavra) != EOF)
        {
            int tamanho = strlen(palavra);

            for (int i = 0; i < tamanho; i++)
            {
                if (ispunct(palavra[i]))
                {
                    palavra[i] = ' ';
                }
                if (isdigit(palavra[i]))
                {
                    palavra[i] = ' ';
                }
            }

            if (tamanho > 3)
            {
                salvarPalavraNoArquivo(palavra, arquivoPalavras);
                totalPalavras++;
            }
        }
        printf("%s, possui total palavras %d\n", nomeArquivoNota, totalPalavras);
    }
    fclose(arquivoAberto);
    fclose(arquivoPalavras);
}

int contarPalavrasRepetidas(char *nomeVocabulario, char *nomeArquivoNotas)
{
    FILE *arqVocabulario = fopen(nomeVocabulario, "w");
    // Alocar memória para a primeira palavra para comparar + estrutura de palavras;
    char *palavraChave = (char *)malloc(sizeof(char) * SIZE);
    struct palavras *p = (struct palavras *)malloc(sizeof(struct palavras) * SIZE);
    // Criar variável para ler palavras do arquivo;
    FILE *listaDePalavras = abreArquivoLeitura(nomeArquivoNotas);
    // Variável para armazenar a contagem total de palavras;
    int totalDePalavras = 0;
    long word_list_pos, word_list2_pos;

    // Ler palavras do arquivo linha por linha;
    while (fgets(palavraChave, SIZE, listaDePalavras) != NULL)
    {
        // Remove \n da linha;
        palavraChave[strlen(palavraChave) - 1] = '\0';
        // Inicializar membros da estrutura de palavras;
        // -> acessa os membros da struct que é referenciado pelo ponteiro *p;
        p->palavra = strdup(palavraChave);
        p->cont = 0;
        word_list_pos = ftell(listaDePalavras);

        // Alocar memória para a palavra atual sendo comparada com a palavra-chave
        char *atualPalavra = (char *)malloc(sizeof(char) * SIZE);
        // Criar variável para ler a segunda lista de palavras do arquivo
        // printf("%s", atualPalavra);
        FILE *listaDePalavras2 = abreArquivoLeitura(nomeArquivoNotas);

        while (fgets(atualPalavra, SIZE, listaDePalavras2) != NULL)
        {
            // Remove \n da linha;
            atualPalavra[strlen(atualPalavra) - 1] = '\0';
            // Se a atual palavra lida for igual à palavra-chave, aumenta sua contagem
            if (strcmp(palavraChave, atualPalavra) == 0)
            {
                word_list2_pos = ftell(listaDePalavras2);
                if (word_list2_pos < word_list_pos)
                    break;

                p->cont++;
            }
        }
        totalDePalavras++;

        if (word_list2_pos >= word_list_pos)
            fprintf(arqVocabulario, "%s : %d\n", p->palavra, p->cont);

        // Free para desalocar memória;
        free(p->palavra);
        free(atualPalavra);
        fclose(listaDePalavras2);
    }

    free(p);
    free(palavraChave);
    fclose(listaDePalavras);
    fclose(arqVocabulario);

    return totalDePalavras;
}

void excluirArquivos()
{
    remove("palavras1.txt");
    remove("palavras2.txt");
    remove("palavras3.txt");
    remove("palavras4.txt");
    remove("palavras5.txt");
}