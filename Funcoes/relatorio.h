#include "auxStrings.h"

void mostraTempoGasto(clock_t end, clock_t begin);
void escreveStringArquivo(FILE* fptr, char* prefixo, char* conteudo, char* sufixo);
void escreveIntArquivo(FILE* fptr, char* prefixo, int conteudo, char* sufixo);
void escreveLongArquivo(FILE* fptr, char* prefixo, long conteudo, char* sufixo);
void registraParametros(FILE* fptrLog , int* tamPadrao, int* numPadroes, int* numTentativas);
void registraTempo(FILE* fptrLog, clock_t end, clock_t begin, char* prefixo, char* sufixo);
