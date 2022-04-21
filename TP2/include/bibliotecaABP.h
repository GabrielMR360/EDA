#ifndef bibliotecaABP_h
#define bibliotecaABP_h

typedef struct no
{
    int chave;
    int fatorDeBalanceamento;
    struct no *esquerda;
    struct no *direita;
} No;

FILE *abreArquivoLeitura(char *nomeArq);

No *inicializa();

No *inserir(No *raiz, int valor);

void imprime(No *raiz);

No *geraABP();

void libera(No *raiz);

void percorreArvore (No* raiz);

int geraFatorBalanceamento(No* raiz);

#endif