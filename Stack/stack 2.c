#include <stdio.h>
#include <stdlib.h>
#define n 3

typedef struct stack{
	int arr[n];
	int top;
}stk;
void push(stk *s);
int pop(stk *s);
int isFull(stk *s);
int isEmpty(stk *s);
void display(stk *s);

int main(){
	int ch;
	stk st;
	st.top=-1;
	do{
		printf("\n1.Push\n2.Pop\n3.Display\n4.Is Full\n5.Is Empty\n6.Exit\n");
		printf("Enter the option: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				//push
				push(&st);
				break;
			case 2:
				//pop
				printf("\nPopped element is: %d",pop(&st));
				break;
			case 3:
				//display
				display(&st);
				break;
			case 4:
				//is Full
				if(isFull(&st)){
					printf("\nStack is full\n");
				}
				else{
					printf("\nStack is not full\n");
				}
				break;
			case 5:
				//is Empty
				if(isEmpty(&st)){
					printf("\nStack is empty\n");
				}
				else{
					printf("\nStack is empty\n");
				}
				break;
			case 6:
				//exit
				exit(0);
			default:
				printf("\nInvalid choice...!\n");
		}
		
	}while(ch);
	
}

int isFull(stk *s){
	if(s->top==n-1){
		return 1;
	}
	else {
		return 0;
	}
}

int isEmpty(stk *s){
	if(s->top==-1){
		return 1;
	}
	else {
		return 0;
	}
}

void push(stk *s){
	int element;
	if(isFull(s)){
		printf("\nStack is full. cannot push any element\n");
	}
	else{
		printf("\nEnter the value need to be pushed: ");
		scanf("%d",&element);
		s->arr[++s->top]=element;
	}
}

int pop(stk *s){
	if(isEmpty(s)){
		printf("\nStack is empty. cannot pop any element\n");
	}
	else{
		return s->arr[s->top--];
	}
}

void display(stk *s){
	if(isEmpty(s)){
		printf("\nStack is empty. cannot display any element\n");
	}
	else{
		int i=s->top;
		printf("\nElements of the stack are: ");
		for(;i>-1;i--){
			printf("%d ",s->arr[i]);
		}
	}
}
