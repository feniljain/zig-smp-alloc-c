#include<stdio.h>
#include<pthread.h>
#include<stdbool.h>

__attribute__((weak)) int get(void);
__attribute__((weak)) void set(int);

void* func(void* b) {
    if(*((bool*)b)) {
        int val = get();
        printf("value from thread 2: %d\n", val);
    } else {
        set(3);
        printf("value set in thread 3: %d\n", get());
    }
}

int main(void) {
    set(1);

    int val = get();
    printf("value from thread 1: %d\n", val);

    pthread_t tid;
    bool t = true;
    pthread_create(&tid, NULL, func, &t);


    pthread_t tid2;
    bool f = false;
    pthread_create(&tid2, NULL, func, &f);

    void* ret;
    void* ret2;

    pthread_join(tid, &ret);
    pthread_join(tid2, &ret2);

    return 0;
}
