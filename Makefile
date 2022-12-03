all:
	gcc -o Main main.c Funcoes/*.c  Funcoes/*.h -lm
	./Main

clean:
	rm Main