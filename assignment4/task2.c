#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100

struct Stack {
    char items[MAX_SIZE];
    int top;
};

void initialize(struct Stack *s1) {
    s1->top = -1;
}

int isFull(struct Stack *s1) {
    return s1->top == MAX_SIZE - 1;
}

void push(struct Stack *s1, char item) {
    if (isFull(s1)) return;
    s1->items[++s1->top] = item;
}

int isEmpty(struct Stack *s1) {
    return s1->top == -1;
}

char pop(struct Stack *s1) {
    if (isEmpty(s1)) return '\0';
    return s1->items[s1->top--];
}

int isBalanced(const char *str) {
    struct Stack s1;
    initialize(&s1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '(') push(&s1, '(');
        else if (str[i] == ')') {
            if (isEmpty(&s1)) return 0;
            pop(&s1);
        }
    }
    return isEmpty(&s1);
}

int main() {
    const char *str = "(()()";
    printf("Is balanced: %s", isBalanced(str) ? "Yes" : "No");
    return 0;
}
