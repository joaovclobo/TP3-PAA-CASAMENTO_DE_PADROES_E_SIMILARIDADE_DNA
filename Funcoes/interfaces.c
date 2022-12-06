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
