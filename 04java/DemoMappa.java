import java.util.HashMap;
import java.util.LinkedHashMap;

class DemoMappa {

  // metodo main
  public static void main(String[] args) {
    // controlla che ci siano almeno due argomenti
    if(args.length < 1) {
      System.out.println("Uso: java DemoMappa s1 s2 s3 s4 ...");
      System.exit(1);
    }

    // crea una mappa che conta il numero di occorrenze
    // di ogni stringa passata come argomento
    HashMap<String, Integer> mappa = new LinkedHashMap<String, Integer>();
    for(String s: args) {
      mappa.put(s, 1 + mappa.getOrDefault(s, 0));
    }
    // stampa il contenuto della mappa
    for (String s: mappa.keySet())
      System.out.println(s + " -> " + mappa.get(s));
  }
}
