#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct faculty{
	int id;
	char *name;
	char *qul;
	int age;
	int no_OfPublications;
	struct faculty *next;
};
struct faculty *root = NULL;
struct faculty *current = NULL;
struct faculty *previous = NULL;

struct faculty *getMemory(){
	struct faculty *p = malloc(sizeof(struct faculty));
	return p;
}
void passInfo(int *info){	
	struct faculty *temp = root;
	while(temp){
		if(temp->id == info[0]){
			temp->no_OfPublications = info[1];			
		}
		temp = temp->next; 
	}
}
void updateValue(char *line){
	char *s = " ";
	char *token;
	int info[2];
	int i=0;
	token = strtok(line,s);
	while( token != NULL ){
		info[i] = atoi(token);
		token = strtok(NULL,s);
		i++;
	}
	passInfo(info);
}
void updateRecord(char *filename,char *update){
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	FILE *fp;
	char *token;
	char *s = " ";
	fp = fopen(filename,"r");
	int startPoint=0;	

	while( ( read = getline(&line,&len,fp) ) != -1 ){
		if( strcmp(line,update) == 0 ){
			startPoint = 1;
		}
		if( strcmp(line,update) != 0 && startPoint == 1){
			updateValue(line);
						
		}
	}
		
}


void display(struct faculty *root){
	while(root){
		printf("Id: %d\t Name: %s\t Qualification: %s\t Age: %d\t NO_Of_Publications: %d\n",root->id,root->name,root->qul,root->age,root->no_OfPublications);
		root = root->next;
	}
}
void deletefiles(int id){
	struct faculty *temp = root;
	struct faculty *p,*q;
	int position = 1;
	int count = 1;
	if(temp == NULL){
		printf("Empty Lsit \n");
		return;
	}
	
	while(temp){	
		if(temp->id == id && count == 1){
			root = temp->next;		
			free(temp);
			return;
		}
		if(temp->id == id && count > 1){
			p->next = temp->next;
			free(temp);
		}
		p = temp;
		temp = temp->next;
		count++;
	}
}

void deleteInstance(char *filename,char *initial,char *breakpoint){
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	FILE *fp;
	char *token;
	char *s = " ";
	fp = fopen(filename,"r");
	int i;	
	int c = 1;
	while( ( read = getline(&line,&len,fp) ) != -1 ){				

		if( strcmp(line,initial) == 0 )		{
			c = 0;
		}
		if( strcmp(line,initial) != 0 && strcmp(line,breakpoint) != 0 ){
			int count = 0;
			if( c == 0  ){				
				token = strtok(line,s);
				if( c == 0  ){
					while(token != NULL){
						count++;
						if(count == 1){
							deletefiles(atoi(token));					
						}
						token = strtok(NULL,s);					
					}
				}				
			}
		}
		if(strcmp(line,breakpoint) == 0){
			break;
		}			

	}
}

void initialread(char *filename,char *initial,char *breakpoint){
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	FILE *fp;
	char *token;
	char *s = " ";
	fp = fopen(filename,"r");
	int i;	
	int c = 1;
	while( ( read = getline(&line,&len,fp) ) != -1 ){				

		if( strcmp(line,initial) == 0 )		{
			c = 0;
		}	
		if( strcmp(line,initial) != 0 && strcmp(line,breakpoint) != 0 ){
			int count = 0;
			current = getMemory();
			token = strtok(line,s);
			if(root == NULL && previous == NULL){
				root = current;
				previous = current;
			}
			if( c == 0  ){
				while(token != NULL){				
				count++;									
					if(count == 1){
						current->id = atoi(token);					
					}
					if(count == 2){
						current->name= NULL;
						current->name = malloc(strlen(token));
						strcpy(current->name,token);						
				
					}
					if(count == 3){
						current->qul= NULL;
						current->qul = malloc(strlen(token));
						strcpy(current->qul,token);						
					}
					if(count == 4){
						current->age = atoi(token);
					}
					if(count == 5){
						current->no_OfPublications = atoi(token);
						current->next = NULL;
						if( previous != NULL ){
							previous->next = current;
						}
					        previous = current;
					}					
				token = strtok(NULL,s);
			}
			}
		}
		if(strcmp(line,breakpoint) == 0){
			break;
		}		
	}
		
}

void main(int argc,char *argv[]){

	char *filename = argv[1];
	char *initial  = "#initial\n";
	char *insert   = "#insert\n";
	char *delete   = "#delete\n";
	char *update   = "#update\n";

	initialread(filename,initial,insert);
	printf("Initial Data \n");
	display(root);
	initialread(filename,insert,delete);		
	printf("After Insert \n");
	display(root);
        deleteInstance(filename,delete,update);			
	printf("After Delete \n");	
	display(root);
	updateRecord(filename,update);	
	printf("After Update \n");	
	display(root);
}
