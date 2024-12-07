#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int* items;
    int top;
    int capacity;
};

void initialize(struct Stack* s, int capacity) {
    s->items = (int*)malloc(capacity * sizeof(int));
    s->top = -1;
    s->capacity = capacity;
}

int isFull(struct Stack* s) {
    return s->top == s->capacity - 1;
}

int isEmpty(struct Stack* s) {
    return s->top == -1;
}

void push(struct Stack* s, int x) {
    if (isFull(s)) return;
    s->items[++s->top] = x;
}

int pop(struct Stack* s) {
    if (isEmpty(s)) return -1;
    return s->items[s->top--];
}

void increment(struct Stack* s, int k, int val) {
    int limit = (k < s->top + 1) ? k : s->top + 1;
    for (int i = 0; i < limit; i++) {
        s->items[i] += val;
    }
}

void printStack(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= s->top; i++) {
        printf("%d", s->items[i]);
        if (i < s->top) printf(", ");
    }
    printf("\n");
}

int main() {
    struct Stack s;
    initialize(&s, 5);
    push(&s, 5);
    push(&s, 2);
    push(&s, 3);
    increment(&s, 2, 1);
    printf("Current Stack after incrementing bottom 2 elements: ");
    printStack(&s);
    printf("Top element popped: %d\n", pop(&s));
    printf("Current Stack: ");
    printStack(&s);
    return 0;
}
