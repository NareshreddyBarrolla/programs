// Lined list create,display,insert,insert_At_End, delete, n_th_node, palindrom operations

#include<stdio.h>
#include<stdlib.h>

struct ListNode{
	int data;
	struct ListNode *next;
};
struct ListNode *head = NULL,*tail = NULL;

struct ListNode *getNodeMemory(){
	struct ListNode *temp;
	temp = (struct ListNode *)malloc(sizeof(struct ListNode));
	return temp;
}

struct ListNode *mid(struct ListNode *head){
	struct ListNode *t1=head,*t2=head;
	int flag = 1;
	while(t1){
		if(flag){
			t1 = t1->next;
			flag = 0;
		}else{
			t1 = t1->next;
			t2 = t2->next;
			flag = 1;
		}
	}
	return t2;
}

void create(){
	struct ListNode *temp;
	int data;
	printf("Enter Data Value \t");
	scanf("%d",&data);
	temp = getNodeMemory();
	temp->data = data;
	if(head == NULL){
		head = temp;
		tail = temp;
		temp->next = NULL;
	}else{
		tail->next = temp;
		temp->next = NULL;
		tail = temp;
	}	
}
void display(){
	struct ListNode *temp = head;	
	while( temp != NULL ){	
		printf("data :%d \n",temp->data);
		temp = temp->next;
	}
}
void Insert(struct ListNode *head,int position){
	int data,k=1;
	printf("Enter Data Value \t");
	scanf("%d",&data);
	struct ListNode *temp = head,*p = NULL,*q = NULL;
	p = getNodeMemory();
	p->data = data;
	if(position == 1){				
		p->next = temp;
		head = p;		
	}else{
		while( temp!=NULL && k < position ){
			k++;
			q = temp;
			temp = temp->next;
		}
		q->next = p;
		p->next = temp;
	}
}
void insertAtEnd(struct ListNode *head){
	struct ListNode *temp = head,*newNode=NULL;
	int data;
	printf("Enter Data Value \t");
	scanf("%d",&data);
	newNode = getNodeMemory();
	newNode->data = data;
	tail->next = newNode;
	tail = newNode;	 
}
void deleteNode(struct ListNode *head,int position){
	struct ListNode *p,*temp = head;
	int k = 1;
	if(position == 1){
		head = temp->next;
		free(temp);
	}else{
		while( temp != NULL && k < position ){
			p = temp;
			temp = temp->next;
			k++;
		}
		p->next = temp->next;
		free(temp);
	}
}

void nthNode(struct ListNode *head,int n){
	struct ListNode *temp = head,*curr = head;
	int count = 0;
	while(temp){
		count++;
		temp = temp->next;
	}
	printf("Count : %d \n",count-1);	
	if( count-1 > n-1 ){
		nthNode(head->next,n);
	}else{
		printf("Node : %d \n",head->data);
	}	
}
struct ListNode *reverse(struct ListNode *head){
	struct ListNode *temp = NULL,*nextNode = NULL;
	while(head){
		nextNode = head->next;
		head->next = temp;
		temp  = head;
		head = nextNode;
	}
	return temp;
}
void palindrom(int count,struct ListNode *midNode,struct ListNode *head){
	struct ListNode *temp = head,*temp1=NULL;
	if(head->next == NULL){
		printf("List is Palindrome \n");
		return;
	}
	int flag = 1;

		while( temp->next != midNode){
			temp = head->next;
		}		
		temp->next = reverse(midNode);
		midNode = temp->next;						
		temp1 = midNode;
		while( head != midNode ){

			if( head->data != temp1->data ){				
				flag = 0;
				break;
			}
			head = head->next;
			temp1 = temp1->next;
		}
		if(flag){
			printf("List is Palindrome \n");
		}else{
			printf("List is not Palindrome \n");		
		}
		temp->next = reverse(midNode);			

}
void main(){
	int choice,position,count=0;	
	struct ListNode *midNode = NULL;
	while(1){
		printf("1.InitialInsertion\t2.NewInsertion\t3.display\t4.InsertAtEnd\t5.Delete\t6.nthNode\t7.mid\t8.exit \t");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				create();
				count++;
				break;
			case 2:
				printf("Enter Position \t");
				scanf("%d",&position);
				Insert(head,position);
				break;
			case 3:
				display();
				break;
			case 4:
				insertAtEnd(head);
				break;
			case 5:
				printf("Enter Position \t");
				scanf("%d",&position);
				deleteNode(head,position);
				break;
			case 6:
				printf("Enter Position \t");
				scanf("%d",&position);
				nthNode(head,position);
				break;
			case 7:
					midNode = mid(head);
					printf("C: %d\t Mid : %d\n",count,midNode->data);
					palindrom(count,midNode,head);
					break;
			case 8:
				exit(0);			
		}		
	}
}
