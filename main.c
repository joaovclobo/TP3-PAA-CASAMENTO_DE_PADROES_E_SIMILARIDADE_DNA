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
    
    cabecalhoMain();

    //TODO - da pra melhorar
    tamProdCartesiano = pow(4, tamPadrao);
	char** prodCartesiano = geraProdCartesiano(tamPadrao, tamProdCartesiano);

    printf("\n\tProduto cartesiano:\t");
    imprimeVetString(tamProdCartesiano, tamPadrao + 1, prodCartesiano);

    char** padroesSorteados = sorteiaPadroes(numPadroes, tamPadrao + 1, tamProdCartesiano, prodCartesiano);

    printf("\n\tPadrões sorteados:\t");
    imprimeVetString(numPadroes, tamPadrao + 1, padroesSorteados);

    begin = clock();
    

    FILE *fptrHuman = abreArquivo("./ArquivosDNA/human.txt");
    long* freqsHuman = contaFrequenciasBHMS(fptrHuman, "Humano", numPadroes, padroesSorteados);

    printf("\tVetor freqs Human: "); imprimeVetLong(numPadroes, freqsHuman); 


    FILE *fptrDog = abreArquivo("./ArquivosDNA/dog.txt");
    long* freqsDog = contaFrequenciasBHMS(fptrDog, "Cachoro", numPadroes, padroesSorteados);

    printf("\tVetor freqs Dog: "); imprimeVetLong(numPadroes, freqsDog); 


    FILE *fptrChimp = abreArquivo("./ArquivosDNA/chimpanzee.txt");
    long* freqsChimp = contaFrequenciasBHMS(fptrChimp, "Chimpanzé", numPadroes, padroesSorteados);

    printf("\tVetor freqs Chimpanzee: "); imprimeVetLong(numPadroes, freqsChimp); 

    end = clock();

    mostraTempoGasto(end, begin);

    // printf("LINHAS LIDAS %d\n", linhasLidas); linhasLidas = 0;

/*     
    cabecalhoMain();

    begin = clock();

        while (!feof(fptrHuman)){fscanf(fptrHuman, "%s", DNA);linhasLidas++;}
    
    end = clock();

    mostraTempoGasto(end, begin);
    
    printf("LINHAS LIDAS %d\n", linhasLidas); linhasLidas = 0;

    begin = clock(); 

        while (!feof(fptrChimp)){fscanf(fptrChimp, "%s", DNA);linhasLidas++;}
    
    end = clock();

    mostraTempoGasto(end, begin);
    printf("LINHAS LIDAS %d\n", linhasLidas); linhasLidas = 0; 


    begin = clock(); 

        for (int i = 0; i < 100000000; i++){
            while (!feof(fptrDog)){fscanf(fptrDog, "%s", DNA); printf("%s", DNA); linhasLidas++;}
            
        }

    end = clock();

    mostraTempoGasto(end, begin);
    printf("LINHAS LIDAS %d\n", linhasLidas); linhasLidas = 0;     
*/
    
    fclose(fptrHuman);
    fclose(fptrChimp);
    fclose(fptrDog);

    return 0;
}

