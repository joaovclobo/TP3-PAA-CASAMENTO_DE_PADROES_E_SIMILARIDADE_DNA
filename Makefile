all:
	gcc -o Main main.c Interfaces/interfaces.c Interfaces/interfaces.h
	./Main

clean:
	rm Main