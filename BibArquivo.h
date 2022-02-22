#ifndef BibArquivo_h
#define BibArquivo_h

#include <stdio.h>

// Leitura do arquivo;
FILE *abre_arquivo_leitura(char *nomeArquivo);

int arquivo_MostraConteudo(FILE *parq);

// Separar arquivos por nota;
void separarArquivosPorNota(FILE *parq);

#endif