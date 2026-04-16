#include "xerrori.h"
#define QUI __LINE__,__FILE__

// traccia codice giocatore bob  esercizio del 16/4/26


int main(int argc, char *argv[])
{
  // definisco l'insieme dei segnali da gestire con sigwait(): solo USR1
  sigset_t set;
  sigemptyset(&set);
  sigaddset(&set, SIGUSR1);
 
  // blocco questi segnali per questo thread (ma è l'unico...)
  int e=0; 
  e= pthread_sigmask(SIG_BLOCK, &set, NULL);
  if (e != 0) xtermina("Errore pthread_sigmask", QUI);

  // attende valore iniziale n
  int s; // segnale ricevuto
  siginfo_t siginfo;
  s = sigwaitinfo(&set, &siginfo);
  if (s<0) xtermina("Errore sigwaitinfo", QUI);
  int n = siginfo.si_value.sival_int;
  
  // inizio partita
  printf("Inizio partita con valore: %d\n", n);
  assert(n>=0);
  
  do {   // main loop
    if(n==0) {
      printf("Ha vinto alice\n"); break;
    }
    // scelgo il nuovo valore di n seguendo le regole del gioco
    n = n-1; 
    // invio il nuovo valore ad alice
    union sigval v;
    v.sival_int = n;
    s = sigqueue(getppid(),SIGUSR1, v); 
    if (s<0) xtermina("Errore sigqueue", QUI);
    if(n==0) {
      printf("Ha vinto bob\n"); break;
    }
    // attendo il nuovo valore di alice con sigwaitinfo
    // e verifico che la mossa di alice sia valida
  } while(1); 
  return 0;
}

