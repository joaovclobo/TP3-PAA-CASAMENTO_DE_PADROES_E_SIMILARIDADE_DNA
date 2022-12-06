all:
	gcc -o Main main.c Funcoes/*.c  Funcoes/*.h -lm

alg1:
	gcc -o Main main.c Funcoes/*.c  Funcoes/*.h -lm
	./Main 1
alg2:
	gcc -o Main main.c Funcoes/*.c  Funcoes/*.h -lm
	./Main 2
alg2:
	gcc -o Main main.c Funcoes/*.c  Funcoes/*.h -lm
	./Main 3

clean:
	rm Main
	clear