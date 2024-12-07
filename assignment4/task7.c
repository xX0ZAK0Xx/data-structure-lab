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

int peek(struct Stack* s) {
    if (isEmpty(s)) return -1;
    return s->items[s->top];
}

void sortStack(struct Stack* s) {
    struct Stack tempStack;
    initialize(&tempStack, s->capacity);

    while (!isEmpty(s)) {
        int temp = pop(s);

        while (!isEmpty(&tempStack) && peek(&tempStack) > temp) {
            push(s, pop(&tempStack));
        }

        push(&tempStack, temp);
    }

    while (!isEmpty(&tempStack)) {
        push(s, pop(&tempStack));
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
    push(&s, 3);
    push(&s, 1);
    push(&s, 4);
    push(&s, 2);
    sortStack(&s);
    printf("Sorted Stack: ");
    printStack(&s);
    return 0;
}
