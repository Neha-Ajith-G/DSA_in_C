#include<stdio.h>
int main(){

    int arr[10]={6,2,5,3,8};
    int n=5;
    int key,i,j;
    for (i=1;i<n;i++){
        key=arr[i];
        j= i-1;
        while( j >= 0 && arr[j] > key ){
            arr[j+1] = arr[j];
            j--;           
        }
         arr[j+1] = key;
    }
    printf("\nSORTED ARRAY:\n");
    for (int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    } 


}
