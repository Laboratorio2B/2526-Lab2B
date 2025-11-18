# Per maggiori informazioni sul comando make:
#     http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
# Sulle variabili automatiche vedere:
#     https://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
 
# definizione del compilatore e dei flag di compilazione
# che vengono usati dalle regole implicite
CC=gcc
CFLAGS=-std=c11 -Wall -O -g
LDLIBS=-lm

EXECS=leggicitta legginomi statiche parole bitops

# se non viene specificato un target dalla linea
# di comando, make esegue il primo del makefile
# in questo caso si chiama `all` e dipende dai
# file specificati in EXECS questi file se non 
# esistono già diventano a loro volta target
# da realizzare
all: $(EXECS)


# regole per ottenere l'eseguibile parole da parole.c e strint.c
parole: parole.o strint.o
	$(CC) parole.o strint.o $(LDLIBS) -o parole
	
parole.o: parole.c strint.h
	$(CC) parole.c $(CFLAGS) -c -o parole.o
	
strint.o: strint.c strint.h
	$(CC) strint.c $(CFLAGS) -c -o strint.o

#%.o: %.c %.h
#	$(CC) $< $(CFLAGS) -O2 -c -o $@


# regola esplicta per legginomi: ha la precedenza
# sulla regola implicita che dice come ottenere 
# l'eseguibile dal file .c. Per accorgerci che viene 
# effettivamente usata questa regola, usiamo flag di compilazione
# diversi da quelli i CFLAGS che sono usati nella regola implicita
legginomi: legginomi.c
	$(CC) -std=c99 -Wall -O2 -o legginomi legginomi.c

# regola per creare l'eseguibile ABR_esempio
# compilando abr_capitali.c (senza -O per usare il debugger)
ABR_esempio: abr_capitali.c
	$(CC) -std=c11 -Wall -g -o ABR_esempio abr_capitali.c


# regola per cancellare gli eseguibili e i file oggetto.
clean:
	rm -f *.o $(EXECS)

# quando eseguo `make zippo` viene eseguito 
# il comando e creato l'archivio 02struct.zip
zippo:
	zip 02struct.zip *.c *.h makefile
