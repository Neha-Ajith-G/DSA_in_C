#include <stdio.h>   
int stack[50],i,j,choice=0,n,top=-1;  
void push(int n);  
void pop();  
void show();  
void main ()  
{  
      

    printf("Stack operations using array:");  
    while(choice != 4)  
    {  
        printf("Choose one from the below options...\n");  
        printf("\n1.Push\n2.Pop\n3.Show\n4.Exit");  
        printf("\n Enter your choice \n");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {  printf("Enter the number of elements in the stack\n ");   
                scanf("%d",&n);   
                push(n);  
                break;  
            }  
            case 2:  
            {  printf("Popped\n");
                pop();  
                break;  
            }  
            case 3:  
            {  printf("Stack:\n");
                show();  
                break;  
            }  
            case 4:   
            {  
                printf("Exiting....");  
                break;   
            }  
            default:  
            {  
                printf("Please Enter your choice again ");  
            }   
        };  
    }  
}   
  
void push (int n)  
{  
    int val;     
    for (i=0;i<n;i++){
     
        if (top == n )  {
            printf("\nStack Overflow\n"); 
         } 
        else   
        {  
            printf("Enter the value:");  
            scanf("%d",&val);         
            top = top +1;   
            stack[top] = val;   
        }   
    } 
 }
  
void pop ()   
{   
    if(top == -1)   
    printf("Stack Underflow\n");  
    else  
    top = top -1;   
}   
void show()  
{  
    for (i=top;i>=0;i--)  
    {  
        printf("%d\n",stack[i]);  
    }  
    if(top == -1)   
    {  
        printf("Stack is empty\n");  
    }  
}  
