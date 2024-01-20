#include<stdio.h>

void selection_sort(int a[],int n){
	int min;
	for(int i=0;i<n;i++){
		min = i;
		for(int j=0;j<n;j++){
			if(a[j]<a[min]){
				min = j;
				int temp = a[min];
				a[min] = a[i];
				a[i] = temp;
			}
			
		}
	}
}

int main(){
	int a[5] = {12,11,13,5,6};
	selection_sort(a,5);
	
	for(int i=0;i<5;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
