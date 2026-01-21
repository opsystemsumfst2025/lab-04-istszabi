#include <stdio.h>
#include <stdlib.h>

int main() {
    // TODO: Hozz letre egy dinamikus int tombot 2 elem merettel
    int capacity = 2;  // Jelenlegi kapacitas
    int size = 0;      // Jelenleg hany elem van benne
    int* data = (int*)malloc(capacity * sizeof(int));
    
    // TODO: Ellenorizd, hogy a malloc sikeres volt-e
    if (data == NULL) {
        perror("Sikertelen malloc");
        return 1;
    }
    
    printf("Dinamikus tomb (kezdeti kapacitas: %d)\n", capacity);
    printf("Irj be szamokat (0 = vege):\n");
    
    while (1) {
        int number;
        printf("> ");
        if (scanf("%d", &number) != 1) {
            printf("Hibas bemenet!\n");
            break;
        }
        
        if (number == 0) {
            break;  // Vege a bevitelnek
        }
        
        // TODO: Ha a tomb betelt (size == capacity), duplázzuk a meretet
        if (size == capacity) {
            int new_capacity = capacity * 2;
            
            // FONTOS: Hasznald a helyes realloc mintát!
            int* temp = (int*)realloc(data, new_capacity * sizeof(int));
            
            if (temp == NULL) {
                printf("Sikertelen realloc!\n");
                free(data);
                return 1;
            }
            
            data = temp;
            capacity = new_capacity;
            printf("[Bovites] Uj kapacitas: %d\n", capacity);
        }
        
        // TODO: Add hozza a szamot a tombhoz
        data[size] = number;
        size++;
    }
    
    // Kiirjuk az eredmenyt
    printf("\nBeirt szamok (%d db): ", size);
    // TODO: Irj egy ciklust, ami kiirja az osszes szamot
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    
    printf("\n");
    
    // TODO: Szabaditsd fel a memoriat!
    free(data);
    
    return 0;
}
