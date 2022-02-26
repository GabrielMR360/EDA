#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BibArquivo.h"
#include <stdbool.h>

#define TAMANHO 42000

struct tfidf
{
    float nota[5];
    char *palavra;
};
struct tfidf *tabela;
int tamTabela = 0;

void montaTabela(char *nomeArquivo, struct tfidf *tabela, int coluna, int tamArq);
void calculaTfidf(struct tfidf *tabela, int tamDoc);

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
            contarPalavrasRepetidas("vocabularioNotas1.txt", "palavras1.txt");
            contarPalavrasRepetidas("vocabularioNotas2.txt", "palavras2.txt");
            contarPalavrasRepetidas("vocabularioNotas3.txt", "palavras3.txt");
            contarPalavrasRepetidas("vocabularioNotas4.txt", "palavras4.txt");
            contarPalavrasRepetidas("vocabularioNotas5.txt", "palavras5.txt");
            excluirArquivos();
            break;
        case 3:
            tabela = calloc(500000, sizeof(struct tfidf));
            if (tabela == NULL)
            {
                printf("erro na alocacao da tabela\n");
            }

            int totaNotas1 = totalDePalavrasNoArquivo("vocabularioNotas1.txt");
            int totaNotas2 = totalDePalavrasNoArquivo("vocabularioNotas2.txt");
            int totaNotas3 = totalDePalavrasNoArquivo("vocabularioNotas3.txt");
            int totaNotas4 = totalDePalavrasNoArquivo("vocabularioNotas4.txt");
            int totaNotas5 = totalDePalavrasNoArquivo("vocabularioNotas5.txt");

            montaTabela("vocabularioNotas1.txt", tabela, 0, totaNotas1);
            calculaTfidf(tabela, totaNotas1);
            montaTabela("vocabularioNotas2.txt", tabela, 1, totaNotas2);
            calculaTfidf(tabela, totaNotas2);
            montaTabela("vocabularioNotas3.txt", tabela, 2, totaNotas3);
            calculaTfidf(tabela, totaNotas3);
            montaTabela("vocabularioNotas4.txt", tabela, 3, totaNotas4);
            calculaTfidf(tabela, totaNotas4);
            montaTabela("vocabularioNotas5.txt", tabela, 4, totaNotas4);
            calculaTfidf(tabela, totaNotas4);

            // printa o arquivo depois de pronto, e as repetidas
            for (int i = 0; i < tamTabela; i++)
            {
                printf("%d - %s numero de ocorrencias: %.2f %.2f\n", i, tabela[i].palavra, tabela[i].nota[0], tabela[i].nota[1]);
            }
            printf("numero de palavras : %d\n", tamTabela);
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
    printf("Programa encerrado!\n");

    return 0;
}

void montaTabela(char *nomeArquivo, struct tfidf *tabela, int coluna, int tamArq)
{

    // abre o arquivo
    FILE *ptrArq;
    ptrArq = fopen(nomeArquivo, "r");
    if (NULL == ptrArq)
    {
        printf("falha na abertura do arquivo! \n");
    }

    // variaveis usadas no loop
    bool instancia1;

    // pega palavras do arquivo
    for (int i = 0; i < tamArq; i++)
    {
        // inicializa variáveis para o loop
        instancia1 = true;
        char *guardaPalavra = calloc(30, sizeof(char));
        int *guardaNota = calloc(1, sizeof(int));

        // scaneia a palavra + número de ocorrências no arquivo
        fscanf(ptrArq, "%s", guardaPalavra);
        fscanf(ptrArq, "%d", guardaNota);

        // busca para ver se a palavra já existe no array
        for (int x = 0; x < tamTabela; x++)
        {
            // se achar a primeira instancia, sai do for como repetida
            if (strcmp(guardaPalavra, tabela[x].palavra) == 0)
            {
                tabela[x].nota[coluna] = *guardaNota;
                instancia1 = false;
                break;
            }
        }

        if (instancia1 == true)
        {
            tabela[tamTabela].nota[coluna] = *guardaNota;
            tabela[tamTabela].palavra = calloc(strlen(guardaPalavra), sizeof(char));
            strcpy(tabela[tamTabela].palavra, guardaPalavra);
            tamTabela++;
        }
        free(guardaPalavra);
    }

    // fecha arquivo
    fclose(ptrArq);
}

void calculaTfidf(struct tfidf *tabela, int tamDoc)
{
    int numDoc = 5;
    int numOcor = 0;
    float log;
    for (int linha = 0; linha < tamTabela; linha++)
    {
        numOcor = 0;
        for (int coluna = 0; coluna < 5; coluna++)
        {
            if (tabela[linha].nota[coluna] != 0)
            {
                numOcor++;
            }
        }

        for (int coluna = 0; coluna < 5; coluna++)
        {
            if (numOcor == 1)
            {
                log = 0.7;
                tabela[linha].nota[coluna] = (tabela[linha].nota[coluna] / tamDoc) * log;
            }
            if (numOcor == 2)
            {
                log = 0.4;
                tabela[linha].nota[coluna] = (tabela[linha].nota[coluna] / tamDoc) * log;
            }
            if (numOcor == 3)
            {
                log = 0.2;
                tabela[linha].nota[coluna] = (tabela[linha].nota[coluna] / tamDoc) * log;
            }
            if (numOcor == 4)
            {
                log = 0.1;
                tabela[linha].nota[coluna] = (tabela[linha].nota[coluna] / tamDoc) * log;
            }
            if (numOcor == 5)
            {
                tabela[linha].nota[coluna] = 0;
            }
        }
    }
}