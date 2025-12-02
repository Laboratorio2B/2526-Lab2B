## Compilazione di codice Java ed esecuzione da riga di comando

Nel caso sia necessario compilare ed eseguire i programmi java dalla linea di comando utilizzare il comando `javac`. Ad esempio si possono compilare tutti i file con estensione `java` nella directory corrente scrivendo
```bash
javac *.java
```  
Questo comando crea un file `.class` per ognuna delle classi contenute nei file `.java` (i nomi dei file `.class` sono quindi quelli delle classi, non dei sorgenti). Se una classe contiene al suo interno il metodo 
`public static void main(String[] args)`  allora è possibile eseguire il codice di tale metodo scrivendo ad esempio
```bash
java GrafoCitta italiane.txt 90
```
in questo caso i parametri "italiane.txt" e "90" sono memorizzati nell'array di stringhe `args` argomento di `main`. Si noti che in questo esempio `args` avrebbe due elementi, non 3 come in C.


## Esercizi


### Città del Sud America (28/11/25)

Scrivere un programma Java che legge le città dal file `02struct/sudAmerica.txt` e le stampa ordinate per nazione e all'interno di ogni nazione ordinate per nome della città. Inoltre si deve stampare per ogni nazione la somma delle popolazioni delle città di quella nazione. 





### Elenco file (28/11/25)

Scrivere un programma Java che legge un  elenco di nomi di file sulla linea di comando e stampa sul terminale l'elenco di questi file con il numero di linee di testo in essi contenute. Si veda il programma `Terna.java` per vedere come leggere (e quindi contare) le linee di un file. L'elenco deve essere ordinato per numero di linee decrescente e a parità di numero di linee lessicograficamente per nome del file. Se qualcuno dei file passati sulla linea di comando non esiste deve essere semplicemente ignoratoe non riportato nell'elenco. 


### Cinema (2/12/25)

Scrivere un programma Java che utilizzando i dati del file `Mini.tsv` (disponbile su moodle) costruisce una mappa `Map<String,Set<String>> ruoli` che associa ad ogni persona le professioni che esso/essa ha avuto. Il file  `Mini.tsv` ha il seguente formato:  
```
nconst      primaryName     birthYear  deathYear  primaryProfession                   knownForTitles
nm0000001   Fred Astaire    1899       1987       actor,miscellaneous,producer        tt0072308,tt0050419,tt0027125,tt0031983
nm0000002   Lauren Bacall   1924       2014       actress,soundtrack,archive_footage  tt0037382,tt0075213,tt0117057,tt0038355
nm0000003   Brigitte Bardot 1934       \N         actress,music_department,producer   tt0057345,tt0049189,tt0056404,tt0054452
nm0000004   John Belushi    1949       1982       actor,writer,music_department       tt0072562,tt0077975,tt0080455,tt0078723
nm0000005   Ingmar Bergman  1918       2007       writer,director,actor               tt0050986,tt0069467,tt0050976,tt0083922
nm0000006   Ingrid Bergman  1915       1982       actress,producer,soundtrack         tt0034583,tt0038109,tt0036855,tt0038787
...
```
per l'esercizio interessano la seconda colonna contente i nomi, e la quinta colonna contenente le professioni separate dal carattere `,`.
Vedere l'esempio `Citta.java` per come effettuare la lettura di una riga alla volta; si noti poi che la prima riga va scartata perché contiene l'intestazione. In ogni altra riga del testo le colonne sono separate dal carattere '\t' e quindi possono essere ottenute utilizzando il metodo `split` (vedere il costruttore della classe `Citta`). Per ottenere le singole professioni applicare il metodo `split()` alla quinta colonna. 

Terminata la lettura, scrivere nel file `attrici.txt` l'elenco delle attrici ordinato alfabeticamente, cioè delle persone che hanno `actress` nell'elenco delle professioni. Per scrivere in un file, aprirlo con 
```
BufferedWriter writer = new BufferedWriter(new FileWriter("attrici.txt")) 
```
(possibilmente dentro un `try`) e scrivere le singole linee con `writer.write(String)`.


**Seconda parte** Durante la lettura del file, costruire anche una mappa che associa ad ogni professione l'insieme delle persone con quella professione. Al termine, per ogni professione (ad esempio `actor`) scrivere un file `actor.txt` contenente l'elenco delle persone con quella professione. Si noti che il file `actress.txt` dovrebbe avere lo stesso contenuto del file `attrici.txt` della prima parte dell'esercizio.



