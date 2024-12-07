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

void insertAfterValue(struct Node* head, int targetValue, int newValue) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->value == targetValue) {
            struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
            newNode->value = newValue;
            newNode->next = temp->next;
            temp->next = newNode;
            return;
        }
        temp = temp->next;
    }
    printf("Value %d not found in the list.\n", targetValue);
}

void insertAtPosition(struct Node** head, int position, int newValue) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = newValue;

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d is out of bounds.\n", position);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteByValue(struct Node** head, int targetValue) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (temp != NULL && temp->value == targetValue) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->value != targetValue) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", targetValue);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;

    if (position == 0) {
        *head = temp->next; 
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position %d is out of bounds.\n", position);
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
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

    addAtBeginning(&head, 5); 
    addAtEnd(&head, 10);
    addAtEnd(&head, 15);

    insertAfterValue(head, 10, 25);

    deleteByValue(&head, 10);

    insertAtPosition(&head, 2, 20);

    deleteAtPosition(&head, 3);

    printf("Linked List: ");
    printList(head);

    return 0;
}
