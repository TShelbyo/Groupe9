CC = gcc
CCOPTS = -Wall

all: main

arbre_naire.o:	arbre_naire.c arbre_naire.h
	${CC} ${CCOPTS} -c arbre_naire.c

arbre_binaire.o:	arbre_binaire.c arbre_binaire.h
	${CC} ${CCOPTS} -c arbre_binaire.c

main.o:	main.c
	${CC} ${CCOPTS} -c main.c

main:	main.o arbre_naire.o arbre_binaire.o
	${CC} ${CCOPTS} -o main main.o arbre_naire.o arbre_binaire.o

clean:
	rm *.o ; rm main
