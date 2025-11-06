# Per maggiori informazioni sul comando make:
#     http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
# Sulle variabili automatiche vedere:
#     https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
 
# definizione del compilatore e dei flag di compilazione
# che vengono usati dalle regole implicite
CC=gcc
CFLAGS=-std=c11 -Wall -O -g
LDLIBS=-lm

EXECS=leggicitta legginomi


# se non viene specificato un target dalla linea
# di comando, make esegue il primo del makefile
# in questo caso si chiama `all` e dipende dai
# file specificati in EXECS
all: $(EXECS)


# regola per creare l'eseguibile ABR_esempio
# compilando abr_capitali.c
ABR_esempio: abr_capitali.c
	$(CC) $(CFLAGS) -o ABR_esempio abr_capitali.c


# quando eseguo `make zippo` viene eseguito 
# il comando e creato l'archivio 02struct.zip
zippo:
	zip 02struct.zip *.c
