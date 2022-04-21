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

No *geraABP();

int max(int num1, int num2);

int altura(No *raiz);

void percorreArvore(No *raiz);

int geraFatorBalanceamento(No *raiz);

void imprime(No *raiz);

void libera(No *raiz);

#endif