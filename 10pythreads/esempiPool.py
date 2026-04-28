#! /usr/bin/env python3

# esempi sui pool di thread

import sys, threading, logging, time, os
import concurrent.futures



# sleep per un numero assegnato di secondi
def tipo1(s):
  print(f"{threading.current_thread().name} Tipo 1: dormo per {s} secondi");
  time.sleep(s)
  print(f"{threading.current_thread().name} fine")
  return s

def tipo2(s):
  print(f"{threading.current_thread().name} Tipo 2: dormo per {s} secondi");
  time.sleep(s)
  print(f"{threading.current_thread().name} fine")
  return s


def main(p):
  with concurrent.futures.ThreadPoolExecutor(max_workers=p) as executor:
    executor.map(tipo1,range(1,6))
    executor.submit(tipo1,3.1415)
    print("=== Esecuzioni tipo 1 inviate")
    with concurrent.futures.ThreadPoolExecutor(max_workers=p) as executor2:
      executor2.map(tipo2,range(3,8))
      print("=== Esecuzioni tipo 2 inviate")
    print("=== Executor2 terminato")  
  print("=== Executor1 terminato")  


# invoca il main con il parametro passato sulla linea di comando 
if len(sys.argv)==2:
  main(int(sys.argv[1]))
else:
  print("Uso:\n\t %s numthread" % sys.argv[0])



