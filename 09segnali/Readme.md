## Esercizi


### Alice, Bob con segnali real-time (16/4/26)


Si consideri il seguente gioco tra Alice e Bob: si parte da un intero *N*, a turno ogni giocatore può: 

* se *N* pari sottrarre 1 da *N* oppure dimezzarlo
* se *N* è dispari può solo sottrarre 1 (la mossa è forzata)

vince che raggiunge il valore zero. Ad esempio, se il valore iniziale è 12 una possibile sequenza di gioco è: 

* Bob: 12 -> 6
* Alice: 6 -> 5
* Bob: 5 -> 4 
* Alice: 4 -> 2 
* Bob: 2 -> 1 
* Alice 1 -> 0 e vince 


Scrivere una coppia di programmi `alice` e `bob` che effettuano un certo numero di partite secondo il seguente schema:



1. `alice` legge dalla linea di comando il valore iniziale *N* e lo comunica a `bob` con un segnale 

2. `bob` attende il valore *N* e successivamente esegue la prima mossa

3. I programmi devono fare mosse valide (non importa se giocano male) e comunicare la mossa scelta all'avversario utilizzando un segnale (la mossa va comunicata anche quando è forzata)

4. Chi riceve la mossa deve verificarne la correttezza e inviare la sua mossa di risposta ancora con un segnale

5. Quando la partita finisce ogni programma deve stampare un messaggio `ha vinto Alice` oppure `ha vinto Bob` e poi si torna al punto 1 per una eventuale nuova partita.

Idealmente i due programmi devono fare sempre mosse valide, accorgersi che la partita è finita e stampare lo stesso messaggio alla fine di ogni partita. 


Dovete scrivere due sorgenti diversi `alice.c` e `bob.c`; l'utente deve eseguire dalla linea di comando `alice` che deve far partire `bob` con una `fork` + `exec`; questo è necessario perchè ogni programma deve poter conoscere il `pid` dell'altro per inviare i segnali. Inviate i segnali con la funzione `sigqueue(3)` per inviare un intero, e `sigwaitinfo(2)` per la ricezione dei segnali.



### heap e ctrl-C (16/4/26)

Modificare il programma `08condVar/heap.c` aggiungendo un thread gestore di segnali tale che quando viene premuto il tasto `ctrl-C` viene fatta un'allocazione di un blocco di 7 unità di memoria che deve essere mantenuto allocato per 5 secondi. Il programma deve essere fatto in modo che successivi invii di `ctrl-C` effettuino successive allocazioni di 7 unità di memoria anche se i precedenti blocchi da 7 non sono ancora stati deallocati (naturalmente l'allocazione può avvenire solo se la memoria è disponibile altrimenti il thread deve rimanere in attesa).

