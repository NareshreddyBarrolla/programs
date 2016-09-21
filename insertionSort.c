#include<stdio.h>

/*     insertion sort     */

int main(){
	int i,j,n,min;
	printf("Enter No.of Elements \t");
	scanf("%d",&n);
	int input[n];
	for(i = 0; i < n; i++){
		scanf("%d",&input[i]);
	}
	int value,hole;
	for(i = 1; i <= n-1; i++){
		value = input[i];
		hole = i;
		while( hole > 0 && input[hole-1] > value ){
			input[hole] = input[hole-1];
			hole = hole-1;
		}
		input[hole] = value;
	}
	printf("Sorted List \n");
	for(i = 0; i < n; i++){
		printf("%d ",input[i]);
	}
	printf("\n");
	return 0;
}


