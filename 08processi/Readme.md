

## Esercizi



### Esercizio su named pipe e funzione execl (2/4/25)


Modificando `scrittore.c` scrivere un programma `xscrivi.out` che invocato dalla linea di comando scrivendo
```
xscrivi.out nome i1 i2 i3 .. ik
```
esegue le seguenti azioni:


* scrive su `stdout` il valore `argc`
* crea la named pipe `nome` nel caso non esista
* se `argc>3` crea un nuovo processo con `fork` e gli fa eseguire *una nuova istanza* del programma `xscrivi.out` passandogli come argomento i primi `argc-1` parametri (vedi esempio sotto)
* apre la pipe `nome` in scrittura e scrive su `nome` tutti gli interi tra `1` e `ik`
* visualizza su `stdout` la somma degli interi scritti nella pipe, chiude la pipe e termina. 

Esempio: se si invoca
```
xscrivi.out tubo 10 15
```
il programma deve:

* visualizzare il valore 4 (`argc`), 
* creare la pipe `tubo`, 
* lanciare l'esecuzione di una nuova istanza di `xscrivi.out` con parametri `tubo 10`
* scrivere su `tubo` gli interi tra 1 e 15, visualizzare la somma 120 e terminare.

La nuova istanza di `xscrivi.out` (che riceve i parametri `tubo 10`) deve:

* visualizzare il valore 3 (il suo `argc`)
* creare la pipe `tubo` (probabilmente la troverà già esistente)
* dato che `argc==3` non deve creare altri processi
* scrivere su `tubo` gli interi tra 1 e 10, visualizzare la somma 55 e terminare.


Per lanciare la nuova versione di `xscrivi.out` dopo la `fork` dovete usare la funzione `execv`, non potete usare la `execl` fatta a lezione. Guardare la pagina `man` per i dettagli.


Per la lettura dei dati scritti nella pipe, modificare lo script `lettore.py` in modo che al termine stampi la somma di tutti gli interi letti dalla pipe; nell'esempio di sopra dovrebbe stampare 175 (somma di 120 + 55). Per evitare affollamento sul terminale, fare partire `lettore.py` da un'altra finestra.



### Processi consumatori multipli (9/4/26)

Modificare l'esempio `shm_prod.c/shm_cons.c` in modo che 1) vengano utilizzati 3 consumatori e 2) i consumatori (eseguibile `shm_cons.out`) vengono lanciati dal produttore `shm_prod.out` utilizzando `fork` e `exec`.

Si osservi che i consumatori necessitano di una variabile `cindex` condivisa e di un relativo mutex per regolarne l'accesso; a questo scopo conviene che il produttore crei un nuovo blocco di memoria condivisa con un unico intero e un ulteriore semaforo con nome da utilizzare come mutex (in alternativa a creare un nuovo blocco, il blocco usato per il buffer può essere creato di dimensione `Buf_size+1`).

