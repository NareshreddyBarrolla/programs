#include<stdio.h>
#include<stdlib.h>

/*   Quick Sort */

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int input[],int start,int end){
	int j;
	int pivot = input[end];
	int pIndex = start;
	
	for(j=start;j<=end-1;j++){
		if ( input[j] <= pivot ) {						
			swap(&input[pIndex], &input[j]);			
			pIndex++;
		}
	}
	swap(&input[pIndex], &input[end]);		
	return pIndex;
	
}
 
void QuickSort(int input[],int start,int end){
	int pIndex,i;
	//static int arrayEnd = end;
	if(start<end){
		pIndex = partition(input,start,end);		
		QuickSort(input,start,pIndex-1);
		QuickSort(input,pIndex+1,end);		
	}
}
int main(){
	int n,i;
	printf("Enter n Value \n");
	scanf("%d",&n);
	int input[n];
	for(i=0;i<n;i++){
		scanf("%d",&input[i]);
	}
	QuickSort(input,0,n-1);
	printf("Count:%d \n",count);
	printf("Sorted Array \n");
	for(i=0;i<n;i++){
		printf("%d ",input[i]);
	}
	printf("\n");
}
