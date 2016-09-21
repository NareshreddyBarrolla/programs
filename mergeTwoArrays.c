#include<stdio.h>
void mergeLists(int nl,int nr,int *l,int *r){
	int A[nl+nr];
	int i=0,j=0,k=0;
	while( i<nl && j<nr ){
		if(l[i] <= r[j] ){
			A[k] = l[i];
			i++;
		}else{
			A[k] = r[j];
			j++;
		}
		k++;
	}
	while(i<nl){
		A[k] = l[i];
		i++;
		k++;
	}
	while(j<nr){
		A[k] = r[j];
		j++;
		k++;
	}
	printf("Sorted Array \n");
	for(i=0;i<k;i++){
		printf("%d ",A[i]);
	}
	printf("\n"); 
}
int main(){
	int l_size,r_size,i;
	printf("enter L and R sizes : \t");
	scanf("%d%d",&l_size,&r_size);
	int l[l_size],r[r_size];
	printf("enter L array values \n");
	for(i=0;i<l_size;i++){
		scanf("%d",&l[i]);
	}
	printf("enter R array values \n");
	for(i=0;i<r_size;i++){
		scanf("%d",&r[i]);
	}
	mergeLists(l_size,r_size,l,r);
}

