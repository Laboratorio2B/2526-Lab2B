

## Esercizi



## Sort parallelo modificato (10/3/26)

Nel programma `pmergesort.c` fatto a lezione, le due funzioni `pmergesort()` e `tbody()` svolgono esenzialmente le stesse operazioni: ordinare l'array con `qsort()` se la dimensione è minore di soglia, oppure partizionare e ordinare in parallelo le due metà.   Dato che duplicare il codice non è mai una buona idea, modificare il programma in maniera da mantenere solamente una delle due funzioni (eventualmente con piccole modifiche) e cancellare completamente l'altra.



## Produttori e consumatori multipli (12/3/26)

Modificare il programma `multip_primi_files.c` in modo che invece di ottenere una singola somma,
vwnga ottenuta un somma distinta per ogni file come nel programma `primi_files.c`. Dato che ogni consumatore 
riceve interi da file diversi, è necessario che ogni unità di lavoro sul buffer consista in due valori: un intero letto da un file e 
un identificatore del file da cui l'intero proviene. Per assicurarsi che i due valori vengano scritti sempre insieme,  
gli elementi del buffer devono essere coppie definite da una struttura del tipo
```
typdef struct {
  int valore;
  int file_id;
}
```



