## Esercizi per casa


### Pari e dispari (19/9/25)

Scrivere un programma `paridispari` che legge gli interi passati dalla linea di comando e scrive quelli pari in un file di nome `pari.txt` e quelli dispari in un file di nome `dispari.txt`. Prima di terminare il programma deva visualizzare sul terminale la somma degli interi pari e dispari letti. Ad esempio se il programma viene invocato scrivendo
```
paridispari 10 70 17 36 -23
```
al termine dell'esecuzione il file `pari.txt` deve contenere
```
10
70
36
```
e il file `dispari.txt`
```
17
-23
```
Il programm deve poi visualizzare sul terminale:
```
Somma interi pari: 116
Somma interi dispari: -6
```

### Costruzione array dinamici (26/9/25)

Scrivere un programma C che legge un intero N e costruisce i seguenti due array di interi:

* l'array `a[]` contente i numeri tra 1 e N che sono multipli 3 ma non di 5: ``3, 6, 9, 12, 18, 21, 24, 27, 33, ...``

* l'array `b[]` contente i numeri tra 1 e N che sono multipli 5 ma non di 3:  ``5, 10, 20, 25, 35, 40, 50, ...``

Al termine della costruzione deve stampare lunghezza e la somma gli elementi degli array `a` e `b`, deve poi deallocarli e terminare. 

Ad esempio per N=100 i due array risultano

```
a = [3, 6, 9, 12, 18, 21, 24, 27, 33, 36, 39, 42, 48, 51, 54, 57, 63, 66, 69, 72, 78, 81, 84, 87, 93, 96, 99]

b = [5, 10, 20, 25, 35, 40, 50, 55, 65, 70, 80, 85, 95, 100]
```

e di conseguenza l'output dovrebbe essere 
```
lunghezza a[] = 27,  somma a[] = 1368
lunghezza b[] = 14,  somma b[] = 735
```

Per N=99999 l'output dovrebbe essere
```
lunghezza a[] = 26667,  somma a[] = 1333366668
lunghezza b[] = 13333,  somma b[] = 666633335
```
Eseguire il programma anche utilizzando `valgrind` verificando che non stampi nessun messaggio d'errore e al termine visualizzi il messaggio 
```
HEAP SUMMARY:
 in use at exit: 0 bytes in 0 blocks
```



### Conversione da stringa a intero (30/9/25)

Scrivere una funzione 
```
int mioa2toi(char *s, int *n)
```
che data una stringa `s` la interpreta come intero decimale (allo stesso modo di `atoi`). Se la conversione avviene con successo il valore ottenuto deve essere scritto in `*n` e la funzione deve restituire il valore 0; se invece la conversione non ha successo la variabile *n* non deve essere modificata e la funzione deve restituire un intero positivo che indica l'errore che si è verificato secondo il seguente schema:

1. se la stringa è vuota o contiene solamente spazi
2. se viene incontrato un carattere che non sia uno fra `+-0123456789` (esempio, la stringa `"234s7"`)
3. se il segno (`+` o `-`) compare più di una volta, o compare in posizione non corretta (esempio le stringhe `"+-34"`, `"-3-4"`, o `"-34+"`)
4. se compare esattamente un segno, ma nessuna cifra (ad esempio la stringa `"-"`)

La conversione deve ignorare eventuali spazi iniziali e deve terminare non appena viene incontrato uno spazio. Quindi l'input `"  +34 21"` deve restituire il valore `0` (conversione OK) e  scrivere in `*n` il valore 34, mentre l'input `"  + 34 21"`deve restituire il valore 4 (conversione fallita perché ha letto il segno e poi lo spazio ha fatto interrompere la conversione prima che incontrasse una qualsiasi cifra. 

Per quanto riguarda la parte di calcolo, a parte la gestione del segno e degli errori, osservate che se l'input è `"XYZ"` e  la stringa `"XY"` è stata convertita nel valore `t` allora `"XYZ"`vale  $10 t + z$ dove $z$ è il valore tra 0 e 9 rappresentato dal carattere `Z`.  Ricordo che i codice ascii di caratteri tra `0` e `9` sono gli interi tra 48 e 57.

La vostra funzione non può usare `atoi`, ma la potete usare nel `main` per verificare la correttezza della vostra funzione, Ad esempio scrivendo:
```
int main(int argc, char *argv[])
{
  for(int i=1;i<argc;i++) {
    int n, e;
    e = mioatoi(argv[i],&n);
    if(e!=0) printf("Errore conversione: %d\n",e);
    else printf("Mia funzione: %d, libreria: %d\n",n,atoi(argv[i]));
  }
  return 0;
} 
```
Fate il test con valori sia positivi che negativi! La riga di comando di default non mette gli spazi dentro gli `argv[]` ma potete inserirli scrivendo la stringa tra doppie virgolette. Quindi scrivendo
```
mioprog + 123
```
 si ha `argv[1]="+"` e `argv[2]="123"`, mentre scrivendo
 ```
mioprog "+ 123"
 ```
 si ha `argv[1]="+ 123"` e non ci sono altri argomenti. 
