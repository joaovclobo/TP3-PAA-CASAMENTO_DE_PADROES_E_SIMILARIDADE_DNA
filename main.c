#include "./Funcoes/interfaces.h"
#include "./Funcoes/relatorio.h"
#include "./Funcoes/similaridade.h"

int main(int argc, char* argv[]){

    cabecalhoMain();

    double time_spent = 0.0;
    clock_t begin, beginTotal;
    clock_t end, endTotal;

    long* freqsHuman;
    long* freqsDog;
    long* freqsChimp;

    int tamProdCartesiano, tamPadrao, numPadroes, numTentativas;
    short tipoAlg = (short) atoi(argv[1]);

    time_t tempo;
    srand((time(&tempo)));

    FILE* fptrLog = abreArquivoAppend("./Arquivos/simulacoesLog.txt");

                //Variaveis de teste
                tamPadrao = 2; numPadroes = 4;
                srand(1);


    registraParametros(fptrLog, &tamPadrao, &numPadroes, &numTentativas);

    /*------------------------------- Gera Produto Cartesiano -------------------------------*/
    tamProdCartesiano = pow(TAMBASES, tamPadrao);
	char** prodCartesiano = geraProdCartesiano(tamPadrao, tamProdCartesiano);

    /*------------------------------- Sorteia Padrões -------------------------------*/


    /*------------------------------- Calcula Similaridades -------------------------------*/

    for (int i = 0; i < numTentativas; i++){
        
        char** padroesSorteados = sorteiaPadroes(numPadroes, tamPadrao + 1, tamProdCartesiano, prodCartesiano);

        FILE* fptrHuman = abreArquivoRead("./Arquivos/human.txt");
        FILE* fptrDog = abreArquivoRead("./Arquivos/dog.txt");
        FILE* fptrChimp = abreArquivoRead("./Arquivos/chimpanzee.txt");

        printf("\n\tPadrões sorteados:\t");
        imprimeVetString(numPadroes, tamPadrao + 1, padroesSorteados);

        beginTotal = clock();

        /*----  Calcula Frequencias Humano ----*/
        begin = clock();

        switch (tipoAlg){
            case 1:     freqsHuman = contaFrequenciasBHMS(fptrHuman, "Humano", numPadroes, padroesSorteados);
            break;

            case 2:     freqsHuman = contaFrequenciasShiftAnd(fptrHuman, "Humano", numPadroes, padroesSorteados);
            break;

            case 3:     freqsHuman = contaFrequenciasKMP(fptrHuman, "Humano", numPadroes, padroesSorteados);
            break;
        
        default:
            break;
        }
        end = clock();

        printf("\tVetor freqs Human: "); imprimeVetLong(numPadroes, freqsHuman); putchar('\n');
        // mostraTempoGasto(end, begin);
        registraTempo(fptrLog, end, begin, "", ",");


        /*----  Calcula Frequencias Cachoro ----*/
        begin = clock();

        switch (tipoAlg){
            case 1:     freqsDog = contaFrequenciasBHMS(fptrDog, "Cachoro", numPadroes, padroesSorteados);
            break;

            case 2:     freqsDog = contaFrequenciasShiftAnd(fptrDog, "Cachoro", numPadroes, padroesSorteados);
            break;

            case 3:     freqsDog = contaFrequenciasKMP(fptrDog, "Cachoro", numPadroes, padroesSorteados);
            break;
        
        default:
            break;
        }
        end = clock();

        printf("\tVetor freqs Dog: "); imprimeVetLong(numPadroes, freqsDog); putchar('\n');
        // mostraTempoGasto(end, begin);
        registraTempo(fptrLog, end, begin, "", ",");

        
        /*----  Calcula Frequencias Chimpanzé ----*/
        begin = clock();

        switch (tipoAlg){
            case 1:     freqsChimp = contaFrequenciasBHMS(fptrChimp, "Chimpanzé", numPadroes, padroesSorteados);
            break;

            case 2:     freqsChimp = contaFrequenciasShiftAnd(fptrChimp, "Chimpanzé", numPadroes, padroesSorteados);
            break;

            case 3:     freqsChimp = contaFrequenciasKMP(fptrChimp, "Chimpanzé", numPadroes, padroesSorteados);
            break;
        
        default:
            break;
        }
        end = clock();

        endTotal = clock();

        printf("\tVetor freqs Chimpanzee: "); imprimeVetLong(numPadroes, freqsChimp); putchar('\n');
        // mostraTempoGasto(end, begin);
        registraTempo(fptrLog, end, begin, "", "\n");

        registraTempo(fptrLog, endTotal, beginTotal, "", "\n");

        //TODO talvez pode ficar em outro lugar
        
        fclose(fptrHuman);
        fclose(fptrChimp);
        fclose(fptrDog);
        
        free(freqsHuman);
        free(freqsDog);
        free(freqsChimp);

    //TODO - Coloca calculo de similaridade


    }


    fclose(fptrLog);

    return 0;
}
