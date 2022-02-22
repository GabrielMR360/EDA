#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BibArquivo.h"

int main()
{
    FILE *farq;

    farq = abre_arquivo_leitura("tripadvisor_hotel_reviews.csv");

    if (farq == NULL)
    {
        printf("Erro na abertura do arquivo.\n");
        exit(1);
    }
    else
    {
        printf("Arquivo aberto com sucesso!\n");
    }

    separarArquivosPorNota(farq);

    fclose(farq);

    return 0;
}