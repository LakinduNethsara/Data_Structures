#include <stdio.h>

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main(){
	int n,i,j;
	printf("Enter the number of elements in array: ");
	scanf("%d",&n);
	int arr[n];
	
	for(i=0;i<n;i++){
		printf("Enter element %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	printf("\n\nElements before sort: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	
	for(i=0;i<n-1;i++){
		int min_index=i;
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[min_index]){
				min_index=j;
			}
		}
		//swap(&arr[min_index],&arr[i]);
		int temp=arr[i];
		arr[i]=arr[min_index];
		arr[min_index]=temp;
	}
	
	printf("\n\nElements of the sorted array are: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	
}
