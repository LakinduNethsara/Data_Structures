#include <stdio.h>
#include <stdlib.h>
#define n 5
int arr[n];
int front=-1;
int rear=-1;

void enqueue();
void dequeue();
void display();
int peek();
int isFull();
int isEmpty();

int main(){
	int ch;
	do {
		printf("\n1.Enqueue\n");
		printf("2.Dequeue\n");
		printf("3.Display\n");
		printf("4.Peek\n");
		printf("5.Is Full\n");
		printf("6.Is Empty\n");
		printf("7.Exit");
		
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				//Enqueue
				enqueue();
				break;
			case 2:
				//Dequeue
				dequeue();
				break;
			case 3:
				//Display
				display();
				break;
			case 4:
				//Peek
				printf("Peek element is: %d",peek());
				break;
			case 5:
				//Is Full
				if(isFull()){
					printf("Queueu is full\n\n");
				}
				else{
					printf("Queueu is not full\n\n");
				}
				break;
			case 6:
				//Is Empty
				if(isEmpty()){
					printf("Queueu is empty\n\n");
				}
				else{
					printf("Queueu is not empty\n\n");
				}
				break;
			case 7:
				//exit
				exit(0);
				break;
			default:
				printf("Invalid choice...\n");
		}
	}while(ch);
}

int isEmpty(){
	if(rear==-1&&front==-1){
		return 1;
	}
	else{
		return 0;
	}
}

int isFull(){
	if(rear==n-1||(rear+1==front)){
		return 1;
	}
	else{
		return 0;
	}
}

void enqueue(){
	if(isFull()){
		printf("Queue is full\n\n");
	}
	else{
		if(front==-1){
			front=0;
		}
		rear++;
		printf("Enter a value: ");
		scanf("%d",&arr[rear]);
	}
}

void display(){
	if(isEmpty()){
		printf("Queue is Empty\n\n");
	}
	else{
		printf("values are: ");
		int i;
		if(front<=rear){
			for(i=front;i<=rear;i++){
				printf("%d ",arr[i]);
			}
		}
		else if(front>rear){
			for(i=front;front>rear;i++){
				printf("%d ",arr[i]);
				if(i==n){
					i=0;
				}
			}
		}
		printf("\n\n");
	}
}

void dequeue(){
	if(isEmpty()){
		printf("Queue is Empty\n\n");
	}
	else{
		if(front==rear){
			front=-1;
			rear=-1;
		}
		else if(front==n-1){
			front=-1;
		}
		else{
			front++;
		}
		
	}
}

int peek(){
	if(isEmpty()){
		printf("Queue is Empty\n\n");
		main();
	}
	else{
		return arr[front];
	}
}
