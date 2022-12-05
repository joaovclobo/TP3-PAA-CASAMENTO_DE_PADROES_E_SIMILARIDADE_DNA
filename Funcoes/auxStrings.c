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

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Tamanho máximo da string de entrada. */
#define MAX 250

int main() {
    /* Nosso número na base n. Ele é um vetor
     * de n+1 posições representando um número
     * na base n.
     */
    int *num ;
    /* BASES é a string de entrada, e str
     * receberá cada permutação.
     */ 
    char BASES[MAX], str[MAX] ;
    int n, tamPadrao, i, j, k ;

    int len = tamPadrao, possProdCar = 0;
    char BASES[] = "ATCG";
    char** prodCartesiano = iniciaVetString(tamProdCartesiano, tamPadrao);

    printf("Entre com o tamPadrao: ") ;
    scanf("%d", &tamPadrao) ;

    strcpy(BASES, str) ;
    n = strlen(BASES) ;

    /* Cria o nosso número. Ele é um vetor de
     * tamPadrao+1 posições, sendo que a última é 
     * reservada para indicar quando todos os
     * números de tamanho tamPadrao foram gerados. */
    num = (int *) calloc( (tamPadrao+1), sizeof(int)) ;
    if ( num == NULL ) {
        perror("calloc") ;
        return -1;
    }

    /* Termina quando a última posição do vetor
     * for 1. */
    while ( num[tamPadrao] == 0 ) {
        for ( i = 0; i < n; i++ ) {
            /* processo de mapeamento. */
            for ( j = 0, k = tamPadrao-1; j < tamPadrao; j++ ) {
                str[k] = BASES[num[j]] ;
                k-- ;
            }
            /* Mostra o resultado. */
            str[tamPadrao] = 0 ;
            printf("%s\n", str) ;
            strcpy(prodCartesiano[possProdCar], data);
            possProdCar++;

            /* incrementa o algarismo menos significativo. */
            num[0]++ ;
        }

        /* Muda de "casa" e lança os vai uns. */ 
        for ( i = 0; i < tamPadrao; i++ ) {
            if ( num[i] == n ) {
                num[i] = 0 ;
                num[i+1]++ ;
            }
        }
    }

    return 0 ;
}
