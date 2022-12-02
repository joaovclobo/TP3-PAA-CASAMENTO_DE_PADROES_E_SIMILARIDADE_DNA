all:
	gcc -o Main main.c Funcoes/funcoesRelatorio.c Funcoes/funcoesRelatorio.h Funcoes/funcoesSimilaridade.c Funcoes/funcoesSimilaridade.h Interfaces/interfaces.c Interfaces/interfaces.h
	./Main

clean:
	rm Main