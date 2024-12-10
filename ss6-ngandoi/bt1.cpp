#include <stdio.h>
#include <stdlib.h>
#define MAX 5


typedef struct {
	int arr[MAX];
	int top;
} Stack;

//tao ngan xep rong
int nganxep (Stack* stack){
	stack->top = -1;
}
//kiem tra rong
int ktrong(Stack* stack){
	return stack->top = -1;
	
}
int ktday(Stack* stack){
	return stack->top >= MAX-1;
}
void push(Stack* stack , int value){
	if(ktday(stack)){
		 printf("Ngan xep da day. Khong the them phan tu %d.\n", value);
        return;
	}
	stack->arr[++(stack->top)] = value;
}
int printList(Stack* stack){
	printf("danh sach : \n");
	for(int i = 0 ; i < stack->top ; i++){
		printf("%d\n",stack->arr[i]);
	}
}

int main(){
	int value;
	Stack stack;
	nganxep(&stack);
	while(1){
		printf("\n======================= MENU =============================\n");
        printf("1. Them phan tu vao ngan xep\n");
        printf("2. In ra ngan xep\n");
        printf("0. Thoat\n");
        printf("Moi ban chon (0 -> 2): ");
        int a ;
        scanf("%d",&a);
        switch(a){
        	case 1 : 
        	    printf("nhap phan tu : ");
        	    scanf("%d",&value);
        	    push(&stack,value);
        	    break;
        	case 2 :
        		printList(&stack);
        		break;
		}
	}
	
}
