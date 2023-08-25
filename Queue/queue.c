#include<stdio.h>
#include <stdlib.h>
#define n 3

int arr[n];
int front=-1;
int rear=-1;
int element;

void enqueue(int);
int dequeue();
int isFull();
int isEmpty();
int peek();
void display();

int main(){
	int ch;
	do{
		printf("\n1.Enqueue");
		printf("\n2.Dequeue");
		printf("\n3.Peek");
		printf("\n4.Disaplay");
		printf("\n5.Is Full");
		printf("\n6.Is Empty");
		printf("\n7.Exit");
		printf("\nEnter your option: ");
		scanf("%d",&ch);
		printf("\n");
		
		switch(ch){
			case 1:
				//enqueue
				printf("\nEnter the element: ");
				scanf("%d",&element);
				enqueue(element);
				break;
			case 2:
				//dequeue
				printf("Dequeue: %d",dequeue());
				break;
			case 3:
				//peek
				printf("\nPeek value is: %d\n",peek());
				break;
			case 4:
				//display
				display();
				break;
			case 5:
				//is full
				if(isFull()){
					printf("\nQueue is full\n");
				}
				else{
					printf("\nQueue is not full\n");
				}	
				break;
			case 6:
				//is empty
				if(isEmpty()){
					printf("\nQueue is empty\n");
				}
				else{
					printf("\nQueue is not empty\n");
				}
				break;
			case 7:
				exit(0);
				break;
			default:
				printf("\nInvalid choice...!\n");
		}
	}while(ch);
	
	
	
}
int isEmpty(){
	if(rear==-1||rear<front)
		return 1;
	else
		return 0;
}

int isFull(){
	if(rear==n-1)
		return 1;
	else 
		return 0;
}

void enqueue(int element){
	if(isFull()){
		printf("\nQueue is full.. Can not enqueue any element\n");
	}
	else{
		if(front==-1){
			front++;
		}
		rear++;
		arr[rear]=element;
	}
}

int dequeue(){
	if(isEmpty()){
		printf("Queue is empty\n\n");
		main();
	}
	else{
		int i=front;
		front++;
		return arr[i];
	}
}

int peek(){
	if(isEmpty()){
		printf("\nQueue is empty\n");
		main();
	}
	else{
		
		return arr[front];
	}
}

void display(){
	if(isEmpty()){
		printf("\nQueue is empty\n");
	}
	else{
		int i;
		printf("\nElements of the queue are: ");
		for(i=front;i<=rear;i++){
			printf("%d ",arr[i]);
		}
	}
}
