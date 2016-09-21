#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root = NULL;
int count = 0;

//int stack[count];
//int queue[count];
struct node **stack;
struct node **queue;
int top=-1;
int front = -1;
int rear = -1;



struct node *getNode(){
	struct node *temp = NULL;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void insert(struct node *root,struct node *new_node){
	if(root->data > new_node->data){
		if(root->left == NULL){
			root->left = new_node;			
			count++;
		}else{
			insert(root->left,new_node);
		}
	}
	if(root->data < new_node->data){
		if(root->right == NULL){
			root->right = new_node;		
			count++;
		}else{
			insert(root->right,new_node);
		}
	}
}

int isFull(){
	if( (rear+1)%count == front){
		return 1;
	}else{
		return 0;
	}
}

int isEmpty(){
	if(front == -1){
		return 1;
	}else{
		return 0;
	}
}

struct node *deQueue(){
	struct node *returnValue;
	if(isEmpty()){
		printf("Queue Empty \n");
		return;
	}else{
		returnValue = queue[front];
		if(front == rear ){
			front =rear = -1;
		}else{
			front = (front+1)%count;	
		}		
	}
	return returnValue;
}

void enqueue(struct node *root){
	if(isFull()){
		printf("Queue overflow\n");
		return;
	}else{
		rear = (rear+1)%count;
		queue[rear] = root;
		if(front == -1){
			front = rear;
		}
	}
}

int isStackFull(){
	if(top == count-1){
		return 1;
	}else{
		return 0;
	}
}

void push(struct node *root){
	if(isStackFull()){
		printf("Stack overflow\n");
		return;
	}else{
		stack[++top] = root;
	}
}
int isStackEmpty(){
	if(top == -1){
		return 1;
	}else{
		return 0;
	}
}
struct node *pop(){
	struct node *returnValue;
	if(isStackEmpty()){
		printf("Stack is Empty\n");
		return;
	}else{
		returnValue = stack[top--];
	}
	return returnValue;
}

void levelorder(struct node *root,int count){
       int height = 0;		
	struct node *temp;	
	enqueue(root);
	while(!isEmpty()){
  		height++;
		temp = deQueue();		
		if(temp->left){
			enqueue(temp->left);
		}
		if(temp->right){
			enqueue(temp->right);
		}
		printf("%d\t",temp->data);
		push(temp);
	}
	printf("\n");
	printf("Level order from buttom to top \n");
	while(!isStackEmpty()){
		printf("%d\t",pop()->data);
	}	
	printf("\nHeight:%d\n",height/2);
}

void main(int argc,char *argv[]){
	int choice,data;
	struct node *new_node;	
	while(1){
		printf("Choice you option\n");
		printf("1.Insert\t2.levelorder\t3.exit\t");
		scanf("%d",&choice);
		switch(choice){
			case 1:			
				new_node  = getNode();
				printf("enter node values\t");
				scanf("%d",&new_node->data);
				if(root == NULL){
					root = new_node;					
					count++;
				}else{
					insert(root,new_node);
				}
				stack = (struct node **)malloc(sizeof(struct node *)*count);				
				queue = (struct node **)malloc(sizeof(struct node *)*count);
				break;
			case 2:				
				levelorder(root,count);
				break;
			case 3:
				exit(0);
				break;	
			default:
				printf("you choose wrong option\n ");		

		}	
	}	
}
