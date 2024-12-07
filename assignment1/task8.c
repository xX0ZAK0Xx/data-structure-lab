#include <stdio.h>
#include <stdbool.h>

bool hasDuplicateRepetitions(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        
        for (int k = i + 1; k < size; k++) {
            int otherCount = 0;
            for (int l = 0; l < size; l++) {
                if (arr[k] == arr[l]) {
                    otherCount++;
                }
            }
            
            if (count == otherCount) {
                return true; 
            }
        }
    }
    
    return false; 
}

int main() {
    int arr1[] = {4, 5, 6, 6, 4, 3, 6, 4};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {3, 4, 6, 3, 4, 7, 4, 6, 8, 6, 6};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    if (hasDuplicateRepetitions(arr1, size1)) {
        printf("Output for arr1: True\n");
    } else {
        printf("Output for arr1: False\n");
    }

    if (hasDuplicateRepetitions(arr2, size2)) {
        printf("Output for arr2: True\n");
    } else {
        printf("Output for arr2: False\n");
    }

    return 0;
}
