#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
};

void addAtBeginning(struct Node** head, int newValue) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = newValue;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL) (*head)->prev = newNode;
    *head = newNode;
}

void addAtEnd(struct Node** head, int newValue) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;
    newNode->value = newValue;
    newNode->next = NULL;
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    while (last->next != NULL) last = last->next;
    last->next = newNode;
    newNode->prev = last;
}

void insertAfterValue(struct Node* head, int value, int newValue) {
    while (head != NULL && head->value != value) head = head->next;
    if (head == NULL) return;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = newValue;
    newNode->next = head->next;
    newNode->prev = head;
    if (head->next != NULL) head->next->prev = newNode;
    head->next = newNode;
}

void insertAtPosition(struct Node** head, int position, int newValue) {
    if (position == 1) {
        addAtBeginning(head, newValue);
        return;
    }
    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) temp = temp->next;
    if (temp == NULL) return;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = newValue;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteByValue(struct Node** head, int value) {
    struct Node* temp = *head;
    while (temp != NULL && temp->value != value) temp = temp->next;
    if (temp == NULL) return;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp == *head) *head = temp->next;
    free(temp);
}

void deleteAtPosition(struct Node** head, int position) {
    struct Node* temp = *head;
    if (position == 1 && temp != NULL) {
        *head = temp->next;
        if (*head != NULL) (*head)->prev = NULL;
        free(temp);
        return;
    }
    for (int i = 1; i < position && temp != NULL; i++) temp = temp->next;
    if (temp == NULL) return;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    free(temp);
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->value);
        if (temp->next != NULL) printf(" <-> ");
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
