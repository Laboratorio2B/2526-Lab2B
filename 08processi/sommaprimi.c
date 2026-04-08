#include "xerrori.h"

// calcola il numero e la somma dei primi contenuti
// in alcuni file di testo 
// utilizza dei processi ausiliari per il conteggio
// la comunicazione avviene attraverso 
// shared memory e con il controllo di alcuni semafori 

// il processo genitore crea un processo figlio mediante 
// fork + exec passando ad ognuno di essi il nome di un file 
// i processi figli calcolano ognuno la somma dei primi del loro file
// e accumulano in memoria condivisa il numero totale di primi 
// Dopo che il processo principale ha stampato i risultati, i  
// processi figli ripartono e accedono a tutte le somme
// per trovare quale file conteneva la somma dei primi maggiore. 
// Si noti che due semafori sono in pratica usati come barrier 
// mentre il terzo è usato come un mutex


#define QUI __LINE__,__FILE__
#define Sh_mem  "/sommaprimi"
#define Sh_sem1 "/sommaprimi1"
#define Sh_sem2 "/sommaprimi2"
#define Mutex   "/sommaprimi3"


int main(int argc, char *argv[])
{ 
  if(argc<2) {
    printf("Uso:\n\t%s file1 [file2 file3 ...] \n",argv[0]);
    exit(1);
  }
  int aux = argc-1;            // numero processi ausiliari

  // ---- creazione array memoria condivisa
  // la memria considvisa consiste delle aux+2 variabili:
  // | nump | indice | sommap[0] | sommap[1] | sommap[2] .... | 
  int shm_size = 2*sizeof(int)+sizeof(long); // uso 4+4+8*aux bytes di memoria condivisa
  int fd = xshm_open(Sh_mem,O_RDWR | O_CREAT, 0660, QUI);
  xftruncate(fd, shm_size, QUI);
  char *tmp = simple_mmap(shm_size,fd, QUI);
  int *nump = (int *) (tmp);
  int *indice = (int *) (tmp + sizeof(int));
  long *sommap = (long *) (tmp + 2*sizeof(int));
  close(fd); // dopo mmap e' possibile chiudere il file descriptor
    
  // ---- creo i semafori
  sem_t *sem1 = xsem_open(Sh_sem1,O_CREAT|O_EXCL,0666,0, QUI);
  sem_t *sem2 = xsem_open(Sh_sem2,O_CREAT|O_EXCL,0666,0, QUI);
  sem_t *mutex = xsem_open(Mutex,O_CREAT|O_EXCL,0666,1, QUI);
  // inizializzo variabili condivise 
  *nump = *indice = 0;
  for(int i=0;i<aux;i++) sommap[i] = 0;

  // faccio partire i processi ausiliari
  for(int i=0;i<aux;i++) {
    if(xfork( QUI)==0) {
      if(execl("sommaprimi_aux.out", "sommaprimi_aux.out", argv[i+1], (char *) NULL)==-1)
        xtermina("exec fallita", QUI);
    }
  }

  // attendo che ogni processo esegua una sem_post()
  // su sem1 per indicare che ha concluso il calcolo 
  for(int i=0;i<aux;i++)
    xsem_wait(sem1, QUI);

  // ora che tutti i figli hanno terminato posso stampare il risultato
  printf("Totale numero primi: %d. Somme ottenute:\n",*nump);
  for(int i=0;i<aux;i++)
    printf("%12ld\n", sommap[i]);

  // faccio ripartire tutti i figli sem2 inizialmente vale 0
  for(int i=0;i<aux;i++)
    xsem_post(sem2, QUI);

  // prenota distruzione oggetti in memoria condivisa 
  xshm_unlink(Sh_mem, QUI);  // distrugge shm quando finito
  xsem_unlink(Sh_sem1, QUI);  // distrugge sem quando finito  
  xsem_unlink(Sh_sem2, QUI);  // distrugge sem quando finito  
  xsem_unlink(Mutex, QUI);   // distrugge sem quando finito

  // unmap memoria condivisa
  xmunmap(tmp,shm_size,QUI);
  // chiude i semafori
  xsem_close(sem1, QUI);
  xsem_close(sem2, QUI);
  xsem_close(mutex, QUI);

  fprintf(stderr, "Io %d ho finito.\n",getpid());
  return 0;
}
