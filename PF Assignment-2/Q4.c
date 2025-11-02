#include<stdio.h>

void push(int stack[], int *top, int maxSize){
	if(*top==maxSize-1){
		printf("Stack Overflow!\n");
		return;
	}
	int element;
	printf("Enter the element you want to insert: ");
	scanf("%d", &element);
	(*top)++;
	stack[*top]=element;
	printf("Element inserted successfully!\n");
}
void pop(int stack[], int *top){
	if(*top==-1){
		printf("Stack Underflow!\n");
		return;
	}
	(*top)--;
	printf("Top element removed successfully!\n");	
}
void peek(int stack[], int top){
	if(top==-1){
		printf("Stack is empty!\n");
		return;
	}
	printf("Top element: %d\n", stack[top]);
}
void display(int stack[], int top){
	if(top==-1){
		printf("Stack is empty!\n");
		return;
	}
	printf("Stack: ");
	for(int j=0; j<=top; j++){
		printf("%d ", stack[j]);
	}
	printf("\n");
}

int main(){
	int stack[5];
	int top=-1; 
	int maxSize=5;
	int choice;

	printf("\tStack\n");
	do{
		printf("Menu:\n");
		printf("1. PUSH\n2. POP\n3. PEEK\n4. DISPLAY\n5. EXIT\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				push(stack, &top, maxSize);
				break;
			case 2:
				pop(stack, &top);
				break;
			case 3:
				peek(stack, top);
				break;
			case 4:
				display(stack, top);
				break;
			case 5:
				printf("Stack Ended!");
				return 1;
			default:
				printf("Invalid Input!\n");
		}
	}
	while(choice!=5);
	
	
	return 0;
}
