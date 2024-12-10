#include <stdio.h>
#include <stdlib.h>
#define MAX 5

// Cau tr�c du li?u ng�n xep
typedef struct {
    int array[MAX]; 
    int top;     
} Stack;

// Tao ngan xep rong 
void initialize(Stack* stack) {
    stack->top = -1; // dat dinh chua top tai vi tri -1 
}

// Ki?m tra ng�n xep c� rong hay kh�ng
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Kiem tra ng�n xep c� day hay kh�ng
int isFull(Stack* stack) {
    return stack->top >= MAX - 1;
}

// Th�m phan tu v�o ng�n xep
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Ngan xep da day. Khong the them phan tu %d.\n", value);
        return;
    }
    stack->array[++(stack->top)] = value; // T�ng dinh  v� th�m gi� tr?
}
//xoa phan tu 
int pop(Stack* stack) {
    return stack->array[(stack->top)--];
}

// In c�c phan tu trong ng�n xep
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Ngan xep rong.\n");
        return;
    }
    printf("Cac phan tu trong ngan xep:\n");
    for (int i = 0; i <= stack->top; i++) { // Duyet tu dinh 
        printf("%d\n", stack->array[i]);
    }
}
//xoa 1 phan tu trong mang

int main() {
    int value;
    Stack stack; // Tao ng�n xep
    initialize(&stack); // Khoi tao ng�n xep

    while (1) { // Vong lap tao menu 
        printf("\n======================= MENU =============================\n");
        printf("1. Them phan tu vao ngan xep\n");
        printf("2. In ra ngan xep\n");
        printf("0. Thoat\n");
        printf("Moi ban chon (0 -> 2): ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Thoat chuong trinh.\n");
                exit(0);
            case 1:
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                push(&stack, value); // G?i h�m push �? th�m ph?n t?
                break;
            case 2:
                printStack(&stack); // G?i h�m in ng�n x?p
                break;
            case 3 :
                value = pop(&stack);
                if(value != 1){
                	printf("da loai bo phan tu : %d",value);
                	break;
				}
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }

    return 0;
}

