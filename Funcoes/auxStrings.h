#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define MAX_BUFFER 100000
#define MIN_BUFFER 50
#define MAX_PADROES 10

char** iniciaVetString(int tamVetor, int tamString);
void imprimeVetString(int tamVetor, int tamString, char** vetor);
void imprimeVetLong(long tamVetor, long* vetor);

int compare (const void * a, const void * b);
void geraProdCartesianoRecur (char *str, char* data, int last, int index, int* possProdCar, char** prodCartesiano);
char** geraProdCartesiano(int tamPadrao, int tamProdCartesiano);
