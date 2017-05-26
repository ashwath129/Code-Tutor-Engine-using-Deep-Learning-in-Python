//#include <stdio.h>
int main()
{    
	int num,sum; 
    printf("Enter a Number :");
    scanf("%d",&num);
    do
    {
   		sum = 0;      /* sum of digits of number */
        do
        {
	        sum += num % 10;    /* add LS digit to sum */
			num /= 10;               /* remove LS digit from num */
        }while (num > 0);
        num = sum;             /* use digit sum as new number */
    }while (num > 9);      /* as long as num has 2 or more digits */
    printf("Sum of digits %d\n", sum);
	return 0;
} 
