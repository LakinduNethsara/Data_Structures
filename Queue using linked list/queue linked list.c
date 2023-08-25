#include <stdio.h>
#include <stdlib.h>
struct node{
 	int data;
 	struct node *next;
};

struct node *front=NULL,*rear=NULL;

void enqueue(int item);
void dequeue();
void peek();
void display();

int main(){
	int choice, item;
	do{
		printf("\n1.Enqueue");
		printf("\n2.Dequeue");
		printf("\n3.Display");
		printf("\n4.Peak");
		printf("\n5.Exit");
		
		printf("\nEnter an option: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				printf("\nEnter a value t enqueue: ");
				scanf("%d",&item);
				enqueue(item);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
			case 4:
				peek();
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("\nInvalid choice...\n");
		}
		
	}while(choice);
}

void enqueue(int item){
	struct node *new_node;
	new_node=(struct node*)malloc(sizeof(struct node));
	if(new_node==NULL){
		printf("\nOut of memory\n");
		main();
	}
	new_node->data=item;
	new_node->next=NULL;
	if(front==NULL&&rear==NULL){
		front=rear=new_node;
	}
	else{
		rear->next=new_node;
		rear=new_node;
	}
}

void dequeue(){
	struct node* temp;
	temp=front;
	if (front==NULL&&rear==NULL){
		printf("\nQueue is empty\n");
		main();
	}
	front=front->next;
	free(temp);
}

void display(){
	struct node *temp;
	if(rear==NULL&&front==NULL){
		printf("\nQueue is empty\n");
		main();
	}
	else{
		temp=front;
		printf("\nElements in the queue are: ");
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
	
}
void peek(){
	if(front==NULL&&rear==NULL){
		printf("\nQueue is empty\n");
		main();
	}
	printf("Peek value is %d",front->data);
}
