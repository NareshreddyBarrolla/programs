#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};	
struct node *root = NULL;

struct node *getNode(){
	struct node *temp = NULL;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void insert(struct node *root,struct node *new_node){
	if(root->data > new_node->data){
		if(root->left == NULL){
			root->left = new_node;
		}else{
			insert(root->left,new_node);
		}
	}
	if(root->data < new_node->data){
		if(root->right == NULL){
			root->right = new_node;
		}else{
			insert(root->right,new_node);
		}
	}
}

void preorder(struct node *root){
	if(root){
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}	
}
void inorder(struct node *root){
	if(root){		
	  inorder(root->left);
      printf("%d", root->data);
      inorder(root->right);
	}	
}

void postorder(struct node *root){	
	if(root){		
		postorder(root->left);		
		postorder(root->right);
		printf("%d ",root->data);
	}	
}

void main(int argc,char *argv[]){
	int choice;
	struct node *new_node;
	while(1){
		printf("1.insert\t2.preorder\t3.inorder\t4.postorder\t5.exit\n");
		printf("enter your choice \t");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				new_node  = getNode();
				printf("enter node values\t");
				scanf("%d",&new_node->data);
				if(root == NULL){
					root = new_node;
				}else{
					insert(root,new_node);
				}
				break;
			case 2:
			    printf("Preorder\n");
				preorder(root);
				printf("\n");
				break;
			case 3:
			    printf("inorder\n");
				inorder(root);
				printf("\n");
				break;
			case 4:
			    printf("postorder\n");
				postorder(root);
				printf("\n");
				break;		
			case 5:
				printf("level order\n");
				levelorder(root);	
			case 5:
				exit(0);
				break;
			default:
				printf("you entered wrong option\n");			
		}	
	}	
}
