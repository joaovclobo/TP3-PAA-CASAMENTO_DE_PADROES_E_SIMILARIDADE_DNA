#include "auxStrings.h"

char** sorteiaPadroes(int numPadroes, int tamPadrao, int tamProdCartesiano, char** prodCartesiano);
int possJahSorteada(int novaPoss, int numPadroesSorteados, int* possSorteadas);

unsigned int BMHS(char* texto, char* padrao);
unsigned int ShiftAnd(char* texto, char* padrao);
void prefixSuffixArray(char* pat, int tamTexto, int* pps);
unsigned int KMPAlgorithm(char* texto, char* padrao);

unsigned int* contaFrequenciasBHMS(FILE* fptr, char* tipoDNA, int numPadroes, char** padroesSorteados);
unsigned int* contaFrequenciasShiftAnd(FILE* fptr, char* tipoDNA, int numPadroes, char** padroesSorteados);
unsigned int* contaFrequenciasKMP(FILE* fptr, char* tipoDNA, int numPadroes, char** padroesSorteados);

double similaridadeCos(unsigned int* freqsDNA1, unsigned int* freqsDNA2, int numPadroes);
