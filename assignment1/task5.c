#include <stdio.h>

void removeNum(int source[], int size, int idx) {
    for (int i = idx; i < size - 1; i++) {
        source[i] = source[i + 1];
    }
    source[size - 1] = 0;
}

int main() {
    int source[] = {10, 20, 30, 40, 50, 60, 70};
    int size = sizeof(source) / sizeof(source[0]);
    int idx = 2;

    removeNum(source, size, idx);

    printf("After removing the element at index %d:\n", idx);
    for (int i = 0; i < size; i++) {
        printf("%d ", source[i]);
    }

    return 0;
}
