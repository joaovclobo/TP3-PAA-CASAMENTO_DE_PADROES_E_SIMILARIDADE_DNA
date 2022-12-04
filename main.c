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

        srand(2);

    //Variaveis de teste
        char* DNA = (char*) calloc(MAX_BUFFER, sizeof(char));
                char* padrao = (char*) calloc(MIN_BUFFER, sizeof(char));

        int linhasLidas = 0;

        tamPadrao = 2; numPadroes = 8;

    tamProdCartesiano = pow(4, tamPadrao);
	char** prodCartesiano = geraProdCartesiano(tamPadrao, tamProdCartesiano);

    printf("\nProduto cartesiano:\n");
    imprimeVetString(tamProdCartesiano, tamPadrao + 1, prodCartesiano);

    char** padroesSorteados = sorteiaPadroes(numPadroes, tamPadrao + 1, tamProdCartesiano, prodCartesiano);

    printf("Padrões sorteados:\n");
    imprimeVetString(numPadroes, tamPadrao + 1, padroesSorteados);

    char text[] = "AACCCTGAACCCTGAACCCTGAACCCTGAACCCTG";

        strcpy(DNA, text);

        long* vetorFreqA = (long*) calloc(numPadroes, sizeof(long));
        // long *vetorFreqB = (long*) calloc(numPadroes, sizeof(long));

        printf("\nTEXTO: %s \n", DNA);

        for (int i = 0; i < numPadroes; i++){
        
        printf("PADRÃO - %s\n", padroesSorteados[i]);
        // printf("\n%ld %d\n", strlen(DNA), tamPadrao);

        printf("BMHS - ");
        vetorFreqA[i] = BMHS(DNA, padroesSorteados[i]);
        printf("REPS BMHS: %ld\n", vetorFreqA[i]);

        printf("Shift AND - ");
        vetorFreqA[i] = ShiftAnd(DNA, padroesSorteados[i]);
        printf("REPS SHIFT - AND: %ld\n", vetorFreqA[i]);

        printf("KMP - ");
        vetorFreqA[i] = KMPAlgorithm(DNA, padroesSorteados[i]);
        printf("REPS KMP: %ld\n\n", vetorFreqA[i]);
        
        }

    // imprimeVetLong(numPadroes, vetorFreqA);
    // imprimeVetLong(numPadroes, vetorFreqB);

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

