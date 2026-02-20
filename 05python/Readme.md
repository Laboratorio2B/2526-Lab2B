# Introduzione a Python


## Python vs C


La sintassi di Python è simile a quella del C tranne che per le sequenti semplificazioni:

 * Non è richiesto il `;` alla fine di ogni linea
 * invece delle `{ }` i blocchi sono evidenziati mediante indentazione (attenti all'editor) e con il carattere `:`
 * Le parentesi `( )` nei test degli `if`/`while`   non sono necessarie
 * `/` vs `//` per distinguere tra divisione e divisione intera. Per i commenti si usa il carattere `#` 
 * non ci sono  `++` e `--`
 * operatori logici si chiamano con il loro nome: `and`, `or`, `not` etc
 * Invece di `true`/`false`/`NULL` ci sono `True`/`False`/`None` 


Python è un linguaggio interpretato non compilato: molto più lento del C (fino a 100+ volte); gli errori vengono segnalati a runtime con messaggi solitamente comprensibili.

Altra differenza sostanziale è che le variabili non hanno tipo e non vanno dichiarate.

Le stringhe sono immutabili e facili da usare. Non c'è il tipo carattere: un carattere è una stringa di lunghezza uno.

Gli interi hanno precisione illimitata: ci pensa l'interprete ad usare un numero adeguato di byte per rappresentare tutte le cifre (fate la prova con il fattoriale)

## Strutture di controllo e iterazione

 * if/else/elif
 * while/continue/break, esiste un comando else per i cicli, non esiste do
 * for è basato sul concetto di range, simile al for-each di Java

## Definizione e invocazione di funzioni

Esempio di funzione che dati due interi restituisce la somma e la stringa contenente la loro concatenazione. Non è una funzione molto sensata: serve per far vedere che è possibile restituire più di un oggetto anche di tipo diverso.

```python
# definizione 
def fun(a,b):
    return a+b,str(a) +str(b)

# invocazione funzione e stampa risultato
s,p = fun(3,5)
print(s,p)
```

## Docstring

Una stringa delimitata da tre virgolette `"""` nella riga immediatamente successiva alla definizione di una funzione di chiama *docstring* e forma un commento che l'interprete associa alla funzione. Viene mostrata con il comando *help* e da alcuni editor specifici per python. Ad esempio

```python
def media(a,b):
  """Calcola la media artimetica"""
  return (a+b)/2

help(media)
Help on function media in module __main__:

media(a, b)
    Calcola la media aritmetica
```



## Costruzione stampa e modifica di una lista
```python
lista = [1,2,3,"ciao"]
print(lista[2:]) # estrae gli elementi da lista[2] alla fine 
lista[2] = 5
lista = lista + [34,40]
lista.append(35)
print(lista)
```

Si noti che le liste in python sono analoghe agli array del C in quanto possiamo accedere all'iesimo elemento in tempo costante scrivendo `a[i]` (ma non dobbiamo preoccuparci di allocazioni e deallocazioni). Malgrado il nome non sono analoghe alle *linked list* del C dove l'accesso agli elementi avviene seguendo i puntatori del campo *next*.




### Esempi di iterazione su una lista usando il ciclo for
```python
parole = ["casa","mare","sole"]
for x in parole:
    print(x.upper())
    x = "monti"
print(parole)
for i in range(len(parole)):
    print(parole[i].upper())
    i = 7
print(parole)

```
Nota: la parola chiave `in` si usa nei cicli for e per testare l'appartenenza. Verificatelo eseguendo lea seguenti istruzioni:
```python
print(4 in [1,2,3])
print(4 in [2,4,8])
```

## Tuple 

Le tuple sono sequenze di oggetti molto simili alle liste; vengono definite e stampate utilizzando le parentesi tonde invece che quadre. La differenza sostanziale è che le tuple sonn immutabili (come le stringhe): una volta creata non possiamo modificarle, in particolare non possiamo modificare i singoli elementi:
```python
a = [2, 3, 5, 7, 11]  # a è una lista
a[1] = 13
print(a)  # -->  [2, 13, 5, 7, 11]
b = (2, 3, 5, 7, 11)  # b è una tupla
b[1] = 13
TypeError
----> 1 b[1] = 13
TypeError: 'tuple' object does not support item assignment
```
Vedremo nel seguito il motivo per cui è utile avere una versione immutabile delle liste.


## Esecuzione di programmi

Inizialmente eseguiremo i programmi chiamando le funzioni all'interno dell'interprete python (prompt `>>>` oppure `[1]`). L'interprete ha il vantaggio di permettere di testare le singole istruzioni/funzioni e di vedere il contenuto delle variabili.

Successivamente eseguiremo i programmi python dalla linea di comando del terminale (in questo caso vengono chiamati `script`). Per poterli eseguire dalla linea di comando è necessario che il file contenente il sorgente inizi con la linea
```python
#!/usr/bin/env python3
```
e che il file venga reso eseguibile con il comando `chmod(1)`


## Lettura dei parametri sulla linea di comando

Per poter accedere ai parametri passati sulla linea di comando come nel C, è necessario importare il modulo `sys` con l'istruzione (solitamente messa all'inzio del file)
```python
import sys
```
A questo punto i parametri passati sulla linea di comando sono disponibili nella lista di stringhe `sys.argv`; quindi `sys.argv[0]` sarà il nome del programma python, `sys.argv[1]` il nome del primo parametro, e così via. Il numero totale di parametri si ottiene con `len(sys.argv)`.


## Dizionari

Sono equivalenti alle `HashMap` di Java ma più semplici da usare. Consistono in una collezione chiavi, dove ad ogni chiave è associato un valore.  

```python
d = {"casa":3, "sole":4}
d["mare"] = 5
d["casa"] = 10
print(d)
for c in d:
    print("Alla chiave", c, "è associato il valore", d[c])
```

I valori possono esere qualsiasi, mentre le chiavi devono essere essere oggetti "immutabili", quindi che non possono (o che non devono) essere modificati. Per questo motivo gli array non possono essere usate come chiavi in un dizionario, per associare ad esempio un valore ad una coppia di interi è necessario usare una tupla:
```python
d[ [1,2] ] = "coppia"
TypeError: unhashable type: 'list'
d[ (1,2) ] = "coppia"
print(d)
{'casa': 10, 'sole': 4, "mare": 5, (1, 2): 'coppia'}
```
Per cancellare un elemento da un dizionario si utilizza il comando `del`:
```python
del d['casa']
```


## Insiemi 

Sono equivalenti agli `HashSet` di Java, ma più semplici da usare. Consistono in una semplice collezione di chiavi senza nessun valore associato. Le operazioni che possiamo fare sono quindi di aggiunta di un elemento (`add`), cancellazione (`remove`), e verifica se un elemento è contenuto nell'insieme (`in`):
```python
s = set()   # crea un insieme vuoto
s.add("rosso")
s.add("verde")
s.add("bianco")
print(s)
{'rosso', 'bianco', 'verde'}
"rosso" in s
True
s.remove("rosso")
"rosso" in s
False
``` 
Mediante un ciclo `for` possiamo poi effettuare la scansione degli elementi di un insieme:
```python
for c in s:  print("  s contiene:", c)
  s contiene: bianco
  s contiene: verde
```
Insiemi e dizionari in python sono entrambi realizzati internamente con tabelle hash, quindi gli oggetti che possono essere memorizzati in un `set` sono gli stessi che si possono usare come chiavi nei dizionari (cioè quelli immutabili).



## Esercizi python 

### Ribalta file (5/2/26)

Scrivere un programma python `reverse.py` che invocato dalla linea di comando scrivendo 
```bash
reverse.py nomefile
```
legge le linee del file di testo `nomefile` e le scrive in ordine inverso su un nuovo file chiamato `nomefile.rev`. Ad esempio se il file `test.txt` contiene le linee
```
prima riga

questa è la terza riga
la seconda era vuota
```
deve essere creato il file `test.txt.rev` contenente
```
la seconda era vuota
questa è la terza riga

prima riga
```
Nota: aprire il file e leggere le linee come nell'esempio `serieA.py`. Per aprire il file `nome` in scrittura usare
```python
with open(nome,"w") as g:
```
e per scrivere una stringa nel file `g` usare la funzione `print` con la keyword `file` nel seguente modo 
```python
print("ciao", file=g)
```

### Ordina file (5/2/26)

Scrivere un programma python `ordina.py` che invocato dalla linea di comando scrivendo 
```bash
reverse.py nomefile
```
legge le linee del file di testo `nomefile` e le scrive in ordine di lunghezza decrescente 
su un nuovo file chiamato `nomefile.dec`. Ad esempio per il file `test.txt` dell'esercizio precedente dovrebbe essere creato un file `test.txt.dec` contente le linee:
```
questa è la terza riga
la seconda era vuota
prima riga


```
Nota: dopo aver letto le linee in un array, ordinarlo mediante il metodo `sort` utilizzando come chiave la lunghezza della stringa.



### Linee (12/2/26)


Risolvere in python l'esercizio C della prova in itinere del 5/12/25 (disponibile su moodle). A questo scopo definire una classe  
con i due campi `chiave` e `linea`; al posto dell'ABR utilizzare un `set()` per eliminare i duplicati; e una lista per memorizzare gli oggetti e per l'ordinamento finale. L'output ottenuto deve essere lo stesso richiesto per il C (si utilizzi il file esempi.zip per i test).


### File profondi (17/2/26)

Scrivere un programma `profondi.py` che invocato dalla linea di comando scrivendo 
```bash
profondi.py nomedir
```
esplora la directory `nomedir` e le sue sottodirectory  e visualizza l'elenco dei file che si trovano a maggiore profondità nell'albero con radice `nomedir` ordinando l'elenco per dimensione di file crescente.
Ad esempio, se la directory `nomedir` ha la seguente struttura:
```
nomedir
├── dir0_d1
│   ├── dir0_d0
│   │   ├── filea0.txt
│   │   └── filea1.txt
│   ├── file0.txt
│   └── file1.txt
├── dir1_d1
│   ├── dir1_d0
│   │   ├── fileb0.txt
│   │   └── fileb1.txt
│   ├── file0.txt
│   └── file1.txt
├── file0.txt
└── file1.txt

```
l'output deve consistere dei 4 file `filea0.txt`, `filea1.txt`, `fileb0.txt`, `fileb1.txt` ordinati per dimensione di file crescente. 

*Suggerimento:* partire dall'esempio `grandi.py` e modificare il metodo `elenco_file` in modo che per ogni file restituisca la tripla `(nome,dimensione,profondita)`. Potete ignorare la problematica che lo stesso file si possa trovare a profondità diverse a seconda dei link seguiti per raggiungerlo.


### Uso di sha1sum (19/2/26)

Modificare lo script `duplicati.py` evitando di confrontare i file con `cmp` usando al suo posto il comando `sha1sum` per ottenre un hash del file. Come visto a lezione, per ottenere l'hash di `filename` basta scrivere 
```python
r = subprocess.run(["sha1sum", filename],stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
if r.returncode!=0:
    raise RuntimeError("sha1sum failed")
sha = r.stdout.split()[0]
```

Il nuovo script invece di elencare coppie di file uguali deve elencare gli insiemi di file che hanno tutti lo stesso hash.



### Esercizio con ricerca di informazioni nei file (20/2/26)

Vedere [testo su moodle](https://elearning.di.unipi.it/mod/page/view.php?id=26026). 



### Cinema (20/2/26)

(Già fatto in Java) Scrivere un programma Python che utilizzando i dati del file `Mini.tsv` (disponbile su moodle) costruisce una mappa che associa ad ogni persona le professioni che esso/essa ha avuto. Il file  `Mini.tsv` ha il seguente formato:  
```
nm0000001   Fred Astaire    1899       1987       actor,miscellaneous,producer        tt0072308,tt0050419,tt0027125,tt0031983
nm0000002   Lauren Bacall   1924       2014       actress,soundtrack,archive_footage  tt0037382,tt0075213,tt0117057,tt0038355
nm0000003   Brigitte Bardot 1934       \N         actress,music_department,producer   tt0057345,tt0049189,tt0056404,tt0054452
nm0000004   John Belushi    1949       1982       actor,writer,music_department       tt0072562,tt0077975,tt0080455,tt0078723
nm0000005   Ingmar Bergman  1918       2007       writer,director,actor               tt0050986,tt0069467,tt0050976,tt0083922
nm0000006   Ingrid Bergman  1915       1982       actress,producer,soundtrack         tt0034583,tt0038109,tt0036855,tt0038787
...
```
per l'esercizio interessano la seconda colonna contente i nomi, e la quinta colonna contenente le professioni separate dal carattere `,`.
In ogni riga del testo le colonne sono separate dal carattere '\t' e possono essere ottenute utilizzando il metodo `split`. Per ottenere le singole professioni applicare il metodo `split()` alla quinta colonna. 


Terminata la lettura, scrivere nel file `attrici.txt` l'elenco delle attrici ordinato alfabeticamente, cioè delle persone che hanno `actress` nell'elenco delle professioni. Per scrivere in un file, aprirlo con 
```
with open('attrici.txt', 'w') as f:
```
e scrivere le singole stringhe di testo con `f.write(stringa)`.


**Seconda parte** Durante la lettura del file, costruire anche una mappa che associa ad ogni professione l'insieme delle persone con quella professione. Al termine, per ogni professione (ad esempio `actor`) scrivere un file `actor.txt` contenente l'elenco delle persone con quella professione. Si noti che il file `actress.txt` dovrebbe avere lo stesso contenuto del file `attrici.txt` della prima parte dell'esercizio.

