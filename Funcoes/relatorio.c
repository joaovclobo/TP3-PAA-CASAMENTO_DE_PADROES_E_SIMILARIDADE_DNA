#include "relatorio.h"

FILE* abreArquivoRead(char* nomeArquivo){

    FILE *fptr;

    printf("\n\tAbrindo o arquivo: %s\n", nomeArquivo);
    
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

    printf("\n\tAbrindo o arquivo: %s\n", nomeArquivo);
    
    fptr = fopen(nomeArquivo, "a");

    if (fptr == NULL){
        printf("\nERRO: Arquivo não encontrado!\nPor favor, insira um arquivo válido!\n");
        return NULL;

    } else{
        return fptr;

    }
}

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

char* geraNomeArquivo(int tamPadrao, int numPadroes, int numTentativas, int tipoAlg){
    
    char* nomeArquivo = calloc(MAX_BUFFER, sizeof(char));
    char* aux = calloc(MAX_BUFFER, sizeof(char));

    strcat(nomeArquivo, "./Arquivos/SIMULACAO-"); 
    itoa(numPadroes, aux, 10);
    strcat(nomeArquivo, aux);
    itoa(tamPadrao, aux, 10);
    strcat(nomeArquivo, "-"); strcat(nomeArquivo, aux);
    itoa(numTentativas, aux, 10);
    strcat(nomeArquivo, "x"); strcat(nomeArquivo, aux);

    switch (tipoAlg){
    case 1:
        strcat(nomeArquivo, "-"); strcat(nomeArquivo, "BMHS.txt");
        break;
    
    case 2:
        strcat(nomeArquivo, "-"); strcat(nomeArquivo, "ShiftAnd.txt");
    break;
    
    case 3:
        strcat(nomeArquivo, "-"); strcat(nomeArquivo, "KMP.txt");
    break;
    
    default:
        break;
    }

    printf("Nome do arquivo da simulação: %s\n", nomeArquivo);
    return nomeArquivo;
}

void registraParametros(int* tamPadrao, int* numPadroes, int* numTentativas){

    printf("\nQual o tamanho do padrão: ");
    scanf("%d", tamPadrao);

    printf("Número de padrões que serão sorteados: ");
    scanf("%d", numPadroes);

    printf("Número de tentativas: ");
    scanf("%d", numTentativas);

}

void registraTempo(FILE* fptrLog, clock_t end, clock_t begin){
    fprintf(fptrLog, "%lf\n", (double)(end - begin) / CLOCKS_PER_SEC);
}
