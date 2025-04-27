#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void *func(void *b) {
  if (*((bool *)b)) {
    char *ptr = malloc(6);
    (*ptr) += 1;
  }
}

int main(void) {
  pthread_t tid;
  bool t = true;
  pthread_create(&tid, NULL, func, &t);

  pthread_t tid2;
  bool f = false;
  pthread_create(&tid, NULL, func, &f);

  void *ret;
  void *ret2;

  pthread_join(tid, &ret);
  pthread_join(tid2, &ret2);

  return 0;
}
