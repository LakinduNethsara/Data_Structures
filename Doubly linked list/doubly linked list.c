#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head,*tail=NULL;

void create();
void insert_begin();
void insert_middle();
void insert_end();
void delete_begin();
void delete_middle();
void delete_end();
void display();
void reverce();
int is_empty();


int main(){
	int ch;
	do{
		printf("1.Create\n");
		printf("2.Insert begin\n");
		printf("3.Insert middle\n");
		printf("4.Insert end\n");
		
		printf("5.Delete begin\n");
		printf("6.Delete middle\n");
		printf("7.Delete end\n");
		
		printf("8.Display\n");
		printf("9.Reverce\n");
		printf("10.Is Empty\n");
		
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				//create
				create();
				break;
			case 2:
				//Insert begin
				insert_begin();
				break;
			case 3:
				//Insert middle
				insert_middle();
				break;
			case 4:
				//Insert end
				insert_end();
				break;
			case 5:
				//Delete begin
				delete_begin();
				break;
			case 6:
				//Delete middle
				delete_middle();
				break;
			case 7:
				//Delete end
				delete_end();
				break;
			case 8:
				//Display
				display();
				break;
			case 9:
				//Reverce
				reverce();
				break;
			case 10:
				//Is Empty
				if(is_empty()){
					printf("Empty...\n");
				}
				else{
					printf("Not empty...\n");
				}
				break;
			case 11:
				//exit
				exit(0);
				break;
			default:
				printf("Invalid choice\n\n");
		}
	}while(ch);
}
int is_empty(){
	if(head==NULL&&tail==NULL){
		return 1;
	}
	else{
		return 0;
	}
}

void create(){
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(!newnode){
		printf("Out of memeory\n");
		return;
	}
	printf("Enter a value: ");
	scanf("%d",&newnode->data);
	newnode->next=newnode->prev=NULL;
	if(is_empty()){
		head=tail=newnode;
	}
	else{
		temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->prev=temp;
		tail=newnode;
	}
}

void display(){
	if(is_empty()){
		printf("nothing to show\n");
	}
	else{
		struct node *temp;
		temp=head;
		printf("Elements are: ");
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}


void reverce(){
	struct node *temp;
	if(is_empty()){
		printf("nothing to print\n");
	}
	else{
		temp=tail;
		printf("Reverce elements are: ");
		while(temp!=NULL){
			printf("%d ",temp->data);
			temp=temp->prev;
		}
		printf("\n");
	}
}


void insert_begin(){
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(!newnode){
		printf("Out of memeory\n");
		return;
	}
	printf("Enter a value: ");
	scanf("%d",&newnode->data);
	newnode->next=newnode->prev=NULL;
	if(is_empty()){
		head=tail=newnode;
	}
	else{
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
	}
}

void insert_end(){
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(!newnode){
		printf("Out of memeory\n");
		return;
	}
	else{
		if(is_empty()){
		head=tail=newnode;
		}
		else{
			printf("Enter a value: ");
			scanf("%d",&newnode->data);
			newnode->next=newnode->prev=NULL;
			newnode->prev=tail;
			tail->next=newnode;
			tail=newnode;
		}	
	}
}

void insert_middle(){
	struct node *newnode,*temp;
	int i,position;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(!newnode){
		printf("Out of memeory\n");
		return;
	}
	else{
		printf("Enter a position: ");
		scanf("%d",&position);
		temp=head;
		for(i=1;i<position-1;i++){
			if(temp==NULL){
				printf("Location is not reachable...\n");
				return;
			}
			temp=temp->next;
		}
		printf("Enter a value: ");
		scanf("%d",&newnode->data);
		newnode->next=newnode->prev=NULL;
		newnode->prev=temp;
		newnode->next=temp->next;
		newnode->next->prev=newnode;
		temp->next=newnode;
	}
}

void delete_begin(){
	if(is_empty()){
		printf("nothing to delete\n");
	}
	else{
		struct node *temp=head;
		if(head==tail){
			head=tail=NULL;
		}
		else{
			head=head->next;
			head->prev=NULL;	
		}
		free(temp);
	}
}

void delete_end(){
	if(is_empty()){
		printf("nothing to delete\n");
	}
	else{
		struct node *temp=tail;
		if(head==tail){
			head=tail=NULL;
		}
		else{
			//tail->next=NULL;
			tail->prev->next=NULL;
			tail=tail->prev;
		}
		free(temp);
	}
}

void delete_middle(){
	int i,position;
	struct node *temp;
	if(is_empty()){
		printf("nothing to delete\n");
	}
	else{
		printf("Enter a position: ");
		scanf("%d",&position);
		temp=head;
		for(i=1;i<position;i++){
			if(temp==NULL){
				printf("position is not reachable...\n");
				return;
			}
			temp=temp->next;
		}
		temp->prev->next=temp->next;
		temp->next->prev=temp->prev;
	}
}


