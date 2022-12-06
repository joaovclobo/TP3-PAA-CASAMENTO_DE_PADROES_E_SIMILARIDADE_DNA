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

    //Variaveis de teste
        srand(1);
        tamPadrao = 8; numPadroes = 4;
    
    cabecalhoMain();

    /*------------------------------- Gera Produto Cartesiano -------------------------------*/
    tamProdCartesiano = pow(TAMBASES, tamPadrao);
	char** prodCartesiano = geraProdCartesiano(tamPadrao, tamProdCartesiano);

    // printf("\n\tProduto cartesiano:\t");
    // imprimeVetString(tamProdCartesiano, tamPadrao + 1, prodCartesiano);


    /*------------------------------- Sorteia Padrões -------------------------------*/
    char** padroesSorteados = sorteiaPadroes(numPadroes, tamPadrao + 1, tamProdCartesiano, prodCartesiano);

    printf("\n\tPadrões sorteados:\t");
    imprimeVetString(numPadroes, tamPadrao + 1, padroesSorteados);

    /*------------------------------- Calcula Similaridades -------------------------------*/

    /*----  Calcula Frequencias Humano ----*/
    begin = clock();

    FILE *fptrHuman = abreArquivo("./ArquivosDNA/human.txt");
    long* freqsHuman = contaFrequenciasBHMS(fptrHuman, "Humano", numPadroes, padroesSorteados);

    end = clock();

    printf("\tVetor freqs Human: "); imprimeVetLong(numPadroes, freqsHuman); 
    mostraTempoGasto(end, begin);


    /*----  Calcula Frequencias Cachoro ----*/
    begin = clock();

    FILE *fptrDog = abreArquivo("./ArquivosDNA/dog.txt");
    long* freqsDog = contaFrequenciasBHMS(fptrDog, "Cachoro", numPadroes, padroesSorteados);

    end = clock();

    printf("\tVetor freqs Dog: "); imprimeVetLong(numPadroes, freqsDog); 
    mostraTempoGasto(end, begin);

    
    /*----  Calcula Frequencias Chimpanzé ----*/
    begin = clock();

    FILE *fptrChimp = abreArquivo("./ArquivosDNA/chimpanzee.txt");
    long* freqsChimp = contaFrequenciasBHMS(fptrChimp, "Chimpanzé", numPadroes, padroesSorteados);

    end = clock();

    printf("\tVetor freqs Chimpanzee: "); imprimeVetLong(numPadroes, freqsChimp); 
    mostraTempoGasto(end, begin);


    /*------------------------------- Fecha os arquivos -------------------------------*/
    fclose(fptrHuman);
    fclose(fptrChimp);
    fclose(fptrDog);

    return 0;
}
