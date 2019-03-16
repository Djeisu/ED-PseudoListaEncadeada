main.o: main.c
	gcc -c main.c -g

pseudo-lista.o: pseudo-lista.c
	gcc -c pseudo-lista.c -g

pLista: main.o pseudo-lista.o
	gcc main.o pseudo-lista.o -o PLista -g

run: pLista
	./PLista