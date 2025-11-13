# compilatore e flag per macchine arm7
CC=gcc
CFLAGS=-std=c11 -Wall -g 

# compilatore e flag per cross-compilazione
# CC=arm-linux-gnueabihf-gcc
# CFLAGS=-std=c11 -g -Wall -static 


all: primi strcmp tok

# stampa elenco dei primi <=N
# l'eseguibile primi dipende da primi.c e primo.s
primi: primi.c primo.s
	$(CC) $(CFLAGS) primi.c primo.s -o primi
	
# confronta le stringhe passate sulla linea di comando con strcmp e armcmp
# $^ = insieme dei prerequisiti
# $@ = il target della regola 
strcmp: strcmp.c strcmp.s
	$(CC) $(CFLAGS) $^ -o $@
	
# implementazione di strtok in ARM
tok: tok.c tok.s
	$(CC) $(CFLAGS) $^ -o $@
	



