#include <stdio.h>
int length;

void rotateRight(int source[], int k) {
    int source2[length];

    for (int i = 0; i < length; i++) {
        source2[(i + k) % length] = source[i];
    }

    for (int i = 0; i < length; i++) {
        source[i] = source2[i];
    }
}

int main() {
    int source[] = {10, 20, 30, 40, 50, 60, 70, 80};
    length = sizeof(source) / sizeof(source[0]);
    int k = 3;

    rotateRight(source, k);

    printf("After rotating right by %d:\n", k);
    for (int i = 0; i < length; i++) {
        printf("%d ", source[i]);
    }

    return 0;
}
