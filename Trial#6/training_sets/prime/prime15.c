//#include<stdio.h>                     

int main()
{
       int n; int i; printf(" enter the number : ");
       scanf("%d",&n);
        for(i=2; i<n; i++)
        {
                if(n%i==0)
                {
                        printf("%d is not a prime number.", n);
                        return (1);
                }
        }
printf("%d is a prime number.", n);
}
