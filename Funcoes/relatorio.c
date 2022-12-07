#include "relatorio.h"

void mostraTempoGasto(clock_t end, clock_t begin){
    printf("\tTempo gasto para a execução: %f segundos\n", (double)(end - begin) / CLOCKS_PER_SEC);
}

void escreveStringArquivo(FILE* fptr, char* prefixo, char* conteudo, char* sufixo){
    fprintf(fptr, "%s%s%s", prefixo, conteudo, sufixo);
}

void escreveIntArquivo(FILE* fptr, char* prefixo, int conteudo, char* sufixo){
    fprintf(fptr, "%s%d%s", prefixo, conteudo, sufixo);
}

void escreveLongArquivo(FILE* fptr, char* prefixo, long conteudo, char* sufixo){
    fprintf(fptr, "%s%ld%s", prefixo, conteudo, sufixo);
}

void registraParametros(FILE* fptrLog , int* tamPadrao, int* numPadroes, int* numTentativas){

    escreveStringArquivo(fptrLog, "|", "===========================================================================", "|\n");

    printf("\nQual o tamanho do padrão: ");
    scanf("%d", tamPadrao);

    printf("Número de padrões que serão sorteados: ");
    scanf("%d", numPadroes);
    printf("Número de tentativas: ");
    scanf("%d", numTentativas);

    escreveIntArquivo(fptrLog, "|\tTamanho do padrão:\t", *tamPadrao, "\t|\t");
    escreveIntArquivo(fptrLog, "Nº padrões:\t", *numPadroes, "\t|\t");
    escreveIntArquivo(fptrLog, "Nº tentativas:\t", *numTentativas, "\t|\n");

    escreveStringArquivo(fptrLog, "|", "===========================================================================", "|\n");
}

void registraTempo(FILE* fptrLog, clock_t end, clock_t begin, char* prefixo, char* sufixo){
    fprintf(fptrLog, "%s%lf%s", prefixo, (double)(end - begin) / CLOCKS_PER_SEC, sufixo);
}
