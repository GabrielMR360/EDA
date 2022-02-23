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
    separarPalavrasPorDocumento("notas1.txt", "palavras1.txt");
    separarPalavrasPorDocumento("notas2.txt", "palavras2.txt");
    separarPalavrasPorDocumento("notas3.txt", "palavras3.txt");
    separarPalavrasPorDocumento("notas4.txt", "palavras4.txt");
    separarPalavrasPorDocumento("notas5.txt", "palavras5.txt");

    fclose(farq);

    return 0;
}