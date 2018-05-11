/* Contador de palavras
 *
 * Este programa recebera uma serie de caracteres representando palavras em sua
 * entrada. Ao receber um caractere fim de linha ('\n'), deve imprimir na tela o
 * numero de palavras separadas que recebeu e, apos, encerrar.
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #include <pthread.h>

#define MAX_NUMBERS 12
#define IN_LENGTH 100
#define N_THREADS 4

int qty_primes = 0;
int complete[MAX_NUMBERS];
unsigned long long int numbers[MAX_NUMBERS];
pthread_mutex_t lock;

int check_prime(unsigned long long int number){
  if (number <= 1 || (number != 2 && number % 2 == 0)){
    return 0;
  }
  else {
    unsigned long long int d = 3;
    while (d <= number / 2) {
      if (number % d == 0){
        return 0;
      }
      d = d + 2;
    }
  }
  return 1;
}

void* worker(void *arg) {
  int instance=0;
  while (1) {
    pthread_mutex_lock(&lock);
    while ( (complete[instance]!=0) && (instance < MAX_NUMBERS)) {
      instance++;
    }
    if (instance >= MAX_NUMBERS) {
      pthread_mutex_unlock(&lock);
      break;
    }
    complete[instance] = 1;
    pthread_mutex_unlock(&lock);
    qty_primes += check_prime(numbers[instance]);
  }
  return NULL;
}

int main() {
  pthread_t workers[N_THREADS];
  int thread_id[N_THREADS];
  int array_current_size = 0;
  char symb;
  for (int i=0; i<N_THREADS; i++) {
    thread_id[i] = i;
  }
  for (size_t i = 0; i < MAX_NUMBERS; i++) {
    numbers[i] = 0;
    complete[i] = 0;
  }

  /* Read the numbers */
  do {
    scanf("%llu%c", &numbers[array_current_size++], &symb);
  } while (symb != '\n');

  /* Disparing threads */
  for (int i=0; i<N_THREADS; i++) {
    pthread_create(&(workers[i]), NULL, worker, (void*) (&thread_id[i]));
  }

  /* Waiting threads */
  for (int i=0; i<N_THREADS; i++) {
    pthread_join(workers[i], NULL);
  }

  printf("%d\n", qty_primes);
  return 0;
}
