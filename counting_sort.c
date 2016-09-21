//couting sort
#include <stdio.h>

int main(){
	int array[] = {1,4,1,2,7,5,2};
	int n = sizeof(array)/sizeof(array[0]);

	int i, max = 0;

	for( i = 0; i < n; i++ ){
		if( max < array[i] ){
			max = array[i];
		}
	}

	int temp1_arr[max+1];

	for( i = 0; i < max+1; i++ ){
		temp1_arr[i] = 0;
	}

	for( i = 0; i < n; i++ ){ 
		temp1_arr[ array[i] ]++;
	}	

	for( i = 1; i < max+1; i++ ){
		temp1_arr[i] = temp1_arr[i-1] + temp1_arr[i];
	}	

	int output_array[n];

	for( i = 0; i < n; i++ ){ 
		output_array[temp1_arr[array[i]]-1] = array[i];
		temp1_arr[array[i]]--;
	}

	for( i = 0; i < n; i++ ){ 
		printf("%d ", output_array[i]);
	}
	printf("\n");

}
