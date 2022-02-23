#ifndef BibArquivo_h
#define BibArquivo_h

#include <stdio.h>

// Leitura do arquivo;
FILE *abre_arquivo_leitura(char *nomeArquivo);

int arquivoMostraConteudo(FILE *parq);

// Separar arquivos por nota;
void separarArquivosPorNota(FILE *parq);

void salvarPalavraNoArquivo(char *palavra, FILE *arquivoPalavras);

void separarPalavrasPorDocumento(char *nomeArquivo, char *nomeArquivoPalavras);

#endif