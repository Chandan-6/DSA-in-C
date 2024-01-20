#include<stdio.h>
#include<stdlib.h>
// bubble sort = comparing the adjacent elements and swaping it.
void bubblesort(int arr[],int n){
	int i,j,temp,max;
	for(i=0;i<n;i++){
		max = i;
		for(j=i+1;j<n;j++){
			if(arr[j] > arr[max]){
				max = j;
			}
		}
		//swaping
		temp = arr[i];
		arr[i] = arr[max];
		arr[max] = temp;
	}	
}

int main(){
	int n;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	printf("\n");
	int arr[n];
	for(int i=0;i<n;i++){
		arr[i] = rand()%100;
	}
	printf("Elements of array are: "); // original array
	for(int i=0;i<n;i++){
    	printf("%d ",arr[i]);
	}
	printf("\n");
	
	bubblesort(arr,n);
	
	printf("sorted array: "); 	// sorted array
	for(int i=0;i<n;i++){
    	printf("%d ",arr[i]);
	}
	printf("\n");
	
	
	
}
