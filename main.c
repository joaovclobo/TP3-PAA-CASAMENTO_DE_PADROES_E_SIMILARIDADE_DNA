#include "./Interfaces/interfaces.h"
#include "./Funcoes/funcoesRelatorio.h"
#include "./Funcoes/funcoesSimilaridade.h"

int main(){

    //Variaveis da main
    double time_spent = 0.0;
    clock_t begin;
    clock_t end;


    //Variaveis de teste
    char* DNA = (char*) calloc(100000, sizeof(char));
    int linhasLidas = 0;

    cabecalhoMain();


    FILE *fptrHuman = abreArquivo("./ArquivosDNA/human.txt");
    begin = clock();

        while (!feof(fptrHuman)){fscanf(fptrHuman, "%s", DNA);linhasLidas++;}
    
    end = clock();

    mostraTempoGasto(end, begin);
    printf("LINHAS LIDAS %d\n", linhasLidas); linhasLidas = 0;
    

/*    FILE *fptrChimp = abreArquivo("./ArquivosDNA/chimpanzee.txt");
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
*/
    
    fclose(fptrHuman);
    // fclose(fptrChimp);
    // fclose(fptrDog);

    return 0;
}