##  Introduzione ad array, puntatori e file (01introC)


**Lezione 1** (16/9/25)

Introduzione al corso: obiettivi e modalità d'esame. Introduzione al linguaggio C. La funzione `main`. Lettura e scrittura di interi dal terminale. Compilazione: linea di comando, errori e warning. Permessi di lettura/scrittura/esecuzione `rwx`. Esecuzione di programmi. Array "statici" (tipo `int a[n]` in `somma.c`). 

-----------------------

**Lezione 2** (19/9/25)


Concetto di PATH, uso di `.` per indicare la directory corrente. File `.bashrc` e sua modifica. 
Allocazione dinamica di array in C: funzioni malloc e free, programma `sommad.c`.
Lettura di input dalla linea di comando con argc/argv. 
Scrittura di file in formato testo, funzioni fopen/fprintf/fclose. Programma `scrivi_primi.c`.
Terminazione in caso di errori: funzione perror().

-------

**Lezione 3** (23/9/25)

Allocazione dinamica di array in C: funzioni malloc/free/realloc, programma `scrivi_primi.c`
Scrittura in un file di testo: fopen(), fprintf(), fclose(). Modalità append.
Introduzione ai puntatori; uso di puntatori negli array.
Significato e uso di `*` e `&`. Uso di `%p` per la stampa di un puntatore. 
Prototipi di funzione; significato istruzioni `#include`

-------

**Lezione 4** (26/9/25)

Utilizzo di *valgrind* per verificare il corretto utilizzo e deallocazione degli array.
Esempio passaggio parametri per riferimento attraverso un puntatore: `sommadprod.c`
Rappresentazione di stringhe in C (inizio): i tipi `char` e `char *`: sorgente `charstr.c`.


------------

**Lezione 5** (30/9/25)

Rappresentazione di stringhe in C (fine).
Stampa di stringhe con `printf`, calcolo lunghezza con `strlen`. 
Struttura dei parametri argc/argv di main().
Copia del puntatore vs copia degli elementi di un array: la funzione strdup()
Comandi `less` e `od` per visualizzare il contenuto di un file.


------------

**Lezione 6** (7/10/25)

Passaggio di array dalle/alle funzioni.
Lettura da un file di testo: comando fscanf().  
Terminazione in caso di errori: funzione perror(). Significato del tipo `const char *`
`stdout` e `stderr` e loro ridirezione.
Uso di `assert`.
Introduzione al *makefile*; compilazione con il comando *make*.
Equivalenza fra `*a` e `a[0]`.
Equivalenza fra `a` e `&a[0]`.
Aritmetica dei puntatori: definizione di `a+i` come `&a[i]`
