//TODO - verificar funções que não estaão sendo usadas
#include "./Funcoes/interfaces.h"
#include "./Funcoes/similaridade.h"

int main(int argc, char* argv[]){

    cabecalhoMain();

    clock_t begin;
    clock_t end;

    unsigned int* freqsHuman;
    unsigned int* freqsDog;
    unsigned int* freqsChimp;

    int tamProdCartesiano, tamPadrao, numPadroes, numTentativas;
    short tipoAlg = (short) atoi(argv[1]);

    time_t tempo;
    srand((time(&tempo)));

    recebeParametros(&tamPadrao, &numPadroes, &numTentativas);

    double* similaridadesHxC = (double*) calloc(numTentativas, sizeof(double));
    double* similaridadesHxD = (double*) calloc(numTentativas, sizeof(double));
    double* similaridadesCxD = (double*) calloc(numTentativas, sizeof(double));
    double* tempos = (double*) calloc(numTentativas, sizeof(double));


    /*------------------------------- Gera Produto Cartesiano -------------------------------*/
    tamProdCartesiano = pow(TAMBASES, tamPadrao);
	char** prodCartesiano = geraProdCartesiano(tamPadrao, tamProdCartesiano);
    

    /*------------------------------- Calcula Similaridades -------------------------------*/
    for (int i = 0; i < numTentativas; i++){
        
        /*------------------------------- Sorteia Padrões -------------------------------*/
        char** padroesSorteados = sorteiaPadroes(numPadroes, tamPadrao + 1, tamProdCartesiano, prodCartesiano);

        putchar('\n');

        FILE* fptrHuman = abreArquivoRead("./Arquivos/human.txt");
        FILE* fptrDog = abreArquivoRead("./Arquivos/dog.txt");
        FILE* fptrChimp = abreArquivoRead("./Arquivos/chimpanzee.txt");

        putchar('\n');

        begin = clock();

        /*----  Calcula Frequencias Humano ----*/
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

        /*----  Calcula Frequencias Cachoro ----*/
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
        
        /*----  Calcula Frequencias Chimpanzé ----*/
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

        similaridadesHxC[i] = similaridadeCos(freqsHuman, freqsChimp, numPadroes);
        similaridadesHxD[i] = similaridadeCos(freqsHuman, freqsDog, numPadroes);
        similaridadesCxD[i] = similaridadeCos(freqsChimp, freqsDog, numPadroes);
        
        tempos[i] = (double)(end - begin) / CLOCKS_PER_SEC;

        mostraTempoGasto(end, begin);

        fclose(fptrHuman);
        fclose(fptrDog);
        fclose(fptrChimp);
        
        free(freqsHuman);
        free(freqsDog);
        free(freqsChimp);

    }
    
    /*------------------------------- Escreve os dados da simulação nos respectivos arquivos -------------------------------*/
    registraDados(tipoAlg, tamPadrao, numPadroes, numTentativas, tempos, similaridadesHxC, similaridadesHxD, similaridadesCxD);
    putchar('\n');

    return 0;
}
