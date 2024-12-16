#include <stdio.h>

void checkDupliacteOccurace(int arr[], int size) {
    int freq[size];
    int visited = -1; 

    for (int i = 0; i < size; i++) {
        freq[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        if (freq[i] == visited) continue; 

        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
                freq[j] = visited;
            }
        }
        freq[i] = count; 
    }

    for (int i = 0; i < size; i++) {
        if (freq[i] == visited) continue; 
        for (int j = i + 1; j < size; j++) {
            if (freq[i] == freq[j] && freq[i] != visited) {
                printf("True\n");
                return;
            }
        }
    }
    printf("False\n");
}

int main() {
    int arr1[] = {4,5,6,6,4,3,6,4}; 
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {3,4,6,3,4,7,4,6,6,6}; 
    int size2 = sizeof(arr2) / sizeof(arr2[0]);


    checkDupliacteOccurace(arr1, size1);
    checkDupliacteOccurace(arr2, size2);

    return 0;
}