#include<stdio.h>

/*     selection sort     */

int main(){
	int i,j,n,min;
	printf("Enter No.of Elements \t");
	scanf("%d",&n);
	int input[n];
	for(i=0;i<n;i++){
		scanf("%d",&input[i]);
	}
	for(i=0;i<n;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if( input[j] < input[min] ){
				min = j;
			}
		}
		if(min != i){
			int temp = input[min];
			input[min] = input[i];			
			input[i] = temp;
		}
	}
	return 0;
}


