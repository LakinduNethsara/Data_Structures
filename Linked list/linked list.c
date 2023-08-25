#include<stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head=NULL;

void create();
void display();
void insert_begin();
void insert_middle();
void insert_end();

void delete_begin();
void delete_middle();
void delete_end();

int main(){
	int ch;
	do {
		printf("\n1.Create linked list");
		printf("\n2.Insert begin");
		printf("\n3.Insert middle");
		printf("\n4.Insert end");
		printf("\n5.Delete begin");
		printf("\n6.Delete middle");
		printf("\n7.Delete end");
		printf("\n8.Display");
		printf("\n9.Exit");
		
		printf("Enter your choice : ");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				//create
				create();
				break;
			case 2:
				//insert begin
				insert_begin();
				break;
			case 3:
				//insert middle
				insert_middle();
				break;
			case 4:
				//insert end
				insert_end();
				break;
			case 5:
				//delete begin
				delete_begin();
				break;
			case 6:
				//delete middle
				delete_middle();
				break;
			case 7:
				//delete end
				delete_end();
				break;
			case 8:
				//display
				display();
				break;
			case 9:
				//exit
				exit(0);
			default:
				printf("\nInvalid choice\n");
		}
		
	}while(ch);
}

void create(){
	struct node *newnode, *temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	
	
	if(!newnode){
		printf("\nOut of memeory\n");
	}
	else{
		printf("Enter the value need to be entered: ");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		
		if(head==NULL){
			head=newnode;
		}
		else{
			temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=newnode;
		}
	}
}

void insert_begin(){
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if (!newnode){
		printf("\nOut of memeory\n");
	}
	else{
		printf("Enter the value: ");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		newnode->next=head;
		head=newnode;
	}
}

void insert_middle(){
	struct node *newnode,*temp;
	int position,i;
	newnode=(struct node*)malloc(sizeof(struct node));
	if (!newnode){
		printf("\nOut of memeory\n");
	}
	else{
		temp=head;
		printf("\nEnter the position: ");
		scanf("%d",&position);
		
		if(temp==NULL){
			printf("\nThere is no such a postion to enter");
			main();
		}
		
		for(i=1;i<position-1;i++){
			temp=temp->next;
			if(temp==NULL){
				printf("\nThere is no such a postion to enter");
				main();
			}
		}
		
		printf("\nEnter the value: ");
		scanf("%d",&newnode->data);
		
		
		
		
		newnode->next=temp->next;
		temp->next=newnode;
	}
		
}

void insert_end(){
	struct node *newnode,*temp;
	int position,i;
	newnode=(struct node*)malloc(sizeof(struct node));
	if (!newnode){
		printf("\nOut of memeory\n");
	}
	else{
		if(head==NULL){
			printf("\nList is empty");
		}
		else{
			temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			printf("\nEnter the value: ");
			scanf("%d",&newnode->data);
			newnode->next=NULL;
			temp->next=newnode;
		}
	}
}

void delete_begin(){
	struct node *temp;
	if(head==NULL){
		printf("\nLinked list is empty\n");
	}
	else{
		temp=head;
		head=head->next;
		free(temp);
	}
}

void delete_end(){
	struct node *temp,*prev_node;
	if(head==NULL){
		printf("\nLinked list is empty\n");
	}
	else{
		if(head->next==NULL){
			printf("\nOnly node is deleted");
			free(head);
			head=NULL;
		}
		else{
			temp=head;
			while(temp->next!=NULL){
				prev_node=temp;
				temp=temp->next;
			}
			prev_node->next=NULL;
			free(temp);
		}
		
	}
	
}

void delete_middle(){
	struct node *temp,*prev_node;
	int position,i;
	if(head==NULL){
		printf("\nLinked list is empty\n");
	}
	else{
		temp=head;
		printf("Enter the position need to be deleted: ");
		scanf("%d",&position);
		for(i=1;i<position;i++){
			prev_node=temp;
			temp=temp->next;
			if(prev_node==NULL){
				printf("\nThere is no such an element to delete");
			}
		}
		prev_node->next=temp->next;
		free(temp);
	}
}



void display(){
	struct node *temp;
	temp=head;
	if(temp==NULL){
		printf("\nLinked list is empty\n");
		main();
	}
	else{
		printf("\nElements are: ");
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}
	}
}
