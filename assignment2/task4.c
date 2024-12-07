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

struct Node* detectCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;  
        fast = fast->next->next; 

        if (slow == fast) {   
            struct Node* entry = head;
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }
            return entry;
        }
    }

    return NULL;
}

void checkCycle(struct Node* head) {
    struct Node* cycleNode = detectCycle(head);
    if (cycleNode != NULL) {
        printf("Has Cycle: Yes\n");
        printf("Cycle Start Node: %d\n", cycleNode->value);
    } else {
        printf("Has Cycle: No\n");
    }
}

int main() {
    struct Node* head = NULL;

    addAtEnd(&head, 10);
    addAtEnd(&head, 20);
    addAtEnd(&head, 30);
    addAtEnd(&head, 40);

    struct Node* temp = head;
    struct Node* cycleStart = NULL;
    while (temp->next != NULL) {
        if (temp->value == 20) {
            cycleStart = temp;
        }
        temp = temp->next;
    }
    temp->next = cycleStart; 
    checkCycle(head);

    return 0;
}
