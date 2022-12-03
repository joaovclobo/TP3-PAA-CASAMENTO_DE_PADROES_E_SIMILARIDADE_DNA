#include "auxStrings.h"

char** iniciaVetString(int tamVetor, int tamString){
   
   char** vetor = malloc(tamVetor*sizeof(char*));

    for (int i =0 ; i < tamVetor; ++i){
        vetor[i] = malloc(tamString*sizeof(char));
    }

    return vetor;
}

void imprimeVetString(int tamVetor, int tamString, char vetor[tamVetor][tamString]){
	for (int i = 0; i < tamVetor; i++){
		printf("%s ", vetor[i]);
	}
    putchar('\n');
}

void imprimeVetStringDin(int tamVetor, int tamString, char** vetor){
	for (int i = 0; i < tamVetor; i++){
		printf("%s ", vetor[i]);
	}
    putchar('\n');
}

//Funções importadas e adaptadas do GeeksforGeeks

void geraProdCartesianoRecur (char *str, char* data, int last, int index){
	int i, len = strlen(str);

	for ( i=0; i<len; i++ )	{

		data[index] = str[i] ;

		if (index == last)
			printf("%s ", data);
		else 
			geraProdCartesianoRecur (str, data, last, index+1);
	}
}

void geraProdCartesiano(int tamPadrao, int tamProdCartesiano){
	int len = tamPadrao - 1, tam;
    char bases[] = "ATCG";
    char** prodCartesiano = iniciaVetString(tamProdCartesiano, tamPadrao);
        
	char *data = (char *) malloc (sizeof(char) * (len + 1)) ;
	data[len] = '\0';

	qsort(bases, len, sizeof(char), compare);

	geraProdCartesianoRecur (bases, data, len-1, 0);

                        putchar('\n');

	free(data);
}

int compare (const void * a, const void * b){
	return ( *(char *)a - *(char *)b );
}
