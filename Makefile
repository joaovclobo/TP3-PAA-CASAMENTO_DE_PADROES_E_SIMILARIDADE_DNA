all:
	gcc -o Main main.c Funcoes/*.c  Funcoes/*.h -lm

alg1:
	gcc -o Main main.c Funcoes/*.c  Funcoes/*.h -lm
	./Main 1
	notify-send -u critical "Acabou"

alg2:
	gcc -o Main main.c Funcoes/*.c  Funcoes/*.h -lm
	./Main 2
	notify-send -u critical "Acabou"

alg3:
	gcc -o Main main.c Funcoes/*.c  Funcoes/*.h -lm
	./Main 3
	notify-send -u critical "Acabou"

clean:
	rm Main
	clear