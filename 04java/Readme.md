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

