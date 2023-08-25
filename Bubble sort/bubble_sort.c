#include <stdio.h>
#include <stdlib.h>

int main(){
	int i,j,n,temp;
	printf("Enter the number of elements in array: ");
	scanf("%d",&n);
	int arr[n];
	for(i=0;i<n;i++){
		printf("Enter element %d: ",i+1);
		scanf("%d",&arr[i]);
	}
	
	printf("\n\nElements of the unsored array: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	for(i=0;i<n-1;i++){
		int a=0;
		for(j=0;j<n-1;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				a=1;
			}
		}
		if(a==0){
			break;
		}
	}
	
	printf("\n\nElements of the sored array: ");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
