//#include<stdio.h>
int main()
{
	int n,rem,sum = 0;
    printf("\nEnter a number : ");
    scanf("%d",&n);
    while(n > 0)
    {
	    while(n != 0)
        {
	        rem = n%10;
           	sum = sum+rem;
            n=n/10;
        }
        if(sum > 9)
        {
        	n = sum;
            sum = 0;
        }          
    }
    printf("%d",sum);
}
