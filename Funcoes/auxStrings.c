#include "auxStrings.h"

char** iniciaVetString(int tamVetor, int tamString){
   
   char** vetor = malloc(tamVetor*sizeof(char*));

    for (int i =0 ; i < tamVetor; ++i){
        vetor[i] = malloc(tamString*sizeof(char));
    }

    return vetor;
}

//Funções importadas e adaptadas do GeeksforGeeks

char** geraProdCartesiano(int tamPadrao, int tamProdCartesiano){
        
    int i, j, k, possProdCar = 0;
    char str[MIN_BUFFER];

    char** prodCartesiano = iniciaVetString(tamProdCartesiano, tamPadrao);

    int *num = (int *) calloc( (tamPadrao+1), sizeof(int));
    if ( num == NULL ) {
        perror("calloc");
        return NULL;
    }

    while ( num[tamPadrao] == 0 ) {
        for ( i = 0; i < TAMBASES; i++ ) {

            for ( j = 0, k = tamPadrao-1; j < tamPadrao; j++ ) {
                str[k] = BASES[num[j]];
                k--;
            }

            str[tamPadrao] = 0;

            strcpy(prodCartesiano[possProdCar], str);
            possProdCar++;

            num[0]++;
        }

        for ( i = 0; i < tamPadrao; i++ ) {
            if ( num[i] == TAMBASES ) {
                num[i] = 0;
                num[i+1]++;
            }
        }
    }

    return prodCartesiano;
}

char *itoa (int value, char *result, int base){
    // check that the base if valid
    if (base < 2 || base > 36) { *result = '\0'; return result; }

    char* ptr = result, *ptr1 = result, tmp_char;
    int tmp_value;

    do {
        tmp_value = value;
        value /= base;
        *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
    } while ( value );

    // Apply negative sign
    if (tmp_value < 0) *ptr++ = '-';
    *ptr-- = '\0';
    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr--= *ptr1;
        *ptr1++ = tmp_char;
    }
    return result;
}

double calculaMediaDouble(int tamVetor, double* vetor){
    double soma = 0;

    for (int i = 0; i < tamVetor; i++){

        soma += vetor[i];
    }
    
    return soma/tamVetor;
}
