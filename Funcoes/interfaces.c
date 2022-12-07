#include "interfaces.h"

void cabecalhoMain(){
    printf("\n\n|============================== Universidade Federal De Viçosa - Campus Florestal ==============================|\n\
|================== Trabalho prático 2 - Disciplina CCF 330 - PROJETO E ANÁLISE DE ALGORITMOS ==================|\n\
|========================================== Viagem com custo mínimo ============================================|\n\
|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n\
|Professor responsável:\t\t\t\t\t\t\t\t\t\t\t\t|\n\
|\tDaniel Mendes Barbosa\t\t\t\t\t\t\t\t\t\t\t|\n\
|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n\
|Alunos responsáveis:\t\t\t\t\t\t\t\t\t\t\t\t|\n\
|\tThiago Rocha - 4225\t\t\t\t\t\t\t\t\t\t\t|\n\
|\tAroldo Simões - 4250\t\t\t\t\t\t\t\t\t\t\t|\n\
|\tJoao Lobo - 4693\t\t\t\t\t\t\t\t\t\t\t|\n\
|\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n\
|===============================================================================================================|\n\n");
}

void recebeParametros(int* tamPadrao, int* numPadroes, int* numTentativas){

    printf("\nQual o tamanho do padrão: ");
    scanf("%d", tamPadrao);

    printf("Número de padrões que serão sorteados (Max: %.lf): ", pow(TAMBASES, *tamPadrao));
    scanf("%d", numPadroes);

    printf("Número de tentativas: ");
    scanf("%d", numTentativas);

}

FILE* abreArquivoRead(char* nomeArquivo){

    FILE *fptr;

    printf("\tAbrindo o arquivo: %s\n", nomeArquivo);
    
    fptr = fopen(nomeArquivo, "r");

    if (fptr == NULL){
        printf("\nERRO: Arquivo não encontrado!\nPor favor, insira um arquivo válido!\n");
        return NULL;

    } else{
        return fptr;

    }
}

FILE* abreArquivoAppend(char* nomeArquivo){

    FILE *fptr;

    printf("\tAbrindo o arquivo: %s\n", nomeArquivo);
    
    fptr = fopen(nomeArquivo, "a");

    if (fptr == NULL){
        printf("\nERRO: Arquivo não encontrado!\nPor favor, insira um arquivo válido!\n");
        return NULL;

    } else{
        return fptr;

    }
}

void registraDados(int tipoAlg, int tamPadrao, int numPadroes, int numTentativas, double* tempos, double* similaridadesHxC, double* similaridadesHxD, double* similaridadesCxD){
    
    FILE* fptrSimulacoes = abreArquivoAppend("./Arquivos/similaridades.csv");
    FILE* fptrTempos = abreArquivoAppend("./Arquivos/tempos.csv");

    double mediaSimilaridadeHxC = calculaMediaDouble(numTentativas, similaridadesHxC);
    double mediaSimilaridadeHxD = calculaMediaDouble(numTentativas, similaridadesHxD);
    double mediaSimilaridadeCxD = calculaMediaDouble(numTentativas, similaridadesCxD);
    double tempoMedio = calculaMediaDouble(numTentativas, tempos);

    fprintf(fptrSimulacoes, "%d,%d,%d,%d,%lf,%lf,%lf\n", tipoAlg, tamPadrao, numPadroes, numTentativas, mediaSimilaridadeHxC, mediaSimilaridadeHxD, mediaSimilaridadeCxD);
    fprintf(fptrTempos, "%d,%d,%d,%d,%lf\n", tipoAlg, tamPadrao, numPadroes, numTentativas, tempoMedio);
     
    fclose(fptrSimulacoes);
    fclose(fptrTempos);

}

void mostraTempoGasto(clock_t end, clock_t begin){
    printf("\n\tTempo gasto para a execução: %f segundos\n\n", (double)(end - begin) / CLOCKS_PER_SEC);
}
