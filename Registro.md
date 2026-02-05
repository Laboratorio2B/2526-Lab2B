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


------------

**Lezione 7** (14/10/25)

Esempio di uso della notazione `&a[i]` nel *mergesort*
Esercitazione in aula su array e stringhe: [testo esercizio](https://elearning.di.unipi.it/mod/page/view.php?id=24746)


----

**Lezione 8** (17/10/25)


Lettura di stringhe con `scanf`: evitare il buffer overflow: modificatori `%Ns` (con N massimo numero di caratteri) e `%ms`
Costruzione/concatenazione di stringhe mediante `asprintf` 




## Definizione di struct: liste e alberi binari di ricerca (02struct)



**Lezione 8** (17/10/25)

Definizione di tipi composti con `struct`; definizione di nuovi tipi con `typedef` e uso combinato con `struct`
Operazioni sui tipi composti, notazioni `.` e  `->`; passaggio per valore e per riferimento di struct. 
Ordinamento di un array di struct mediante mergesort
Array di puntatori a struct vs array di struct. Esempio: array di capitali.

----


**Lezione 9** (21/10/25)

Ordinamento array di puntatori a struct mediante mergesort (`array_capitali.c`)
Terminazione in caso di errori: funzione perror() e variabile globale `errno`
Confronto lessicografico di stringhe: funzione `strcmp`.
Introduzione all'uso delle funzioni come parametri di altre funzioni.
Funzioni `fseek` e `ftell`. Uso del tipo `long`.
Esercizio: ordinamento di file per dimensione e nome (`array_file.c`). 


---

**Lezione 10** (24/10/25)

Puntatori generici (`void *`). La funzione di ordinamento di libreria `qsort`: tipo della funzione di confronto, casting.


---

**Lezione 11** (28/10/25)

Prova in itinere sui contenuti delle lezioni 1-9. 


----

**Lezione 12** (31/10/25)

Introduzione alle *linked list*: creazione, stampa, distruzione di liste. Inserimento in testa e in coda. 
Linked list: procedure ricorsive per la cancellazione e l'inserimento ordinato. 



----

**Lezione 13** (4/11/25)

Alberi binari di ricerca: procedure ricorsive per costruzione, visita e deallocazione.
Alberi binari di ricerca: visita in preorder, ricerca di un elemento, calcolo altezza (file `abr_capitali.c`)
Makefile: concetto di target, prerequisiti e comandi.


----


**Lezione 14** (7/11/25)

Lettura da file con getline(). Parsing di stringhe mediante strtok() (esempi `leggicitta.c` e `legginomi.c`).
Funzionamento interno di strtok(). Varabili statiche (esempio `statiche.c`)
Makefile: target di default, meccanismo di risoluzione dei prerequisiti, regole implicite



## Assembler ARM (03assembler)


**Lezione 15** (11/11/25)

Test di primalità in assembler ARM (`primo.s`). 
Uso di un debugger: esecuzione passo/passo, breakpoint, visualizzazione variabili locali o registri, espressioni, breakpoint condizionali.
Accesso a sistemi remoti via ssh con X11 forwarding. Uso di gdbgui per debugging su sistemi remoti attraverso un browser, visualizzazione di strutture con puntatori all'interno del debugger. 

---

**Lezione 16** (14/11/25)

File oggetto (`.o`) e compilazione separata (programma `parole`) 
Realizzazione della compilazione separata nel makefile. Utilizzo delel variabili 
`$<`, `$^`, e `$@` nel makefile.
Implementazione `strtok` in assembler ARM (`tok.s`)


---

**Lezione 17** (18/11/25)

Implementazione quicksort in C e in assembler (`quicksort.c`, `quicksort.s` e `quicksort2.s`)
e misura dei tempi di esecuzione con `times(3)` .
Concetto di compilazione condizionale con `#ifdef` e suo controllo attraverso il makefile.
Operazioni bitwise in C: `&`, `|`, `^`, `~`, `<<`, `>>`. 
Uso di variabili intere come array di bit. Esempi in `bitops.c` (non commentati a lezione).



## Java (04ava)


**Lezione 18** (21/11/25)


Definizione e uso di matrici bidimensionali definite in modo statico (ad esempio `int a[3][5]`) e in modo dinamico come array di righe.
Introduzione a Java: la classe `Coppia`, la classe `ArrayList<>`, metodi `sort` e `contains`.


-----

**Lezione 19** (25/11/25)


Java: overloading vs overriding. Overriding dei metodi `toString` e  `equals`. Uso dell'annotazione `@Override`
La classe `TreeSet` e l'interfaccia `Comparable`. Lettura da file con `BufferedReader` e `FileReader`.
Uso di eccezioni. Java: la classe `HashSet` e il metodo `hashCode` (sorgente `Citta.java`).

-----

**Lezione 20** (28/11/25)

Cenni sulla gerarchia delle collezioni: `Set` vs `HashSet` vs 'LinkedHashSet', `List` vs `ArrayList` vs `LinkedList`.
Java: classi (astratte) e interfacce; differenza di uso fra `extends` e `implements`.
Classe `Grafo`, cammini minimi con algoritmo di Dijkstra. Classe `LogGrafo` 
e implementazione di un grafo di città mediante l'interfaccia `Nodo` 

-----


**Lezione 21** (2/12/25)

Esercitazione su lettura/scrittura di file e uso di collezioni e mappe in Java.


-----

**Lezione 22** (5/12/25)

Prova in itinere sul contenuto delle lezioni 10-21




## Uso di Python per interagire con il file system (05python)


**Lezione 23** (3/2/26)


Introduzione a Python, differenze e similarità con il C. 
Sintassi, interprete, istruzioni `if`, `else`, `elif`, `for`, `while`. 
Definizione di funzioni e Docstring. Liste e tuple.
Interprete ed esecuzione dalla linea di programma. 


-----


**Lezione 22** (5/2/26)

Esecuzione dalla linea di comando: uso di `import` e `sys.argv`. 
Uso di `#!/usr/bin/env python3` e permesso di execuzione. 
Dizionari e insiemi: funzionamento interno e vincoli sulle chiavi.  
Esempio: costruzione classifica leggendo risultati da file. Apertura di file con `with` e `open`. 
Istruzione `raise` per segnalare gli errori. Sorting di liste utilizzando una key function. 
Esercizi per casa: *Ribalta file* e *Ordina file*


