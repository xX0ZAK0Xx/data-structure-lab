#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int minItems[MAX_SIZE];
    int top;
};

void initialize(struct Stack *s1) {
    s1->top = -1;
}

int isFull(struct Stack *s1) {
    return s1->top == MAX_SIZE - 1;
}

void push(struct Stack *s1, int item) {
    if (isFull(s1)) return;
    s1->items[++s1->top] = item;
    if (s1->top == 0 || item < s1->minItems[s1->top - 1]) {
        s1->minItems[s1->top] = item;
    } else {
        s1->minItems[s1->top] = s1->minItems[s1->top - 1];
    }
}

int isEmpty(struct Stack *s1) {
    return s1->top == -1;
}

int pop(struct Stack *s1) {
    if (isEmpty(s1)) return -1;
    return s1->items[s1->top--];
}

int getMin(struct Stack *s1) {
    if (isEmpty(s1)) return -1;
    return s1->minItems[s1->top];
}

int main() {
    struct Stack s1;
    initialize(&s1);
    push(&s1, 5);
    push(&s1, 3);
    push(&s1, 10);
    push(&s1, 2);
    printf("Minimum element after pushes: %d\n", getMin(&s1));
    pop(&s1);
    printf("Minimum element after one pop: %d\n", getMin(&s1));
    return 0;
}
