#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define MAX_BUFFER 100000
#define MIN_BUFFER 50
#define MAX_PADROES 15
#define BASES "ATCG"
#define TAMBASES 4

char** iniciaVetString(int tamVetor, int tamString);

char *itoa(int value, char *result, int base);

char** geraProdCartesiano(int tamPadrao, int tamProdCartesiano);
double calculaMediaDouble(int tamVetor, double* vetor);
