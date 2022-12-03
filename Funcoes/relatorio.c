#include "relatorio.h"

void mostraTempoGasto(clock_t end, clock_t begin){
    printf("\nTempo gasto para a execução: %f segundos\n", (double)(end - begin) / CLOCKS_PER_SEC);
}
