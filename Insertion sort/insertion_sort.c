#include <stdio.h>

int main(){
	int i,j,k,n,temp;
	printf("Enter the number of elements in the array: ");
	scanf("%d",&n);
	int arr[n];
	
	for(i=0;i<n;i++){
		printf("Enter the element %d:",i+1);
		scanf("%d",&arr[i]);
	}
	
	printf("\n\nElements before sort: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	
	
	
	for(k=1;k<n;k++){
		temp=arr[k];
		j=k-1;
		while(temp<arr[j]&&j>=0){
			arr[j+1]=arr[j];
			j--;	
		}
		arr[j+1]=temp;
		
	}
	
	printf("\n\nElements of the sorted array are: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	
}
