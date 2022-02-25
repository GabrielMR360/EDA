#ifndef BibArquivo_h
#define BibArquivo_h

#include <stdio.h>

// Leitura do arquivo;
FILE *abreArquivoLeitura(char *nomeArquivo);

// Imprime conteúdo do arquivo;
int arquivoMostraConteudo(FILE *parq);

// Separar arquivos por nota;
void separarArquivosPorNota(FILE *parq);

// Salva palavras no arquivo e remove os espacos;
void salvarPalavraNoArquivo(char *palavra, FILE *arquivoPalavras);

// Vocabulário de cada arquivo de nota;
void separarPalavrasPorDocumento(char *nomeArquivo, char *nomeArquivoPalavras);

// Conta as palavras repetidas e grava em um novo arquivo;
int contarPalavrasRepetidas(char *nomeVocabulario, char *nomeArquivoNotas);

// Exclui arquivos de palavras após a contagem de palavras repetidas;
void excluirArquivos();

#endif