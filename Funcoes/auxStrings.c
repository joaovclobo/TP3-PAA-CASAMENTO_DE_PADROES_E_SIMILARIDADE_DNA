#include "auxStrings.h"

char** iniciaVetString(int tamVetor, int tamString){
   
   char** vetor = malloc(tamVetor*sizeof(char*));

    for (int i =0 ; i < tamVetor; ++i){
        vetor[i] = malloc(tamString*sizeof(char));
    }

    return vetor;
}

void imprimeVetString(int tamVetor, int tamString, char** vetor){
	for (int i = 0; i < tamVetor; i++){
		printf("%s ", vetor[i]);
	}
    putchar('\n');
}

void imprimeVetLong(long tamVetor, long* vetor){
	for (int i = 0; i < tamVetor; i++){
		printf("%ld ", vetor[i]);
	}
    putchar('\n');
}

//Funções importadas e adaptadas do GeeksforGeeks

void geraProdCartesianoRecur (char *str, char* data, int last, int index, int* possProdCar, char** prodCartesiano){
	int i, len = strlen(str);

	for ( i=0; i<len; i++ )	{

		data[index] = str[i] ;

		if (index == last){
            strcpy(prodCartesiano[*possProdCar], data);
            (*possProdCar)++;
        }
		else{
            geraProdCartesianoRecur (str, data, last, index+1, possProdCar, prodCartesiano);
        }
	}
}

char** geraProdCartesiano(int tamPadrao, int tamProdCartesiano){
	int len = tamPadrao, possProdCar = 0;
    char bases[] = "ATCG";
    char** prodCartesiano = iniciaVetString(tamProdCartesiano, tamPadrao);
        
	char *data = (char *) malloc (sizeof(char) * (len + 1)) ;
	data[len] = '\0';

	qsort(bases, len, sizeof(char), compare);

	geraProdCartesianoRecur (bases, data, len-1, 0, &possProdCar, prodCartesiano);

	free(data);
    return prodCartesiano;
}

int compare (const void * a, const void * b){
	return ( *(char *)a - *(char *)b );
}
