#include "auxStrings.h"

void cabecalhoMain();
void recebeParametros(int* tamPadrao, int* numPadroes, int* numTentativas);

//TODO - descrever as funções de manupilação 
FILE* abreArquivoRead(char* nomeArquivo);
FILE* abreArquivoAppend(char* nomeArquivo);
void registraDados(int tipoAlg, int tamPadrao, int numPadroes, int numTentativas, double* tempos, double* similaridadesHxC, double* similaridadesHxD, double* similaridadesCxD);

void mostraTempoGasto(clock_t end, clock_t begin);
