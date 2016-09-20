#include<stdio.h>
#include<stdlib.h>

struct arrayStack{
	int top;
	int capacity;
	int *array;
};
struct arrayStack *s = NULL;


struct arrayStack *createStack(int capacity){
	struct arrayStack *s = (struct arrayStack *)malloc(sizeof(struct arrayStack));
	s->top = -1;
	s->capacity = capacity;
	s->array = (int*)malloc(sizeof(int)*capacity);
	if(s == NULL ){
		printf("Memory error\n");
		return;
	}
   return s;
}

int isFull(struct arrayStack *s){
	if(s->top == s->capacity-1){
		return 1;
	}else{
		return 0;
	}
}

void push(struct arrayStack *s,int data){
	if(isFull(s)){
		printf("stack is full\n");
		return;
	}else{
		s->array[++s->top] = data;
	}	
}
int isEmpty(struct arrayStack *s){
	if(s->top == -1 ){
		return 1;
	}else{
		return 0;
	}
}
int pop(struct arrayStack *s){
	if(isEmpty(s)){
		printf("stack is Empty\n");
		return 0;
	}else{
		return(s->array[s->top--]);
	}
}
int top(struct arrayStack *s){
	return s->array[s->top];
}
void main(int argc,char *argv[]){
	int capacity = atoi(argv[1]);
	int choice;
	int data;
	int popElement;
	int topElement;
	s = createStack(capacity);
	while(1){
		printf("1.push\t2.pop\t3.top\t4.isEmpty\t5.isFull\t6.exit\n");
		printf("enter your choice \n");
		scanf("%d",&choice);
		switch(choice){	
			case 1:				
				printf("enter element\t");
				scanf("%d",&data);
				push(s,data);
				break;
			case 2:
				popElement = pop(s);
				printf("popElement is : %d\n",popElement);
				break;	
			case 3:
				topElement = top(s);
				printf("topElement is : %d\n",topElement);	
				break;
			default:
				printf("you choose wrong option\n");	

		}	
	}	
}