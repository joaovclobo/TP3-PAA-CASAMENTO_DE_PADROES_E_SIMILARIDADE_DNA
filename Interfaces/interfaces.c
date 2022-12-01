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

int opcoesEncontraCaminho(){

    int escolhaUsuario;

    printf("\nEscolha uma das seguintes opções para encontrar o caminhos:\n\n\
    1) - Utilizando uma função que usa \"Memorization\";\n\
    2) - Utilizando uma função que usa Backtracking;\n\
    3) - Utilizando uma função que usa Froça Bruta;\n\
    4) - Encontrar e mostrar os caminhos (utilizando função que usa \"Memorization\");\n\
    5) - Encontrar a numero de caminhos divisiveis por k (utilizando função que usa Força Bruta).\n");

    scanf("%d", &escolhaUsuario);
    return escolhaUsuario;
}

int opcoesImprimirCaminho(){
    int option = 0;

    printf("\nEscolha uma das seguintes opções para visualizar os caminhos mínimos:\n\n\
    1) - Matriz caminho colorida\n\
    2) - Matriz caminho representada com emojis\n\
    3) - Forma tradicional: Coordenadas\n\
    4) - Matriz de pesos colorida\n");
    

    scanf("%d", &option);

    return option;


}
