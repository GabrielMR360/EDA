#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaABP.h"

int main()
{
    No *raiz = inicializa();

    raiz = geraABP();

    imprime(raiz);

    printf("\n");

    libera(raiz);

    return 0;
}