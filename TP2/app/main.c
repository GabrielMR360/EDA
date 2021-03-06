#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaABP.h"

int main()
{
    int opcao = 0;
    No *raiz = inicializa();

    printf("\n\n\n");
    printf("|---------------Trabalho Prático 02------------|\n");
    printf("|-----------Árvore Binária de Pesquisa---------|\n\n");

    while (opcao != 4)
    {

        printf("|---------------------MENU---------------------|\n");
        printf("|---------1 Gerar ABP--------------------------|\n");
        printf("|---------2 Calcular Fator de Balanceamento----|\n");
        printf("|---------3 Imprimir ABP-----------------------|\n");
        printf("|---------4 Sair-------------------------------|\n");
        printf("|----------------------------------------------|\n");

        printf("Escolha uma opção");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            raiz = geraABP();
            printf("\n\n\nGerando ABP...");
            printf("\n\n\n\nABP gerada!!\n\n\n");
            break;
        case 2:
            printf("\n\n\nCalculando fator de balanceamento...");
            percorreArvore(raiz);
            printf("\n\n\n\nFator de balanceamento calculado para cada nó!!\n\n\n");
            break;
        case 3:
            printf("\n\n\nImprindo ABP...\n\n\n");
            imprime(raiz);
            printf("\n\n\n");
            break;
        case 4:
            printf("\n\n\nSaindo...\n");
            libera(raiz);
            exit(0);
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
    }
    printf("\n");

    return 0;
}