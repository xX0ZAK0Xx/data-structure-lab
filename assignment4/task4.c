#include <stdio.h>
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

void reverseString(const char *str, char *reversed) {
    struct Stack s1;
    initialize(&s1);
    int length = strlen(str);
    for (int i = 0; i < length; i++) push(&s1, str[i]);
    int index = 0;
    while (!isEmpty(&s1)) reversed[index++] = pop(&s1);
    reversed[index] = '\0';
}

int main() {
    const char *str = "Data";
    char reversed[MAX_SIZE];
    reverseString(str, reversed);
    printf("Reversed string: %s", reversed);
    return 0;
}
