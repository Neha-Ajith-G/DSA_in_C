//quicksort pivot first el
#include <stdio.h>
void swap(int *x,int *y){
	int t= *x;
	*x = *y;
	*y = t;
}
//partition fn with 1st el as pivot;
int Partition(int a[],int lb,int ub){
	int pi=a[lb];
	int start=lb;
	int end=ub;
	while (start<end){
		while(a[start]<=pi){
			start++;
		}
		while(a[end]>pi){
			end--;
		}
		if(start<end){
			swap(&a[start],&a[end]);
		}
	}
	swap(&a[lb],&a[end]);
	return end;

}
//quicksort fn
void Quicksort(int a[],int lb,int ub);
void Quicksort(int a[],int lb,int ub){
	
	if (lb<ub){
		int pi= Partition(a,lb,ub);
		
		//recursively sort left subarr
		Quicksort(a,lb,pi-1);
		//recusively sort right
		Quicksort(a,pi+1,ub);
	}
	
}
void printArr(int a[],int size){
	for (int i=0;i<size;i++){
		printf("%d\n",a[i]);
	}
	printf("\n");
}
//main
int main(){
	int a[]={7,6,10,5,9,2,1,15,7};
	int n = sizeof(a)/sizeof(a[0]);
	printf("Original array:\n");
	printArr(a,n);
	Quicksort(a,0,n-1);
	printf("Sorted array:\n");
	printArr(a,n);
	return 0;
}