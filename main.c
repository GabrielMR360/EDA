#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BibArquivo.h"

int main()
{
    FILE *farq;
    int opcao = 0;
    // Nome do dataset "tripadvisor_hotel_reviews.csv"
    char *nomeDataSet;

    printf("|##########TRABALHO-1 VETORES-DINAMICOS########|\n\n");
    while (opcao != 4)
    {
        printf("|---------------------MENU---------------------|\n");
        printf("|---------1 Abrir arquivo das avaliacoes-------|\n");
        printf("|---------2 Gerar vocabulario para cada nota---|\n");
        printf("|---------3 Exibir TF-IDFs---------------------|\n");
        printf("|---------4 Exibir TF-IDF de uma nota----------|\n");
        printf("|---------5 Sair-------------------------------|\n");
        printf("|----------------------------------------------|\n");

        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Informe o nome do arquivo principal: ");
            scanf("%s", nomeDataSet);

            farq = abreArquivoLeitura(nomeDataSet);

            if (farq == NULL)
            {
                printf("Erro na abertura do arquivo.\n");
            }
            else
            {
                printf("Arquivo aberto com sucesso!\n");
            }

            separarArquivosPorNota(farq);

            break;
        case 2:
            separarPalavrasPorDocumento("notas1.txt", "palavras1.txt");
            separarPalavrasPorDocumento("notas2.txt", "palavras2.txt");
            separarPalavrasPorDocumento("notas3.txt", "palavras3.txt");
            separarPalavrasPorDocumento("notas4.txt", "palavras4.txt");
            separarPalavrasPorDocumento("notas5.txt", "palavras5.txt");
            break;
        case 3:
            printf("TF-IDF de todas as notas\n");
            break;
        case 4:
            printf("TF-IFD de uma nota especifica\n");
            break;
        case 5:
            break;

        default:
            printf("Opcao invalida\n");
            break;
        }
        if (opcao == 5)
        {
            break;
        }
    }

    fclose(farq);

    return 0;
}