#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char arr[MAX];  
    int top;        
} Stack;

void initStack(Stack* stack) {
    stack->top = -1;
}

// Ki?m tra ngãn x?p ð?y
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}
void push(Stack* stack, char c) {
    if (isFull(stack)) {
        printf("Ngãn xep day!\n");
        return;
    }
    stack->arr[++(stack->top)] = c;
}

// L?y ph?n t? t? ngãn x?p
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngãn xep rong!\n");
        return '\0';
    }
    return stack->arr[(stack->top)--];
}

void reverseString(char str[]) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < strlen(str); i++) {
        push(&stack, str[i]);
    }

    printf("Chuoi dao nguoc: ");
    while (!isEmpty(&stack)) {
        printf("%c", pop(&stack));
    }
    printf("\n");
}

int main() {
    char str[MAX];
    printf("Nhap chuoi: ");
    fgets(str, MAX, stdin);
    str[strcspn(str, "\n")] = '\0';

    reverseString(str);

    return 0;
}

