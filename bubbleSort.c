#include<stdio.h>

/*     bubble sort     */

int main(){

	int i,j,n,flag = 1;
	
	printf("Enter No.of Elements \t");
	scanf("%d",&n);
	
	int input[n];
	
	for(i=0;i<n;i++){
		scanf("%d",&input[i]);
	}

	for(i=n-1;i>=0;i--){
		if(flag){
				flag = 0;
			for(j=0;j<i;j++){
				if( input[j] > input[j+1] ){
					int temp  = input[j];
					input[j] = input[j+1];
					input[j+1] = temp;
					flag = 1;
				}
			}
		}
	}
	printf("Sorted List \n");
	for(i=0;i<n;i++){
		printf("%d ",input[i]);
	}
	printf("\n");
	return 0;
}
