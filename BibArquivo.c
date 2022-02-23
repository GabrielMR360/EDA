#include "BibArquivo.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

FILE *abre_arquivo_leitura(char *nomeArquivo)
{
    return fopen(nomeArquivo, "r");
}

void separarArquivosPorNota(FILE *parq)
{
    FILE *notas1, *notas2, *notas3, *notas4, *notas5;
    char line[9000];

    notas1 = fopen("notas1.txt", "w");
    notas2 = fopen("notas2.txt", "w");
    notas3 = fopen("notas3.txt", "w");
    notas4 = fopen("notas4.txt", "w");
    notas5 = fopen("notas5.txt", "w");

    if (notas1 == NULL || notas2 == NULL || notas3 == NULL || notas4 == NULL || notas5 == NULL)
    {
        printf("Erro na gravação do arquivo\n");
    }

    while (fgets(line, 9000, parq) != NULL) // Enquanto não for o fim do arquivo, lê até o \n
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

    if (arquivoPalavras == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(arquivoPalavras, "%s\n", palavra);
}

void separarPalavrasPorDocumento(char *nomeArquivoNota, char *nomeArquivoPalavras)
{

    FILE *arquivoAberto = fopen(nomeArquivoNota, "r");
    FILE *arquivoPalavras = fopen(nomeArquivoPalavras, "w");
    char palavra[9000];
    int totalPalavras = 0;

    if (arquivoAberto == NULL)
        printf("Can't open %s for reading.\n", nomeArquivoNota);
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