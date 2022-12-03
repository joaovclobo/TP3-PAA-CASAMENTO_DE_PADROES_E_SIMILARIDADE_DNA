#include "similaridade.h"

void criaVetsFrequencias(int* freqsA, int* freqsB, int numPadroes){
    
    freqsA = (int*) calloc(numPadroes, sizeof(int));
    freqsB = (int*) calloc(numPadroes, sizeof(int));
}

char** sorteiaPadroes(int numPadroes, int tamPadrao, int tamProdCartesiano, char prodCartesiano[tamProdCartesiano][tamPadrao]){

    char** padroesSorteados = iniciaVetString(numPadroes, tamPadrao);

    int possSorteadas[numPadroes], possRandon;

    for (int i = 0; i < numPadroes; i++){
        possSorteadas[i] = -1;
    }

    for (int i = 0; i < numPadroes; i++){

        possRandon = rand() % tamProdCartesiano;

        while (possJahSorteada(possRandon, i, possSorteadas) == 1){
            
            possRandon = rand() % tamProdCartesiano;
        }

        strcpy(padroesSorteados[i], prodCartesiano[possRandon]);
        possSorteadas[i] = possRandon;
    }

    return padroesSorteados;
}

int possJahSorteada(int possRandon, int numPadroesSorteados, int* possSorteadas){

    for (int i = 0; i < numPadroesSorteados; i++){
        if (possSorteadas[i] == possRandon){

            return 1;
        }
        
    }

    return 0;
}
