import java.io.BufferedReader;
import java.io.FileReader;
import java.util.TreeSet;

/*
 * Classe che rappresenta una terna di interi
 * Tra le terne è definito un ordinamento naturale
 * basato sulle componenti x,y,z in questo ordine
 * 
 * Implementa l'interfaccia Comparable<Terna>
 * per poter essere usata in un TreeSet<Terna>
 * che è l'analogo dell'ABR in C
 * 
 * Il main() legge da file una lista di terne
 * e stampa quelle che sono pitagoriche
 * La stampa è fatta scorrendo il TreeSet
 * quindi le terne vendono visitate in ordine
 * crescente secondo l'ordinamento naturale
 * definito nel metodo compareTo()  
 * 
 * Il progrmma mostra anche la lettura da file
 * e l'uso delle eccezioni 
 */

class Terna implements Comparable<Terna> {
  int x,y,z; // variabili d'istanza

  // costruttore
  Terna(int x, int y, int z) {
    this.x = x;  // usiamo this per distinguere tra variabili d'istanza e parametri
    this.y = y;
    this.z = z;
  }

  // costruttore che legge la terna da una stringa
  Terna(String s) { // possibile s "12 34 61"
    String[] parts = s.split(" ");
    if (parts.length != 3) {
      throw new IllegalArgumentException("Stringa non valida per Terna: " + s);
    }
    x = Integer.parseInt(parts[0]);
    y = Integer.parseInt(parts[1]);
    z = Integer.parseInt(parts[2]);
  }

  // crea stringa che rappresenta la terna
  @Override
  public String toString() {
    return String.format("%d %d %d",x,y,z);
  }

  @Override
  public boolean equals(Object o) {
    if(o == null || !(o instanceof Terna))
      return false;
    Terna t = (Terna)o;      // casting simile a quello del C
    return x==t.x && y==t.y && z==t.z;
  }

  // metodo compareTo richiesto dall'interfaccia Comparable
  // a sua volta richiesta da TreeSet
  // confronta due terne considerando le componenti x,y,z in questo ordine
  public int compareTo(Terna t) {
    if(x != t.x)
      return x - t.x;
    if(y != t.y)
      return y - t.y;
    return z - t.z;
  }

  // terna pitagorica?
  public boolean pitagorica() {
    return x*x + y*y == z*z;
  }

  
  public static void main(String[] args) {
    // controlla che ci siano un argomento (il nome del file)
    if(args.length !=1) {
      System.out.println("Uso: java Terna nomefile");
      System.exit(1);
    }

    // crea un insieme di terne inizialmente vuoto
    TreeSet<Terna> insieme = new TreeSet<Terna>();

    // apre il file e legge una linea alla volta
    int tot_linee = 0;
    try {
      BufferedReader in = new BufferedReader(new FileReader(args[0]));
      while(in.ready()) {
        String line = in.readLine();
        Terna t = new Terna(line);
        insieme.add(t);
        tot_linee++;
      }
      in.close();
    } catch(Exception e) {
      System.err.println("Errore: " + e);
      // stampo la traccia dello stack per debug
      e.printStackTrace();
      System.exit(2);
    }
    // stampa numero totale di terne
    System.out.println("Totale linee lette dal file: " + tot_linee);
    System.out.println("Totale terne nell'insieme: " + insieme.size());

    // stampa la lista delle terne pitagoriche 
    for(Terna t: insieme)
      if (t.pitagorica())
        System.out.println(t);
    System.out.println("---- end ----");
  }  
}
