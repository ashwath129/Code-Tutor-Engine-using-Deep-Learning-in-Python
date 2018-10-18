//#include <stdio.h>
int main()
{    
	int num,sum; 
	printf("Enter a Number :");
    scanf("%d",&num);
    do
    {
	    sum = 0;      
        do
        {
	        sum += num % 10;    
            num /= 10;              
        }while (num > 0);
        num = sum;            
    }while (num > 9);     
    printf("Sum of digits %d\n", sum);
    return 0;
} 
