#ifndef BibArquivo_h
#define BibArquivo_h

#include <stdio.h>

// Leitura do arquivo;
FILE *abreArquivoLeitura(char *nomeArquivo);

// Imprime conteúdo do arquivo;
int arquivoMostraConteudo(FILE *parq);

// Separar arquivos por nota;
void separarArquivosPorNota(FILE *parq);

// Salva palavras no arquivo;
void salvarPalavraNoArquivo(char *palavra, FILE *arquivoPalavras);

// Vocabulário de cada arquivo de nota;
void separarPalavrasPorDocumento(char *nomeArquivo, char *nomeArquivoPalavras);

#endif