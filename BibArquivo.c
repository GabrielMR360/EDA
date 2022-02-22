#include "BibArquivo.h"
#include <stdio.h>
#include <string.h>

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

    int maiorLinha = 0;

    while (fgets(line, 9000, parq) != NULL) // Enquanto não for o fim do arquivo, lê até o \n
    {
        int tamanhoLinha = 0;

        tamanhoLinha = strlen(line); // tamanho da linha

        if (maiorLinha < tamanhoLinha)
        {
            maiorLinha = tamanhoLinha;
        }

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
    printf("%d", maiorLinha);
    fclose(notas1);
    fclose(notas2);
    fclose(notas3);
    fclose(notas4);
    fclose(notas5);
}

int arquivo_MostraConteudo(FILE *parq)
{
    int c;
    if (parq == NULL)
        return 0; // Erro: ponteiro não apontado.
    while (1)
    {
        c = fgetc(parq);
        if (feof(parq))
        {
            break;
        }
        printf("%c", c);
    }
    return 1;
}