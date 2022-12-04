#include "./Funcoes/interfaces.h"
#include "./Funcoes/relatorio.h"
#include "./Funcoes/similaridade.h"

int main(){

    //Variaveis da main
    double time_spent = 0.0;
    clock_t begin;
    clock_t end;

    int tamProdCartesiano, tamPadrao, numPadroes;

    time_t tempo;
    srand((time(&tempo)));

        srand(1);

    //Variaveis de teste
        char* DNA = (char*) calloc(MAX_BUFFER, sizeof(char));
                char* padrao = (char*) calloc(MIN_BUFFER, sizeof(char));

        int linhasLidas = 0;

        tamPadrao = 2; numPadroes = 4;

    tamProdCartesiano = pow(4, tamPadrao);
	char** prodCartesiano = geraProdCartesiano(tamPadrao, tamProdCartesiano);

    printf("\nProduto cartesiano:\n");
    imprimeVetString(tamProdCartesiano, tamPadrao + 1, prodCartesiano);

    char** padroesSorteados = sorteiaPadroes(numPadroes, tamPadrao + 1, tamProdCartesiano, prodCartesiano);

    printf("Padrões sorteados:\n");
    imprimeVetString(numPadroes, tamPadrao + 1, padroesSorteados);

    FILE *fptrHuman = abreArquivo("./ArquivosDNA/human.txt");
    begin = clock();

        long* vetorFreqA = (long*) calloc(numPadroes, sizeof(long));
        long* vetorFreqB = (long*) calloc(numPadroes, sizeof(long));

    while (!feof(fptrHuman)){
        fscanf(fptrHuman, "%s", DNA);

        // printf("\nTEXTO: %s \n", DNA);

        for (int i = 0; i < numPadroes; i++){
        
        // printf("PADRÃO - %s\n", padroesSorteados[i]);

        // vetorFreqA[i] += BMHS(DNA, padroesSorteados[i]);
        // vetorFreqA[i] += ShiftAnd(DNA, padroesSorteados[i]);
        vetorFreqA[i] += KMPAlgorithm(DNA, padroesSorteados[i]);

        }

        linhasLidas++;
    }
    printf("Vetor freqs A: ");
    imprimeVetLong(numPadroes, vetorFreqA);
    printf("Vetor freqs B: ");
    imprimeVetLong(numPadroes, vetorFreqB);

    end = clock();

    mostraTempoGasto(end, begin);

    printf("LINHAS LIDAS %d\n", linhasLidas); linhasLidas = 0;

/*     cabecalhoMain();

    FILE *fptrHuman = abreArquivo("./ArquivosDNA/human.txt");
    begin = clock();

        while (!feof(fptrHuman)){fscanf(fptrHuman, "%s", DNA);linhasLidas++;}
    
    end = clock();

    mostraTempoGasto(end, begin);
    
    printf("LINHAS LIDAS %d\n", linhasLidas); linhasLidas = 0;

   FILE *fptrChimp = abreArquivo("./ArquivosDNA/chimpanzee.txt");
    begin = clock(); 

        while (!feof(fptrChimp)){fscanf(fptrChimp, "%s", DNA);linhasLidas++;}
    
    end = clock();

    mostraTempoGasto(end, begin);
    printf("LINHAS LIDAS %d\n", linhasLidas); linhasLidas = 0; 


    FILE *fptrDog = abreArquivo("./ArquivosDNA/dog.txt");
    begin = clock(); 

        for (int i = 0; i < 100000000; i++){
            while (!feof(fptrDog)){fscanf(fptrDog, "%s", DNA); printf("%s", DNA); linhasLidas++;}
            
        }

    end = clock();

    mostraTempoGasto(end, begin);
    printf("LINHAS LIDAS %d\n", linhasLidas); linhasLidas = 0;     

    
    fclose(fptrHuman);
    // fclose(fptrChimp);
    // fclose(fptrDog);
*/
    return 0;
}

