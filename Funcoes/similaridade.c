#include "similaridade.h"

char** sorteiaPadroes(int numPadroes, int tamPadrao, int tamProdCartesiano, char** prodCartesiano){

    char** padroesSorteados = iniciaVetString(numPadroes, tamPadrao);

    int possSorteadas[numPadroes], possRandon;

    for (int i = 0; i < numPadroes; i++){
        possSorteadas[i] = -1;
    }

    for (int i = 0; i < numPadroes; i++){

        possRandon = rand() % tamProdCartesiano;

        while (possJahSorteada(possRandon, i, possSorteadas) == 1){
            
            possRandon = rand() % tamProdCartesiano;
        }

        strcpy(padroesSorteados[i], prodCartesiano[possRandon]);
        possSorteadas[i] = possRandon;
    }

    return padroesSorteados;
}

int possJahSorteada(int possRandon, int numPadroesSorteados, int* possSorteadas){

    for (int i = 0; i < numPadroesSorteados; i++){
        if (possSorteadas[i] == possRandon){

            return 1;
        }
        
    }

    return 0;
}

long BMHS(char* texto, char* padrao){
  long i, j, k, d[MAX_BUFFER + 1], ocorrencias = 0;
  long tamTexto = strlen(texto), tamPadrao = strlen(padrao);

  for (j = 0; j <= MAX_BUFFER; j++)  {
    d[j] = tamPadrao + 1;
  } 

  for (j = 1; j <= tamPadrao; j++){
    d[padrao[j-1]] = tamPadrao - j + 1;
  }

  i = tamPadrao;

 /*-- Pesquisa --*/
  while (i <= tamTexto){
    k = i; 
    j = tamPadrao;
    
    while (texto[k-1] == padrao[j-1] && j > 0) {k--; j--; }
    
    if (j == 0){
      ocorrencias++;

    }

    i += d[texto[i]];
  }

  return ocorrencias;
}

long ShiftAnd(char* texto, char* padrao){
  long Masc[MAX_BUFFER], i, R = 0;
  long ocorrencias = 0;
  long tamTexto = strlen(texto), tamPadrao = strlen(padrao);

  for (i = 0; i < MAX_BUFFER; i++){
    Masc[i] = 0;
  } 
    
  for (i = 1; i <= tamPadrao; i++){ 
    Masc[padrao[i-1] + 127] |= 1 << (tamPadrao - i);
  }

  for (i = 0; i < tamTexto; i++){
    R = ((((unsigned long)R) >> 1) | (1 << (tamPadrao - 1))) & Masc[texto[i] + 127];

      if ((R & 1) != 0){

      ocorrencias++;  
    }
  }

  return ocorrencias;
}

void prefixSuffixArray(char* pat, int tamTexto, int* pps) {
   int length = 0;
   pps[0] = 0;
   int i = 1;
   while (i < tamTexto) {
      if (pat[i] == pat[length]) {
         length++;
         pps[i] = length;
         i++;
      } else {
         if (length != 0)
         length = pps[length - 1];
         else {
            pps[i] = 0;
            i++;
         }
      }
   }
}

long KMPAlgorithm(char* texto, char* padrao) {
   int tamTexto = strlen(padrao);
   int tamPadrao = strlen(texto);
   int pps[tamTexto];
   long ocorrencias = 0;

   prefixSuffixArray(padrao, tamTexto, pps);
   int i = 0;
   int j = 0;
   while (i < tamPadrao) {
      if (padrao[j] == texto[i]) {
         j++;
         i++;
      }
      if (j == tamTexto) {
         ocorrencias++;
         j = pps[j - 1];
      }
      else if (i < tamPadrao && padrao[j] != texto[i]) {
         if (j != 0)
         j = pps[j - 1];
         else
         i = i + 1;
      }
   }

   return ocorrencias;
}
