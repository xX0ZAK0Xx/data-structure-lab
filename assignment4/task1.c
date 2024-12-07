#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *s1) {
    s1->top = -1;
}

int isFull(struct Stack *s1) {
    return s1->top == MAX_SIZE - 1;
}

void push(struct Stack *s1, int item) {
    if (isFull(s1)) {
        printf("Stack overflow\n");
        return;
    }
    s1->items[++s1->top] = item;
}

int isEmpty(struct Stack *s1) {
    return s1->top == -1;
}

int pop(struct Stack *s1) {
    if (isEmpty(s1)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s1->items[s1->top--];
}

void printStack(struct Stack *s1) {
    if (isEmpty(s1)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= s1->top; i++) {
        printf("%d", s1->items[i]);
        if (i < s1->top) printf(" ");
    }
}

int main() {
    struct Stack s1;
    initialize(&s1);
    push(&s1, 10);
    push(&s1, 20);
    push(&s1, 30);
    printf("Top element popped: %d\n", pop(&s1));
    printf("Current Stack: ");
    printStack(&s1);
    return 0;
}
