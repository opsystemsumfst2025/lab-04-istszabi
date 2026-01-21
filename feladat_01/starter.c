#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Globalis bankszamla egyenleg
int balance = 0;

// TODO: Definiald a szalak szamat (10)
#define NUM_THREADS 10

// TODO: Definiald, hogy hanyszor noveljen minden szal (1000)
#define INCREMENTS_PER_THREAD 1000

// A szal fuggveny, amit minden szal vegre fog hajtatni
void* deposit_money(void* arg) {
    // TODO: Irj egy ciklust, ami INCREMENTS_PER_THREAD-szer fut
    // TODO: Minden iteracioban noveld a balance valtozot egyel
    for (int i = 0; i < INCREMENTS_PER_THREAD; i++) {
        balance++;
    }
    return NULL;
}

int main() {
    // TODO: Hozz letre egy pthread_t tombot NUM_THREADS meretu elemmel
    pthread_t threads[NUM_THREADS];

    printf("Kezdeti egyenleg: %d dollar\n", balance);
    printf("Inditas: %d penztaros, mindegyik %d dollar befizetesevel...\n", 
           NUM_THREADS, INCREMENTS_PER_THREAD);

    // TODO: Inditsd el a szalakat egy ciklussal
    // Hasznald a pthread_create fuggvenyt
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, deposit_money, NULL) != 0) {
            perror("pthread_create hiba");
            return 1;
        }
    }

    // TODO: Vard meg, hogy minden szal befejeződjon
    // Hasznald a pthread_join fuggvenyt
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Vegso egyenleg: %d dollar\n", balance);
    printf("Vart egyenleg: %d dollar\n", NUM_THREADS * INCREMENTS_PER_THREAD);

    if (balance != NUM_THREADS * INCREMENTS_PER_THREAD) {
        printf("\nADATVESZTES TORTENT! Ez egy race condition.\n");
    } else {
        printf("\nSzerencses vagy - ezuttal jo lett az eredmeny.\n");
        printf("De ez nem jelenti, hogy a kod helyes!\n");
    }

    return 0;
}
