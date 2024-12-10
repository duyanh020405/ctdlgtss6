#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char arr[MAX];  
    int top;       
} Stack;

// Hàm kh?i t?o ngãn x?p r?ng
void initStack(Stack* stack) {
    stack->top = -1;

int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char c) {
    if (isFull(stack)) {
        printf("Ngãn x?p ð?y!\n");
        return;
    }
    stack->arr[++(stack->top)] = c;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0'; 
    }
    return stack->arr[(stack->top)--];
}

int isValidExpression(char* expr) {
    Stack stack;
    initStack(&stack);

    for (int i = 0; i < strlen(expr); i++) {
        char ch = expr[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(&stack, ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            char top = pop(&stack);
            if ((ch == ')' && top != '(') || 
                (ch == '}' && top != '{') || 
                (ch == ']' && top != '[')) {
                return 0; // Không h?p l?
            }
        }
    }

    return isEmpty(&stack);
}

int main() {
    char expr[MAX];

    printf("Nhap bieu thuc: ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0'; 
    if (isValidExpression(expr)) {
        printf("Bieu thuc hop le\n");
    } else {
        printf("Bieu thuc khong hop le\n");
    }

    return 0;
}

