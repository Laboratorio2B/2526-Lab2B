#include "xerrori.h"
#define QUI __LINE__,__FILE__

// esempio base di gestione segnali in maniera sincrona
// con sigwait e quindi senza handler
// i segnali attesi da sigwait() devo essere bloccati
// perché sigwait() gestisce i segnali pending 

// confrontare con segnali.c che esegue una gestione
// simile ma in maniera asincrona.

// Si noti che entrambi gli esempi assumono che il main()
// non svolga altra attività che quella di attendere i segnali.
// In un programma reale il main() solitamente svolge altre
// attività e quindi la chiamata a sigwait() è fatta in un
// thread dedicato. 

// se si definisce SIGWAITINFO si usa sigwaitinfo()
// per attendere il segnale: questo permette ad esempio di
// sapere chi ha inviato il segnale (pid del processo)
#define SIGWAITINFO 1 


typedef struct {
  int tot_segnali;
  int continua;
  sigset_t set;
} args;


// effettua la gestione di tutti i segnali indicati in a->set
void *tgestore(void *v) {
  args *a = (args *) v;
    
  while(1) {   // loop di attesa dei segnali
    int s; // segnale ricevuto
    #ifndef SIGWAITINFO 
    // sigwait() restituisce il segnale ricevuto in s
    e = sigwait(a->set, &s); 
    if (e != 0) xtermina("Errore sigwait", QUI);
    #else
    siginfo_t siginfo;
    s = sigwaitinfo(&a->set, &siginfo);
    if (s <0) xtermina("Errore sigwaitinfo", QUI);
    printf("Segnale %d inviato da %d con valore %d \n", s, siginfo.si_pid, siginfo.si_value.sival_int);
    #endif
    
    // qui è safe usare la printf, non siamo in un handler
    printf("Segnale %d ricevuto dal processo %d\n", s, getpid());
    a->tot_segnali++;
    if(s!=SIGUSR1) {
      kill(getpid(),SIGUSR1); // manda SIGUSR1 a se stesso  
    }
    if(s==SIGUSR2) {
      // forza uscita dal loop infinito del main()
      a->continua = 0;
    }
  };
  return NULL;
}


int main(int argc, char *argv[])
{
  // definisco l'insieme dei segnali da gestire con sigwait()
  // in questo caso tutti meno SIGQUIT (cioè C-\)
  sigset_t mask;
  sigfillset(&mask);
  sigdelset(&mask,SIGQUIT); // elimino sigquit dall'insieme
 
  // blocco questi segnali per questo thread, al momento è l'unico
  // ma il blocco vale anche per i thread generati da questo 
  int e=0; 
  e= pthread_sigmask(SIG_BLOCK, &mask, NULL);
  if (e != 0) xtermina("Errore pthread_sigmask", QUI);

  // visualizza il pid
  printf("Se vuoi mandarmi dei segnali il mio pid e': %d\n", getpid());
  
  // variabili da passare al thread gestore di segnali
  args a;
  a.continua = 1; a.tot_segnali = 0; a.set = mask; 
  pthread_t t;
  xpthread_create(&t,NULL,&tgestore,&a,QUI);
  e = pthread_detach(t);   // non necessito di fare join su questo thread
  if (e != 0) xtermina("Errore pthread_detach", QUI);

  do {   // loop apparentemente senza uscita
    sleep(30);     // la sleep viene interrotta dai segnali 
    puts("loop1: svegliato");           
  } while(a.continua!=0); 
  printf("Ricevuti: %d segnali (uscito primo loop)\n", a.tot_segnali);
    
  return 0;
}

