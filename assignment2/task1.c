#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

void addAtBeginning(struct Node** head, int newValue) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = newValue;
    newNode->next = *head;
    *head = newNode;
}

void addAtEnd(struct Node** head, int newValue) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    newNode->value = newValue;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->value);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
}

int main() {
    struct Node* head = NULL;

    addAtBeginning(&head, 10);
    addAtEnd(&head, 20);
    addAtEnd(&head, 30);
    addAtBeginning(&head, 5);

    printf("Linked List: ");
    printList(head);

    return 0;
}
