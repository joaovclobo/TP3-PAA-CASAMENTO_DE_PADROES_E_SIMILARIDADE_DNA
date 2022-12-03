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
        char* DNA = (char*) calloc(100000, sizeof(char));
        int linhasLidas = 0;

        tamPadrao = 3; numPadroes = 3;

        char prodCartesiano[16][3] = {"AA", "AT", "AC", "AG", "TA", "TT", "TC", "TG", "CA", "CT", "CC", "CG", "GA", "GT", "GC", "GG"};

    tamProdCartesiano = pow(4, tamPadrao - 1);
	geraProdCartesiano(tamPadrao, tamProdCartesiano);

    printf("Produto cartesiano:\n");
    imprimeVetString(tamProdCartesiano, tamPadrao, prodCartesiano);

    // char** padroesSorteados = sorteiaPadroes(numPadroes, tamPadrao, tamProdCartesiano, prodCartesiano);

    // printf("Padrões sorteados:\n");
    // imprimeVetStringDin(numPadroes, tamPadrao, padroesSorteados);

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