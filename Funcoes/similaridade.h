#include "auxStrings.h"

char** sorteiaPadroes(int numPadroes, int tamPadrao, int tamProdCartesiano, char** prodCartesiano);
int possJahSorteada(int novaPoss, int numPadroesSorteados, int* possSorteadas);

long BMHS(char* texto, char* padrao);
long ShiftAnd(char* texto, char* padrao);
void prefixSuffixArray(char* pat, int tamTexto, int* pps);
long KMPAlgorithm(char* texto, char* padrao);

long* contaFrequenciasBHMS(FILE* fptr, char* tipoDNA, int numPadroes, char** padroesSorteados);
long* contaFrequenciasShiftAnd(FILE* fptr, char* tipoDNA, int numPadroes, char** padroesSorteados);
long* contaFrequenciasKMP(FILE* fptr, char* tipoDNA, int numPadroes, char** padroesSorteados);
