#include "xerrori.h"

#define QUI __LINE__,__FILE__


int main(int argc, char *argv[])
{ 
  if(argc!=2) {
    printf("Uso:\n\t%s nome_pipe\n",argv[0]);
    exit(1);
  }

  // crea la named pipe da usare per le comunicazioni
  int e = mkfifo(argv[1],0660);
  if(e==0) 
    puts("Named pipe creata");
  else if(errno== EEXIST)
    puts("La named pipe esiste già; procedo...");
  else    
    xtermina("Errore creazione named pipe",QUI);


#ifdef USA_EXEC
  // faccio partire il lettore, eventualmente anche un programma python
  if(xfork(QUI)==0) {
    // violiamo le convenzioni e passiamo un argv[0] diverso dal nome del programma
    // è solo dimostrativo, non si deve fare!!!
    if(execl("lettore.out", "attore.???", argv[1], (char *) NULL)==-1)
      xtermina("execl fallita",QUI);
  }
#endif
    
  // apre file descriptor associato alla named pipe
  int fd = open(argv[1], O_WRONLY);
  if (fd < 0) // se il file non esiste termina con errore
    xtermina("Errore apertura named pipe", QUI);
  // scrive interi sulla pipe per sempre
  puts("Ora inizio a scrivere");
  for (int val = 0; ; val++) {
    ssize_t e = write(fd,&val,sizeof(val));
    if(e!=sizeof(val))
      xtermina("Errore scrittura pipe",QUI);
    if(val%10000==0)
      fprintf(stderr,"%d: scritti %d interi\n",getpid(),val);
  }
  xclose(fd,QUI);
  printf("Io %d ho finito.\n",getpid());
  return 0;
}



