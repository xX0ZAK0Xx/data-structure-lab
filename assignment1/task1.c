#include <stdio.h>

int length;

void shiftLeft(int source[], int k) {
    for (int i = 0; i < length; i++) {
        if (i + k < length) {
            source[i] = source[i + k];
        } else {
            source[i] = 0;
        }
    }
}

int main() {
    int source[] = {10, 20, 30, 40, 50, 60, 70, 80};
    length = sizeof(source) / sizeof(source[0]);
    int k = 3;
    
    shiftLeft(source, k);

    printf("After left shift by %d:\n", k);
    for (int i = 0; i < length; i++) {
        printf("%d ", source[i]);
    }
    
    return 0;
}
