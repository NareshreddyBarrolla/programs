#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *link;
};

struct node *root=NULL,*temp,*current;

void create(){
	int n;
	printf("enter data value \n");
	scanf("%d",&n);
	if(root == NULL){
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = n;
//		temp->next = Null;
		current = temp; 
		root = temp;
	}else{
		temp = (struct node*)malloc(sizeof(struct node));
		temp->data = n;
		current->link = temp;  
		current = temp;
		
	}
}

void dispaly(){

	printf("Your Data \n");

	struct node *temp;
	temp = root;
	while(temp!=NULL){
		printf("%d \n",temp->data);
		temp = temp->link;
	}
}

void search(){
	int value;
	printf("enter the value to be search \n");
	scanf("%d",&value);
	struct node *temp = root;

	while(temp != NULL){
		if(temp->data == value){
			printf("Value found \n");
			break;
		}else{
			temp = temp->link;
		}
	}
}

void delete(){
	int value;
	printf("enter the value to be delete \n");
	scanf("%d",&value);
	struct node *temp = root,*store;

	while(temp != NULL){

		struct node *prev = temp;

		if(temp->data == value){

			printf("Value found \n");

			store = temp->link;
			prev->link = store;
			free(temp);
				
			break;
		}else{
			temp = temp->link;
		}
	}
}

void main(){
	int ch;
		while(1){
			printf("1.create,2.display,3.search,4.delete,5.exit \n");
			printf("Ur choice \n");
			scanf("%d",&ch);
	
			switch(ch){
				case 1:
					create();
					break;
				case 2:
					dispaly();
					break;
				case 3:
					search();
					break;
				case 4:
					delete();
					break;
				case 5:
					exit(0);
				default:
					printf("Wrong option \n");
			}
		}
}
