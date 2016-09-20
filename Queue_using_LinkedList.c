#include<stdio.h>
#include<stdlib.h>

struct Queue{
	int front,rear;
	int capacity;
	int array;
};
struct Queue q = NULL;
struct Queue *createQueue(int capacity){
	struct Queue *q = NULL;
	q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = -1;
	q->array = (int *)malloc(sizeof(int)*capacity);
	return q;
}
int isFull(struct Queue *s){
	if(  (s->rear+1)%capacity == s->front ){
		return 1;	
	}else{
		return 0;
	}
}
void enQueue(struct Queue *s,int data){
	if(isFull(s)){
		printf("Queue overflow\n");
		return;		
	}else{
		s->rear = (s->rear+1)%capacity;
		s->array[s->rear] = data;
		if(s->front == -1){
			s->front = s->rear;
		}
	}
}
int isEmpty(struct queue *q){
	if(q->front == -1){
		return 1;
	}else{
		return 0;
	}
}
int Dequeue(struct queue *q){
	int data = 0;
	if(isEmpty(q)){
		printf("Queue Empty\n");
		return;
	}else{
		data = q->array[s->front];
		if(q->front == q->rear){
			q->front = q->rear = -1;
		}else{
			q->front = (q->front+1)%q->capacity;
		}
	}
	return data;
}

void main(int argc,char *argv[]){
	int capacity = atoi(argv[1]);
	int choice,data,deQueueElement;
	printf("1.Enqueue\t2.Dequeue\t3.exit\n");
	printf("enter your choice \t");
	scanf("%d",&choice);
	q = createQueue(capacity);
	switch(choice){
		case 1:
			printf("enter data value \t");
			scanf("%d",&data);
			enQueue(q,data);
			break;
		case 2:
			deQueueElement = Dequeue(q)	
		default:
			printf("you choose wrong option\n");	
	}
}