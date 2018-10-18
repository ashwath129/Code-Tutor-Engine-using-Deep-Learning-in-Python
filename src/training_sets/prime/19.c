
	
#include<stdio.h>
 
int main()
{
    int n,i,flag=1;
    printf("Enter any number:");
    scanf("%d",&n);
    
    for(i=2;i<n/2;++i)
        if(n%i==0)
        {
            flag=0;
            break;
        }
    
    if(flag==1)
        printf("\nThe given number is prime");
    else
        printf("\nThe given number is not prime");
 
    return 0;
}