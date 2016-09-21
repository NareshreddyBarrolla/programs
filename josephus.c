#include<stdio.h>
#include<stdlib.h>

struct CLL{
	int data;
	struct CLL *next;
};
struct CLL *head = NULL,*current=NULL;

struct CLL *getMemory(){
	struct CLL *temp = NULL;
	temp = (struct CLL *)malloc(sizeof(struct CLL));
	if(temp){
		return temp;
	}else{
		printf("Memory is not alloctated \n");
	}
}
void insert(){
	struct CLL *newNode = NULL;
	int data;
	printf("Enter data value \t");
	scanf("%d",&data);
	newNode = getMemory();
	newNode->data = data;
	if(head == NULL){
		head = newNode;
		newNode->next = NULL;
		current = newNode;
	}else{
		current->next = newNode;
		newNode->next = head;
		current = newNode;
	}
	
}

void display(struct CLL *head){
	struct CLL *temp = head;
	while(temp){
		printf("%d \n",temp->data);
		temp = temp->next;
		if(temp == head){
			break;
		}
	}
}

void josephus(struct CLL *head,int k){
	struct CLL *temp = head,*prev = NULL,*del = NULL;
	int count = 1;
	while(temp->next != temp){
		if(count == k){
			prev->next = temp->next;
			del = temp;
			temp = temp->next;
			free(del);
			count = 1;
		}
		prev = temp;
		temp = temp->next;
		count++; 		
	}
	printf("Leader Node : %d \n",temp->data);
}

void main(){
	int choice;
	while(1){
		printf("1.Insert\t2.Josephus\t3.Display\t4.exit \t");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				insert();
				break;
			case 2:
				josephus(head,3);
				break;
			case 3:
				display(head);
				break;
			case 4:
				exit(0);
			default:
				printf("choose wrong option \n");
		}
	}	
}
