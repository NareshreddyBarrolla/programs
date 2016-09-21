#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head1 = NULL,*head2 = NULL,*current = NULL;

struct node *merge(struct node *a,struct node *b){
	if( a == NULL){
		return b;
	}
	if(b == NULL){
		return a;
	}
	struct node *temp = NULL,*tempHead = NULL;
	
	while( a && b ){
		if( a->data > b->data ){
			if(tempHead == NULL){
				tempHead = b;
				temp =b;
			}else{
				temp->next = b;
				temp = b;
			}
			b = b->next;
		}else{
			if(tempHead == NULL){
				tempHead = a;
				temp =a;
			}else{
				temp->next = a;
				temp = a;
			}
			a = a->next;
		}
	}
	
	while(a){
		temp->next = a;
		temp = a;
		a = a->next;
	}
	while(b){
		temp->next = b;
		temp = b;
		b = b->next;
	}
	
	return tempHead;	
}

void CreateList(int choice){

	struct node *temp;
	if(choice == 1){
		temp = head1;
	}else{
		temp = head2;
	}
	if(temp == NULL){
		current = NULL;
	}
	int data;
	printf("Enter data\t");
	scanf("%d",&data);
	
	struct node *newNode  = malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	if(temp == NULL){
		temp = newNode;
		current = newNode;		
	}else{
		current->next = newNode;
		current = newNode;
	}
	
	if(choice == 1){
		head1 = temp;
	}else{
		head2 = temp;
	}
	
}
void display(struct node *head){
	
	while(head){		
		printf("%d ",head->data);
		head = head->next;
	}
	printf("\n");
}
int main(){
	int choice;
	struct node *tempHead;
	while(1){
		printf("1.CreateList1()\t2.CreateList2()\t3.display()\t4.merge()\t5.exit()\t");;
		scanf("%d",&choice);
			switch(choice){
				case 1:
					CreateList( 1 );
					break;
				case 2:
					CreateList( 2 );
					break;	
				case 3:
					display(head2);
					break;
				case 4:
					tempHead = merge(head1,head2);
					display(tempHead);
					break;	
				case 5:
					exit(0);
					break;						
			}
	}
	return 0;
}
