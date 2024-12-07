#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void initialize(struct Stack* s) {
    s->top = NULL;
}

void push(struct Stack* s, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = s->top;
    s->top = newNode;
}

int isEmpty(struct Stack* s) {
    return s->top == NULL;
}

int pop(struct Stack* s) {
    if (isEmpty(s)) return -1;
    struct Node* temp = s->top;
    int value = temp->value;
    s->top = s->top->next;
    free(temp);
    return value;
}

void printStack(struct Stack* s) {
    struct Node* current = s->top;
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    while (current != NULL) {
        printf("%d", current->value);
        if (current->next != NULL) printf(" ");
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Stack s;
    initialize(&s);
    push(&s, 1);
    push(&s, 2);
    printf("Top element popped: %d\n", pop(&s));
    printf("Current Stack: ");
    printStack(&s);
    return 0;
}
