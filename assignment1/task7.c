#include <stdio.h>

void removeAll(int source[], int size, int element) {
    int completed = 0;
    
    for (int i = 0; i < size; i++) {
        if (source[i] != element) {
            source[completed] = source[i];
            completed++;
        }
    }

    for (int i = completed; i < size; i++) {
        source[i] = 0;
    }
}

int main() {
    int source[] = {10, 20, 30, 10, 50, 60, 10, 80};
    int size = sizeof(source) / sizeof(source[0]);
    int element = 10; 

    removeAll(source, size, element);

    printf("After removing all occurrences of %d:\n", element);
    for (int i = 0; i < size; i++) { 
        printf("%d ", source[i]);
    }

    return 0;
}
