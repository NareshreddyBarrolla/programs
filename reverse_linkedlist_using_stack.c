// Reversing a liked list using satck

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *root = NULL,*temp,*current;

int stack[20];
int top = -1;

void create(){ 

	int data;
	printf("Enter data value \t");
	scanf("%d",&data);
	
	if(root == NULL){
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = data;
		temp->next = NULL;
		root = temp;
		current = temp;
	}else{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = data;
		temp->next = NULL;
		current->next = temp;
		current = temp;
	}
}

void display(){
	struct node *temp = root;
	while(temp != NULL){
		printf("%d \t",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void push(int data){
	top++;
	stack[top] = data;
}


void reverse_print(){
	int i;

	struct node *temp = root;

	while(temp != NULL){
		push(temp->data);	
		temp = temp->next;
	}
	
	printf("Revers of the give linked list \n");
	for(i=top;i>-1;i--){
		printf("%d \t",stack[i]);
	}
	printf("\n");
}

void main(){
	int ch;
	while(1){
		printf("1.create \t 2.Display \t 3.Reverse \t 4.Exit \n");
		printf("Enter ur choice \t");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				reverse_print();
				break;
			case 4:
				exit(0);
			default:
				printf("you entered wrong option \n");

		}
		
	}
}
