#include "xerrori.h"

// programma per il conteggio di numero dei primi in un
// file di testo. 
// Usa shared memory e semafori per comunicare i risultati al
// genitore e agli altri processi figli
// vedere sommaprimi.c per i dettagli


#define QUI __LINE__,__FILE__
#define Sh_mem  "/sommaprimi"
#define Sh_sem1 "/sommaprimi1"
#define Sh_sem2 "/sommaprimi2"
#define Mutex   "/sommaprimi3"



// restituisce true/false a seconda che n sia primo o composto
bool primo(int n)
{
  if(n<2) return false;
  if(n%2==0) {
    if(n==2)  return true;
    else return false; }
  for (int i=3; i*i<=n; i += 2) 
      if(n%i==0) return false;
  return true;
}


int main(int argc, char *argv[]) {
  if(argc!=2) {
    printf("Uso:\n\t%s nomefile\n",argv[0]);
    exit(1);
  }
  // fprintf(stderr, "Processo %d (figlio di %d) iniziato\n",getpid(),getppid());
  // ---- creazione array memoria condivisa
  // la memria considvisa consiste delle aux+2 variabili:
  // | nump | indice | sommap[0] | sommap[1] | sommap[2] .... | 
  int shm_size = 2*sizeof(int)+sizeof(long); // uso 4+4+8*aux bytes di memoria condivisa
  int fd = xshm_open(Sh_mem,O_RDWR | O_CREAT, 0660, QUI);
  char *tmp = simple_mmap(shm_size,fd, QUI);
  int *nump = (int *) (tmp);
  int *indice = (int *) (tmp + sizeof(int));
  long *sommap = (long *) (tmp + 2*sizeof(int));
  close(fd); // dopo mmap e' possibile chiudere il file descriptor
    
  // ---- apro i semafori NON devo usare O_CREAT altrimenti perdo il valore presente  
  sem_t *sem1 = xsem_open(Sh_sem1, 0,0,0,QUI);
  sem_t *sem2 = xsem_open(Sh_sem2,0,0,0, QUI);
  sem_t *mutex = xsem_open(Mutex,0,0,0, QUI);

  // --- apro il file e conto i primi
  int tot=0; long somma=0; 
  // apro il file e conto i primi
  FILE *f = fopen(argv[1],"rt");
  if(f==NULL) {
    printf("Apertura file %s fallita\n", argv[1]);
  }
  else {
    while(true) {
      int e, n;
      e = fscanf(f,"%d",&n);
      if(e!=1) break;
      if(primo(n)) {
        tot +=1;
        somma += n;
      }
    }
    fclose(f);
  }
  // ottengo il mio identificatore
  xsem_wait(mutex, QUI); // equivalente a mutex_lock
  int id = *indice;  // legge valore corrente indice 
  *indice += 1;     // incrementa indice
  xsem_post(mutex, QUI); // equivalente a mutex_unlock
  printf("Il processo %d con file %s ha ottenuto l'id %d\n",getpid(), argv[1],id);
  
  // scrivo la somma nella mia posizione dell'array (no mutex)
  sommap[id] = somma;
  // incremento il totale dei primi (mutex necessario)
  xsem_wait(mutex, QUI); // equivalente a mutex_lock
  *nump += tot;     // incrementa indice
  xsem_post(mutex, QUI); // equivalente a mutex_unlock

  // segnalo al processo pincipale che ho terminato il conteggio
  xsem_post(sem1, QUI);


  // attendo dal processo principale il vai per la seconda fase
  xsem_wait(sem2, QUI);
  
  // quando arrivo qui tutti i processi figli hanno ottenuto l'indice e fatto
  // quindi *indice contiene il numero di processi figli
  
  long maxsum=0;
  for(int j=0; j<*indice; j++)
    if(sommap[j]>maxsum) maxsum= sommap[j];
  
  if(somma==maxsum) 
    printf("Io processo %d con file %s ho la somma massima: %ld\n",getpid(),argv[1], somma);

  // chiude i semafori
  xsem_close(sem1, QUI);
  xsem_close(sem2, QUI);
  xsem_close(mutex, QUI);
  exit(0);
}

