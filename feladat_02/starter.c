#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Globalis bankszamla egyenleg
int balance = 0;

// TODO: Deklaralj egy pthread_mutex_t valtozot ide
pthread_mutex_t mutex;

#define NUM_THREADS 10
#define INCREMENTS_PER_THREAD 1000

// A szal fuggveny, amit minden szal vegre fog hajtani
void* deposit_money(void* arg) {
    for (int i = 0; i < INCREMENTS_PER_THREAD; i++) {
        // TODO: Zarold a mutexet itt (pthread_mutex_lock)
        pthread_mutex_lock(&mutex);

        balance++;

        // TODO: Oldsd fel a mutexet itt (pthread_mutex_unlock)
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    
    // TODO: Inicializald a mutexet
    // Vagy hasznald: pthread_mutex_init(&mutex, NULL);
    // Vagy globalis szinten: pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_init(&mutex, NULL);
    
    printf("Kezdeti egyenleg: %d dollar\n", balance);
    printf("Inditas: %d penztaros, mindegyik %d dollar befizetesevel...\n", 
           NUM_THREADS, INCREMENTS_PER_THREAD);
    printf("MOST MAR MUTEX VEDEEMMEL!\n\n");
    
    // Szalak inditasa
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, deposit_money, NULL) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }
    
    // Szalak bevarasa
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(1);
        }
    }
    
    // TODO: Suntessed meg a mutexet (pthread_mutex_destroy)
    pthread_mutex_destroy(&mutex);
    
    printf("Vegso egyenleg: %d dollar\n", balance);
    printf("Vart egyenleg: %d dollar\n", NUM_THREADS * INCREMENTS_PER_THREAD);
    
    if (balance == NUM_THREADS * INCREMENTS_PER_THREAD) {
        printf("\nSIKER! A mutex megvedi a kozos valtozot.\n");
    } else {
        printf("\nHIBA! Meg mindig van adatvesztes. Ellenorizd a mutex hasznalatat!\n");
    }
    
    return 0;
}
