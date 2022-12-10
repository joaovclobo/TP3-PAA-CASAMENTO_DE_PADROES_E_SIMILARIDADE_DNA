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
void imprimeVetString(int tamVetor, int tamString, char** vetor);
void imprimeVetUInt(int tamVetor, unsigned int* vetor);

int compare(const void * a, const void * b);
char *itoa(int value, char *result, int base);

//TODO - verificar esta e outras funçẽos se estão sendo usadas e mudar o nome desse arquivo
void geraProdCartesianoRecur(char *str, char* data, int last, int index, int* possProdCar, char** prodCartesiano);
char** geraProdCartesiano(int tamPadrao, int tamProdCartesiano);
double calculaMediaDouble(int tamVetor, double* vetor);
