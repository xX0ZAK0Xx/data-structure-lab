#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

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

struct Node* mergeSortedLists(struct Node* headA, struct Node* headB) {
    if (headA == NULL) return headB;
    if (headB == NULL) return headA;

    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (headA != NULL && headB != NULL) {
        if (headA->value <= headB->value) {
            tail->next = headA;
            headA = headA->next;
        } else {
            tail->next = headB;
            headB = headB->next;
        }
        tail = tail->next;
    }
    
    if (headA != NULL) {
        tail->next = headA;
    } else {
        tail->next = headB;
    }

    return dummy.next;
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
    struct Node* listA = NULL;
    struct Node* listB = NULL;

    addAtEnd(&listA, 10);
    addAtEnd(&listA, 30);

    addAtEnd(&listB, 20);
    addAtEnd(&listB, 40);

    struct Node* mergedList = mergeSortedLists(listA, listB);

    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
